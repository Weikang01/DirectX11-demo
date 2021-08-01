#include <Windows.h>


int CALLBACK WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{

    const auto pClassName = "DirectX11 Tutorial";
    // Register window class
    WNDCLASSEXA wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = DefWindowProc;
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
    while (true)
    {

    }

    return 0;
}