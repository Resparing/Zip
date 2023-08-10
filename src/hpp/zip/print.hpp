//Header Guard
#pragma once

//Includes
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <zip/zipOptions.hpp>
#include <zip/typedefs.hpp>

namespace PRIVATE
{
    template <typename... Args>
    static string_t joinArgs(const char delimeter, const Args&... args)
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
    static void appendLog(const string_t message)
    {
        std::fstream file;
        file.open(PRINT::logPath, std::fstream::in | std::fstream::out | std::fstream::app);

        file << message << '\n';

        file.close();
    }
}

//Macros
#define printLog(...) fullPrintLog(__LINE__, __FILE__, __VA_ARGS__)
#define printLogWarning(...) fullPrintLogWarning(__LINE__, __FILE__, __VA_ARGS__)
#define printLogError(...) fullPrintLogError(__LINE__, __FILE__, __VA_ARGS__)


/* Functions */

//Clear Log
static void clearLog(void)
{
    std::fstream file;
    file.open(PRINT::logPath, std::fstream::in | std::fstream::out | std::fstream::trunc);
    file.close();
}

//Prints to the Screen
template <typename... Args>  //Template
void fullPrintLog(const int32_t lineNumber, const string_t filePath, const Args&... args)
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
void fullPrintLogWarning(const int32_t lineNumber, const string_t filePath, const Args&... args)
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
void fullPrintLogError(const int32_t lineNumber, const string_t filePath, const Args&... args)
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