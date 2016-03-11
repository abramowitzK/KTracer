#pragma once
#include <glm\vec3.hpp>
#include <glm\common.hpp>
#include <glm\geometric.hpp>
class Scene;
using namespace glm;
class Ray
{
public:
	Ray();
	Ray(vec3 start, vec3 dir);
	~Ray();
	vec3 Trace(Scene s, int d);
	vec3 Origin() const;
	vec3 Dir() const;
private:
	vec3 m_start;
	vec3 m_dir;
};

