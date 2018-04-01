#ifndef OFFSETS_H
#define OFFSETS_H
#include "remote.h"

struct Offsets {
    Offsets(remote::Handle&, remote::MapModuleMemoryRegion);
    unsigned long localPlayer {0};
    unsigned int localPlayerIndex {0};
    unsigned long glowcalladdr {0};
    int addressOfGlowPointerOffset {0};
    unsigned long foundLocalPlayerLea {0};
    unsigned long PlayerResourcesInstr {0};
    unsigned long PostProcessInstr {0};
    unsigned long PostProcessPointer {0};
};
#endif // OFFSETS_H
