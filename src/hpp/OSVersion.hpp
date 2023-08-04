//Header Guard
#pragma once

//Includes
#include <string>

#ifdef _WIN32
    #if _WIN64
        std::string OS = "Windows - 64";
    #else
        std::string OS = "Windows - 32";
    #endif

#elif __APPLE__
    //Include Header
    #include <TargetConditionals.h>

    //Codnititions
    #if TARGET_OS_EMBEDDED
        std::string OS = "Apple - iOS Embedded";
    #elif TARGET_IPHONE_SIMULATOR
        std::string OS = "Apple - iPhone Simulator";
    #elif TARGET_OS_IPHONE
        std::string OS = "Apple - iPhone";
    #elif TARGET_OS_MAC
        std::string OS = "Apple - Mac";
    #else
        std::string OS = "Apple";
    #endif

#elif __unix__
    std::string OS = "Unix";

#elif __ANDROID__
    std::string OS = "Android"

#elif __linux__
    std::string OS = "Linux";

#else
    std::string OS = "Unknown";

#endif