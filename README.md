# Surtrlog

A robust platform independent logging framework. 

## Core Concepts 

1. Device   - The output device that logging messages should be written to.
2. LogLevel - A configuration for logging. It defines which output to write to 
			  write to, what headers to write, and so on. The can be configured
			  on the global or logger level. 
3. Logger   - The primary means for configuring the logging framework. It is a
			  collection of log levels and provides an interface for configuring
			  them. 