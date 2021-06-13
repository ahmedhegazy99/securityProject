#include "sBoxCipher.h"
#include "cipher.h"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

sBoxCipher::sBoxCipher()
{
    getKey();
}

void sBoxCipher :: getKey(){
    bool keyValidated = false;
    cout << "Enter sBox key (3 binary digit) : ";
    cin >>key;
    keyValidated = keyVaildation();
    while(keyValidated == false){
        cout<<"Wrong Key! try another(3 binary digit) : "<<endl;
        cin >>key;
        keyValidated = keyVaildation();
    }

}

bool sBoxCipher :: keyVaildation(){
    if(key.length() != 3 ){
            return false;
    }
    else{
        for(int i=0;i<key.length();i++){
            if(!isdigit(key[i])){
                return false;
                break;
            }
            else{
                if(!(key[i] == '0' || key[i] == '1')){
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}

void sBoxCipher :: convertPlainTextToBinary(string plainText){

    for(int i=0;i<plainText.length();i++){
        string charBinary = bitset<8>(plainText[i]).to_string();
        plainTextBinary.push_back(charBinary);
    }
}

bool sBoxCipher :: isSymbol(string character){
    for(int i=0;i<11;i++){
        if(character == symbols[i]){
            return true;
            break;
        }
    }
    return false;
}

vector<string> sBoxCipher :: splitBinaryToFourDigit(vector<string> list){
    vector<string> splitedArray;
    for(int i  = 0 ; i<list.size();i++){
        if(isSymbol(list[i])){
            string str1 = list[i];
            splitedArray.push_back(str1);
        }else{
            string str1 = list[i].substr(0,list[i].size()/2);
            string str2 = list[i].substr(list[i].size()/2,list[i].size());

            splitedArray.push_back(str1);
            splitedArray.push_back(str2);
        }
    }
    return splitedArray;
}

string sBoxCipher :: xorResult(int x,int k){
     if(!x != !k){
         return "1";
    }
    else{
        return "0";
    }
}

string sBoxCipher :: findt1t2(){
    for(int i = 0 ;i<8;i++){
        if(box[0] == sBox[i][0] && box[1] == sBox[i][1] && box[2] == sBox[i][2]){
            return sBox[i][3];
            break;
        }
    }
}

vector<string> sBoxCipher :: concatString(vector<string> list){
    vector<string> concArray;
    for(int i=0;i<list.size();i=i+2){
        if(list[i].size() == 8){
            concArray.push_back(list[i]);
            i--;
        }
        else{
            string str1 = list[i];
            string str2 = list[i+1];
            string str = str1+str2;

            concArray.push_back(str);
        }
    }
    return concArray;
}

string sBoxCipher :: convertBinaryVectorToDecimalString(vector<string> list){
    string text;

    for(int i=0;i<list.size();i++){
        text = text.append(to_string(bitset<8>(list[i]).to_ullong()));
        text = text.append("  ");
    }

    return text;
}

string sBoxCipher :: convertBinaryVectorToString(vector<string> list){
    string text;
    for(int i=0;i<list.size();i++){
        text = text.append(bitset<8>(list[i]).to_string());
        text = text.append("   ");
    }
    return text;
}

string sBoxCipher :: reverseXor(int t,int u){
    if(u==0 ){
        return to_string(t);
    }
    else if(u==1 ){
        if(t==1) return "0";
        else return "1";
    }
}

string sBoxCipher :: convertBinaryToPlainText(vector<string> list){
    string str;
    for(int i = 0;i<list.size();i++){
        char c  = static_cast<char>(bitset<8>(list[i]).to_ullong());
         str =str+ c;
    }
    return str;
}

void sBoxCipher :: Encrypt(string message){
    convertPlainTextToBinary(message);
    plainTextBinary = splitBinaryToFourDigit(plainTextBinary);

    int k1 = (int) key[0] - 48;
    int k2 = (int) key[1] - 48;
    int k3 = (int) key[2] - 48;

    for(int i = 0 ;i<plainTextBinary.size();i++){
        if(isSymbol(plainTextBinary[i])){
            encrypted.push_back(plainTextBinary[i]);
        }
        else{
            string str = plainTextBinary[i];
            int x1 = (int) str[0] - 48;
            int x2 = (int) str[1] - 48;
            int x3 = (int) str[2] - 48;
            int x4 = (int) str[3] - 48;

            box[0] = xorResult(x3,k1);
            box[1] = xorResult(x4,k2);
            box[2] = xorResult(x3,k3);

            string t1t2 = findt1t2();

            int t1 = (int) t1t2[0] - 48;
            int t2 = (int) t1t2[1] - 48;

            string u1 = xorResult(x1,t1);
            string u2 = xorResult(x2,t2);
            string u1u2 = u1+u2;
            string encryptedBinary = to_string(x3)+to_string(x4)+u1u2;
            encrypted.push_back(encryptedBinary);

        }
    }

    encrypted = concatString(encrypted);
    encryptedDec = convertBinaryVectorToDecimalString(encrypted);
    encryptedStr = convertBinaryVectorToString(encrypted);

}

void sBoxCipher :: Decrypt(vector<string> message){

    message = splitBinaryToFourDigit(message);

    int k1 = (int) key[0] - 48;
    int k2 = (int) key[1] - 48;
    int k3 = (int) key[2] - 48;

    for(int i = 0;i<message.size();i++){
        if(isSymbol(message[i])){
            decryptedBin.push_back(message[i]);
        }
        else{
            string str = message[i];
            int x3 = (int)  str[0] -48;
            int x4 = (int)  str[1] -48;
            int u1 = (int) str[2] - 48;
            int u2 = (int) str[3] - 48;

            box[0] = xorResult(x3,k1);
            box[1] = xorResult(x4,k2);
            box[2] = xorResult(x3,k3);

            string t1t2 = findt1t2();
            int t1 = (int) t1t2[0] - 48;
            int t2 = (int) t1t2[1] - 48;

            string x1 = reverseXor(t1,u1);
            string x2 = reverseXor(t2,u2);

            string decryptedBinary = x1+x2+to_string(x3)+to_string(x4);
            decryptedBin.push_back(decryptedBinary);

        }
    }

    decryptedBin = concatString(decryptedBin);
    decryptedStr = convertBinaryVectorToString(decryptedBin);
    decrypted = convertBinaryToPlainText(decryptedBin);
}
