#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H
#include "cipher.h"

class vigenereCipher : public cipher
{
    public:
        vigenereCipher();
        void Encrypt(string message);
        void Decrypt(string message);

    private:
        int key[3];
        void getKey();
};

#endif // VIGENERECIPHER_H
