#pragma once

#include <fstream>

namespace IBusko {
	class Logger final {
		private:
			std::ofstream file;
			
			static Logger* instance;
			
			Logger();
			~Logger();
		public:
			Logger(const Logger&) = delete;
			Logger& operator = (const Logger&) = delete;
			
			static Logger& get_instance();
			
			void log(const char* msg);
	};
}
