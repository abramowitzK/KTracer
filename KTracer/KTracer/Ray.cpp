#include "Ray.h"
#include "Sphere.h"
#include "Scene.h"
#include "TriangleMesh.h"

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
	for (Object* obj : s.GetObjects()) {
		if (obj->GetType() == ObjectType::Sphere) {
			Sphere* s = dynamic_cast<Sphere*>(obj);
			if (s->Intersect(*this)) {
				return vec3(1.0, 0.5, 0.0);
			}
		}
		else if (obj->GetType() == ObjectType::TriangleMesh) {
			TriangleMesh* t = dynamic_cast<TriangleMesh*>(obj);
			if (t->Intersect(*this)) {
				return vec3(0.0, 0.0, 1.0);
			}
		}
	}
	return vec3(1.0, 1.0, 1.0);
}
vec3 Ray::Origin() const{
	return m_start;
}
vec3 Ray::Dir() const{
	return m_dir;
}
