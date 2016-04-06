#include "Ray.h"
#include "Sphere.h"
#include "Scene.h"
#include "TriangleMesh.h"

Ray::Ray(){
	m_start = glm::vec3(0.0, 0.0, 0.0);
	m_dir = glm::vec3(-1.0, 0.0, 0.0);
}

Ray::Ray(glm::vec3 start, glm::vec3 dir){
	m_start = start;
	m_dir = glm::normalize(dir);
}

Ray::~Ray(){

}
glm::vec4 Ray::Trace(Scene s, int d){
	float tmin = 1e6;
	float closestTmin = INFINITY;
	vec3 inter;//not using these yet.
	vec3 norm;
	Object* closestObj = nullptr;
	for (auto obj : s.GetObjects()) {
		if (obj->Intersect(*this, tmin, inter, norm)) {
			if (tmin < closestTmin) {
				closestObj = obj;
				closestTmin = tmin;
			}
		}
	}
	if (closestObj != nullptr) {
		return closestObj->GetColor();
	}
	return vec4(1.0, 1.0, 1.0, 1.0);
}
vec3 Ray::Origin() const{
	return m_start;
}
vec3 Ray::Dir() const{
	return m_dir;
}
