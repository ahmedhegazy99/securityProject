#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

class cipher
{
    protected:
        int ascii[20];
        int key;

    public:
        string encrypted="";
        string decrypted="";
        cipher();
        void Encrypt(string message);
        void Decrypt(string message);
        void getKey();
        void cAscii(string text);
        void BA(int bin);
        string AT(int ascii[]);

};

#endif // CIPHER_H
