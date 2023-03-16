#pragma once

#include <iostream>

namespace PixTerm {

	class Buffer {
	public:
		Buffer();
		Buffer(float* data, size_t size, bool _is3D = false);
		// for obj loading
		Buffer(const char* path);
		~Buffer();

		float* mData = nullptr;
		size_t mSize = 0;

		bool is3D = true;

	private:
		bool LoadModel(const char* path);
	};

}
