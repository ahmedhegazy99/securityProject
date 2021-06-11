#include <iostream>
#include <fstream>
#include "caesarCipher.h"
#include "affineCipher.h"

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
    e.Encrypt(message);
    cout<<"encrypte caesar message: "<<e.encrypted<<endl;
    e1.Encrypt(e.encrypted);
    cout<<"encrypte affine message: "<<e1.encrypted<<endl;





    e1.Decrypt(e1.encrypted);
    cout<<"decrypte affine message: "<<e1.decrypted<<endl;
    e.Decrypt(e1.decrypted);
    cout<<"decrypte caesar message: "<<e.decrypted<<endl;



    return 0;
}
