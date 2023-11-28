#ifndef CP_ENGINE_C_APPLICATION_H
#define CP_ENGINE_C_APPLICATION_H

#include "Core.h"

namespace cp
{
	class CP_API CApplication
	{
	public:
		/*
		* Constructor.
		*/
		CApplication();

		/*
		* Destructor.
		*/
		virtual ~CApplication();

		/*
		* Runs application's main loop.
		*/
		void run();
	};
}

#endif

