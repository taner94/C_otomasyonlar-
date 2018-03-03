#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <conio.h> 

struct ogrblg{ 
    char isim[30]; 
    int vize[50]; 
    int odev[50]; 
    int indis1; 
    int indis2; 
    int final; 
    int knt; 
}; 

struct ortalama{ 
    char isim[30]; 
    float not; 
}; 

void ortalamalistele(void); 
void kayit(void); 
void listele(void); 
void notgir(void); 
void ortalamalar(void); 

FILE *fptr; 

void main() 
{ 

   int a; 
    if((fptr = fopen("notlar.dat","r+b")) == NULL) 
        if((fptr = fopen("notlar.dat","w+b")) == NULL) { 
        printf("Dosya acilamadi"); 
        exit(EXIT_FAILURE);
		}  
        while( a != 7)
		{ 
        printf("\n\t\t Not Girisi      [1]      \n\t\t Notlari Listele [2]      \n\t\t Cikis           [3]      \n");  
        printf(" "); 
        scanf("%d",&a); 
        printf("\n"); 
        switch(a){ 
            case 1: notgir(); break; 
            case 2: listele();break; 
            case 3: exit(0);  break; 
            default : printf("Gecerli karakter girmediniz .!\n\n");break; 
        } 
        } 
   fclose(fptr); 

} 



void kayit(void) 
{ 
    struct ogrblg ogrenci; 
    printf("\nOgrenci Ismi   :   "); 
    fflush(stdin); 
    gets(ogrenci.isim); 
    ogrenci.indis1 = 0; 
    ogrenci.indis2 = 0; 
    fseek(fptr,0,SEEK_END); 
    fwrite(&ogrenci,sizeof(struct ogrblg),1,fptr); 
    printf("\n"); 
} 

void notgir(void) 
{ 

   char name[30]; 
   int s; 
   struct ogrblg ogrenci; 
   printf("\nOgrenci Ismi               :  "); 
   fflush(stdin); 
   gets(name); 
   fseek(fptr,0,SEEK_SET); 

   while(fread(&ogrenci,sizeof(struct ogrblg),1,fptr) > 0)
   { 
        if(!stricmp(ogrenci.isim,name))
		{ 
            if(ogrenci.knt == 1)
			{ 
                printf("\nFinal notu bilgisi mevcut .\n\n"); 
                return; 
            } 
            printf("\nVize(1)  Odev(2)  Final(3) :  "); 
            scanf("%d",&s); 
            if(s == 1)
			{ 
                printf("\nVize  Notu                 :  "); 
                ogrenci.indis1++; 
                scanf("%d",&ogrenci.vize[ogrenci.indis1]); 
            }
			else if(s == 2)
			{ 
                printf("\nOdev  Notu                 :  "); 
                ogrenci.indis2++; 
                scanf("%d",&ogrenci.odev[ogrenci.indis2]); 
            } 
			else if(s == 3)
			{ 
                printf("\nFinal Notu                 :  "); 
                scanf("%d",&ogrenci.final); 
                ogrenci.knt = 1; 
            } 
            fseek(fptr,-(long)sizeof(struct ogrblg),1); 
            fwrite(&ogrenci,sizeof(struct ogrblg),1,fptr); 
            printf("\nKaydedildi .\n\n"); 
            return; 
        } 
    }
    printf("\nBoyle bir ogrenci kayitli degil . \n\n"); 
} 

void listele(void) 
{ 
    struct ogrblg ogrenci; 
    int m=0,n=0; 

    fseek(fptr, 0L, SEEK_SET); 
    while(fread(&ogrenci,sizeof(struct ogrblg),1,fptr)>0)
	{ 
        printf("%s ",ogrenci.isim); 
        while(ogrenci.indis1 > m)
		{ 
        printf("vz %d ",ogrenci.vize[m+1]); 
        m++; 
        } 
        while(ogrenci.indis2 > n)
		{ 
            printf("od %d ",ogrenci.odev[n+1]); 
            n++; 
        } 
        if(ogrenci.knt == 1)
		{ 
            printf("fn %d SON",ogrenci.final); 
        } 
        m=0;n=0; 
        printf("\n\n"); 
    } 
} 

void ortalamalar(void) 
{ 

    struct ogrblg ogrenci; 
    struct ortalama ort; 
    FILE *optr; 
    int m=0,n=0; 
    char a; 
    float ortalama=0,odev=0,vize=0; 
    if((optr = fopen("ortalamalar.dat","w+b")) == NULL)
	{ 
        printf("Dosya acilamadi .!"); 
        exit(EXIT_FAILURE); 
    }
	else
	{ 
        fseek(fptr, 0, SEEK_SET); 
        fseek(optr, 0, SEEK_SET); 
        while(fread(&ogrenci,sizeof(struct ogrblg),1,fptr)>0)
		{ 
            if(ogrenci.indis1 != 0)
			{ 
                while(ogrenci.indis1 > m)
				{ 
                    vize+=(ogrenci.vize[m+1]); 
                    m++; 
				} 
                vize=vize/(ogrenci.indis1); 
                m=0; 
			} 
            if(ogrenci.indis2 != 0)
			{ 
                while(ogrenci.indis2 > m)
				{ 
                odev+=(ogrenci.odev[m+1]); 
                m++; 
                } 
                odev=odev/(ogrenci.indis2); 
                 m=0;
			} 
           if(ogrenci.knt != 1)
		    {  
                printf("(%s) icin final notu bilgisi eksik .!\n",ogrenci.isim); 
            }
			else
			{ 
                ortalama=(vize*35)/100 + (odev*15)/100 + (ogrenci.final)/2; 
                sscanf(ogrenci.isim,"%s ",ort.isim); 
                ort.not=ortalama; 
                fwrite(&ort,sizeof(struct ortalama),1,optr); 
				odev=0,vize=0; 
			} 
		} 
	}
    fclose(optr); 
    printf("\n(ortalamalar.dat) Dosyasi Basariyla Olusturuldu .\n\n\n"); 
    return; 
} 

void ortalamalistele(void) 
{ 
    FILE *optr; 
    struct ortalama ort; 
    if((optr = fopen("ortalamalar.dat","r+b")) == NULL)
	{ 
        printf("Dosya Acilamiyor .!\n"); 
        exit(EXIT_FAILURE); 
    }
	else
	{ 
	    fseek(optr,0,SEEK_SET); 
        printf("\n%-17s%15s\n","Isim","Ortalama"); 
        printf("\n"); 
        while(fread(&ort,sizeof(struct ortalama),1,optr)>0)
		{ 
            printf("%-17s%15.2f\n\n",ort.isim,ort.not); 
		} 
    } 
    fclose(optr); 
    return; 
}
