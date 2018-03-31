#ifndef MUSICKIT_CHANGER_H
#define MUSICKIT_CHANGER_H

#include "cheat.h"

class MusicKitChanger {
public:
    MusicKitChanger(int MusicID, remote::Handle* csgo, remote::MapModuleMemoryRegion* client)
{
	if(!csgo || !client)
		return;

	if(!csgo->MusicKitChangerEnabled)
		return;

	unsigned long localPlayer = 0;
	unsigned int LocalPlayerIndex;
	unsigned int originalMusicID;
	unsigned int spoofedMusicID = MusicID;

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

	if(csgo->m_addressOfPlayerResource && originalMusicID != spoofedMusicID)
	{
		csgo->Write((void*) (csgo->m_addressOfPlayerResource + 0x5020 + (LocalPlayerIndex * 4)), &spoofedMusicID, sizeof(spoofedMusicID));
		cout << "Changed music kit ID to " << dec << spoofedMusicID << " on address " << hex << csgo->m_addressOfPlayerResource + 0x5020 + (LocalPlayerIndex * 4);
		cout << " on entity index " << dec << LocalPlayerIndex << endl;
	}
}
};

#endif // MUSICKIT_CHANGER_H
