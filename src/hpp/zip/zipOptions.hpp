//Header Guard
#pragma once

//Includes
#include <string>

#include <zip/Crypt.hpp>
#include <zip/Typedefs.hpp>

namespace PRINT
{
    //Will Encrpt Logs
    const bool encryptLogs = false;

    //Log Items to a Log File
    const bool logToFile = false;

    //Log File Path
    const string_t logPath = "bin/Log.txt";

    //Warning Logs Will Give Runtime Errors
    const bool enableRuntimeWarningLogging = false;

    //Error Logs Will Give Runtime Errors
    const bool enableRuntimeErrorLogging = true;
}