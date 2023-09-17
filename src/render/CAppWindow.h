#ifndef CP_C_APP_WINDOW_H
#define CP_C_APP_WINDOW_H

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

