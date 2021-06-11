#include "cipher.h"
#include <iostream>
using namespace std;

cipher::cipher(){}

void getKey(){
    cout << "Enter key: ";
    cin >> key;
}

void cAscii(string message){
    for(int i = 0 ; i< message.length() ; i++ ){
        cipher.ascii[i]= (int)message[i];
        //cout << ascii[i] << endl;
    }
}

string AT(int ascii[]){
    string text;
    for(int i = 0 ; i< ascii.length() ; i++ ){
        text[i]= char(ascii[i]);
        //cout << message[i] << endl;
    }
    return text;
}

//void Encrypt(string message){}
//void Decrypt(string message){}
//void cBinary(int ascii){}
//void BA(int bin){}




