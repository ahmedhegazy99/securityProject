#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H
#include "cipher.h"


class affineCipher : public cipher
{
    public:
        affineCipher();
        void Encrypt(string message);
        void Decrypt(string message);
        void getKey();

    protected:

    private:
        int key, m;
};

#endif // AFFINECIPHER_H
