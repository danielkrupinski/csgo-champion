#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(int MusicID, remote::Handle* csgo, remote::MapModuleMemoryRegion* client)
        : spoofedMusicID{MusicID} {};
private:
    unsigned long localPlayer {0};
    unsigned int LocalPlayerIndex {0};
    unsigned int originalMusicID {0};
    unsigned int spoofedMusicID {0}; //MusicID;
};

#endif // MUSICKIT_CHANGER_H
