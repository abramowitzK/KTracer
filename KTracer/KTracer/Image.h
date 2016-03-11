#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <glm\vec3.hpp>
#include <vector>
#include "Logger.h"
using namespace std;
using namespace glm;
class Image
{
public:
	Image();
	Image(unsigned height, unsigned width);
	void WriteToPPM(string FileName);
	vector<vec3> operator[](unsigned index) {
		return m_data[index];
	}
	void Set(int i, int j, vec3 data) {
		m_data[i][j] = data;
	}
	~Image();
private:
	unsigned m_height;
	unsigned m_width;
	vector<vector<vec3>> m_data;

};

