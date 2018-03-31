#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(int MusicID, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
};

#endif // MUSICKIT_CHANGER_H
