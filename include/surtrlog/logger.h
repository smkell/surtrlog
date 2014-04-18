#ifndef SURTRLOG_LOGGER_H_
#define SURTRLOG_LOGGER_H_

#include "surtrlog/loglevels.h"
#include <iostream>
#include <sstream>

namespace surtrlog {

	// Forward declarations
	class LogLevel;

	class Logger {
	public:
		Logger() {}
		virtual ~Logger() {}

		template<class Level>
		std::streambuf* rdbuf() {
			return Level::GetInstance().rdbuf();
		}

		template<class Level>
		void rdbuf(std::streambuf* buf) {
			Level::GetInstance().rdbuf(buf);
		}

		template<class Level>
		LogLevel& Log() {
			Level& level = static_cast<Level&>(Level::GetInstance());
			return level << "[ " << level.header() << " ] ";
		}

		LogLevel& Log() {
			return Default::GetInstance();
		}
	};
}
#endif	// SURTRLOG_LOGGER_H_
