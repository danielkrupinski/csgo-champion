#include "cheat.h"

void cheat::NoFlash(remote::Handle* csgo, remote::MapModuleMemoryRegion* client)
{
	if(!csgo || !client)
		return;

	if(!csgo->NoFlashEnabled)
		return;

	unsigned long localPlayer = 0;
	float m_flFlashMaxAlpha;
	float NoFlashAlpha = 0.f;

	csgo->Read((void*) csgo->m_addressOfLocalPlayer, &localPlayer, sizeof(long));

	if(!localPlayer)
		return;

	csgo->Read((void*) (localPlayer + 0xABD4), &m_flFlashMaxAlpha, sizeof(m_flFlashMaxAlpha));

	if(m_flFlashMaxAlpha == 255.f && m_flFlashMaxAlpha != NoFlashAlpha)
		csgo->Write((void*) (localPlayer + 0xABD4), &NoFlashAlpha, sizeof(float));
}
