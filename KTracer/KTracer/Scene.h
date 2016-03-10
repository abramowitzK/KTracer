#pragma once
#include <vector>
#include "Image.h"
#include "Camera.h"
#include "Object.h"
#include "Ray.h"
using namespace std;
using namespace glm;
class Scene
{
public:
	Scene();
	~Scene();
	Image Render();
private:
	Camera m_camera;
	vector<Object> m_objects;

};

