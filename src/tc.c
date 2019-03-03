#include "tc.h"

void yapiciFonksiyon(struct TcKimlik  *tc)  //Tc icin malloc ile yer ayrilir
{
	tc->Tc=malloc(sizeof(int)*11);  
}

void TcOlustur(struct TcKimlik  *tc )  //Tc olusturma
{

	int i,r;
	for (i=0; i<9 ; i++)
    {
    
        r=rand()%10;
    	tc->Tc[i]=r;
        while (tc->Tc[0]==0)  //Tc kimlik numarasinin ilk hanesi sifir ise farkli rakamlar atanir
        {
            r=rand()%10;
    		tc->Tc[0]= r;
        }
    }
    int tekTop=0;
    int ciftTop=0;
    int sonhane;
    for(i=0; i<9; i++)
    {
        if (i%2==0)
			tekTop+=tc->Tc[i];  //Tc kimlik numarasinin icindeki tek haneler toplanır
        if(i%2==1)      
            ciftTop+=tc->Tc[i];  //Tc kimlik numarasi icindeki cift haneler toplanır
    }
    tc->Tc[9]=(tekTop*7-ciftTop)%10;  // 10.hane hesaplama kuraliimiz   
    int toplam=0;
	for (i = 0; i < 10; i++)   
    {               
        toplam+=tc->Tc[i];  //
    }
	tc->Tc[10]=toplam%10;    //11. Hane kuralimiz    
}

void yikiciFonksiyon(struct TcKimlik *tc)  //Ayirdigimiz bellegi iade etmek icin gerekli fonksiyon
{
	free(tc->Tc);
}



