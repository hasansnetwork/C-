#include "tel.h"

void yapiciFonksiyon3(struct Telefon * telefon) //Telefon no icin malloc ile yer ayirdik
{
	telefon->telefon=malloc(sizeof(int)*11);
}
void TelefonOlustur(struct Telefon * telefon)  //Telefon numarasi olusturma fonksiyonumuz
{
	int i,r;
	
	char gsmKod [][4]={"0531","0532","0533","0534","0535","0536","0537","0538","0539",
            "0541","0542","0543","0544","0545","0546",
            "0505","0506","0507",
            "0551","0552","0553","0554","0555","0556","0557","0558","0559"};
    r=rand()%27;
    for(i=0;i<4;i++)
    {
    	telefon->telefon[i]=gsmKod[r][i]-48;    //Char to int
	}
	for(i=4;i<11;i++)
	{
		telefon->telefon[i]=rand()%10;
	}
}

void yikiciFonksiyon3(struct Telefon * telefon)    //Ayirdigimiz bellegi isimiz bitince iade ettik
{
	free(telefon->telefon);
}

