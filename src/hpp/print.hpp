//Header Guard
#pragma once

//Includes
#include <sstream>
#include <iostream>
#include <fstream>

#include <HelperFunctionOptions.hpp>
#include <typedefs.hpp>

namespace PRIVATE
{
    template <typename... Args>
    string_t joinArgs(const char delimeter, const Args&... args)
    {
        std::ostringstream oss;

        if(delimeter != '\0')
        {
            ((oss << args << delimeter), ...);
        }
        else
        {
            ((oss << args), ...);
        }

        return oss.str();
    }

    //Add to File Log
    void appendLog(const string_t message)
    {
        std::fstream file;
        file.open(OPTIONS::logPath, std::fstream::in | std::fstream::out | std::fstream::app);

        file << message << '\n';

        file.close();
    }
}


/* Functions */

//Clear Log
void clearLog(void)
{
    std::fstream file;
    file.open(OPTIONS::logPath, std::fstream::in | std::fstream::out | std::fstream::trunc);
    file.close();
}

//Prints to the Screen
template <typename... Args>  //Template
void fullPrintLog(const int lineNumber, const string_t filePath, const Args&... args)
{
    //Concatenate Message
    string_t information = PRIVATE::joinArgs('\0', '[', filePath, ": ", lineNumber, "] ");
    string_t message = PRIVATE::joinArgs(' ', args...);
    string_t fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    std::cout << fullMessage << '\n';
}

//Prints Warning to the Screen
template <typename... Args>  //Template
void fullPrintLogWarning(const int lineNumber, const string_t filePath, const Args&... args)
{
    //Concatenate Message
    string_t information = PRIVATE::joinArgs('\0', "[� ", filePath, ": ", lineNumber, "] ");
    string_t message = PRIVATE::joinArgs(' ', args...);
    string_t fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    std::cout << fullMessage << '\n';
}

//Prints Error to the Screen
template <typename... Args>  //Template
void fullPrintLogError(const int lineNumber, const string_t filePath, const Args&... args)
{
    //Concatenate Message
    string_t information = PRIVATE::joinArgs('\0', "[⚠️ ", filePath, ": ", lineNumber, "] ");
    string_t message = PRIVATE::joinArgs(' ', args...);
    string_t fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    std::cout << fullMessage << '\n';
}

//Defines
#define printLog(...) fullPrintLog(__LINE__, __FILE__, __VA_ARGS__)
#define printLogWarning(...) fullPrintLogWarning(__LINE__, __FILE__, __VA_ARGS__)
#define printLogError(...) fullPrintLogError(__LINE__, __FILE__, __VA_ARGS__)