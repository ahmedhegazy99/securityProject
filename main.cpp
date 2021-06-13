#include <iostream>
#include <fstream>
#include "caesarCipher.h"
#include "affineCipher.h"
#include "vigenereCipher.h"
#include "fallVigenere.h"
#include "playfair.h"
#include "inverseShift.h"
#include "sBoxCipher.h"

using namespace std;

int main()
{

    string message;

    fstream myFile;
	myFile.open("myFile.txt");
    myFile<<"COMPUTER SECURITY";
    myFile.close();

	myFile.open("myFile.txt");
	while (getline (myFile, message)) {
        cout <<"Plain Text: "<< message<<endl;
    }
    myFile.close();

    caesarCipher e;
    affineCipher e1;
    vigenereCipher e2;
    fallVigenere e3;
    playfair e4;
    inverseShift e5;
    sBoxCipher e6;


    e.Encrypt(message);
    cout<<"Encrypted caesar message: "<<e.encrypted<<endl;
    e1.Encrypt(e.encrypted);
    cout<<"Encrypted affine message: "<<e1.encrypted<<endl;
    e2.Encrypt(e1.encrypted);
    cout<<"Encrypted Simple Shift vigenere message: "<<e2.encrypted<<endl;
    e3.Encrypt(e2.encrypted);
    cout<<"Encrypted Fall Vigenere message: "<<e3.encrypted<<endl;
    e4.Encrypt(e3.encrypted);
    cout<<"Encrypted playfair message: "<<e4.encrypted<<endl;
    e5.Encrypt(e4.encrypted);
    cout<<"Encrypted Inverse Shift message: "<<e5.encrypted<<endl;
    e6.Encrypt(e5.encrypted);
    //cout<<"encrypted binary sBox message: "<<endl<<e6.encryptedStr<<endl;
    cout<<"\nEncrypted S-Box message: "<<endl<<e6.encryptedDec<<endl;



    e6.Decrypt(e6.encrypted);
    //cout<<"decrypted sBox message: "<<endl<<e6.decryptedStr<<endl;
    cout<<"\nDecrypted S-Box message: "<<e6.decrypted<<endl;
    e5.Decrypt(e6.decrypted);
    cout<<"Decrypted Inverse Shift message: "<<e5.decrypted<<endl;
    e4.Decrypt(e5.decrypted);
    cout<<"Decrypted playfair message: "<<e4.decrypted<<endl;
    e3.Decrypt(e4.decrypted);
    cout<<"Decrypted Fall Vigenere message: "<<e3.decrypted<<endl;
    e2.Decrypt(e3.decrypted);
    cout<<"Decrypted Simple Shift Vigenere message: "<<e2.decrypted<<endl;
    e1.Decrypt(e1.encrypted);
    cout<<"Decrypted affine message: "<<e1.decrypted<<endl;
    e.Decrypt(e1.decrypted);
    cout<<"Decrypted caesar message: "<<e.decrypted<<endl;

    return 0;
}
