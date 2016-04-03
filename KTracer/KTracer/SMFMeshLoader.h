#pragma once 
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>
#include "TriangleMesh.h"
#include "StringUtil.h"
using namespace glm;
class SMFMeshLoader {
public:
	SMFMeshLoader();
	~SMFMeshLoader();
	void LoadFile(std::string filename);
	TriangleMesh GetMesh(std::string filename);
private:
	void CalcFaceNormals(int triangle, const std::vector<unsigned> &indices, const std::vector<vec4>& vertices, std::vector<vec3>& faceNormals);
	void CalcVertexNormals(const std::vector<unsigned> &indices, const std::vector<vec3> &faceNormals, std::vector<vec3>& normals);
	void ParseVertex(std::vector<vec4> &vertices, const std::string line);
	void ParseFace(std::vector<unsigned> &indices, const std::string line);
private:
	std::map<std::string, TriangleMesh> m_resourceMap;
};

