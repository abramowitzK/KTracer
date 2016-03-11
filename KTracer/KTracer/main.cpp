#include <string>
#include "Logger.h"
#include "Scene.h"
using namespace std;
int main() {
	const string FILEPATH = "Log.txt";
	Logger::InitLogger(FILEPATH);
	Scene scene = Scene();
	scene.AddSphere(new Sphere(vec3(5.0, 0.0, 0.0), quat(), 1.0, 3.0));
	Image* i = scene.Render();
	i->WriteToPPM("image.ppm");
	Logger::Shutdown();
	return 0;
}