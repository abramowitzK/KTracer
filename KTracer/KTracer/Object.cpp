#include "Object.h"

Object::Object(vec3 pos, quat rotation, float scale, vec4 color){
	m_pos = pos;
	m_rot = rotation;
	m_uniformScale = scale;
	m_col = color;
}
Object::~Object(){
}
ObjectType Object::GetType(){
	return ObjectType::None;
}

vec3 & Object::GetPosition() {
	return m_pos;
}

vec4 & Object::GetColor() {
	return m_col;
}
