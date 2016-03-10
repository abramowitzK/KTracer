#pragma once
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>
#include <glm\geometric.hpp>
#include <glm\common.hpp>
#include "Ray.h"
using namespace glm;
class Camera
{
public:
	Camera();
	Camera(vec3 position, vec3 up, vec3 right, float viewAngle, float distanceToPlane);
	~Camera();
	Ray** GenerateRays(int hRes, int vRes);
private:
	float m_viewAngle;
	float m_distanceToPlane;
	vec3 m_position;
	vec3 m_up;
	vec3 m_right;
	vec3 m_forward;

};

