#include "offsets.h"

Offsets::Offsets(remote::Handle& csgo, remote::MapModuleMemoryRegion client)
{
    void* foundGlowPointerCall = client.find(csgo,
        "\xE8\x00\x00\x00\x00\x48\x8b\x3d\x00\x00\x00\x00\xBE\x01\x00\x00\x00\xC7", // 2017-10-06
        "x????xxx????xxxxxx");

    glowcalladdr = csgo.GetCallAddress(foundGlowPointerCall);

    csgo.Read((void*) (glowcalladdr + 0x10), &addressOfGlowPointerOffset, sizeof(int));

    csgo.m_addressOfGlowPointer = glowcalladdr + 0x10 + addressOfGlowPointerOffset + 0x4;

    foundLocalPlayerLea = (long)client.find(csgo,
        "\x48\x89\xe5\x74\x0e\x48\x8d\x05\x00\x00\x00\x00", //27/06/16
        "xxxxxxxx????");

    csgo.m_addressOfLocalPlayer = csgo.GetCallAddress((void*)(foundLocalPlayerLea+0x7));

    PlayerResourcesInstr = (long)client.find(csgo,
        "\x48\x8B\x05\x00\x00\x00\x00\x55\x48\x89\xE5\x48\x85\xC0\x74\x10\x48",
        "xxx????xxxxxxxxxx");

    csgo.PlayerResourcesPointer = csgo.GetAbsoluteAddress((void*)(PlayerResourcesInstr), 3, 7);

    PostProcessInstr = (long)client.find(csgo,
        "\x80\x3D\x00\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x85\xC9",
        "xx????xxx????xx");

    PostProcessPointer = csgo.GetAbsoluteAddress((void*)PostProcessInstr, 2, 7);
}
