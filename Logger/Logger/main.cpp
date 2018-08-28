#include <iostream>
#include <sstream>
#include "Logger.h"

using namespace std;
using namespace CPlusPlusLogging;

int main()
{
   LOG_ALWAYS("<=============================== START OF PROGRAM ===============================>");
   // Log message using Direct Interface
   // Log Level: LOG_ERROR
   LOG_ALWAYS("Message Logged using Direct Interface, Log level: LOG_ALWAYS");
   LOG_ERROR("Message Logged using Direct Interface, Log level: LOG_ERROR");
   LOG_WARNING("Message Logged using Direct Interface, Log level: LOG_WARNING");
   LOG_INFO("Message Logged using Direct Interface, Log level: LOG_INFO");

   // Log message C++ Interface
   Logger* pLogger = NULL; // Create the object pointer for Logger Class
   pLogger = Logger::getInstance();

   pLogger->always("Message Logged using C++ Interface, Log level: LOG_ALWAYS");
   pLogger->error("Message Logged using C++ Interface, Log level: LOG_ERROR");
   pLogger->warning("Message Logged using C++ Interface, Log level: LOG_WARNING");
   pLogger->info("Message Logged using C++ Interface, Log level: LOG_INFO");

   // Log Variables
   std::string name = "Pankaj Choudhary";
   std::string address = "Delhi, India";
   int age = 26;

   std::ostringstream ss;
   ss << endl;
   ss << "\t" << "My Contact Details:" << endl;
   ss << "\t" << "Name: " << name << endl;
   ss << "\t" << "Address: " << address << endl;
   ss << "\t" << "Age: " << age << endl << endl;

   //pLogger->enableConsoleLogging();
   pLogger->updateLogLevel(LOG_LEVEL_INFO);

   // Log ostringstream ss to all the log levels
   LOG_ALWAYS("Logging ostringstream using Direct Interface");
   LOG_ERROR(ss);
   LOG_WARNING(ss);
   LOG_INFO(ss);
  

   Logger::getInstance()->always("Logging ostringstream using C++ Interface");
   Logger::getInstance()->error(ss);
   Logger::getInstance()->warning(ss);
   Logger::getInstance()->info(ss);
   
   
   LOG_ALWAYS("<=============================== END OF PROGRAM ===============================>");
   return 0;
}