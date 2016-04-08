#include "Sphere.h"



Sphere::Sphere(vec3 pos, quat rot, float scale, float radius) : Object(pos, rot, scale, vec4(1.0, 0.0, 0.0, 1.0)) {
	m_radius = radius;
	m_radiusSquared = m_radius*m_radius;
}
Sphere::~Sphere() {}
bool Sphere::Intersect(const Ray & ray, float & tmin, vec3 & intPoint, vec3 & normal) {
	float xo = ray.Origin().x;
	float yo = ray.Origin().y;
	float zo = ray.Origin().z;
	float xd = ray.Dir().x;
	float yd = ray.Dir().y;
	float zd = ray.Dir().z;
	//always equals 1 since this is a normalized vector
	//double a = 1.0f;// xd*xd + yd*yd + zd*zd;
	double b = 2.0f*(xd*(xo - GetPosition().x) + yd*(yo - GetPosition().y) + zd*(zo - GetPosition().z));
	double c = pow(xo - GetPosition().x, 2.0) + pow(yo - GetPosition().y, 2.0) + pow(zo - GetPosition().z, 2.0) - m_radiusSquared;
	double descrim = b*b - 4 * c;
	double epsilon = 0.00000000001;
	if (descrim < epsilon)
		return false;
	float t0 = (-b - sqrtf(b*b - 4 * c)) / 2.0f;
	float t1 = (-b + sqrtf(b*b - 4 * c)) / 2.0f;
	if (t0 < epsilon) {
		if (t1 < epsilon)
			return false;
		else {
			tmin = t1;
			intPoint = ray.Origin() + tmin*ray.Dir();
			normal = intPoint - m_pos;
			return true;
		}
	} else {
		if (t1 > epsilon)
			tmin = fminf(t1, t0);
		else
			tmin = t0;
		intPoint = ray.Origin() + tmin*ray.Dir();
		normal = intPoint - m_pos;
		return true;
	}
}

ObjectType Sphere::GetType() {
	return ObjectType::Sphere;
}

void Sphere::Rotate(float x, float y, float z) {}

void Sphere::Translate(float x, float y, float z) {}
