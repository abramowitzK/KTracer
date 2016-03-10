#include "Image.h"



Image::Image(){
	m_width = 640;
	m_height = 480;
	m_data = new glm::vec3*[m_height];
	for (int i = 0; i < m_height; i++) {
		m_data[i] = new glm::vec3[m_width];
	}
}
Image::Image(unsigned height, unsigned width){
	m_width = height;
	m_height = width;
	m_data = new glm::vec3*[m_height];
	for (int i = 0; i < m_height; i++) {
		m_data[i] = new glm::vec3[m_width];
	}
}
void Image::WriteToPPM(string FileName){
	Logger::Log("Beginning to write to PPM");
	std::ofstream ofs("./image.ppm", ios::out | ios::binary);
	ofs << "P6\n" << m_width << " " << m_height << "\n255\n";
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
		ofs << (unsigned char)(min(1.0f, m_data[i][j].x) * 255) <<
			(unsigned char)(min(1.0f, m_data[i][j].y) * 255) <<
			(unsigned char)(min(1.0f, m_data[i][j].z) * 255);
	}
	Logger::Log("Finished writing to PPM");
}
Image::~Image(){
	for (int i = 0; i < m_height; i++) {
		delete[] m_data[i];
	}
	delete[] m_data;
}
