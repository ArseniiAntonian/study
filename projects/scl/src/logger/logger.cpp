#include "logger.hpp"

using IBusko::Logger;

Logger* Logger::instance = nullptr;

Logger::Logger() {
	// TODO
}

Logger::~Logger() {
	// TODO
}

Logger& Logger::get_instance() {
	if (!instance) {
		instance = new Logger();
	}
	return *instance;
}

void Logger::log(const char* msg) {
	file.open("log.txt", std::ios::app);
	file << msg;
	file.close();
}
