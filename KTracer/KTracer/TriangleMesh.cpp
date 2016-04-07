#include "TriangleMesh.h"


TriangleMesh::TriangleMesh() : Object(vec3(0, 0,0), quat(), 1.0, vec4(0, 0, 1.0, 1.0)){
}

TriangleMesh::TriangleMesh(vector<vec3> vertices, vector<unsigned> indices) : Object(vec3(0), quat(), 1.0, vec4(0, 0, 1.0, 1.0)) {
	m_vertices = vertices;
	m_indices = indices;
}


TriangleMesh::~TriangleMesh(){
}

bool TriangleMesh::Intersect(const Ray & ray, float& tmin, vec3 & intPoint, vec3 & normal){
	float tMin = 1000000;
	for (int i = 0; i < m_indices.size(); i += 3) {
		vec3 v1 = m_vertices[m_indices[i]];
		vec3 v2 = m_vertices[m_indices[i + 1]];
		vec3 v3 = m_vertices[m_indices[i + 2]];
		float t;
		if (RayIntersectsTriangle(ray, v1, v2, v3, t, intPoint, normal)) {
			if (t < tMin) {
				tMin = t;
			}
		}
	}
	if (tMin < 100000)
		tmin = tMin;
	return tMin < 1000000 && tMin> 0;
}

ObjectType TriangleMesh::GetType()
{
	return ObjectType::TriangleMesh;
}

bool TriangleMesh::RayIntersectsTriangle(const Ray & ray, vec3& v1, vec3 &v2, vec3 &v3, float & tNear, vec3 & intPoint, vec3 & normal){
	//Moller-Trumbore algorithm
	//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
	vec3 e1, e2, h, s, q;
	float a, f, u, v;
	vec3 p = ray.Origin();
	vec3 d = ray.Dir();
	e1 = v2 - v1;
	e2 = v3 - v1;
	float epsilon = 0.00000000000000000000001;
	h = cross(d, e2);
	a = dot(e1, h);
	if (a > -epsilon && a < epsilon)
		return false;
	f = 1.0 / a;
	s = p - v1;
	u = dot(s, h) * f;

	if (u < 0.0 || u > 1.0)
		return false;

	q = cross(s, e1);

	v = dot(d, q) * f;

	if (v < 0.0 || u + v > 1.0)
		return false;

	// at this stage we can compute t to find out where
	// the intersection point is on the line
	tNear = dot(e2, q) * f;
	if (tNear < 0)
		return false;

	return true;
}

void TriangleMesh::Translate(float x, float y, float z) {
	auto m = glm::translate(vec3(x, y, z));
	for (int i = 0; i < m_vertices.size(); i++) {
		m_vertices[i] = vec3(m*vec4(m_vertices[i], 1.0));
	}
}

void TriangleMesh::Rotate(float x, float y, float z) {
	quat rot = glm::quat(glm::vec3(glm::radians(x), glm::radians(y), glm::radians(z)));
	for (int i = 0; i < m_vertices.size(); i++) {
		m_vertices[i] = rot*m_vertices[i];
	}
}
