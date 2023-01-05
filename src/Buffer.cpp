#include "../include/Pixterm.h"

namespace PixTerm {
	Buffer::Buffer() {}

	Buffer::Buffer(float* data, size_t size, bool _is3D)
		: mData(data), mSize(size), is3D(_is3D) {}

	Buffer::~Buffer() {}
}
