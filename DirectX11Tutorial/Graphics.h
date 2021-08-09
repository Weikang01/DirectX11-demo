#pragma once
#include "lib_Win.h"
#include <d3d11.h>

class Graphics
{
public:
	Graphics(HWND hWnd);
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
};

