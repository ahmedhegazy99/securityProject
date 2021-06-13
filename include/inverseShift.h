#ifndef INVERSESHIFT_H
#define INVERSESHIFT_H
#include "cipher.h"

class inverseShift : public cipher
{
    public:
        inverseShift();
        void Encrypt(string message);
        void Decrypt(string message);

    private:
        void getKey();
};

#endif // INVERSESHIFT_H
