#include "noflash.h"

NoFlash::NoFlash(remote::Handle* csgo, remote::MapModuleMemoryRegion* client)
{
    if(!csgo || !client)
		return;

	if(!csgo->NoFlashEnabled)
		return;

	csgo->Read((void*) csgo->m_addressOfLocalPlayer, &localPlayer, sizeof(long));

	if(!localPlayer)
		return;

	csgo->Read((void*) (localPlayer + 0xABD4), &m_flFlashMaxAlpha, sizeof(m_flFlashMaxAlpha));

	if(m_flFlashMaxAlpha == 255.0f && m_flFlashMaxAlpha != NoFlashAlpha)
		csgo->Write((void*) (localPlayer + 0xABD4), &NoFlashAlpha, sizeof(float));
}
