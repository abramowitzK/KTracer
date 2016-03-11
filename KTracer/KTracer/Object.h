#pragma once
#include <glm\common.hpp>
#include <glm\geometric.hpp>
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>
#include <glm\glm.hpp>
#include <glm\mat4x4.hpp>
#include <glm\gtc\quaternion.hpp>
using namespace glm;
enum class ObjectType {
	None,
	Sphere,
	TriangleMesh,
};
class Object
{
public:
	Object(vec3 pos, quat rotation, float scale);
	virtual ~Object();
	virtual ObjectType GetType();
protected:
	vec3 m_pos;
	quat m_rot;
	float m_uniformScale;

};

