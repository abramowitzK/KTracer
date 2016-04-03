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
	//TriangleMesh mesh = loader.GetMesh("bound-bunny_1k.smf");
	Scene scene = Scene();
	scene.AddSphere(new Sphere(vec3(16.0, 0.0, 0.0), quat(), 1.0, 1.0));
	//scene.AddTriangleMesh(&mesh);
	Image* i = scene.Render();
	i->WriteToPPM("image.ppm");
	Logger::Shutdown();
	delete i;
	return 0;
}