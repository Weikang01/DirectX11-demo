#include "App.h"
#include <iomanip>

App::App()
	:wnd(800, 600, "DirectX11 Tutorial")
{}

int App::run()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek() * .5f + .5f);
	wnd.Gfx().ClearBuffer(c, 1.f - c, 1.f);
	wnd.Gfx().EndFrame();
}
