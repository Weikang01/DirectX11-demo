#include <Windows.h>
#include <sstream>
#include "WindowsMessageMap.h"
#include "Window.h"

LRESULT CALLBACK Wndproc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static WindowsMessageMap mm;
    OutputDebugString(mm(msg, lParam, wParam).c_str());

    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(69);
        break;
    case WM_KEYDOWN:
        if (wParam == 'F')
        {
            SetWindowTextA(hWnd, "Respects");
        }
        break;
    case WM_KEYUP:
        if (wParam == 'F')
        {
            SetWindowTextA(hWnd, "DangerField");
        }
        break;
    case WM_CHAR:
        {
            static std::string title;
            title.push_back((char)wParam);
            SetWindowTextA(hWnd, title.c_str());
        }
        break;
    case WM_LBUTTONDOWN:
        {
            POINTS pt = MAKEPOINTS(lParam);
            std::ostringstream oss;
            oss << "(" << pt.x << "," << pt.y << ")";
            SetWindowText(hWnd, oss.str().c_str());
        }
        break;
    }


    return DefWindowProc(hWnd, msg, wParam, lParam);
}


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