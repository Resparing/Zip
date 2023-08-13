//Header Guard
#pragma once

//Include Headers
#include <zip/Typedefs.hpp>

//Macros
#define AES_ECB "\0"

namespace base64
{
    string_t encode(string_t plainText);
    string_t decode(string_t cipherText);
}

namespace AES
{
    string_t generateKey(int length);


    string_t encrypt(string_t plainText, string_t key, string_t iv);
    string_t decrypt(string_t cipherText, string_t key, string_t iv);
}

namespace SHA
{
    string_t hash();
}