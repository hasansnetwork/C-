#ifndef IMEI_H
#define IMEI_H
#include "stdio.h"
#include "stdlib.h"

struct IMEI
{
    int * imei;
    void (*yapiciFonksiyon2)(struct IMEI * Imei);
	void (*ImeiOlustur)(struct IMEI * Imei);
	void (*yikiciFonksiyon2)(struct IMEI * Imei);
};

void yapiciFonksiyon2(struct IMEI * Imei);
void ImeiOlustur(struct IMEI * Imei);
void yikiciFonksiyon2(struct IMEI * Imei);

#endif


