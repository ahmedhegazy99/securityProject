#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include "cipher.h"

class playfair : public cipher
{
    public:
        playfair();
        string Encrypt(string input);
        string Decrypt(string input);

    private:
        string key;
        void getKey();
        int Mod(int a, int b);
};

#endif // PLAYFAIR_H
