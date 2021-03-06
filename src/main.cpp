#include <iostream>

#include <unistd.h>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <chrono>
#include <thread>
#include <libconfig.h++>
#include "keylistener.h"
#include "remote.h"
#include "cheat.h"
#include "logger.h"
#include "config.h"
#include "noflash.h"
#include "musickit_changer.h"

using namespace std;

constexpr bool dumpOffsets {0}; // set to 1 if you want to dump offsets

int main()
{
	Logger::init();

	if (getuid())
	{
		Logger::error(string("You need to be ") + UNDERLINE + "root");
		return 0;
	}

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

    csgo.findOffsets(client);
    Cfg cfg;
    KeyListener keyListener;
    cfg.display = keyListener.display;
    cfg.updateValues();

	if (dumpOffsets) {
		Logger::address ("client_client.so:\t", client.start);
		//Logger::address ("engine_client.so:\t", pEngine);

		Logger::address ("Glow pointer:\t", csgo.addressOfGlowPointerOffset);
		Logger::address ("GlowObject pointer:\t", csgo.m_addressOfGlowPointer);

		Logger::address ("LocalPlayer function:\t", csgo.foundLocalPlayerLea);
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

	while (csgo.IsRunning())
	{
        keyListener.listen(csgo,cfg);

        try {
			cheat::GlowAndTrigger(keyListener, cfg.colors, cfg.fullBloom, cfg.glowStyle, cfg.healthBased, cfg.rainbowOn, cfg.paintBlack, &csgo, &client);
		}

		catch (int exception) {
			Logger::error("Couldn't find glow address, did you close the game?");
			break;
		}

		bool postProcessOrig {0};
		csgo.Read((void*) (csgo.PostProcessPointer), &postProcessOrig, sizeof(postProcessOrig));

		if (postProcessOrig != cfg.disablePostProcessing) {
			if(cfg.disablePostProcessing == 0 || cfg.disablePostProcessing == 1) // prevent writes under 0 or over 1
				csgo.Write((void*) (csgo.PostProcessPointer), &cfg.disablePostProcessing, sizeof(cfg.disablePostProcessing));
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
