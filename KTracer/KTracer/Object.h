#pragma once
#include <glm\common.hpp>
#include <glm\geometric.hpp>
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>
#include <glm\glm.hpp>
#include <glm\mat4x4.hpp>
#include <glm\gtc\quaternion.hpp>
#include "Ray.h"
using namespace glm;
enum class ObjectType {
	None,
	Sphere,
	TriangleMesh,
};
class Object
{
public:
	Object(vec3 pos, quat rotation, float scale, vec4 color);
	virtual ~Object();
	virtual ObjectType GetType();
	virtual bool Intersect(const Ray& ray, float & tmin, vec3 & intPoint, vec3 & normal) = 0;
	virtual void Rotate(float x, float y, float z) = 0;
	vec3& GetPosition();
	vec4& GetColor();
	void SetColor(vec4 color);
protected:
	vec4 m_col;
	vec3 m_pos;
	quat m_rot;
	float m_uniformScale;

};

