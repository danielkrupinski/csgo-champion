#ifndef NOFLASH_H
#define NOFLASH_H

#include "cheat.h"

class NoFlash {
public:
    NoFlash(remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
private:
    unsigned long localPlayer {0};
	float m_flFlashMaxAlpha {0};
	float NoFlashAlpha {0.0f};
};

#endif // NOFLASH_H
