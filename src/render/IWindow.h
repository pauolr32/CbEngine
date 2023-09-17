#ifndef CP_ENGINE_C_WINDOW_H
#define CP_ENGINE_C_WINDOW_H

#include <Windows.h>

namespace cp::render
{
	class IWindow
	{
	public:
		IWindow();
		~IWindow() = default;

		bool init();
		bool release();
		bool broadcast();
		bool isRunning();

		// EVENTS
		virtual void onCreate() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy();

	protected:
		HWND m_hwnd;
		bool m_is_running {false};
	};
}

#endif // !CP_ENGINE_C_WINDOW_H

