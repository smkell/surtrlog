/*****************************************************************************/
/*!
    \file   logger.h
    \brief  Defines the interface for the Logger class.
*/
/*****************************************************************************/

/*** Include Guard ***********************************************************/
#ifndef SURTRLOG_LOGGER_H_
#define SURTRLOG_LOGGER_H_

/*** Includes ****************************************************************/
#include "surtrlog/loglevels.h"

namespace surtrlog {

	// Forward declarations
	class LogLevel;

    /*************************************************************************/
    /*!
        \brief  A Logger is the primary interface for logging messages. 

        The logger holds configurations for the LogLevels and exposes those 
        LogLevels to the consumer of the library.
    */
    /*************************************************************************/
	class Logger {
	public:
        // Constructor
		Logger();
        // Destructor
		virtual ~Logger();

        /*********************************************************************/
        /*!
            \brief  Returns the LogLevel corresponding to the given Level
                    type identifier.
            \tparam Level   The LogLevel to return.
            \return The LogLevel whose type corresponds to the given Level
                    type identifier.
        /*********************************************************************/
		template<class Level>
		LogLevel& Log() {
            return Level::GetInstance();
        }

        /*********************************************************************/
        /*!
            \brief  Returns the default LogLevel.
            \return The default LogLevel. 
        */
        /*********************************************************************/
		Default& Log() {
            return Default::GetInstance();
        }
	};
}       // namespace surtrlog
#endif	// SURTRLOG_LOGGER_H_