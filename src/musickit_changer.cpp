#include "musickit_changer.h"

MusicKitChanger::MusicKitChanger(remote::Handle* csgo_a, remote::MapModuleMemoryRegion* client)
    : csgo{csgo_a}
{
    if(!csgo || !client)
        return;

    if(!csgo->MusicKitChangerEnabled)
        return;

    csgo->Read((void*) csgo->m_addressOfLocalPlayer, &localPlayer, sizeof(long)); // TODO: GetLocalPlayerIndex from engine_client.so

    if(!localPlayer)
        return;

    csgo->Read((void*) (localPlayer+0x94), &LocalPlayerIndex, sizeof(LocalPlayerIndex));

    if(!LocalPlayerIndex)
        return;

    if(LocalPlayerIndex > 64) // Not a correct value.
        return;

    csgo->Read((void*) (csgo->PlayerResourcesPointer), &csgo->m_addressOfPlayerResource, sizeof(unsigned long));

    csgo->Read((void*) (csgo->m_addressOfPlayerResource + 0x5020 + (LocalPlayerIndex * 4)), &originalMusicID, sizeof(originalMusicID));

    if(!originalMusicID)
        return;
}

void MusicKitChanger::ChangeMusic(unsigned MusicId)
{
    spoofedMusicID = MusicId;
    std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
    if(csgo->m_addressOfPlayerResource && std::chrono::duration_cast<std::chrono::seconds>(currTime-lastUpdate).count() > 5)
    {
        csgo->Write((void*) (csgo->m_addressOfPlayerResource + 0x5020 + (LocalPlayerIndex * 4)), &spoofedMusicID, sizeof(spoofedMusicID));
        cout << "Changed music kit ID to " << dec << spoofedMusicID << " on address " << hex << csgo->m_addressOfPlayerResource + 0x5020 + (LocalPlayerIndex * 4);
        cout << " on entity index " << dec << LocalPlayerIndex << endl;
        lastUpdate = std::chrono::steady_clock::now();
    }
}
