#ifndef NOFLASH_H
#define NOFLASH_H

#include "cheat.h"

class NoFlash {
public:
    NoFlash(remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
};

#endif // NOFLASH_H
