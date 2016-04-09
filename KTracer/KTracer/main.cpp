#include <string>
#include <cstdlib>
#include <string>
#include <chrono>
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
	loader.LoadFile("teapot.smf");
	TriangleMesh mesh = loader.GetMesh("bound-bunny_1k.smf");
	mesh.Translate(0, -1.5, 0);
	mesh.SetColor(vec4(1.0, 1.0, 1.0, 1.0));
	TriangleMesh mesh2 = loader.GetMesh("teapot.smf");
	mesh2.Translate(0, 0.75, 0);
	mesh2.SetColor(vec4(1.0, 1.0, 1.0, 1.0));
	Scene scene = Scene();
	Sphere* s = new Sphere(vec3(-3.0, 0.0, 0.0), quat(), 1.0, 0.25);
	s->SetColor(vec4(1.0, 1.0, 1.0, 1.0));
	scene.AddSphere(s);
	Sphere* s2 = new Sphere(vec3(3.0, 0.0, 0.0), quat(), 1.0, 1.0);
	s2->SetColor(vec4(1.0, 1.0, 1.0, 0.0));
	scene.AddSphere(s2);
	scene.AddTriangleMesh(&mesh);
	scene.AddTriangleMesh(&mesh2);
	auto start = chrono::high_resolution_clock::now();
	Image* i = scene.Render();
	auto end = chrono::high_resolution_clock::now();
	auto total = end - start;
	float total2 = total.count() / 1.0e9;
	Logger::Log("Rendering finished in: " + std::to_string(total2) + " seconds.");
	i->WriteToPNG("image.png");
	Logger::Shutdown();
	delete i;
	delete s;
	delete s2;
	return 0;
}