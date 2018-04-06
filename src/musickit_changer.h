#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(remote::Handle*, remote::MapModuleMemoryRegion*);
    void ChangeMusic(unsigned MusicId);
private:
    std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
    remote::Handle* csgo;
    unsigned long localPlayer {0};
    unsigned int LocalPlayerIndex {0};
    unsigned int originalMusicID {0};
    unsigned int spoofedMusicID {0};
};

#endif // MUSICKIT_CHANGER_H
