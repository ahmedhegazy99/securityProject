#include <iostream>
#include <fstream>
#include"caesarCipher.h"

using namespace std;

int main()
{
    //int key;
    string message;

    fstream myFile;
	myFile.open("myFile.txt");
    myFile<<"computer security";
    myFile.close();

	myFile.open("myFile.txt");
	while (getline (myFile, message)) {
        cout <<"Plain Text: "<< message<<endl;
    }
    myFile.close();

    caesarCipher t;
    t.Encrypt(message);
    cout<<"encrypte message: "<<t.encrypted<<endl;
    t.Decrypt(t.encrypted);
    cout<<"decrypte message: "<<t.decrypted<<endl;

/*char c = ' ';
cout<<"enter char"<<endl;
//cin>>c;
cout<<(int)c<<endl;
cout<<char((int)c);
*/
    return 0;
}
