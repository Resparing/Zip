//Header Guard
#pragma once

//Includes
#include <string>

/* Integer */
//8 Bit Integer
#ifndef _INT8_T
    #define _INT8_T
    typedef signed char int8_t;
#endif

//16 Bit Integer
#ifndef _INT16_T
    #define _INT16_T
    typedef signed short int16_t;
#endif

//32 Bit Integer
#ifndef _INT32_T
    #define _INT32_T
    typedef signed int int32_t;
#endif

//64 Bit Integer
#ifndef _INT64_T
    #define _INT64_T
    typedef signed long int64_t;
#endif


//8 Bit Unsigned Integer
#ifndef _U_INT8_T
    #define _U_INT8_T
    typedef unsigned char uint8;
#endif

//16 Bit Unsigned Integer
#ifndef _U_INT16_T
    #define _U_INT16_T
    typedef unsigned short int16_t;
#endif

//32 Bit Unsigned Integer
#ifndef _U_INT32_T
    #define _U_INT32_T
    typedef unsigned int int32_t;
#endif

//64 Bit Unsigned Integer
#ifndef _U_INT64_T
    #define _U_INT64_T
    typedef unsigned long int64_t;
#endif

/* String */
typedef std::string string_t;