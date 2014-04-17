#include "surtrlog/logger.h"
#include "surtrlog/loglevels.h"
#include <iostream>
#include <string>

surtrlog::LogLevel::LogLevel() 
	: mBuf(std::cout.rdbuf())
	, mHeader("") {
}

surtrlog::LogLevel::LogLevel(std::string header) 
	: mBuf(std::cout.rdbuf())
	, mHeader(header) {
}

surtrlog::LogLevel::~LogLevel() {}

std::streambuf* surtrlog::LogLevel::rdbuf() const {
	return mBuf;
}

std::streambuf* surtrlog::LogLevel::rdbuf(std::streambuf* buf) {
	std::streambuf* old = mBuf;
	mBuf = buf;
	return old;
}

std::string surtrlog::LogLevel::header() const {
	return mHeader;
}

std::string surtrlog::LogLevel::header(std::string header) {
	std::string old = mHeader;
	mHeader = header;
	return old;
}

namespace surtrlog {
	Debug Debug::sInstance;
	Default Default::sInstance;
	Info Info::sInstance;
	Warn Warn::sInstance;
	Error Error::sInstance;
}


