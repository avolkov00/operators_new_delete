#include "myClass.h"
#include <iostream>
#include "MyAllocator.h"

void* myClass::operator new(size_t size) 
{
	void* newMemory = std::malloc(size);
	if (!newMemory) throw std::bad_alloc();
	else return newMemory;
}


void myClass::operator delete(void* freeMemory) 
{
	std::free(freeMemory);
}


void* myClass::operator new[](size_t size)
{
	void* newMemory = std::malloc(size);
	if (!newMemory) throw std::bad_alloc();
	else return newMemory;

}

void myClass::operator delete[](void* freeMemory) {
	std::free(freeMemory);
}

void* myClass::operator new(std::size_t size, const std::nothrow_t&) {
	void* newMemory = std::malloc(size);
	if (!newMemory) return nullptr;
	else return newMemory;
}


void* myClass::operator new[](std::size_t size, const std::nothrow_t&) {
	void* newMemory = std::malloc(size);
	if (!newMemory) return nullptr;
	else return newMemory;
}


