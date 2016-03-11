#include "Camera.h"



Camera::Camera(){
}

Camera::Camera(vec3 position, vec3 up, vec3 forward, float viewAngle, float distanceToPlane){
	m_viewAngle = viewAngle;
	m_distanceToPlane = distanceToPlane;
	m_position = position;
	m_up = normalize(up);
	m_forward = normalize(forward);
	m_right = cross(forward, up);
}

Camera::~Camera(){
}

Ray ** Camera::GenerateRays(int hRes, int vRes)
{
	//Responsibility of the user to clean this up.
	Ray** rays = new Ray*[vRes];
	for (int i = 0; i < vRes; i++) {
		rays[i] = new Ray[hRes];
	}
	vec3 y = cross(m_right, m_forward);
	for (int i = 0; i < vRes; i++) {
		for (int j = 0; j < hRes; j++) {
			float s_j = m_distanceToPlane * 2 * tanf(m_viewAngle / 2.0f);
			float s_k = s_j*(vRes / (float)hRes);
			vec3 posOfPixel = m_position + m_distanceToPlane * m_forward - ((float)(s_j / 2.0)) * m_right - ((float)(s_k / 2.0)) * y;
			vec3 dir = (posOfPixel + s_j*(i / (float)(hRes - 1)) * m_right + s_k*(j / (float)(vRes - 1)) *y) - m_position;
			dir = normalize(dir);
			rays[i][j] = Ray(m_position, dir);
		}
	}
	return rays;
}
