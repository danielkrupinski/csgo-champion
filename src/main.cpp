#include <iostream>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <X11/extensions/XTest.h>

#include <unistd.h>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <chrono>
#include <thread>
#include <libconfig.h++>

#include "remote.h"
#include "cheat.h"
#include "logger.h"
#include "config.h"
#include "noflash.h"
#include "musickit_changer.h"
#include "offsets.h"

using namespace std;
//using namespace libconfig;

constexpr bool dumpOffsets {0}; // set to 1 if you want to dump offsets

Display* display = XOpenDisplay(0);

Cfg cfg {display};

bool GetKeyCodeState(KeyCode keyCode)
{
    if (!display)
    {
        return false;
    }

    char szKey[32];

    XQueryKeymap(display, szKey);

    return szKey[keyCode / 8] & (1 << (keyCode % 8));
}

int main()
{
	Logger::init();

	if (getuid())
	{
		Logger::error(string("You need to be ") + UNDERLINE + "root");
		return 0;
	}

	cfg.updateConfigValues();

	remote::Handle csgo;

	while (true)
	{
		if (remote::FindProcessByName("csgo_linux64", &csgo))
			break;

		usleep(500);
	}

	stringstream ss;
	ss << "\t PID:\t [";
	ss << csgo.GetPid();
	ss << "]";

	Logger::normal (ss.str());

	remote::MapModuleMemoryRegion client;

	client.start = 0;

	while (client.start == 0) {
		if (!csgo.IsRunning()) {
			Logger::error("The game is not even running!");
			return 0;
		}

		csgo.ParseMaps();

		for (auto region : csgo.regions) {
			if (region.filename.compare("client_client.so") == 0 && region.executable) {
				client = region;
				break;
			}
		}

		usleep(500);
	}

	client.client_start = client.start;

    Offsets offsets {csgo, client};
	//unsigned long pEngine = remote::getModule("engine_client.so", csgo.GetPid());

	/*if (pEngine == 0)
	{
		Logger::error("Couldn't find engine module!");
		return 0;
	}*/

	//csgo.a_engine_client = pEngine;



	if (dumpOffsets) {
		Logger::address ("client_client.so:\t", client.start);
		//Logger::address ("engine_client.so:\t", pEngine);

		Logger::address ("Glow pointer:\t", offsets.addressOfGlowPointerOffset);
		Logger::address ("GlowObject pointer:\t", csgo.m_addressOfGlowPointer);

		Logger::address ("LocalPlayer function:\t", offsets.foundLocalPlayerLea);
		Logger::address ("LocalPlayer address:\t", csgo.m_addressOfLocalPlayer);

		Logger::address ("DT_CSPlayerResource pointer:\t", csgo.PlayerResourcesPointer);
	}

	csgo.GlowEnabled = false;
	csgo.RCSEnabled = false;
	csgo.TriggerEnabled = false;
	csgo.FovChangerEnabled = cfg.iFovEnabled;
	csgo.MusicKitChangerEnabled = cfg.musicKitEnabled;
	csgo.NoFlashEnabled = cfg.NoFlashEnabled;
	csgo.triggerKeyEnabled = cfg.triggerKeyEnabled;
	csgo.keycodeTriggerKey = cfg.keycodeTriggerKey;

    MusicKitChanger music_changer {&csgo, &client};

	cout << CYAN << endl;
	cout << " Champion for CS:GO initialized.\n"
	        "  > created by: Daniel Krupiński\n";
	cout << RESET << endl;

	char keys[32];
	char lastkeys[32];

	while (csgo.IsRunning())
	{
		XQueryKeymap(display, keys);

		for (int i=0; i!=sizeof(keys); ++i)
		{
			if (keys[i] != lastkeys[i])
			{
				for (int j=0, test=1; j!=8; ++j, test*=2)
				{
					if ((keys[i] & test) && ((keys[i] & test) != (lastkeys[i] & test)))
					{
						const int code = i * 8 + j;

						if (code == cfg.keycodeGlow)
						{
							csgo.GlowEnabled = !csgo.GlowEnabled;
							Logger::toggle("Glow ESP\t\t", csgo.GlowEnabled);
						}

						if (code == cfg.keycodeRCS)
						{
							csgo.RCSEnabled = !csgo.RCSEnabled;
							Logger::toggle("RCS\t\t", csgo.RCSEnabled);
						}

						if (code == cfg.keycodeTriggerToggle)
						{
							csgo.TriggerEnabled = !csgo.TriggerEnabled;
							Logger::toggle("Trigger\t\t", csgo.TriggerEnabled);
						}
					}
				}
			}

			lastkeys[i] = keys[i];
		}

        try {
			cheat::GlowAndTrigger(cfg.colors, cfg.fullBloom, cfg.glowStyle, cfg.healthBased, cfg.rainbowOn, cfg.paintBlack, &csgo, &client);
		}

		catch (int exception) {
			Logger::error("Couldn't find glow address, did you close the game?");
			break;
		}

		bool postProcessOrig {0};
		csgo.Read((void*) (offsets.PostProcessPointer), &postProcessOrig, sizeof(postProcessOrig));

		if (postProcessOrig != cfg.disablePostProcessing) {
			if(cfg.disablePostProcessing == 0 || cfg.disablePostProcessing == 1) // prevent writes under 0 or over 1
				csgo.Write((void*) (offsets.PostProcessPointer), &cfg.disablePostProcessing, sizeof(cfg.disablePostProcessing));
		}

        music_changer.ChangeMusic(cfg.musicKitID);
        NoFlash no_flash(&csgo, &client);
		cheat::RCS(cfg.sensitivity, cfg.m_yaw, cfg.m_pitch, cfg.rcsValue, &csgo, &client);
		cheat::FovChanger(cfg.iFov, &csgo, &client);

		//updateConfigValues(); // this lags on some slow systems

		std::this_thread::sleep_for(chrono::milliseconds(1)); // optimization
	}

	return 0;
}
