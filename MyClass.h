#pragma once
#include "MyAllocator.h"

class myClass {

public:


	void* operator new(size_t size);

	void operator delete(void* freeMemory);

	void* operator new[](size_t size);

	void operator delete[](void* freeMemory);

	void* operator new(std::size_t size, const std::nothrow_t&);

	void* operator new[](std::size_t size, const std::nothrow_t&);

};
