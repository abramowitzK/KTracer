#include <string>
#include "Logger.h"
#include "Scene.h"
#include "SMFMeshLoader.h"
#include "TriangleMesh.h"
using namespace std;
int main() {
	const string FILEPATH = "Log.txt";
	Logger::InitLogger(FILEPATH);
	SMFMeshLoader loader = SMFMeshLoader();
	loader.LoadFile("bound-bunny_1k.smf");
	loader.LoadFile("box.smf");
	TriangleMesh mesh = loader.GetMesh("bound-bunny_1k.smf");
	mesh.Translate(0, 0, 0);
	//TriangleMesh mesh2 = loader.GetMesh("box.smf");
	//mesh2.Rotate(90.0, 0.0, 90.0);
	//mesh2.Translate(0, 0, 4);
	//mesh2.SetColor(vec4(0.0, 1.0, 0.0, 1.0));
	Scene scene = Scene();
	Sphere* s = new Sphere(vec3(4.0, 2.0, 2.0), quat(), 1.0, 0.25);
	s->SetColor(vec4(1.0, 1.0, 0.0, 1.0));
	scene.AddSphere(s);
	scene.AddSphere(new Sphere(vec3(2.0, 0.0, 0.0), quat(), 1.0, 1.0));
	scene.AddTriangleMesh(&mesh);
	//scene.AddTriangleMesh(&mesh2);
	Image* i = scene.Render();
	i->WriteToPPM("image.ppm");
	Logger::Shutdown();
	delete i;
	return 0;
}