#include "Pixterm.h"

namespace PixTerm {
	bool Terminal::DrawTriangles(const Buffer &buffer, unsigned char c, const glm::mat4& model) {
		if (buffer.is3D) {
			for (int i = 0; i < buffer.mSize; i += 9) {
				float x1 = (buffer.mData[i]); 
				float y1 = (buffer.mData[i+1]); 
				float z1 = (buffer.mData[i+2]);

				float x2 = (buffer.mData[i+3]); 
				float y2 = (buffer.mData[i+4]); 
				float z2 = (buffer.mData[i+5]); 

				float x3 = (buffer.mData[i+6]); 
				float y3 = (buffer.mData[i+7]); 
				float z3 = (buffer.mData[i+8]); 

				glm::vec3 line1 = model * glm::vec4(x1, y1, z1, 1);
				glm::vec3 line2 = model * glm::vec4(x2, y2, z2, 1);
				glm::vec3 line3 = model * glm::vec4(x3, y3, z3, 1);

				//std::cout << line1.x << " ; " << line1.y << " .. " << line2.x << " ; " << line2.y << " .. " << line3.x << " ; " << line3.y << std::endl;

				DrawTriangle(GetX(line1.x), GetY(line1.y), GetX(line2.x), GetY(line2.y), GetX(line3.x), GetY(line3.y), c);
			}
			return 1;
		}
		for (int i = 0; i < buffer.mSize; i += 6) {
			//std::cout << "\nSTART PROCESS" << std::endl;
			float x1 = (buffer.mData[i]); 
			float y1 = (buffer.mData[i+1]); 

			float x2 = (buffer.mData[i+2]); 
			float y2 = (buffer.mData[i+3]); 

			float x3 = (buffer.mData[i+4]); 
			float y3 = (buffer.mData[i+5]); 

			//std::cout << x1 << " " << y1 << " ; " << x2 << " " << y2 << " ; " << x3 << " " << y3 << std::endl;
			glm::vec3 line1 = model * glm::vec4(x1, y1, 0, 1);
			glm::vec3 line2 = model * glm::vec4(x2, y2, 0, 1);
			glm::vec3 line3 = model * glm::vec4(x3, y3, 0, 1);
			//std::cout << "END PROCESS " << std::endl;

			//std::cout << std::endl;
			//std::cout << line1.x << " ; " << line1.y << " .. " << line2.x << " ; " << line2.y << " .. " << line3.x << " ; " << line3.y << std::endl;
			//std::cout << GetX(line1.x) << " ; " << GetY(line1.y) << " .. " << GetX(line2.x) << " ; " << GetY(line2.y) << " .. "  << GetX(line3.x) << " ; " << GetY(line3.y) << std::endl;
			DrawTriangle(GetX(line1.x), GetY(line1.y), GetX(line2.x), GetY(line2.y), GetX(line3.x), GetY(line3.y), c);
		}

		//std::cout << "DRAW DONE" << std::endl;

		return 1;
	}

	bool Terminal::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char c, unsigned char fill) {
		std::vector<Point> buffer;

		bool first = DrawLine(x1, y1, x2, y2, c, &buffer);
		bool second = DrawLine(x2, y2, x3, y3, c, &buffer);
		bool third = DrawLine(x3, y3, x1, y1, c, &buffer);

		if (fill) {
			//for (auto& i : buffer) {
			//	logger.push_back(std::to_string(i.x) + " " + std::to_string(i.y));
			//}
			
			// get max Y and min Y
			unsigned int minY = std::min(std::min(y1, y2), y3);
			unsigned int maxY = std::max(std::max(y1, y2), y3);

			std::vector<std::vector<Point>> vec;
			vec.reserve(maxY-minY);
			for(int i = 0; i <= maxY-minY; i++) {
				vec.push_back({});
			}

			for (auto& i : buffer) {
				vec[i.y-minY].push_back({i.x,i.y});
			}

			for (int i = 0; i <= maxY-minY; i++) {
				std::sort(vec[i].begin(), vec[i].end(), [](Point& a, Point& b) { return a.x < b.x; }); // return 'a < b'
				auto xL = vec[i][vec[i].size()-2].x;
				auto xR = vec[i][vec[i].size()-1].x;
				if (xR-xL > 0)
				DrawLine(xL+1, i+minY, xR-1, i+minY, fill);
			}

			//std::string temp;
			//for (int i = 0; i <= maxY-minY; i++) {
			//	temp = std::to_string(i) + ": ";
			//	for (auto& j : vec[i]) {
			//		temp.append(std::to_string(j.x) + ", ");
			//	}
			//logger.push_back(temp);
			//}
			//logger.push_back(std::to_string(minY));
			//logger.push_back(std::to_string(maxY));
		}
		return first || second || third;
	}

}
