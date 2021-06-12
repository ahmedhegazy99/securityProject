#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include "cipher.h"

class caesarCipher : public cipher
{
    private:
        void getKey();

    public:
        caesarCipher();
        void Encrypt(string message);
        void Decrypt(string message);
};

#endif // CAESARCIPHER_H
