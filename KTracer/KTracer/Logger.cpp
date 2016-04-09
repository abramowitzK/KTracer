#include "Logger.h"
#ifdef OS_WINDOWS
fstream Logger::s_log = fstream();
bool Logger::s_isInitialized = false;
#endif
void Logger::InitLogger(string FilePath) {
#ifdef OS_WINDOWS
	s_log.open(FilePath, ios::out | ios::trunc);
	s_isInitialized = true;
#endif
}
void Logger::Log(string Message) {
#ifdef OS_WINDOWS
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
#endif
}

void Logger::Shutdown(){
#ifdef OS_WINDOWS
	if (s_log) {
		Log("Shutting down!");
		s_log.close();
	}
#endif
}

double Logger::GetTime() {

}
