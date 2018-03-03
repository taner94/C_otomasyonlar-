#include <stdio.h>
#include <windows.h>
struct OGRENCI {
    char K_adi[20]; 
    char Sifre[20];
}kisi[10],yedek[10];


void kayit_ekle();
void listele();
char menu();
int   sayac;


int main()
{
    char secim;
    do{
        secim=menu();
        switch(secim)
		{
            case '1':kayit_ekle();  break;
            case '2':listele();     break;
        }
    }while(secim<='2' && secim>='1');
 
    }
char menu()
{
    char tus;
    printf("Kayit ekle---<1>\nListele------<2>\n");
    tus=getch();
    return tus;
}
void kayit_ekle()
{
    char tus2;
    FILE *dosya;
    dosya=fopen("a.txt","w");
    do{
	    printf("%d.kisi adi giriniz      :",sayac+1);scanf("%s",kisi[sayac].K_adi);
        printf("%d.kisinin bölüm giriniz :",sayac+1);scanf("%s",kisi[sayac].Sifre);
        printf("yeni kayit için e basin ve menüye donmek için herhangi bir tusa basin \n");tus2=getch();
        fprintf(dosya,"%s\t%s\n",kisi[sayac].K_adi,kisi[sayac].Sifre);
		sayac++;
    }while(tus2=='e' || tus2=='E');
    fclose(dosya);
}
void listele()
{
    FILE *dosya;
    dosya=fopen("a.txt","r");
    int a=0,i;
    while(!feof(dosya))
    {
        fscanf(dosya,"%s%s",yedek[a].K_adi,yedek[a].Sifre);
        a++;      
    }
    for(i=0;i<(a-1);i++)
        printf("%d\t%s\t%s\n",i+1,yedek[i].K_adi,yedek[i].Sifre);
    fclose(dosya);
}
