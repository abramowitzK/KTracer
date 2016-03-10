#pragma once
#include "Object.h"
class Sphere :
	public Object
{
public:
	Sphere(vec4 pos, quat rot, float scale);
	~Sphere();
};

