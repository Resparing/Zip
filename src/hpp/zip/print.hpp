//Header Guard
#pragma once

//Includes
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <zip/Crypt.hpp>
#include <zip/Typedefs.hpp>
#include <zip/ZipOptions.hpp>

namespace PRIVATE
{
    template <typename... Args>
    static string joinArgs(const char delimeter, const Args&... args)
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
    static void appendLog(const string message)
    {
        std::fstream file;
        file.open(PRINT::logPath, std::fstream::in | std::fstream::out | std::fstream::app);

        file << message << '\n';

        file.close();
    }

    //File Variables
    static std::fstream file;
    static std::streambuf* originalCoutBuffer;
}

//Macros
#define printLog(...) fullPrintLog(__LINE__, __FILE__, __VA_ARGS__)
#define printLogWarning(...) fullPrintLogWarning(__LINE__, __FILE__, __VA_ARGS__)
#define printLogError(...) fullPrintLogError(__LINE__, __FILE__, __VA_ARGS__)


/* Main Functions */

//Open Log
static void openLog(void)
{
    //Clear Buffer
    std::cout << std::endl;

    //Open File
    PRIVATE::file.open(PRINT::logPath, std::fstream::in | std::fstream::out | std::fstream::trunc);

    //If std::cout Logging is Enabled
    if(PRINT::logToFile == true)
    {
        //Change Output
        PRIVATE::originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(PRIVATE::file.rdbuf());
    }
}

static void closeLog(void)
{
    //If std::cout Logging is Enabled
    if(PRINT::logToFile == true)
    {
        //Redirect Print Statements
        std::cout.rdbuf(PRIVATE::originalCoutBuffer);
    }

    //Clear Buffer
    std::cout << std::endl;

    //Close File
    PRIVATE::file.close();
}

//Prints to the Screen
template <typename... Args>  //Template
void fullPrintLog(const int32_t lineNumber, const string filePath, const Args&... args)
{
    //Concatenate Message
    string information = PRIVATE::joinArgs('\0', '[', filePath, ": ", lineNumber, "] ");
    string message = PRIVATE::joinArgs(' ', args...);
    string fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Encrypt Logs if Needed
    if(PRINT::encryptLogs == true)
    {
        fullMessage = base64::encode(AES::encrypt(fullMessage, base64::decode(PRINT::key), AES_ECB));
    }

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    std::cout << fullMessage << '\n';
}

//Prints Warning to the Screen
template <typename... Args>  //Template
void fullPrintLogWarning(const int32_t lineNumber, const string filePath, const Args&... args)
{
    //Concatenate Message
    string information = PRIVATE::joinArgs('\0', "[� ", filePath, ": ", lineNumber, "] ");
    string message = PRIVATE::joinArgs(' ', args...);
    string fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Encrypt Logs if Needed
    if(PRINT::encryptLogs == true)
    {
        fullMessage = base64::encode(AES::encrypt(fullMessage, base64::decode(PRINT::key), AES_ECB));
    }

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    if(PRINT::enableRuntimeWarningLogging == true)
    {
        std::cerr << fullMessage << '\n';
    }
    else
    {
        std::cout << fullMessage << '\n';
    }
}

//Prints Error to the Screen
template <typename... Args>  //Template
void fullPrintLogError(const int32_t lineNumber, const string filePath, const Args&... args)
{
    //Concatenate Message
    string information = PRIVATE::joinArgs('\0', "[⚠️ ", filePath, ": ", lineNumber, "] ");
    string message = PRIVATE::joinArgs(' ', args...);
    string fullMessage = PRIVATE::joinArgs('\0', information, message);

    //Encrypt Logs if Needed
    if(PRINT::encryptLogs == true)
    {
        fullMessage = base64::encode(AES::encrypt(fullMessage, base64::decode(PRINT::key), AES_ECB));
    }

    //Add to Log
    PRIVATE::appendLog(fullMessage);

    //Output Message
    if(PRINT::enableRuntimeErrorLogging == true)
    {
        std::cerr << fullMessage << '\n';
    }
    else
    {
        std::cout << fullMessage << '\n';
    }
}

//Prints an Array
template <typename T, size_t Rows>
void printArray(const T (&array)[Rows])
{
    //Message String
    string message;

    for(uint32_t i = 0; i < Rows; i++)
    {
        
    }
}

template <typename T, size_t Rows, size_t Cols>
void printArray2D(const T (&array)[Rows][Cols])
{
    
}

template <typename T, size_t Depth, size_t Rows, size_t Cols>
void printArray3D(const T (&array)[Depth][Rows][Cols])
{
    
}