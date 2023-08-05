//Header Guard
#pragma once

//Includes
#include <string>

#include <typedefs.hpp>

#ifdef _WIN32
    #if _WIN64
        string_t OS = "Windows - 64";
    #else
        string_t OS = "Windows - 32";
    #endif

#elif __APPLE__
    //Include Header
    #include <TargetConditionals.h>

    //Codnititions
    #if TARGET_OS_EMBEDDED
        string_t OS = "Apple - iOS Embedded";
    #elif TARGET_IPHONE_SIMULATOR
        string_t OS = "Apple - iPhone Simulator";
    #elif TARGET_OS_IPHONE
        string_t OS = "Apple - iPhone";
    #elif TARGET_OS_MAC
        string_t OS = "Apple - Mac";
    #else
        string_t OS = "Apple";
    #endif

#elif __unix__
    string_t OS = "Unix";

#elif __ANDROID__
    string_t OS = "Android"

#elif __linux__
    string_t OS = "Linux";

#else
    string_t OS = "Unknown";

#endif