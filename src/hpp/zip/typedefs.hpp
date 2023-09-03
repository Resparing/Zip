//Header Guard
#pragma once

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

/* Floating Point */
typedef float float32_t;  //32 Bit Floating Point Number
typedef double float64_t;  //64 Bit Floating Point Number

/* String */
#ifdef _LIBCPP_STRING
    typedef std::string string;
#endif

/* Exit Codes */
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
    #define EXIT_FAILURE 1
#endif

/* Miscellaneous */