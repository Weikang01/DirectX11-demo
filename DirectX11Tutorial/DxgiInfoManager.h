#pragma once
#include "lib_Win.h"
#include <wrl.h>
#include <string>
#include <vector>
#include <dxgidebug.h>

class DxgiInfoManager
{
public:
	DxgiInfoManager();
	~DxgiInfoManager() = default;
	DxgiInfoManager(const DxgiInfoManager&) = delete;
	DxgiInfoManager& operator=(const DxgiInfoManager&) = delete;
	void Set() noexcept;
	std::vector<std::string> GetMessages() const;

private:
	unsigned long long next = 0u;
	struct IDXGIInfoQueue* pDxgiInfoQueue = nullptr;
};

