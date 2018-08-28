// C++ Header File(s)
#include <iostream>
#include <cstdlib>
#include <ctime>

// Code Specific Header Files(s)
#include "Logger.h"

using namespace std;
using namespace CPlusPlusLogging;

Logger* Logger::m_Instance = 0;

// Log file name. File name should be change from here only
const string logFileName = "MyLogFile.log";

Logger::Logger()
{
	m_File.open(logFileName.c_str(), ios::out | ios::app);
	m_LogLevel = LOG_LEVEL_INFO;
	m_LogType = FILE_LOG;
}


Logger::~Logger()
{
   m_File.close();
}

Logger* Logger::getInstance() throw ()
{
   if (m_Instance == 0) 
   {
      m_Instance = new Logger();
   }
   return m_Instance;
}

void Logger::lock()
{
#ifdef WIN32
   EnterCriticalSection(&m_Mutex);
#else
   pthread_mutex_lock(&m_Mutex);
#endif
}

void Logger::unlock()
{
#ifdef WIN32
   LeaveCriticalSection(&m_Mutex);
#else
   pthread_mutex_unlock(&m_Mutex);
#endif
}

void Logger::logIntoFile(std::string& data)
{
   lock();
   m_File << getCurrentTime() << "  " << data << endl;
   unlock();
}

void Logger::logOnConsole(std::string& data)
{
   cout << getCurrentTime() << "  " << data << endl;
}

string Logger::getCurrentTime()
{
   string currTime;
   //Current date/time based on current time
   time_t now = time(0); 
   // Convert current time to string
   currTime.assign(ctime(&now));

   // Last charactor of currentTime is "\n", so remove it
   string currentTime = currTime.substr(0, currTime.size()-1);
   return currentTime;
}

// Interface for Always Log 
void Logger::always(const char* text) throw()
{
	string data;
	data.append("[ALWAYS]: ");
	data.append(text);

	// No check for ALWAYS logs
	if ((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_ALWAYS))
	{
		logIntoFile(data);
	}
	else if ((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_ALWAYS))
	{
		logOnConsole(data);
	}
}

void Logger::always(std::string& text) throw()
{
	always(text.data());
}

void Logger::always(std::ostringstream& stream) throw()
{
	string text = stream.str();
	always(text.data());
}

// Interface for Error Log
void Logger::error(const char* text) throw()
{
   string data;
   data.append("[ERROR]: ");
   data.append(text);

   // ERROR must be capture
   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_ERROR))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_ERROR))
   {
      logOnConsole(data);
   }
}

void Logger::error(std::string& text) throw()
{
   error(text.data());
}

void Logger::error(std::ostringstream& stream) throw()
{
   string text = stream.str();
   error(text.data());
}

// Interface for Warning Log 
void Logger::warning(const char* text) throw()
{
   string data;
   data.append("[WARNING]: ");
   data.append(text);

   // WARNING must be capture
   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_WARNING))
   {
      logIntoFile(data);
   }
   else if(m_LogType == CONSOLE && (m_LogLevel <= LOG_LEVEL_WARNING))
   {
      logOnConsole(data);
   }
}

void Logger::warning(std::string& text) throw()
{
   warning(text.data());
}

void Logger::warning(std::ostringstream& stream) throw()
{
   string text = stream.str();
   warning(text.data());
}


// Interface for Info Log
void Logger::info(const char* text) throw()
{
   string data;
   data.append("[INFO]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_INFO))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_INFO))
   {
      logOnConsole(data);
   }
}

void Logger::info(std::string& text) throw()
{
   info(text.data());
}

void Logger::info(std::ostringstream& stream) throw()
{
   string text = stream.str();
   info(text.data());
}



// Interfaces to control log levels
void Logger::updateLogLevel(LogLevel logLevel)
{
   m_LogLevel = logLevel;
}

// Enable all log levels
void Logger::enaleLog()
{
   m_LogLevel = ENABLE_LOG; 
}

// Disable all log levels, except error and alarm
void Logger:: disableLog()
{
   m_LogLevel = DISABLE_LOG;
}

// Interfaces to control log Types
void Logger::updateLogType(LogType logType)
{
   m_LogType = logType;
}

void Logger::enableConsoleLogging()
{
   m_LogType = CONSOLE; 
}

void Logger::enableFileLogging()
{
   m_LogType = FILE_LOG ;
}

