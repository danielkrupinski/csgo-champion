#include "config.h"

string getConfigValue(string property)
{
	try
	{
		string name = cfg.lookup(property);
		return name;
	}
	catch (const SettingNotFoundException &nfex)
	{
		stringstream ss;
		ss << "Cannot find property: '" << property << "' in config.cfg file";
		Logger::error(ss.str());
	}

	return nullptr;
}
