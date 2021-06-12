/*#include "sBoxCipher.h"
#include "cipher.h"
#include <iostream>

sBoxCipher::sBoxCipher()
{

}

void sBoxCipher::cBinary(int *ascii){
    for(int j=0; j< sizeof(ascii) / sizeof(ascii[0]); j++){
        for (int i=0; i<8; i++){
            //bintemp[i] = ascii[j] % 2;
            bintemp.insert(i, (ascii[j] % 2))
            ascii[j] = ascii[j] / 2;
        }
        bin = bintemp;
    }
    for (int i=0; i<8; i++){
        cout<<bintemp[i]<<" , "<<bin[i]<<endl;
    }
}
*/
