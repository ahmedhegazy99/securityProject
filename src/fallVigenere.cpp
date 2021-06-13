#include "fallVigenere.h"
#include <iostream>

using namespace std;

fallVigenere::fallVigenere()
{
    getKey();
}

void fallVigenere :: getKey(){
    cout << "Enter Fall Vigenere Word key ( capital ): ";
    cin>>key;
}

void fallVigenere :: Encrypt(string message){
    unsigned int i,j=0;
    cAscii(message);

    for (i=0; i< message.size(); i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = (((ascii[i] + key[j++]) % 26) +65);
                if(ascii[i] > 90 ){
                    ascii[i] = ascii[i] - 26;
                }
            }
            if(j == key.length())
                j=0;
    }
    encrypted = AT(ascii);
}

void fallVigenere :: Decrypt(string message){
    unsigned int i,j=0;
    cAscii(message);

    for (i=0; i< message.size(); i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = ((((ascii[i] - key[j++]) + 26) %26) + 65 );
                if(ascii[i] > 90 ){
                    ascii[i] = ascii[i] - 26;
                }
            }
            if(j == key.length())
                j=0;
    }
    decrypted = AT(ascii);
}
