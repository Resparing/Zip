///Include Header File
#include "../zip/crypt.hpp"

//Includes
#include <cmath>
#include <iomanip>
#include <string>

#include <zip/Print.hpp>
#include <zip/Typedefs.hpp>

string_t encryptECB(string_t plainText, string_t key)
{
    

    return "";
}

string_t encryptCBC(string_t plainText, string_t key, string_t iv)
{
    return "";
}


/* Main Functions */
string_t AES::generateKey(int length)
{
    if(length!= 16 && length != 24 && length != 32)
    {
        printLogError("Invalid Key Length");

        abort();
    }
}

string_t AES::encrypt(string_t plainText, string_t key, uint8_t mode, string_t iv)
{
    if(key.length() != 16 && key.length() != 24 && key.length() != 32)
    {
        printLogError("Invalid Key Length");

        abort();
    }

    if(iv == "\0")
	{
		return encryptECB(plainText, key);
	}
	else
	{
		return encryptCBC(plainText, key, iv);
    }
}

string_t decrypt(string_t cipherText, string_t key, string_t iv)
{

}
