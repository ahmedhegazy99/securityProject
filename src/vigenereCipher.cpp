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
    cout<<"You enterd( ";
    for(int i=0; i<4; i++){cout<<key[i]<<" ";}
    cout<<")"<<endl;
}

void vigenereCipher :: Encrypt(string message){
    unsigned int i,j=0;
    cAscii(message);
    //int h=0;

    for (i=0; i<= message.size(); i++){
            //cout<<"j: "<<j<<"   i: "<<i<<endl;
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = (((ascii[i] + key[j++]) % 26) + 65);
            }
            //cout<<"ascii("<<h++<<"): "<<ascii[i]<<endl;
            if(j>3)
            j=0;


    }
    encrypted = AT(ascii);
}

void vigenereCipher :: Decrypt(string message){
    unsigned int i,j=0;
    cAscii(message);
    //int h=0;

    for (i=0; i<= message.size(); i++){
            //cout<<"j: "<<j<<"   i: "<<i<<endl;
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = ((((ascii[i] - key[j++]) + 26) % 26) + 65);
            }
            //cout<<"ascii("<<h++<<"): "<<ascii[i]<<endl;
            if(j>3)
            j=0;


    }
    decrypted = AT(ascii);
}
