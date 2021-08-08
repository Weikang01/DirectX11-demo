#include <Windows.h>
#include <WinInet.h>
#include <ShlObj.h>
#include <iostream>


int main()
{
	CoInitialize(nullptr);

	IActiveDesktop* pDesktop = nullptr;
	WCHAR wszWallpaper[MAX_PATH];

	CoCreateInstance(
		CLSID_ActiveDesktop,
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(IActiveDesktop),
		reinterpret_cast<void**>(&pDesktop)
	);

	pDesktop->GetWallpaper(wszWallpaper, MAX_PATH, 0);
	pDesktop->Release();
	std::wcout << wszWallpaper;

	IShellLink* pLink = nullptr;
	CoCreateInstance(
		CLSID_ShellLink,
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(IShellLink),
		reinterpret_cast<void**>(&pLink)
	);
	pLink->SetPath(wszWallpaper);

	IPersistFile* pPersist = nullptr;
	pLink->QueryInterface(__uuidof(IPersistFile), reinterpret_cast<void**>(&pPersist));

	pPersist->Save(L"C:\\wallpaper.lnk", FALSE);
	pPersist->Release();
	pLink->Release();

	CoUninitialize();
	
	std::cin.get();
}