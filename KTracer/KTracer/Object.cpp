#include "Object.h"

Object::Object(vec4 pos, quat rotation, float scale){
	m_pos = pos;
	m_rot = rotation;
	m_uniformScale = scale;
}
Object::~Object(){
}
ObjectType Object::GetType(){
	return ObjectType::None;
}
