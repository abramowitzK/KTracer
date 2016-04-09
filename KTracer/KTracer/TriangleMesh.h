#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/common.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include "Object.h"
#include "Ray.h"
#include "Logger.h"

using namespace glm;
using namespace std;
class TriangleMesh :
	public Object
{
public:
	TriangleMesh();
	TriangleMesh(vector<vec3> vertices, vector<unsigned> indices);
	~TriangleMesh();
	bool Intersect(const Ray& ray, float & tmin, vec3 & intPoint, vec3 & normal);
	// Inherited via Object
	virtual void Rotate(float x, float y, float z) override;
	// Inherited via Object
	virtual void Translate(float x, float y, float z) override;
	virtual ObjectType GetType() override;
private:
	bool RayIntersectsTriangle(const Ray& ray, vec3& v1, vec3& v2, vec3& v3, float & t, vec3 & intPoint, vec3 & normal);
	vector<vec3> m_vertices;
	vector<unsigned> m_indices;





};

