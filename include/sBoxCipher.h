#ifndef SBOXCIPHER_H
#define SBOXCIPHER_H
#include "cipher.h"
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>


class sBoxCipher : public cipher
{
    public:
        sBoxCipher();
        void Encrypt(string message);
        void Decrypt(vector<string> message);
        vector<string> encrypted;
        string encryptedStr = "";
        string encryptedDec = "";
        string decrypted = "";
        string decryptedStr = "";


    private:
        vector<string> decryptedBin;
        void getKey();
        void convertPlainTextToBinary(string plainText);
        bool isSymbol(string character);
        bool keyVaildation();
        string key;
        string box[3];
        vector<string> plainTextBinary;

        string symbols [11] = {
            "00101110","00100111","00111010","00111011","00111111","00100001",
            "00101100","00100010","00101000","00101001","00100000"
            };

        string sBox[8][4] = {
                {"0","0","0","11"},{"0","0","1","01"},{"0","1","0","00"},{"0","1","1","10"},
                {"1","0","0","01"},{"1","0","1","00"},{"1","1","0","11"},{"1","1","1","10"}
                };

        vector<string> splitBinaryToFourDigit(vector<string> list);
        vector<string> concatString(vector<string> list);
        string xorResult(int x,int k);
        string findt1t2();
        string reverseXor(int t,int u);
        string convertBinaryToPlainText(vector<string> list);
        string convertBinaryVectorToDecimalString(vector<string> list);
        string convertBinaryVectorToString(vector<string> list);
};

#endif // SBOXCIPHER_H

