#include "App.h"

App::App()
	:wnd(800, 600, "DirectX11 Tutorial")
{
}

int App::run()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessageA(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);

		DoFrame();
	}
	if (gResult == -1)
	{
		throw WND_LAST_EXCEPT();
	}
	return msg.wParam;
}

void App::DoFrame()
{
}
