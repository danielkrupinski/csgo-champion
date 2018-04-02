#ifndef REMOTE_H
#define REMOTE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/uio.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <inttypes.h>

#define FL_ONGROUND (1<<0)

namespace remote {
	class Handle;

	struct MapModuleMemoryRegion {
		// Memory
		unsigned long start {0};
		unsigned long end {0};

		// Permissions
		bool readable {0};
		bool writable {0};
		bool executable {0};
		bool shared {0};

		// File data
		unsigned long offset {0};
		unsigned char deviceMajor {0};
		unsigned char deviceMinor {0};
		unsigned long inodeFileNumber {0};
		std::string pathname {""};
		std::string filename {""};

		unsigned long client_start {0};

		void* find(Handle handle, const char* data, const char* pattern);
	};

	class Handle {
	public:
    	unsigned long PlayerResourcesPointer {0};

    	unsigned long m_addressOfGlowPointer {0};
    	unsigned long m_addressOfLocalPlayer {0};
    	unsigned long m_addressOfForceAttack {0};
    	unsigned long m_oAddressOfForceJump {0};
    	unsigned long m_addressOfAlt1 {0};
    	unsigned long m_addressOfOnGround {0};
    	unsigned long m_addressOfPlayerResource {0};

    	unsigned long a_engine_client {0};

    	unsigned long m_dwEntityList {0};

    	bool GlowEnabled {0};
    	bool RCSEnabled {0};
    	bool TriggerEnabled {0};
    	bool NoFlashEnabled {0};
    	bool MusicKitChangerEnabled {0};
    	bool FovChangerEnabled {0};
    	bool triggerKeyEnabled {0};
    	int keycodeTriggerKey {0};

    	Handle() : pid{-1} {}
    	Handle(pid_t target);
    	Handle(std::string target);

    	std::string GetPath();
    	std::string GetWorkingDirectory();
    	constexpr pid_t GetPid(){ return pid; }

    	void ParseMaps();

    	constexpr bool IsValid();
    	bool IsRunning();

    	bool Write(void* address, void* buffer, size_t size);
    	bool Read(void* address, void* buffer, size_t size);

    	unsigned long GetCallAddress(void* address);
    	unsigned long GetAbsoluteAddress(void* address, int offset, int size);

    	MapModuleMemoryRegion* GetRegionOfAddress(void* address);

	private:
		std::string GetSymbolicLinkTarget(std::string target);

		pid_t pid {-1};
		std::string pidStr {""};
		//FILE* memr;
		//FILE* memw;

	public:
		std::vector<MapModuleMemoryRegion> regions;
	};

	unsigned long getModule(const char* modname, pid_t pid);
	bool FindProcessByName(std::string name, Handle* out);
};

#endif // REMOTE_H
