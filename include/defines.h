#ifndef CP_ENGINE_DEFINES_H
#define CP_ENGINE_DEFINES_H

#include <stdint.h>

namespace cp
{
	#ifndef __cplusplus
		#define					false 0
		#define					true 1
	#endif
	
	#ifdef __cplusplus
		typedef bool			b8;
	#else
	#ifndef __bool_true_false_are_defined
		typedef _Bool		bool;
	#endif
		typedef bool		b8;
	#endif
	
		typedef size_t				usize;
	
		typedef uint8_t				u8;
		typedef int8_t				s8;
		typedef uint16_t			u16;
		typedef int16_t				s16;
		typedef uint32_t			u32;
		typedef int32_t				s32;
		typedef s32					b32;
		typedef uint64_t			u64;
		typedef int64_t				s64;
		typedef float				f32;
		typedef double				f64;
		typedef const char* const_str;
	
		typedef int32_t				bool32_t;
		typedef float				float32_t;
		typedef double				float64_t;
	
		typedef bool32_t			bool32;
	
	#define uint16_max			UINT16_MAX
	#define uint32_max			UINT32_MAX
	#define int32_max			INT32_MAX
	#define float_max			FLT_MAX
	#define float_min			FLT_MIN
	
	#if defined (__cplusplus)
	#define default_val() {}
	#else
	#define default_val() {0}
	#endif
	
	#define cp_max(A, B) ((A) > (B) ? (A) : (B))
	
		/*
		*  PLATFORM DEFINES
		*/
	
		/* Android */
	#if (defined __ANDROID__)
	#define PLATFORM_ANDROID
	
	/* Apple */
	#elif (defined __APPLE__ || defined _APPLE)
	#define PLATFORM_APPLE
	
	/* Windows */
	#elif (defined _WIN32 || defined _WIN64)
	#define __USE_MINGW_ANSI_STDIO	1
	#define OEMRESOURCE
	#define PLATFORM_WIN
	#define PLATFORM_WINDOWS
	
	#include <windows.h>
	
	#define WIN32_LEAN_AND_MEAN
	
	/* Linux */
	#elif (defined linux || defined _linux || defined __linux__)
	#define PLATFORM_LINUX
	
	/* Emscripten */
	#elif (defined __EMSCRIPTEN__)
	#define PLATFORM_WEB
	
	/* Else - Platform undefined and unsupported or custom */
	#endif
	
	#define SAFE_RELEASE_C(ptr)		\
		if (ptr != NULL)			\
		{							\
			free(ptr);				\
		}
	
	#define SAFE_RELEASE(ptr)		\
		if ((ptr))					\
		{							\
			(ptr)->Release();		\
			(ptr) = NULL;			\
		}
	
	#define SAFE_DELETE(ptr)		\
		if ((ptr) != NULL)			\
		{							\
			delete (ptr);			\
			(ptr) = NULL;			\
		}

	#ifndef cp_inline
		#define cp_inline static inline
	#endif
}

#endif

