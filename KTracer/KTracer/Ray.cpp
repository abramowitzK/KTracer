#include "Ray.h"
#include "Scene.h"

Ray::Ray(){
	m_start = glm::vec3(0.0, 0.0, 0.0);
	m_start = glm::vec3(-1.0, 0.0, 0.0);
}

Ray::Ray(glm::vec3 start, glm::vec3 dir){
	m_start = start;
	dir = glm::normalize(dir);
	m_dir = dir;
}

Ray::~Ray(){

}

glm::vec3 Ray::Trace(Scene s, int d){
	return glm::vec3();
}
