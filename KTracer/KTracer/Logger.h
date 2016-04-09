#pragma once
#include <string>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class Logger
{
public:
	static void InitLogger(string FilePath);
	static void Log(string Message);
	static void Shutdown();
	static fstream s_log;
	static bool s_isInitialized;
	static double GetTime();
	static std::chrono::system_clock::time_point s_epoch;
};

