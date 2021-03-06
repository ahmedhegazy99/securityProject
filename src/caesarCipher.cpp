#include "caesarCipher.h"
#include "cipher.h"
#include <iostream>

using namespace std;

caesarCipher::caesarCipher()
{
    getKey();
}

void caesarCipher :: getKey(){
    cout << "Enter caesar key ( 1 integer ): ";
    cin >> key;
}

void caesarCipher :: Encrypt(string message){
    unsigned int i;
    cAscii(message);

    for (i=0; i< message.size(); i++){
        if(ascii[i] == 95 || ascii[i] == 32){
            ascii[i] = ascii[i];
        }else{
            if (isupper(ascii[i])){
                if(((message[i] - 64 + key) % 26) <= 0)
                    ascii[i]= (((message[i] - 64 + key) % 26)+ 26 + 64);
                else
                    ascii[i]= (((message[i] - 64 + key) % 26)+ 64);
                //cout<<"message[i] - 64 + key = "<<message[i] - 64 + key<<"  "<<"((message[i] - 64 + key) % 26)"<<((message[i] - 64 + key) % 26)<<endl;
            }else
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
            if (isupper(ascii[i])){
                if(((message[i] - 64 - key) % 26) <= 0)
                    ascii[i]= (((message[i] - 64 - key) % 26)+ 26 + 64);
                else
                    ascii[i]= (((message[i] - 64 - key) % 26)+ 64);
            }else{
                if(((message[i] - 96 - key) % 26) <= 0)
                    ascii[i]= (((message[i] - 96 - key) % 26)+ 26 + 96);
                else
                    ascii[i]= (((message[i] - 96 - key) % 26)+ 96);
            }
        }
    }
         decrypted = AT(ascii);
    }


