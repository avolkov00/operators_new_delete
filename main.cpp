#include <iostream>
#include "MyClass.h"
#include "MyAllocator.h"

int main()
{
	myClass* object = new myClass;
	delete object;

	myClass* objects = new myClass[5];
	delete[] objects;

	myAllocator<int> allocator(10);
	int* objectInMemory = allocator.allocate(6);
	allocator.deallocate(objectInMemory, 6);
	int* array = new int[5];
	allocator.construct(array, 5);
	allocator.destroy(array);
	


}
