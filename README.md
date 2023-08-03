# C++ Helper Functions
A small library used to help with C++ developers!


### Functions
1. Logging
    - printLog
        - Will Print the Script Directory, Line Number and Message (Can Have Multiple Messages)

    - printLogWarning
        - Will Print the Script Directory, Line Number, Warning Symbol and Message (Can Have Multiple Messages)

    - printLogError
        - Will Print the Script Directory, Line Number, Error Symbol and Message (Can Have Multiple Messages)


2. Typedefs
    - All Integer typedefs including:
        - int8_t (8 bit integer)
        - int32_t (32 bit integer / Default)

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
1. Encrypt Logs(Will Encrypt With AES Encryption)
2. Will Save Logs to a Log File