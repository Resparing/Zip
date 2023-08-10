//Header Guard
#pragma once

//Includes
#include <string>

#include <zip/crypt.hpp>
#include <zip/typedefs.hpp>

namespace PRINT
{
    //Will Encrpt Logs
    const bool encryptLogs = false;

    //Encryption Key
    const string_t key = "Input Your Password Here! MUST BE IN BASE64!!!";

    //Log File Path
    const string_t logPath = "bin/Log.txt";

    //Warning Logs Will Give Runtime Errors
    const bool enableRuntimeWarningLogging = false;

    //Error Logs Will Give Runtime Errors
    const bool enableRuntimeErrorLogging = true;
}