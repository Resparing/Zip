# Zip
A small library used to help with C++ developers!


### Functions
1. Logging
    - Better Version of `std::cout` Which can Accept Multiple Arguments, Options Include:
        1. printLog
            - Will Print the Script Directory, Line Number and Message (Can Have Multiple Messages)

        2. printLogWarning
            - Will Print the Script Directory, Line Number, Warning Symbol and Message (Can Have Multiple Messages)

        3. printLogError
            - Will Print the Script Directory, Line Number, Error Symbol and Message (Can Have Multiple Messages)


2. Typedefs
    - All Integer typedefs Including:
        - int8_t (8 bit integer)
        - uint8_t (8 bit unsigned integer)
        - int16_t (16 bit integer)
        - uint16_t (16 bit unsinged integer)
        - int32_t (32 bit integer / Default)
        - int8_t (8 bit integer)

    - All Float typdefs Including:
        - float32_t (32 bit floating point number / Default)
        - float64_t (64 bit floating point number)

    - String typedef

3. OS Version
    - Will Give Out OS Version:

        - Windows (32 bit or 64 bit)
        - Apple
            - iOS Embedded
            - iPhone Simulator
            - iPhone
            - Mac
        - Unix
        - Android
        - Linux
        - Unknown (If cannot find OS)


### Options
- Logging
    1. Encrypt Logs(Will Encrypt With AES Encryption)
    2. Will Save Logs to a Log File
    3. Error Logs Will Throw Runtime Errors
    4. Warning Logs Will Throw Runtime Errors