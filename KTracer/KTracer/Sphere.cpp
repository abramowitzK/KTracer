#include "Sphere.h"



Sphere::Sphere(vec3 pos, quat rot, float scale, float radius) : Object(pos, rot, scale, vec4(1.0, 0.0, 0.0, 1.0)) {
	m_radius = radius;
	m_radiusSquared = m_radius*m_radius;
}
Sphere::~Sphere() {}
bool Sphere::Intersect(const Ray & ray, float & tmin, vec3 & intPoint, vec3 & normal) {
	//vec3 t =  m_pos - ray.Origin();
	//float length = glm::length(t);
	//float v = dot(t, ray.Dir());
	//float d = pow(m_radius, 2.0) - (pow(length, 2.0) - pow(v, 2.0));
	//if (d < 0)
	//	return false;
	//return true;
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
	if (descrim < epsilon) {
		//No intersections
		return false;
	}
	float t0 = (-b - sqrtf(b*b - 4 * c)) / 2.0f;
	float t1 = (-b + sqrtf(b*b - 4 * c)) / 2.0f;
	if (t0 < epsilon) {
		//t0 is negative
		if (t1 < epsilon)
			return false;
		else {
			tmin = t1;
			return true;
		}
	} else {
		//t0 is positive.
		if (t1 > epsilon)
			tmin = fminf(t1, t0);
		else
			tmin = t0;
		return true;
	}
}

ObjectType Sphere::GetType() {
	return ObjectType::Sphere;
}

void Sphere::Rotate(float x, float y, float z) {}

void Sphere::Translate(float x, float y, float z) {}
