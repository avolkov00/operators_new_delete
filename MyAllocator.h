#pragma once
#include <stdexcept>

template <class Type>
class myAllocator {
public:

	myAllocator(std::size_t size) : _size(size) {};

	Type* allocate(std::size_t size) const {
		if (size > _size) throw std::bad_alloc();
		else return new Type[size];
	}

	void deallocate(Type* freeMemory, std::size_t size) const noexcept {
		delete[] freeMemory;
	}

	Type max_size() const noexcept {
		return sizeof(Type);
	}

	template< typename... Args >
	void construct(Type* p, const Args&... args) const {
		new(p) Type(args...);
	}

	void destroy(Type* object) const {
		object->~Type();
	}

private:
	size_t _size;
};


