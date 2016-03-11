#include "Sphere.h"



Sphere::Sphere(vec3 pos, quat rot, float scale, float radius) : Object(pos, rot, scale) {
	m_radius = radius;
}
Sphere::~Sphere(){
}
bool Sphere::Intersect(const Ray & ray)
{
	vec3 t =  m_pos - ray.Origin();
	float length = glm::length(t);
	float v = dot(t, ray.Dir());
	float d = pow(m_radius, 2.0) - (pow(length, 2.0) - pow(v, 2.0));
	if (d < 0)
		return false;
	return true;
}

ObjectType Sphere::GetType()
{
	return ObjectType::Sphere;
}
