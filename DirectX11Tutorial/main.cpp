#include <Windows.h>
#include "WindowsMessageMap.h"

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
    default:
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

    const auto pClassName = "DirectX11 Tutorial";
    // Register window class
    WNDCLASSEXA wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = Wndproc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;
    RegisterClassExA(&wc);

    // create windle instance
    HWND hWnd = CreateWindowExA(
        0, pClassName, 
        "DirectX11 Tutorial Window",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
        200, 200, 640, 480, 
        nullptr, nullptr, hInstance, nullptr);

    // show the window
    ShowWindow(hWnd, SW_SHOW);

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