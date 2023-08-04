//Header Guard
#pragma once

//Includes
#include <sstream>
#include <iostream>
#include <fstream>

//Include Options
#include <HelperFunctionOptions.hpp>

namespace PRIVATE
{
    template <typename... Args>
    std::string joinArgs(char delimeter, const Args&... args)
    {
        std::ostringstream oss;
        ((oss << args << delimeter), ...);

        return oss.str();
    }
}


/* Functions */

//Clear Log.txt
void clearLog(void)
{
    std::fstream file;
    file.open(OPTIONS::logPath, std::fstream::in | std::fstream::out | std::fstream::trunc);
    file.close();
}

//Prints to the Screen
template <typename... Args>  //Template
void fullPrintLog(const int lineNumber, std::string filePath, const Args&... args)
{
    //Concatenate Message
    std::string information = PRIVATE::joinArgs('\0', '[', filePath, ": ", lineNumber, "] ");
    std::string message = PRIVATE::joinArgs(' ', args...);
    std::string fullMessage = PRIVATE::joinArgs('\0', information, message);


    std::cout << fullMessage << '\n';
}

//Prints Warning to the Screen
template <typename... Args>  //Template
void fullPrintLogWarning(const int lineNumber, std::string filePath, const Args&... args)
{
    //Concatenate Message
    std::string information = PRIVATE::joinArgs('\0', "[� ", filePath, ": ", lineNumber, "] ");
    std::string message = PRIVATE::joinArgs(' ', args...);
    std::string fullMessage = PRIVATE::joinArgs('\0', information, message);

    std::cout << fullMessage << '\n';
}

//Prints Error to the Screen
template <typename... Args>  //Template
void fullPrintLogError(const int lineNumber, std::string filePath, const Args&... args)
{
    //Concatenate Message
    std::string information = PRIVATE::joinArgs('\0', "[⚠️ ", filePath, ": ", lineNumber, "] ");
    std::string message = PRIVATE::joinArgs(' ', args...);
    std::string fullMessage = PRIVATE::joinArgs('\0', information, message);

    std::cout << fullMessage << '\n';
}

//Defines
#define printLog(...) fullPrintLog(__LINE__, __FILE__, __VA_ARGS__)
#define printLogWarning(...) fullPrintLogWarning(__LINE__, __FILE__, __VA_ARGS__)
#define printLogError(...) fullPrintLogError(__LINE__, __FILE__, __VA_ARGS__)