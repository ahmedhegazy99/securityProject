#ifndef FALLVIGENERE_H
#define FALLVIGENERE_H
#include "cipher.h"

class fallVigenere : public cipher
{
    public:
        fallVigenere();
        void Encrypt(string message);
        void Decrypt(string message);

    private:
        string key ;
        void getKey();
};

#endif // FALLVIGENERE_H
