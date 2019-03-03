#ifndef KISI_H
#define KISI_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tc.h"
#include "imei.h"
#include "tel.h"

struct Kisi
{
	char * Isim;
	char * Soyisim;
	int yas;
	int * TcKimlikNo;
	int * TelefonNo;
	int * ImeiNo;		
	
	void (*yapiciFonksiyon4)(struct Kisi * kisi);
	void (*KisiOlustur)(struct Kisi * kisi);
	void (*yikiciFonksiyon4)(struct Kisi * kisi);
};

void yapiciFonksiyon4(struct Kisi * kisi);
void KisiOlustur (struct Kisi * kisi);
void yikiciFonksiyon4(struct Kisi * kisi);
#endif
