#include "../include/Pixterm.h"

namespace PixTerm {

	Buffer::Buffer(float* data, size_t size)
		: mData(data), mSize(size) {}

	Buffer::~Buffer() {}
}
