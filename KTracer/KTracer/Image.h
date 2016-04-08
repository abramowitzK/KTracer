#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <glm\vec4.hpp>
#include <vector>
#include "Logger.h"
#include "LodePNG.h"
using namespace std;
using namespace glm;
class Image
{
public:
	Image();
	Image(unsigned height, unsigned width);
	void WriteToPPM(string FileName);
	void WriteToPNG(string FileName);
	vector<vec4> operator[](unsigned index) {
		return m_data[index];
	}
	void Set(int i, int j, vec4 data) {
		m_data[i][j] = data;
	}
	~Image();
private:
	unsigned m_height;
	unsigned m_width;
	vector<vector<vec4>> m_data;

};

