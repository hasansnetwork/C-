#ifndef TEL_H
#define TEL_H
#include "stdio.h"
#include "stdlib.h"

struct Telefon
{
    int * telefon;
    void (*yapiciFonksiyon3)(struct Telefon * telefon);
	void (*TelefonOlustur)(struct Telefon * telefon);
	void (*yikiciFonksiyon3)(struct Telefon * telefon);
};

void yapiciFonksiyon3(struct Telefon * telefon);
void TelefonOlustur(struct Telefon * telefon);
void yikiciFonksiyon3(struct Telefon * telefon);

#endif


