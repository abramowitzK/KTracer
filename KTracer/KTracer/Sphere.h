#pragma once
#include "Object.h"
#include "Ray.h"
class Sphere :
	public Object
{
public:
	Sphere(vec3 pos, quat rot, float scale, float radius);
	~Sphere();
	virtual bool Intersect(const Ray& ray, float& tmin, vec3 & intPoint, vec3 & normal) override;
	virtual ObjectType GetType() override;
private:
	float m_radius;
	float m_radiusSquared;

	// Inherited via Object
	virtual void Rotate(float x, float y, float z) override;
};

