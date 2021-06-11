#include "caesarCipher.h"
#include "cipher.h"
#include <iostream>

using namespace std;

caesarCipher::caesarCipher()
{
getKey();
}

void caesarCipher :: getKey(){
    cout << "Enter key: ";
    cin >> key;
}

void caesarCipher :: Encrypt(string message){
    unsigned int i;
    cAscii(message);

    for (i=0; i< message.size(); i++){
        if(ascii[i] == 95 || ascii[i] == 32){
            ascii[i] = ascii[i];
        }else{
            ascii[i]= (((message[i] - 96 + key) % 26)+ 96);
        }
    }
    encrypted = AT(ascii);
}

void caesarCipher :: Decrypt(string message){
    int i;

    cAscii(message);

    for (i=0; i<message.length(); i++){
        if(ascii[i] == 95 || ascii[i] == 32){
            ascii[i] = ascii[i];
        }else{
            if(((message[i] - 96 - key) % 26) <= 0)
                ascii[i]= (((message[i] - 96 - key) % 26)+ 26 + 96);
            else
                ascii[i]= (((message[i] - 96 - key) % 26)+ 96);
            }
        }
         decrypted = AT(ascii);
    }


