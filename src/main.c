#include<stdio.h>
#include "windows.h"
#include<stdlib.h>
#include<time.h>
#include "tc.h"
#include "imei.h"
#include "tel.h"
#include "kisi.h"

int main()
{
	
	FILE *dosya; // dosyamizi gosterecek dosya isminde pointer

	struct Kisi kisi;
	int secim,kSayi;
	
	do{
	printf("1- Rastgele Kisi Uret\n");
	printf("2-Uretilmis Dosya Kontrol Et\n");
	printf("3- CIKIS \n");
	scanf("%d",&secim);
	
	switch(secim)
	{
		int i,j,r; char tcTut[12],imeiTut[16],telTut[12],yasTut[2];
		srand(time(NULL));  //Random sayilarimizin farkli cikmasi icin
		case 1:
			
			printf("Kisi sayisi giriniz.:");
			scanf("%d",&kSayi);
			printf(" Tahmini tamamlama suresi %d saniye. \n",kSayi);
			for(j=0;j<kSayi;j++)
			{	
			
				dosya=fopen("kisiler.txt","a");
				
				kisi.yapiciFonksiyon4=yapiciFonksiyon4;
				
				kisi.yapiciFonksiyon4(&kisi);
				
				kisi.KisiOlustur=KisiOlustur;
				
				kisi.KisiOlustur(&kisi);	
				
				printf("%s %s ",kisi.Isim,kisi.Soyisim);
		
	
				for(i=0;i<11;i++)
				{
					printf("%d",kisi.TcKimlikNo[i]);
					tcTut[i]=kisi.TcKimlikNo[i]+'0';
				
				}
				
				tcTut[11]='\0';
			
				printf(" %d ",kisi.yas);
			
				for(i=0;i<11;i++)
				{
					printf("%d",kisi.TelefonNo[i]);
					telTut[i]=kisi.TelefonNo[i]+'0';
				}
			
				telTut[11]='\0';
			
				printf(" ");
			
				for(i=0;i<15;i++)
				{
					printf("%d",kisi.ImeiNo[i]);
					imeiTut[i]=kisi.ImeiNo[i]+'0';
				}
				imeiTut[15]='\0';
	

				fprintf(dosya,"%s %s %s %d %s %s \n",tcTut,kisi.Isim,kisi.Soyisim,kisi.yas,telTut,imeiTut);	
			
				printf("\n");
			
				kisi.yikiciFonksiyon4=yikiciFonksiyon4;
			
				kisi.yikiciFonksiyon4(&kisi);
			
				fclose(dosya);
			
				Sleep(100);
			
				srand((unsigned) time(NULL));
			
				Sleep(900);
			
			
		}
		
		
		break;
		
				int counter,dogruMu,dogruMuI;
		
				int tekTop;int ciftTop;	
			
		
				char imeiKontrol[3004][15],tcKontrol[3000][11],isimK[20],syim[20],yas[2],tel[11];
			
				int imeiTest[3000][15],tcTest[3000][11];
		// KONTROL
			case 2:
			
			
				dosya=fopen("kisiler.txt","r");  //Dosyayi okuma modunda acar
				i=0; counter=0;
				while(!feof(dosya)) //Dosya sonuna kadar git
				{	
			
					fscanf(dosya,"%s %s %s %s %s %s",&tcKontrol[i],&isimK,&syim,&yas,tel,&imeiKontrol[i]);  // Satir okuma islemi

					counter++;
					i++;
		
				}		
			
	        	if(tcKontrol[0][0]==0) dogruMu= 0;
	        	int gecerliTc,gecersizTc,gecerliImei,gecersizImei;
		    	tekTop=0; ciftTop=0; gecerliTc=0; gecersizTc=0;   gecerliImei=0; gecersizImei=0;
		
				for(j=0;j<counter-1;j++)  // Ana Döngü
				{
					for(i=0;i<9;i++)
					{
							tcTest[j][i]=tcKontrol[j][i]-'0';
							
						if (i%2==0)//tek ise
    					{
    						tekTop=tcTest[j][i]+tekTop;   //Tek basamaklar toplami bulunur.
    						
						}
    				
   				        if (i%2==1)//Çift ise
    					{
    					ciftTop=tcTest[j][i]+ciftTop;   //Cift basamaklar toplami bulunur.
   	         	 		
						}
					
					}
					
					for(i=0;i<11;i++)
					{
						tcTest[j][i]=tcKontrol[j][i]-'0';    //Char to int donusumu
					//	printf(" s %d , i %c \n",tcTest[j][i],tcKontrol[j][i]);
					}
	
					if((tekTop*7-ciftTop)%10!=tcTest[j][9]) 
					{
							dogruMu= 0;  //Kurala uymaz ise		
							printf("gecersiz tc \n");
					}
			
       				else if((tekTop+ciftTop+tcTest[j][9])%10!=tcTest[j][10]) 
				   {	
					   dogruMu= 0;  //Kurala uymaz ise
					   printf("gecersiz kontrol2 \n");
					}
					else
					{
						gecerliTc++;
						
					}
				
					if(dogruMu==0)
					gecersizTc++;
		
			
					tekTop=0; ciftTop=0;
				
				
			
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/* BURDAN SONRASI Imei */
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					dogruMuI= 1; dogruMu=1;
					for(i=0;i<15;i++)
					{
						
						imeiTest[j][i]=imeiKontrol[j][i]-'0';
					//	printf(" ,ImeiTest %d \n",imeiTest[j][i]);
						
					}
					for(i=0;i<14;i++)
					{
						//printf("Hane kontrol..:%d",imeiTest[j][i]);
						if(i%2==0) tekTop+=imeiTest[j][i];  //Tek basamaklar topla
						
						if(i%2==1) ciftTop+= ((imeiTest[j][i]*2)%10 + (imeiTest[j][i]*2)/10); // cift basamak islemi
					//	printf("\nTEk.: %d , Cift.:%d  :",tekTop,ciftTop);
						
					}
					
					if(((tekTop+ciftTop)%10)!=0)
        			{
            			if(imeiTest[j][14]!=(10-((tekTop+ciftTop)%10))) 
            			{	
						dogruMuI= 0;   // son basamak kurala uyuyormu uymuyormu
            	
						}
				
        			}
        			else 
        			{
        				if(imeiTest[j][14]!=0)
            			{
           		 		dogruMuI= 0; 
           		
           				}
			    	
					}
				
				
        		
					if(dogruMuI==0)
        			{
						gecersizImei++;
						//printf("DENEM ... . 3\n");
					}
					else
					{
						gecerliImei++;	
					}
			
				
					tekTop=0; ciftTop=0;
			}
			printf("T.C. Kimlik Kontrol\n %d Gecerli  %d Gecersiz \n",gecerliTc,gecersizTc);
			printf("IMEI Kontrol \n %d  Gecerli %d Gecersiz\n",gecerliImei,gecersizImei);
			
			
		
			break;
			
			case 3:
				exit(0);
			
			break;
				default:
		
				printf("Hatali Secim!!!");
		
				break;
						
	}
	
	
	}while(secim==1||secim==2);
	
	system("pause");
	
	return 0 ;
}
