#include <cstdlib>
#include <openssl/aes.h>
#include <iostream>
#include <zip/Crypt.hpp>

int main(void)
{

    unsigned char cipher[32];
    const unsigned char userKey[] = "dsadsandjkasfjasdiadskss";
    const unsigned char input[] = "tLy1IRZUjtLoQxE4tLy1IRZUjtLoQxE4";

    //ENC
    AES_KEY aesENCKey;

    AES_set_encrypt_key(userKey, 128, &aesENCKey);
    AES_encrypt(input, cipher, &aesENCKey);

    std::cout << cipher << std::endl;

    //DEC
    AES_KEY aesDEC;

    unsigned char plain[32];

    AES_set_decrypt_key(userKey, 128, &aesDEC);
    AES_decrypt(cipher, plain, &aesDEC);

    std::cout << plain << std::endl;
    std::cout << input << std::endl;

    return EXIT_SUCCESS;
}