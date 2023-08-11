///Include Header File
#include "../zip/crypt.hpp"

//Includes
#include <cmath>
#include <string>
#include <iomanip>

#include <zip/print.hpp>
#include <zip/typedefs.hpp>

//Variables
const uint8_t sBox[256] =
{
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

const uint8_t rCon[256] =
{
    0X8D, 0X01, 0X02, 0X04, 0X08, 0X10, 0X20, 0X40, 0X80, 0X1B, 0X36, 0X6C, 0XD8, 0XAB, 0X4D, 0X9A,
    0X2F, 0X5E, 0XBC, 0X63, 0XC6, 0X97, 0X35, 0X6A, 0XD4, 0XB3, 0X7D, 0XFA, 0XEF, 0XC5, 0X91, 0X39,
    0X72, 0XE4, 0XD3, 0XBD, 0X61, 0XC2, 0X9F, 0X25, 0X4A, 0X94, 0X33, 0X66, 0XCC, 0X83, 0X1D, 0X3A,
    0X74, 0XE8, 0XCB, 0X8D, 0X01, 0X02, 0X04, 0X08, 0X10, 0X20, 0X40, 0X80, 0X1B, 0X36, 0X6C, 0XD8,
    0XAB, 0X4D, 0X9A, 0X2F, 0X5E, 0XBC, 0X63, 0XC6, 0X97, 0X35, 0X6A, 0XD4, 0XB3, 0X7D, 0XFA, 0XEF,
    0XC5, 0X91, 0X39, 0X72, 0XE4, 0XD3, 0XBD, 0X61, 0XC2, 0X9F, 0X25, 0X4A, 0X94, 0X33, 0X66, 0XCC,
    0X83, 0X1D, 0X3A, 0X74, 0XE8, 0XCB, 0X8D, 0X01, 0X02, 0X04, 0X08, 0X10, 0X20, 0X40, 0X80, 0X1B,
    0X36, 0X6C, 0XD8, 0XAB, 0X4D, 0X9A, 0X2F, 0X5E, 0XBC, 0X63, 0XC6, 0X97, 0X35, 0X6A, 0XD4, 0XB3,
    0X7D, 0XFA, 0XEF, 0XC5, 0X91, 0X39, 0X72, 0XE4, 0XD3, 0XBD, 0X61, 0XC2, 0X9F, 0X25, 0X4A, 0X94,
    0X33, 0X66, 0XCC, 0X83, 0X1D, 0X3A, 0X74, 0XE8, 0XCB, 0X8D, 0X01, 0X02, 0X04, 0X08, 0X10, 0X20,
    0X40, 0X80, 0X1B, 0X36, 0X6C, 0XD8, 0XAB, 0X4D, 0X9A, 0X2F, 0X5E, 0XBC, 0X63, 0XC6, 0X97, 0X35,
    0X6A, 0XD4, 0XB3, 0X7D, 0XFA, 0XEF, 0XC5, 0X91, 0X39, 0X72, 0XE4, 0XD3, 0XBD, 0X61, 0XC2, 0X9F,
    0X25, 0X4A, 0X94, 0X33, 0X66, 0XCC, 0X83, 0X1D, 0X3A, 0X74, 0XE8, 0XCB, 0X8D, 0X01, 0X02, 0X04,
    0X08, 0X10, 0X20, 0X40, 0X80, 0X1B, 0X36, 0X6C, 0XD8, 0XAB, 0X4D, 0X9A, 0X2F, 0X5E, 0XBC, 0X63,
    0XC6, 0X97, 0X35, 0X6A, 0XD4, 0XB3, 0X7D, 0XFA, 0XEF, 0XC5, 0X91, 0X39, 0X72, 0XE4, 0XD3, 0XBD,
    0X61, 0XC2, 0X9F, 0X25, 0X4A, 0X94, 0X33, 0X66, 0XCC, 0X83, 0X1D, 0X3A, 0X74, 0XE8, 0XCB, 0X8D
};

/* Helper Functions */
#pragma region

//String to 3D Array of 4x4 grids
void transformString(string_t plainText, int32_t numBlocks, unsigned char message[][4][4])
{
    //Fill out Message
    for(uint32_t numTables = 0; numTables < numBlocks; numTables++)
    {
        //Cut Plain Text String - 16 Characters Long
        string_t cutPlainText = plainText.substr(numTables * 16, 16);

        //If Cut Text Length is Less Than 16, Append "SPACE"
        while(cutPlainText.length() < 16)
        {
            cutPlainText += '\0';
        }

        //Fill Out Message
        for(uint8_t rows = 0; rows < 4; rows++)
        {
            for(uint8_t cols = 0; cols < 4; cols++)
            {
                message[numTables][cols][rows] = cutPlainText[rows * 4 + cols];
            }
        }
    }
}

//GMul - Used In MixColumns
uint8_t gMul(uint8_t a, uint8_t b)
{
    //Credit to Topaco - https://stackoverflow.com/questions/66115739/aes-mixcolumns-with-python

    uint8_t tmp = (a << 1) & 0xFF;

    if(b == 1)
    {
        return a;
    }
    if(b == 2)
    {
        return a < 128 ? tmp : tmp ^ 0x1B;
    }
    if(b == 3)
    {
        return gMul(a, 2) ^ a;
    }
}

//Mix Single Column
void mixColumn(unsigned char cipherColumn[4], unsigned char result[4])
{
    //Credit to Topaco - https://stackoverflow.com/questions/66115739/aes-mixcolumns-with-python

    result[0] = gMul(cipherColumn[0], 2) ^ gMul(cipherColumn[1], 3) ^ gMul(cipherColumn[2], 1) ^ gMul(cipherColumn[3], 1);
    result[1] = gMul(cipherColumn[0], 1) ^ gMul(cipherColumn[1], 2) ^ gMul(cipherColumn[2], 3) ^ gMul(cipherColumn[3], 1);
    result[2] = gMul(cipherColumn[0], 1) ^ gMul(cipherColumn[1], 1) ^ gMul(cipherColumn[2], 2) ^ gMul(cipherColumn[3], 3);
    result[3] = gMul(cipherColumn[0], 3) ^ gMul(cipherColumn[1], 1) ^ gMul(cipherColumn[2], 1) ^ gMul(cipherColumn[3], 2);
}

//Expand Keys
void keyExpansion(){}

//Add Round Key
void addRoundKey(unsigned char cipherBlock[4][4], unsigned char roundKey[4][4])
{
    //Iterate Through Array
    for(uint8_t rows = 0; rows < 4; rows++)
    {
        for(uint8_t cols = 0; cols < 4; cols++)
        {
            cipherBlock[rows][cols] ^= roundKey[rows][cols];
        }
    }
}

//Replace Bytes
void subBytes(unsigned char cipherBlock[4][4])
{
    //Iterate Through Array
    for(uint8_t rows = 0; rows < 4; rows++)
    {
        for(uint8_t cols = 0; cols < 4; cols++)
        {
            //Look up Value in sBox
            cipherBlock[rows][cols] = sBox[cipherBlock[rows][cols]];
        }
    }
}

//Shift Rows
void shiftRows(unsigned char cipherBlock[4][4])
{
    //Temporary Array to Preform Shifting
    unsigned char shiftedState[4][4];

    //Shift Rows
    shiftedState[0][0] = cipherBlock[0][0];
    shiftedState[1][0] = cipherBlock[1][1];
    shiftedState[2][0] = cipherBlock[2][2];
    shiftedState[3][0] = cipherBlock[3][3];

    shiftedState[0][1] = cipherBlock[0][1];
    shiftedState[1][1] = cipherBlock[1][2];
    shiftedState[2][1] = cipherBlock[2][3];
    shiftedState[3][1] = cipherBlock[3][0];

    shiftedState[0][2] = cipherBlock[0][2];
    shiftedState[1][2] = cipherBlock[1][3];
    shiftedState[2][2] = cipherBlock[2][0];
    shiftedState[3][2] = cipherBlock[3][1];

    shiftedState[0][3] = cipherBlock[0][3];
    shiftedState[1][3] = cipherBlock[1][0];
    shiftedState[2][3] = cipherBlock[2][1];
    shiftedState[3][3] = cipherBlock[3][2];

    //Copy Back Into Array
    for(uint8_t rows = 0; rows < 4; rows++)
    {
        for(uint8_t cols = 0; cols < 4; cols++)
        {
            cipherBlock[rows][cols] = shiftedState[rows][cols];
        }
    }
}

//Mix Columns
void mixColumns(unsigned char cipherBlock[4][4])
{
    //Temporary Array
    unsigned char mixedState[4][4];

    //Iterate Over Columns
    for(uint8_t cols = 0; cols < 4; cols++)
    {
        //Column and Result Array
        unsigned char column[4];
        unsigned char result[4];

        //Fill Out Column Array
        for(uint8_t rows = 0; rows < 4; rows++)
        {
            column[rows] = cipherBlock[rows][cols];
        }

        //Convert Column
        mixColumn(column, result);

        //Add Column to State
        for(uint8_t rows = 0; rows < 4; rows++)
        {
            mixedState[rows][cols] = result[rows];
        }
    }

    //Copy Back Into Array
    for(uint8_t rows = 0; rows < 4; rows++)
    {
        for(uint8_t cols = 0; cols < 4; cols++)
        {
            cipherBlock[rows][cols] = mixedState[rows][cols];
        }
    }
}

#pragma endregion  //Helper Functions

string_t encryptECB(string_t plainText, string_t key)
{
    //Amount of plainText Blocks
    const int32_t numBlocks = ceil(plainText.length() / 16.0f);

    //Array of 256 bit segments of plainText
    unsigned char message[numBlocks][4][4];

    transformString(plainText, numBlocks, message);

    //Figure out Number of Rounds
    uint32_t numRounds = static_cast<uint32_t>(key.length() * (1/32) + 6);

    //Repeat for Entire Message
    for(uint32_t i = 0; i < numBlocks; i++)
    {
        //Create CipherBlock
        unsigned char cipherBlock[4][4];

        //Fill Out Cipher Block
        for(uint8_t rows = 0; rows < 4; rows++)
        {
            for(uint8_t cols = 0; cols < 4; cols++)
            {
                cipherBlock[cols][rows] = message[i][cols][rows];
            }
        }

       //Create Round Key
        unsigned char roundKey[4][4];

        //Key Expansion
        keyExpansion();

        //Initial Add Round Key
        addRoundKey(cipherBlock, roundKey);

        //Rounds
        for(uint8_t rounds = 0; rounds < numRounds - 1; rounds++)
        {
            subBytes(cipherBlock);
            shiftRows(cipherBlock);
            mixColumns(cipherBlock);
            addRoundKey(cipherBlock, roundKey);
        }

        //Final Rounds
        subBytes(cipherBlock);
        shiftRows(cipherBlock);
        addRoundKey(cipherBlock, roundKey);

    }

    return "";
}

string_t encryptCBC(string_t plainText, string_t key, string_t iv)
{

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

string_t AES::encrypt(string_t plainText, string_t key, string_t iv)
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
