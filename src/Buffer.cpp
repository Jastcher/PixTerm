#include "../include/Pixterm.h"

namespace PixTerm {
	Buffer::Buffer() {}

	Buffer::Buffer(float* data, size_t size, bool _is3D)
		: mData(data), mSize(size), is3D(_is3D) {}

	Buffer::Buffer(const char* path) {
		LoadModel(path);
	}

	Buffer::~Buffer() {
		delete mData;
	}

	bool Buffer::LoadModel(const char* path) {
		std::cout << "LOADING MODEL: " << path << std::endl;
		std::vector<glm::vec3> vertices;
		std::vector<float> _data;

		std::ifstream f;
		f.open(path);
        if (!f.is_open()) {
			std::cout << "FILE COULD NOT BE OPENED" << std::endl;
            return 0;
        }
		std::cout << "FILE OPENED" << std::endl;

		std::string line;
        while (std::getline(f, line)) {

            std::stringstream s;
            s << line;

            char junk;

            if (line[0] == 'v') {
				glm::vec3 v;
                s >> junk >> v.x >> v.y >> v.z;
                vertices.push_back(v);
            }
            else if (line[0] == 'f') {
                int f[3];
                s >> junk >> f[0] >> f[1] >> f[2];
				
				for (int i = 0; i < 3; i++) {
					auto v = vertices[f[i]];
					_data.push_back(v.x-1);
					_data.push_back(v.y-1);
					_data.push_back(v.z-1);
				}
            }
        }

		std::cout << "DATA COLLECTED" << std::endl;
		std::cout << "SIZE" << _data.size() << std::endl;
		mSize = _data.size();
		mData = (float*)malloc(sizeof(_data.data()) * _data.size());
		memcpy(mData, _data.data(), _data.size());
		std::cout << mData[0]<<std::endl;
		return 1;
	}
}
