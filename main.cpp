#include <iostream>
#include <fstream>
#include "caesarCipher.h"
#include "affineCipher.h"
#include "vigenereCipher.h"
#include "fallVigenere.h"
#include "playfair.h"
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
    //sBoxCipher e6;


    e.Encrypt(message);
    cout<<"encrypted caesar message: "<<e.encrypted<<endl;
    e1.Encrypt(e.encrypted);
    cout<<"encrypted affine message: "<<e1.encrypted<<endl;
    e2.Encrypt(e1.encrypted);
    cout<<"encrypted vigenere message: "<<e2.encrypted<<endl;
    e3.Encrypt(e2.encrypted);
    cout<<"encrypted Fall Vigenere message: "<<e3.encrypted<<endl;
    e4.Encrypt(e3.encrypted);
    cout<<"encrypted playfair message: "<<e4.encrypted<<endl;



    e4.Decrypt(e4.encrypted);
    cout<<"decrypted playfair message: "<<e4.decrypted<<endl;
    e3.Decrypt(e4.decrypted);
    cout<<"decrypted Fall Vigenere message: "<<e3.decrypted<<endl;
    e2.Decrypt(e3.decrypted);
    cout<<"decrypted vigenere message: "<<e2.decrypted<<endl;
    e1.Decrypt(e2.decrypted);
    cout<<"decrypted affine message: "<<e1.decrypted<<endl;
    e.Decrypt(e1.decrypted);
    cout<<"decrypted caesar message: "<<e.decrypted<<endl;

    /*int ass[]={104,111,112,101};

    e7.cBinary(ass);
*/
    return 0;
}
