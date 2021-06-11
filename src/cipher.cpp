#include "cipher.h"
#include <iostream>
using namespace std;

cipher::cipher(){}

void cipher::getKey(){
    cout << "Enter key: ";
    cin >> key;
}

void cipher::cAscii(string message){
    for(int i = 0 ; i< message.length() ; i++ ){
        ascii[i]= (int)message[i];
    }
}

string cipher::AT(int ascii[]){
    string text="00000000000000000";
    for(int i = 0 ; i< 17 ; i++ ){
        text[i]= char(ascii[i]);
    }
    return text;
}

void Encrypt(string message){}
void Decrypt(string message){}
void cBinary(int ascii){}
void BA(int bin){}




