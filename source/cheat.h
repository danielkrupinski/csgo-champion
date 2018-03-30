#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <X11/extensions/XTest.h>

#include <chrono>
#include <thread>
#include <stddef.h>

#include "remote.h"
#include "types.h"
#include "logger.h"

extern "C"
{
	#include <xdo.h>
}

using namespace std;

#define TEAM_SPECTATOR			1

#define LIFE_ALIVE			0 // alive
#define LIFE_DYING			1 // playing death animation or still falling off of a ledge waiting to hit ground
#define LIFE_DEAD			2 // dead. lying still.
#define LIFE_RESPAWNABLE		3
#define LIFE_DISCARDBODY		4

#define MAX_TRAIL_LENGTH		30
#define MAX_PLAYER_NAME_LENGTH		128

bool GetKeyCodeState(KeyCode keyCode);

namespace cheat 
{
	template<class T> class CUtlVector 
	{
	public:
		T* DataPtr; // 0000 (054612C0)
		unsigned int Max; // 0004 (054612C4)
		unsigned int unk02; // 0008 (054612C8)
		unsigned int Count; // 000C (054612CC)
		unsigned int DataPtrBack; // 0010 (054612D0)
	};

	struct GlowObjectDefinition_t 
	{
		bool ShouldDraw( int nSlot ) const 
		{
			return m_pEntity && ( m_nSplitScreenSlot == -1 || m_nSplitScreenSlot == nSlot ) && ( m_bRenderWhenOccluded || m_bRenderWhenUnoccluded );
		}

		bool IsUnused() const 
		{
			return m_nNextFreeSlot != GlowObjectDefinition_t::ENTRY_IN_USE;
		}

		long writeStart() 
		{
			return (long(&(this)->m_flGlowRed) - long(this));
		}

		long writeEnd() 
		{
			return (long(&(this)->m_nNextFreeSlot) - long(this));
		}
		
		void* m_pEntity;   				    //0x0000
		float m_flGlowRed;					//0x0002
		float m_flGlowGreen;				//0x0003
		float m_flGlowBlue;              	//0x0004
		float m_flGlowAlpha;             	//0x0010
		uint8_t pad_0014[4];                //0x0014
		float m_flSomeFloat;             	//0x0018
		uint8_t pad_001C[4];                //0x001C
		float m_flAnotherFloat;          	//0x0020
		bool m_bRenderWhenOccluded : 8;     //0x0024
		bool m_bRenderWhenUnoccluded : 8;   //0x0025
		bool m_bFullBloomRender : 8;        //0x0026
		uint8_t pad_0027[5];                //0x0027
		int m_nGlowStyle;              		//0x002C
		int m_nSplitScreenSlot;        		//0x0030
		int m_nNextFreeSlot;           		//0x0034

		static const int END_OF_FREE_LIST = -1;
		static const int ENTRY_IN_USE = -2;
	}; // sizeof() == 0x34

	class CGlowObjectManager
	{
	public:
		CUtlVector<GlowObjectDefinition_t> m_GlowObjectDefinitions; // 0000
		int m_nFirstFreeSlot; // 0014 (054612D4)
		unsigned int unk1; // 0018 (054612D8)
		unsigned int unk2; // 001C (054612DC)
		unsigned int unk3; // 0020 (054612E0)
		unsigned int unk4; // 0024 (054612E4)
		unsigned int unk5; // 0028 (054612E8)
	};

	extern void GlowAndTrigger(ColorRGBA colors, bool fullBloom, int glowStyle, bool healthBased, bool rainbow, bool paintBlack, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
	extern void RCS(float sensitivity, float m_yaw, float m_pitch, Vector2D rcsValue, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
	extern void SpoofMusicKit(int MusicID, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
	extern void FovChanger(int fov, remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
	extern void NoFlash(remote::Handle* csgo, remote::MapModuleMemoryRegion* client);
};