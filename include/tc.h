#ifndef TC_H
#define TC_H
#include "stdio.h"
#include "stdlib.h"


struct TcKimlik
{

    int * Tc;
    void (*TcOlustur)(struct TcKimlik * tc );
    void (*yapiciFonksiyon)(struct TcKimlik *tc);
    void (*yikiciFonksiyon)(struct TcKimlik *tc);

};

void yapiciFonksiyon(struct TcKimlik *tc);
void TcOlustur(struct TcKimlik  *tc);
void yikiciFonksiyon(struct TcKimlik *tc);


#endif


