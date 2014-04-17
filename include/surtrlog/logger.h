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
		Logger();
		virtual ~Logger();

		template<typename Level>
		LogLevel& Log() {
			return Level::GetInstance();
		}

		LogLevel& Log() {
			return Default::GetInstance();
		}
	};
}
#endif	// SURTRLOG_LOGGER_H_