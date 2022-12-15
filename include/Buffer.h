#pragma once

#include <iostream>

namespace PixTerm {

	class Buffer {
	public:
		Buffer(float* data, size_t size);
		~Buffer();

		float* mData;
		size_t mSize;
	};

}
