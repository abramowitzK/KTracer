#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <glm\vec3.hpp>
#include "Logger.h"
using namespace std;
class Image
{
public:
	Image();
	Image(unsigned height, unsigned width);
	void WriteToPPM(string FileName);
	glm::vec3* operator[](unsigned index) {
		return m_data[index];
	}
	~Image();
private:
	unsigned m_height;
	unsigned m_width;
	glm::vec3** m_data;

};

