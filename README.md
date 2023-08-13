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

        4. printArray
            - Will Print a 1D Array, no Line Numbers or File

        4. printArray2D
            - Will Print a 2D Array, no Line Numbers or File

        4. printArray3D
            - Will Print a 3D Array, no Line Numbers or File

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

4. Cryptography
    - AES (ECB and CBC) Encryption and Decryption
    - Base64 Encoding and Decoding
    - SHA256 Hashing (Options with just Hashing, Salting, and Peppering)


### Options
- Logging
    1. Encrypt Logs(Will Encrypt With AES Encryption)
    2. Will Save `std::cout` to a Log File (Log Functions will Automatically Save)
    3. A Log File Path
    4. Error Logs Will Throw Runtime Errors
    5. Warning Logs Will Throw Runtime Errors

<hr>
### UNFINISHED FUNCTIONS / TODO
- printArray()
- printArray2D()
- printArray3D()

- AES generateKey()
- AES Encrypt() - Working on Currently
- AES Decrypt()

- SHA 256 Hash
- SHA 256 Hash with Salt
- SHA 256 Hash with Salt and Pepper