#include "TriangleMesh.h"



TriangleMesh::TriangleMesh() : Object(vec3(0, 0,0), quat(), 1.0, vec4(0, 0, 1.0, 1.0)){
}

TriangleMesh::TriangleMesh(vector<vec4> vertices, vector<unsigned> indices) : Object(vec3(0), quat(), 1.0, vec4(0, 0, 1.0, 1.0)) {
	m_vertices = vertices;
	m_indices = indices;
}


TriangleMesh::~TriangleMesh(){
}

bool TriangleMesh::Intersect(const Ray & ray, float& tmin, vec3 & intPoint, vec3 & normal){
	for (int i = 0; i < m_indices.size(); i += 3) {
		vec4 v1 = m_vertices[m_indices[i]];
		vec4 v2 = m_vertices[m_indices[i + 1]];
		vec4 v3 = m_vertices[m_indices[1 + 2]];
		if (RayIntersectsTriangle(ray, vec3(v1), vec3(v2), vec3(v3), tmin, intPoint, normal))
			return true;
	}
	return false;
}

ObjectType TriangleMesh::GetType()
{
	return ObjectType::TriangleMesh;
}

bool TriangleMesh::RayIntersectsTriangle(const Ray & ray, vec3 v1, vec3 v2, vec3 v3, float & tNear, vec3 & intPoint, vec3 & normal){
	//Moller-Trumbore algorithm
	//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
	vec3 e1, e2, h, s, q;
	float a, f, u, v;
	vec3 p = ray.Origin();
	vec3 d = ray.Dir();
	e1 = v2 - v1;
	e2 = v3 - v1;
	float epsilon = 0.000000001;
	h = cross(d, e2);
	a = dot(e1, h);
	if (a > -epsilon && a < epsilon)
		return false;
	f = 1 / a;
	s = p - v1;
	u = f * dot(s, h);

	if (u < 0.0 || u > 1.0)
		return false;

	q = cross(s, e1);

	v = f * dot(d, q);

	if (v < 0.0 || u + v > 1.0)
		return false;

	// at this stage we can compute t to find out where
	// the intersection point is on the line
	float t = f * dot(e2, q);

	if (t > epsilon) {
		tNear = t;
		return true;
	}

	return false;
}
