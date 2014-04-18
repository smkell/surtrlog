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
		static Default& GetInstance() { return sInstance; }

	private:
		static Default sInstance;
	};

	class Info : public LogLevel {
	public:
		static Info& GetInstance() { return sInstance; }

	protected:
		Info() : LogLevel("INFO") {}

	private:
		static Info sInstance;
	};

	class Debug : public LogLevel {
	public:
		static Debug& GetInstance() { return sInstance; }

	protected:
		Debug() : LogLevel("DEBUG") {}

	private:
		static Debug sInstance;
	};

	class Warn : public LogLevel {
	public:
		static Warn& GetInstance() { return sInstance; }

	protected:
		Warn() : LogLevel("WARN") {}

	private:
		static Warn sInstance;
	};

	class Error : public LogLevel {
	public:
		static Error& GetInstance() { return sInstance; }

	protected:
		Error() : LogLevel("ERROR") {}

	private:
		static Error sInstance;
	};

	static surtrlog::LogLevel& operator <<(surtrlog::LogLevel& level, std::string msg) {
		level.rdbuf()->sputn(msg.c_str(), msg.length());
		return level;
	}
}
#endif
