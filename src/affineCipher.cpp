#include "affineCipher.h"
#include "cipher.h"
#include <iostream>
#include <math.h>

using namespace std;

affineCipher::affineCipher()
{
    getKey();
}

void affineCipher :: getKey(){
    cout << "Enter affine key ( 1 integer ): ";
    cin >> key;
    cout << "Enter m ( 1 integer ): ";
    cin >> m;

    //get m inverse
    for (int i = 0; i < 26; i++){
        flag = (m * i) % 26;
        if (flag == 1){ mi = i;}
    }
    while((m*mi)%26 != 1){
        cout << "This number has no inverse." << endl << "Please enter new m: " ;
        cin >> m;
        mi = 0;
        flag = 0;
        for (int i = 0; i < 26; i++){
            flag = (m * i) % 26;
            if (flag == 1){ mi = i;}
        }
    }

}

void affineCipher :: Encrypt(string message){
    unsigned int i;
    cAscii(message);

    for (i=0; i< message.size(); i++){
        if(ascii[i] == 95 || ascii[i] == 32){
            ascii[i] = ascii[i];
        }else{
            if (isupper(ascii[i]))
                ascii[i] = ((((m * (ascii[i]-65) ) + key) % 26) + 65);
            else
                ascii[i] = ((((m * (ascii[i]-97) ) + key) % 26) + 97);
        }
    }
    encrypted = AT(ascii);
}

void affineCipher :: Decrypt(string message){
    unsigned int i;

    cAscii(message);

    for (i=0; i< message.size(); i++){
        if(ascii[i] == 95 || ascii[i] == 32){
            ascii[i] = ascii[i];
        }else{
            if (isupper(ascii[i]))
                ascii[i] = (((mi * ((ascii[i]+65 - key)) % 26)) + 65);
            else{
                ascii[i] = ((((mi * (ascii[i]+97)) - key) % 26) + 97);

            }
        }
    }
    decrypted = AT(ascii);
}
