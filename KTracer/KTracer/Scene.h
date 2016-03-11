#pragma once
#include <vector>
#include "Image.h"
#include "Camera.h"
#include "Object.h"
#include "Ray.h"
#include "Sphere.h"
#include "TriangleMesh.h"
using namespace std;
using namespace glm;
class Scene
{
public:
	Scene();
	~Scene();
	Image* Render();
	const vector<Object*> & GetObjects() const;
	void AddSphere(Sphere* s) {
		m_objects.push_back(s);
	}
	void AddTriangleMesh(TriangleMesh* t) {
		m_objects.push_back(t);
	}
private:
	Camera m_camera;
	vector<Object*> m_objects;

};

