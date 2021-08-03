#include <Windows.h>
#include <sstream>
#include "WindowsMessageMap.h"
#include "Window.h"

int CALLBACK 
WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
    Window wnd(600, 400, "DirectX11 Tutorial");
    Window wnd2(600, 400, "DirectX11 Tutorial");

    // message pump
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }
    else
    {
        return msg.wParam;
    }
}