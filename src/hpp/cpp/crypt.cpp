//Include Header File
#include "../zip/Crypt.hpp"

//Include Headers
#include <bitset>
#include <string>
#include <vector>

#include <zip/Typedefs.hpp>
#include <zip/Print.hpp>

//Base64 Character Table
const string base64IndexTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* Main Functions */

string base64::encode(const string plainText)
{
    //Binary String
    string binaryString;

    //Turn cipherText Into Binary String
    for(char c : plainText)
    {
        //Find Index
        uint16_t index = (uint16_t)c;

        //Turn Into Binary Value
        std::bitset<8> binaryValue(index);

        //Add to Bool Indexes Vector
        for(int8_t i = 7; i >= 0; i--)
        {
            binaryString += std::to_string(binaryValue[static_cast<size_t>(i)]);
        }
    }

    //Ending Equal Signs
    string padding;

    //Make Sure the Text is the Correct Size, Appending Equal Signs
    while(binaryString.length() % 6 != 0)
    {
        padding += "=";
        binaryString += "0";
    }

    //CipherText
    string cipherText;

    //Iterate Over Binary String
    for(size_t i = 0; i < binaryString.length(); i += 6)
    {
        //Bits String
        string bits;

        //Turn bits into a Byte
        for(size_t j = 0; j < 6; j++)
        {
            bits += binaryString[i + j];
        }

        //Convert Binary into Char
        char c = base64IndexTable[static_cast<uint64_t>(std::stoi(bits, nullptr, 2))];  //SGVsbG8sIFdvcmxkIQ==

        //Add to Plaintext
        cipherText += c;
    }

    //Return the Result + Padding
    return cipherText + padding;
}

string base64::decode(string cipherText)
{
    //Figure out Amount of Padding
    uint16_t padding = 0;

    for(char c : cipherText)
    {
        if(c == '=')
        {
            padding++;
        }
    }

    //Remove Padding From String
    cipherText.erase(std::remove(cipherText.begin(), cipherText.end(), '='), cipherText.end());

    //Binary String
    string binaryString;

    //Turn cipherText Into Binary String
    for(char c : cipherText)
    {
        //Find Index
        uint16_t index = static_cast<uint16_t>(base64IndexTable.find(c));

        //Turn Into Binary Value
        std::bitset<6> binaryValue(index);

        //Add to Bool Indexes Vector
        for(int32_t i = 5; i >= 0; i--)
        {
            binaryString += std::to_string(binaryValue[static_cast<size_t>(i)]);
        }
    }

    //Add Equal Signs to Binary String
    for(int8_t i = 0; i < padding; i ++)
    {
        binaryString += "0";
    }

    //PlainText String
    string plainText;

    //Iterate Over String
    for(size_t i = 0; i < binaryString.length(); i += 8)
    {
        //Byte String
        string byte;

        //Turn bits into a Byte
        for(size_t j = 0; j < 8; j++)
        {
            byte += binaryString[i + j];
        }

        //Convert Binary into Char
        char c = (char)std::stoi(byte, nullptr, 2);

        //Add to Plaintext
        plainText += c;
    }

    //Return PlainText
    return plainText;
}