#include "Logger.h"
fstream Logger::s_log = fstream();
bool Logger::s_isInitialized = false;
void Logger::InitLogger(string FilePath) {
	s_log.open(FilePath, ios::out | ios::trunc);
	s_isInitialized = true;
}
void Logger::Log(string Message) {
	//Someone forgot to init the logger so we'll just initialize it to a default filename
	if (!s_isInitialized) {
		s_log.open("Log.txt", ios::out | ios::trunc);
	}
	auto time = chrono::system_clock::now();
	char date[26];
	auto tt = chrono::system_clock::to_time_t(time);
	ctime_s(date, 26, &tt);
	date[strcspn(date, "\n")] = 0;
	ostringstream os = ostringstream();
	os << "[" <<  date << "]: " << Message << "\n";
	s_log << os.str();
}

void Logger::Shutdown(){
	if (s_log) {
		Log("Shutting down!");
		s_log.close();
	}
}

double Logger::GetTime() {

}
