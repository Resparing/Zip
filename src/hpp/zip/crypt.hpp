//Header Guard
#pragma once

//Include Headers
#include <zip/Typedefs.hpp>

//Macros
#define AES_ECB 1
#define AES_CBC 2

namespace base64
{
    string encode(string plainText);
    string decode(string cipherText);
}

namespace AES
{
    string generateKey(int length);


    string encrypt(string plainText, string key, uint8_t mode, string iv = "\0");
    string decrypt(string cipherText, string key, uint8_t mode, string iv = "\0");
}

namespace SHA
{
    string hash(string text);
    string hash(string text, string salt);
    string hash(string text, string salt, string pepepr);
}