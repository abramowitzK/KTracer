#include "Image.h"



Image::Image(){
	m_width = 640;
	m_height = 480;
	m_data = vector<vector<vec4>>(m_height);
	for (int i = 0; i < m_height; i++) {
		m_data[i] = vector<vec4>(m_width);
	}
}
Image::Image(unsigned height, unsigned width){
	m_width = width;
	m_height = height;
	m_data = vector<vector<vec4>>(m_height);
	for (int i = 0; i < m_height; i++) {
		m_data[i] = vector<vec4>(m_width);
	}
}
void Image::WriteToPPM(string FileName){
	Logger::Log("Beginning to write to PPM");
	std::ofstream ofs(FileName, ios::out | ios::binary);
	ofs << "P6\n" << m_width << " " << m_height << "\n255\n";
	for (int i = 0; i < m_width; i++) {
		for (int j = 0; j < m_height; j++)
		ofs << (unsigned char)(min(1.0f, m_data[i][m_height-j-1].x) * 255) <<
			(unsigned char)(min(1.0f, m_data[i][m_height - j - 1].y) * 255) <<
			(unsigned char)(min(1.0f, m_data[i ][m_height - j - 1].z) * 255);
	}
	Logger::Log("Finished writing to PPM");
}
void Image::WriteToPNG(string FileName) {  
	std::vector<unsigned char> image;
	image.resize(m_width * m_height * 4);
	for(unsigned y = 0; y < m_height; y++)
		for(unsigned x = 0; x < m_width; x++){
			image[4 * m_width * y + 4 * x + 0] = (unsigned char)(m_data[y][m_height - x - 1].x*255);
			image[4 * m_width * y + 4 * x + 1] = (unsigned char)(m_data[y][m_height - x - 1].y*255);
			image[4 * m_width * y + 4 * x + 2] = (unsigned char)(m_data[y][m_height - x - 1].z*255);
			image[4 * m_width * y + 4 * x + 3] = (unsigned char)255;
		}
	lodepng::encode(FileName, image, m_width, m_height);
}
Image::~Image(){
}
