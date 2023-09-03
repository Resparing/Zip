///Include Header File
#include "../zip/crypt.hpp"

//Includes
#include <cmath>
#include <iomanip>
#include <string>

#include <zip/Print.hpp>
#include <zip/Typedefs.hpp>

string encryptECB(string plainText, string key)
{
    

    return "";
}

string encryptCBC(string plainText, string key, string iv)
{
    return "";
}


/* Main Functions */
string AES::generateKey(int length)
{
    if(length!= 16 && length != 24 && length != 32)
    {
        printLogError("Invalid Key Length");

        abort();
    }
}

string AES::encrypt(string plainText, string key, uint8_t mode, string iv)
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

string decrypt(string cipherText, string key, string iv)
{

}
