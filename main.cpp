#include <iostream>
#include <fstream>
#include "caesarCipher.h"
#include "affineCipher.h"
#include "vigenereCipher.h"

using namespace std;

int main()
{
    string message="VIGENERE CIPHER";

    fstream myFile;
	myFile.open("myFile.txt");
    myFile<<"COMPUTER SECURITY";
    myFile.close();

	myFile.open("myFile.txt");
	while (getline (myFile, message)) {
        cout <<"Plain Text: "<< message<<endl;
    }
    myFile.close();

    //caesarCipher e;
    //affineCipher e1;
    vigenereCipher e2;
/*
    e.Encrypt(message);
    cout<<"encrypted caesar message: "<<e.encrypted<<endl;
    e1.Encrypt(e.encrypted);
    cout<<"encrypted affine message: "<<e1.encrypted<<endl;*/
    e2.Encrypt(message);
    cout<<"encrypted vigenere message: "<<e2.encrypted<<endl;


    e2.Decrypt(e2.encrypted);
    cout<<"decrypted vigenere message: "<<e2.decrypted<<endl;
/*   e1.Decrypt(e2.encrypted);
    cout<<"decrypted affine message: "<<e1.decrypted<<endl;
    e.Decrypt(e1.decrypted);
    cout<<"decrypted caesar message: "<<e.decrypted<<endl;
*/


    return 0;
}
