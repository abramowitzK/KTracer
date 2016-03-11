#pragma once
#include "Object.h"
#include "Ray.h"
class Sphere :
	public Object
{
public:
	Sphere(vec3 pos, quat rot, float scale, float radius);
	~Sphere();
	bool Intersect(const Ray& ray);
	virtual ObjectType GetType() override;
private:
	float m_radius;
};

