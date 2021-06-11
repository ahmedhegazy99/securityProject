#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

class cipher
{
    private:

        int key;
        //int bin[];


    protected:
        int ascii[50];

    public:
        string encrypted;
        string decrypted;
        cipher();
        //void Encrypt(string message);
        //void Decrypt(string message);
        void getKey();
        void cAscii(string text);
        //void cBinary(int ascii);
        //void BA(int bin);
        void AT(int ascii[]);

};

#endif // CIPHER_H
