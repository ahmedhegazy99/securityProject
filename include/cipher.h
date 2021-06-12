#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

class cipher
{
    private:
        //int key;
        const static int l = 20;

    protected:
        int ascii[l];
        int bin[l];
        int key;

    public:
        string encrypted="";
        string decrypted="";
        cipher();
        void Encrypt(string message);
        void Decrypt(string message);
        void getKey();
        void cAscii(string text);
        void cBinary(int ascii);
        void BA(int bin);
        string AT(int ascii[]);

};

#endif // CIPHER_H
