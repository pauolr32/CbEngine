#ifndef CP_ENGINE_C_APP_WINDOW_H
#define CP_ENGINE_C_APP_WINDOW_H

#include "Core.h"
#include "IWindow.h"

namespace cp::render
{
	class CAppWindow : public IWindow
	{
	public:
		CAppWindow() = default;
		~CAppWindow() = default;

		void onCreate() override;
		void onUpdate() override;
		void onDestroy() override;
	};
}

#endif

