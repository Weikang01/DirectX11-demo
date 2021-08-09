#pragma once
#include "lib_Win.h"
#include <vector>

class DxgiInfoManager
{
public:
	DxgiInfoManager();
	~DxgiInfoManager();
	DxgiInfoManager(const DxgiInfoManager&) = delete;
	DxgiInfoManager& operator=(const DxgiInfoManager&) = delete;
	void Set() noexcept;
	std::vector<std::strong_ordering> GetMessage() const;

private:
	unsigned long long next = 0u;
	struct IDXGIInfoQueue* pDxgiInfoQueue = nullptr;
};

