//Header Guard
#pragma once

//Include Headers
#include <zip/Typedefs.hpp>

//Macros
#define AES_ECB 1
#define AES_CBC 2

namespace base64
{
    string_t encode(string_t plainText);
    string_t decode(string_t cipherText);
}

namespace AES
{
    string_t generateKey(int length);


    string_t encrypt(string_t plainText, string_t key, uint8_t mode, string_t iv = "\0");
    string_t decrypt(string_t cipherText, string_t key, uint8_t mode, string_t iv = "\0");
}

namespace SHA
{
    string_t hash();
}