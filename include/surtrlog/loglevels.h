#ifndef SURTRLOG_LOGLEVELS_H_
#define SURTRLOG_LOGLEVELS_H_

#include <iostream>
#include <sstream>

namespace surtrlog {
	class LogLevel {
	public:
		static LogLevel& GetInstance();

		std::streambuf* rdbuf() const;
		std::streambuf* rdbuf(std::streambuf* buf);

		std::string header() const;
		std::string header(std::string header);
	protected:
		LogLevel();
		LogLevel(std::string header);
		virtual ~LogLevel();

		std::streambuf* mBuf;
		std::string mHeader;
	};

	class Default : public LogLevel {
	public:
		static Default& GetInstance();

	private:
		static Default sInstance;
	};

	class Info : public LogLevel {
	public:
		static Info& GetInstance();

	protected:
		Info() : LogLevel("INFO") {}

	private:
		static Info sInstance;
	};

	static surtrlog::LogLevel& operator <<(surtrlog::LogLevel& level, std::string msg) {
		std::ostringstream out;
		if (level.header() != "") {
			out << "[ " << level.header() << " ] " << msg;	
		} else {
			out << msg;
		}
		
		level.rdbuf()->sputn(out.str().c_str(), out.str().length());
		return level;
	}
}
#endif