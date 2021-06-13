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
        int m, mi = 0;
        int flag = 0;
        void getKey();
};

#endif // AFFINECIPHER_H
