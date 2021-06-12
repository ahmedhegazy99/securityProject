#include "vigenereCipher.h"
#include <iostream>

using namespace std;

vigenereCipher::vigenereCipher()
{
    getKey();
}

void vigenereCipher :: getKey(){
    cout << "Enter 4 vigenere keys : ";
    for(int i=0; i<4; i++){
        cin>>key[i];
    }
}

void vigenereCipher :: Encrypt(string message){
    unsigned int i,j=0;
    cAscii(message);

    for (i=0; i<= message.size(); i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = (ascii[i] + key[j++]);
                if(ascii[i] > 90 ){
                    ascii[i] = ascii[i] - 26;
                }
            }
            if(j>=4)
                j=0;
    }
    encrypted = AT(ascii);
}

void vigenereCipher :: Decrypt(string message){
    unsigned int i,j=0;
    cAscii(message);

    for (i=0; i<= message.size(); i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = ((ascii[i] - key[j++]) + 26);
                if(ascii[i] > 90 ){
                    ascii[i] = ascii[i] - 26;
                }
            }
            if(j>3)
                j=0;
    }
    decrypted = AT(ascii);
}
