/*****************************************************************************/
/*!
    \file   logger.cc
    \brief  Implements the Logger class.
*/
/*****************************************************************************/

/*** Includes ****************************************************************/
#include "surtrlog/logger.h"
#include "surtrlog/loglevels.h"
#include <iostream>
#include <string>

/*****************************************************************************/
/*!
    \brief  Initializes a new instance of the LogLevel class with default 
            values.
    
    The default output buffer is stdout and the default log header is an empty
    string.
*/
/*****************************************************************************/
surtrlog::LogLevel::LogLevel() 
	: mBuf(std::cout.rdbuf())
	, mHeader("") {
}

/*****************************************************************************/
/*!
    \brief  Initializes a new instance of the LogLevel class with the specified
            log header, and the default output buffer.

    The default output buffer is stdout.
*/
/*****************************************************************************/
surtrlog::LogLevel::LogLevel(std::string header) 
	: mBuf(std::cout.rdbuf())
	, mHeader(header) {
}

/*****************************************************************************/
/*!
    \brief  Destructs an instance of the LogLevel class and performs any 
            neccesary clean up actions.
*/
/*****************************************************************************/
surtrlog::LogLevel::~LogLevel() {
    mBuf = NULL;
}

/*****************************************************************************/
/*!
    \brief  Returns the output buffer for the LogLevel.
    \return The output buffer this LogLevel writes to.
*/
/*****************************************************************************/
std::streambuf* surtrlog::LogLevel::rdbuf() const {
	return mBuf;
}

/*****************************************************************************/
/*!
    \brief  Sets the output buffer for the LogLevel.
    \param  buf The new output buffer for the LogLevel.
    \return The previous output buffer for hte LogLevel.
*/
/*****************************************************************************/
std::streambuf* surtrlog::LogLevel::rdbuf(std::streambuf* buf) {
	std::streambuf* old = mBuf;
	mBuf = buf;
	return old;
}

/*****************************************************************************/
/*!
    \brief  Gets the log header for the LogLevel.
    \return The log header for the LogLevel.
*/
/*****************************************************************************/
std::string surtrlog::LogLevel::header() const {
	return mHeader;
}

/*****************************************************************************/
/*!
    \brief  Sets the log header for the LogLevel.
    \param  header  The new log header for the LogLevel.
    \return The previous log header for the LogLevel.
*/
/*****************************************************************************/
std::string surtrlog::LogLevel::header(std::string header) {
	std::string old = mHeader;
	mHeader = header;
	return old;
}

// Static instance declarations.
namespace surtrlog {
	Debug Debug::sInstance;
	Default Default::sInstance;
	Info Info::sInstance;
	Warn Warn::sInstance;
	Error Error::sInstance;
}


