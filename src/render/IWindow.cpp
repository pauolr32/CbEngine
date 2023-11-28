#include "IWindow.h"

namespace cp::render
{
	IWindow* window { nullptr };

	IWindow::IWindow() :
		m_hwnd()
	{

	}

	LRESULT CALLBACK WndProc(HWND a_hwnd, UINT a_msg, WPARAM a_wparam, LPARAM a_lparam)
	{
		switch (a_msg)
		{
			case WM_CREATE:
			{
				window->onCreate();
				break;
			}
			case WM_DESTROY:
			{
				window->onDestroy();
				::PostQuitMessage(0);
				break;
			}
			default:
			{
				return ::DefWindowProc(a_hwnd, a_msg, a_wparam, a_lparam);
			}
		}

		return NULL;
	}

	bool IWindow::init()
	{
		WNDCLASSEX wc{};
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = "WindowName";
		wc.lpszMenuName = "MenuName";
		wc.style = NULL;
		wc.lpfnWndProc = WndProc;

		if (!::RegisterClassEx(&wc))
		{
			return false;
		}

		if (!window)
		{
			window = this;
		}

		m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "WindowName", "AppName", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 762,
			NULL, NULL, NULL, NULL);

		if (!m_hwnd)
		{
			return false;
		}

		::ShowWindow(m_hwnd, SW_SHOW);
		::UpdateWindow(m_hwnd);


		m_is_running = true;

		return true;
	}

	bool IWindow::release()
	{
		return !::DestroyWindow(m_hwnd);
	}

	bool IWindow::broadcast()
	{
		MSG msg;

		while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		window->onUpdate();

		Sleep(0);

		return true;
	}

	bool IWindow::isRunning()
	{
		return m_is_running;
	}

	void IWindow::onDestroy()
	{
		m_is_running = false;
	}
}