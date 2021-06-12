#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H
#include "cipher.h"

class affineCipher : public cipher
{
    public:
        affineCipher();
        void Encrypt(string message);
        void Decrypt(string message);

    private:
        int m;
        void getKey();
};

#endif // AFFINECIPHER_H
