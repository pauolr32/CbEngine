#ifndef CP_ENGINE_CORE_H
#define CP_ENGINE_CORE_H

#include <defines.h>

#ifdef PLATFORM_WINDOWS
	#ifdef CpEngine_EXPORTS
		#define CP_API __declspec(dllexport)
	#else
		#define CP_API __declspec(dllimport)
	#endif
#else
	#error CpEngine only supports Windows!
#endif


#endif

