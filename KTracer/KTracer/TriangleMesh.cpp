#include "TriangleMesh.h"



TriangleMesh::TriangleMesh() : Object(vec3(0, 0,0), quat(), 1.0){
}

TriangleMesh::TriangleMesh(vector<vec4> vertices, vector<unsigned> indices) : Object(vec3(0), quat(), 1.0) {
	m_vertices = vertices;
	m_indices = indices;
}


TriangleMesh::~TriangleMesh(){
}

bool TriangleMesh::Intersect(const Ray & ray){
	float t = -1e10;
	for (int i = 0; i < m_indices.size(); i += 3) {
		vec4 v1 = m_vertices[m_indices[i]];
		vec4 v2 = m_vertices[m_indices[i + 1]];
		vec4 v3 = m_vertices[m_indices[1 + 2]];
		if (RayIntersectsTriangle(ray, vec3(v1), vec3(v2), vec3(v3), t))
			return true;
	}
	return false;
}

ObjectType TriangleMesh::GetType()
{
	return ObjectType::TriangleMesh;
}

bool TriangleMesh::RayIntersectsTriangle(const Ray & ray, vec3 v1, vec3 v2, vec3 v3, float & tNear){
	vec3 e1, e2, h, s, q;
	float a, f, u, v;
	vec3 p = ray.Origin();
	vec3 d = ray.Dir();
	e1 = v2 - v1;
	e2 = v3 - v1;

	h = cross(d, e2);
	a = dot(e1, h);
	if (a > -0.00001 && a < 0.00001)
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

	if (t > 0.00001) // ray intersection
		return true;

	else // this means that there is a line intersection
		 // but not a ray intersection
		return false;

	return false;
}
