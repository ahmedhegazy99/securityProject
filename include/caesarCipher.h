#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include "cipher.h"
#include <string>


class caesarCipher : public cipher
{
    private:

        int key;


    public:
        caesarCipher();
        void Encrypt(string message);
        void Decrypt(string message);

};

#endif // CAESARCIPHER_H
