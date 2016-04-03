#pragma once
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <vector>
#include "Object.h"
#include "Ray.h"
using namespace glm;
using namespace std;
class TriangleMesh :
	public Object
{
public:
	TriangleMesh();
	TriangleMesh(vector<vec4> vertices, vector<unsigned> indices);
	~TriangleMesh();
	bool Intersect(const Ray& ray, float & tmin, vec3 & intPoint, vec3 & normal);
	virtual ObjectType GetType() override;
private:
	bool RayIntersectsTriangle(const Ray& ray, vec3 v1, vec3 v2, vec3 v3, float & t, vec3 & intPoint, vec3 & normal);
	vector<vec4> m_vertices;
	vector<unsigned> m_indices;
};

