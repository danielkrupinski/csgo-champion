#include "config.h"
#include "logger.h"

using namespace std;
using namespace libconfig;

string Cfg::getValue(string property)
{
	try {
		string name = cfg.lookup(property);
		return name;
	}

	catch (const SettingNotFoundException& nfex) {
		stringstream ss;
		ss << "Cannot find property: '" << property << "' in config.cfg file";
		Logger::error(ss.str());
	}

	return nullptr;
}

void Cfg::updateValues()
{
	try {
		cfg.readFile("config.cfg");
	}

	catch (const FileIOException& fioex) {
		Logger::error("Error reading config file!");
	}

	catch (const ParseException& pex) {
		stringstream ss;
		ss << "Parsing error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError();
		Logger::error(ss.str());
	}

	keycodeGlow =  XKeysymToKeycode(display, XStringToKeysym(getValue("glowKey").c_str()));
	keycodeRCS =  XKeysymToKeycode(display, XStringToKeysym(getValue("rcsKey").c_str()));
	keycodeTriggerToggle =  XKeysymToKeycode(display, XStringToKeysym(getValue("triggerToggleKey").c_str()));
	keycodeTriggerKey =  XKeysymToKeycode(display, XStringToKeysym(getValue("triggerKey").c_str()));

	enemyRed = (::atof(getValue("glowRed").c_str()) / 255);
	enemyGreen = (::atof(getValue("glowGreen").c_str()) / 255);
	enemyBlue = (::atof(getValue("glowBlue").c_str()) / 255);
	enemyAlpha = ::atof(getValue("glowAlpha").c_str());

	fullBloom = ::atof(getValue("fullBloom").c_str());
	glowStyle = ::atof(getValue("glowStyle").c_str());

	healthBased = ::atof(getValue("healthBased").c_str());

	rainbowOn = ::atof(getValue("rainbow").c_str());

	sensitivity = ::atof(getValue("sensitivity").c_str());

	paintBlack = ::atof(getValue("paintBlack").c_str());

	m_pitch = ::atof(getValue("m_pitch").c_str());
	m_yaw = ::atof(getValue("m_yaw").c_str());

	rcsValue = { ::atof(getValue("rcsValueX").c_str()), ::atof(getValue("rcsValueY").c_str()) };

	disablePostProcessing = ::atof(getValue("disablePostProcessing").c_str());

	musicKitEnabled = ::atof(getValue("musicKitChangerEnabled").c_str());
	musicKitID = ::atof(getValue("musicKitID").c_str());

	iFovEnabled = ::atof(getValue("fovEnabled").c_str());
	iFov = ::atof(getValue("fov").c_str());

	NoFlashEnabled = ::atof(getValue("noFlash").c_str());

	triggerKeyEnabled = ::atof(getValue("triggerKeyEnabled").c_str());

	colors =
	{
		enemyRed, enemyGreen, enemyBlue, enemyAlpha,
	};
}
