//Header Guard
#pragma once

//Includes
#include <string>

#include <zip/Typedefs.hpp>

#ifdef _WIN32
    #if _WIN64
        string OS = "Windows - 64";
    #else
        string OS = "Windows - 32";
    #endif

#elif __APPLE__
    //Include Header
    #include <TargetConditionals.h>

    //Codnititions
    #if TARGET_OS_EMBEDDED
        string OS = "Apple - iOS Embedded";
    #elif TARGET_IPHONE_SIMULATOR
        string OS = "Apple - iPhone Simulator";
    #elif TARGET_OS_IPHONE
        string OS = "Apple - iPhone";
    #elif TARGET_OS_MAC
        string OS = "Apple - Mac";
    #else
        string OS = "Apple";
    #endif

#elif __unix__
    string OS = "Unix";

#elif __ANDROID__
    string OS = "Android"

#elif __linux__
    string OS = "Linux";

#else
    string OS = "Unknown";
#endif