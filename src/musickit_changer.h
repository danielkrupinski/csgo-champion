#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(int MusicID, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
private:
    unsigned long localPlayer = 0;
    unsigned int LocalPlayerIndex;
    unsigned int originalMusicID;
    unsigned int spoofedMusicID = MusicID;
};

#endif // MUSICKIT_CHANGER_H
