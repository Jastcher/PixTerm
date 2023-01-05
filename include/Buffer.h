#pragma once

#include <iostream>

namespace PixTerm {

	class Buffer {
	public:
		Buffer();
		Buffer(float* data, size_t size, bool _is3D = false);
		~Buffer();

		float* mData;
		size_t mSize;

		bool is3D = false;
	};

}
