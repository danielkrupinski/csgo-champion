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

	keycodeGlow =  XKeysymToKeycode(display, XStringToKeysym(getConfigValue("glowKey").c_str()));
	keycodeRCS =  XKeysymToKeycode(display, XStringToKeysym(getConfigValue("rcsKey").c_str()));
	keycodeTriggerToggle =  XKeysymToKeycode(display, XStringToKeysym(getConfigValue("triggerToggleKey").c_str()));
	keycodeTriggerKey =  XKeysymToKeycode(display, XStringToKeysym(getConfigValue("triggerKey").c_str()));

	enemyRed = (::atof(getConfigValue("glowRed").c_str()) / 255);
	enemyGreen = (::atof(getConfigValue("glowGreen").c_str()) / 255);
	enemyBlue = (::atof(getConfigValue("glowBlue").c_str()) / 255);
	enemyAlpha = ::atof(getConfigValue("glowAlpha").c_str());

	fullBloom = ::atof(getConfigValue("fullBloom").c_str());
	glowStyle = ::atof(getConfigValue("glowStyle").c_str());

	healthBased = ::atof(getConfigValue("healthBased").c_str());

	rainbowOn = ::atof(getConfigValue("rainbow").c_str());

	sensitivity = ::atof(getConfigValue("sensitivity").c_str());

	paintBlack = ::atof(getConfigValue("paintBlack").c_str());

	m_pitch = ::atof(getConfigValue("m_pitch").c_str());
	m_yaw = ::atof(getConfigValue("m_yaw").c_str());

	rcsValue = { ::atof(getConfigValue("rcsValueX").c_str()), ::atof(getConfigValue("rcsValueY").c_str()) };

	disablePostProcessing = ::atof(getConfigValue("disablePostProcessing").c_str());

	musicKitEnabled = ::atof(getConfigValue("musicKitChangerEnabled").c_str());
	musicKitID = ::atof(getConfigValue("musicKitID").c_str());

	iFovEnabled = ::atof(getConfigValue("fovEnabled").c_str());
	iFov = ::atof(getConfigValue("fov").c_str());

	NoFlashEnabled = ::atof(getConfigValue("noFlash").c_str());

	triggerKeyEnabled = ::atof(getConfigValue("triggerKeyEnabled").c_str());

	colors =
	{
		enemyRed, enemyGreen, enemyBlue, enemyAlpha,
	};
}
