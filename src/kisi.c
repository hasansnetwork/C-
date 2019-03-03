#include "kisi.h"


void yapiciFonksiyon4(struct Kisi * kisi) // Malloc ile bellekte yer ayirdik
{
	kisi->Isim=malloc(sizeof(char)*20);
	kisi->Soyisim=malloc(sizeof(char)*20);
	kisi->TcKimlikNo=malloc(sizeof(int)*11);
	kisi->TelefonNo=malloc(sizeof(int)*11);
	kisi->ImeiNo=malloc(sizeof(int)*15);	
}
void KisiOlustur (struct Kisi * kisi)  //Isim Soyisim atamasi 
{
	FILE *dosya;   // Dosya islemi icin dosya tanimladik
	
	int i,r; char kelimeIsim[3004][20],kelimeSoy[3004][20];
	i=0;
	if((dosya=fopen("random_isimler.txt","r"))!=NULL)	
		{
	
			
			r=rand()%2997;
			
			for(i=0;i<r;i++)
			{		
					
					fscanf(dosya,"%s %s",&kelimeIsim[r],&kelimeSoy[r]);
					
				
			}
			
			strcpy(kisi->Isim,kelimeIsim[r]);
			strcpy(kisi->Soyisim,kelimeSoy[r]);
			
			r++;
		
		}
	
	
	struct TcKimlik tc;

	tc.yapiciFonksiyon=yapiciFonksiyon;

	tc.yapiciFonksiyon(&tc);

	tc.TcOlustur=TcOlustur;

	tc.TcOlustur(&tc);

	for(i=0;i<11;i++)
		kisi->TcKimlikNo[i]=tc.Tc[i];

	tc.yikiciFonksiyon=yikiciFonksiyon;

	tc.yikiciFonksiyon(&tc);
	
	kisi->yas=rand()%100;
	
	struct Telefon tel;
	
	tel.yapiciFonksiyon3=yapiciFonksiyon3;
	
	tel.yapiciFonksiyon3(&tel);
	
	tel.TelefonOlustur=TelefonOlustur;
	
	tel.TelefonOlustur(&tel);
	
		for(i=0;i<11;i++)
			kisi->TelefonNo[i]=tel.telefon[i];
	
	tel.yikiciFonksiyon3=yikiciFonksiyon3;
	
	tel.yikiciFonksiyon3(&tel);
	
	struct IMEI imei;
	
	imei.yapiciFonksiyon2=yapiciFonksiyon2;
	
	imei.yapiciFonksiyon2(&imei);
	
	imei.ImeiOlustur=ImeiOlustur;
	
	imei.ImeiOlustur(&imei);
	
		for(i=0;i<15;i++)
			kisi->ImeiNo[i]=imei.imei[i];
	
	imei.yikiciFonksiyon2=yikiciFonksiyon2;

	imei.yikiciFonksiyon2(&imei);
		
}
void yikiciFonksiyon4(struct Kisi * kisi)  //Ayirdigimiz bellegi serbest biraktik
{
	free(kisi->Isim);

	free(kisi->Soyisim);

	free(kisi->TcKimlikNo);

	free(kisi->TelefonNo);

	free(kisi->ImeiNo);
}

