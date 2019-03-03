#include "imei.h"

void yapiciFonksiyon2(struct IMEI * Imei)
{
	Imei->imei=malloc(sizeof(int)*15);
}
void ImeiOlustur(struct IMEI * Imei)
{
	
	int i,r ;
	for (i = 0; i < 14; i++) //14 haneye random rakam atarız
    {
        r=rand()%10;
        Imei->imei[i]=r;
    }
    int tekTop=0,ciftler=0;
    for (i = 0; i < 14; i++) 
    {  
        if(i%2==0) tekTop+=Imei->imei[i];  //Tek hane kontrolu
        if(i%2==1) ciftler+= (Imei->imei[i]*2)%10 + (Imei->imei[i]*2)/10; //Cift hanelerin kontrol islemi
    }
    if(((tekTop+ciftler)%10)==0)
	{
        Imei->imei[14]=0;
    }
	else
	{
        Imei->imei[14]=10-(tekTop+ciftler)%10;  //15.haneyi bulup diziye atama yaptık
    }
  
}
void yikiciFonksiyon2(struct IMEI * Imei)  //Ayirdigimiz bellegi serbest biraktik
{
	free(Imei->imei);
}
