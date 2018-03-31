#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(int, remote::Handle*, remote::MapModuleMemoryRegion*);
private:
    unsigned long localPlayer {0};
    unsigned int LocalPlayerIndex {0};
    unsigned int originalMusicID {0};
    unsigned int spoofedMusicID {0};
};

#endif // MUSICKIT_CHANGER_H
