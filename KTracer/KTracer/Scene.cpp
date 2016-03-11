#include "Scene.h"



Scene::Scene(){
	m_camera = Camera(vec3(-10.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(1.0, 0.0, 0.0), 70.0, 10.0);
}


Scene::~Scene()
{
}

Image* Scene::Render()
{
	Image* im = new Image(600, 600);
	Ray** rays = m_camera.GenerateRays(600, 600);
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 600; j++) {
			im->Set(i,j, rays[i][j].Trace(*this, 1));
		}
	}
	return im;
}

const vector<Object*>& Scene::GetObjects() const{
	return m_objects;
}
