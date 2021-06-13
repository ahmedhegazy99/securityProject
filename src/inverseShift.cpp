#include "inverseShift.h"
#include <iostream>

using namespace std;

inverseShift::inverseShift()
{
     getKey();
}

void inverseShift :: getKey(){
    cout << "Enter inverseShift key ( 1 integer ): ";
    cin >> key ;
}

void inverseShift :: Encrypt(string message){
    int j = 0;
    string temp = message;
    for(int i = message.length()-1 ; i>=0 ; i--){
        message[j] = temp[i];
        j++ ;
    }
    cAscii(message);

    for (int i=0 ; i< message.size() ; i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = ascii[i] + key;
                 if(ascii[i] > 90 ){
                    ascii[i] = ascii[i] - 26;
                }
            }
    }
    encrypted = AT(ascii);
}

void inverseShift :: Decrypt(string message){
    int j = 0;
    string temp = message;
    for(int i = message.length()-1 ; i>=0 ; i--){
        message[j] = temp[i];
        j++ ;
    }
    cAscii(message);

    for (int i=0; i< message.size(); i++){
            if(ascii[i] == 95 || ascii[i] == 32){
                ascii[i] = ascii[i];
            }else{
                ascii[i] = ascii[i] - key;
                if(ascii[i] < 65 ){
                    ascii[i] = ascii[i] + 26;
                }
            }
    }
    decrypted = AT(ascii);
}
