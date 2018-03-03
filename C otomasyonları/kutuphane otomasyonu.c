//Library Automations version 1.1

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>

struct kullanici {

	char tckimlik[11];
	char no[11];
	char adi[20];
	char soyad[20];
	char statu[20];
	char adres[100];
	char tel[11];
	char email[40];
	char sifre[15];	

}ogrenciuye,personeluye,uyesildir[BUFSIZ],uyeguncelleme[BUFSIZ]; 

struct infobook {

	char isbnno[25];
	char kitapad[25];
	char yazarad[20];
	char tur[15];
	char yayintarihi[8];
	char yayinevi[20];

}kitap,kitapsildir[BUFSIZ],kitapguncelleme[BUFSIZ],kitapodunc[BUFSIZ],kitaprezerve[BUFSIZ];

struct odunc{

	int o_no;
	char o_isbnno[25];
	char o_tckimlik[11];
	char o_alma[8];
	char o_teslim[8];

}o;

struct rezerve{

	int r_no;
	char r_isbnno[25];
	char r_tckimlik[11];
	char r_alma[8];
	char r_teslim[8];

}r;

void uyeekle();  
void uyesil();
void uyeguncelle();
void kitapekle();
void kitapsil();
void kitapguncelle();
void kitapiade();
void odunckitap();
void rezervekitap();
void kitaparama();
void kitapkatalogu();
void osifredegistir(char []);
void psifredegistir(char []);
int peruyemi(char [],char [],FILE*);
int ogruyemi(char[],char[],FILE*);
void peruyeol();
void ogruyeol();
int menu1();
int menu2();
int menu3();
int sorgulama(char []);
FILE *Kitap;
FILE *Uye;
int sayac=0;
int sayac1=0;
int sayac2=0;

int main()
{
	char oyedek[15];
	char pyedek[15];
	char cevap;
	int x;
	char tc[11];
	char sifre[5];
	int secim1,secim2,secim3;
	int secim;
	secim1=menu1();	 
	if (secim1==1)
	{
		if(sayac==0)
		{
			//kutuphane personelinin Tc Kimlik Numarasi:12345678911 şifresi:12345
			for(;;)
			{
				system("cls");
				printf("\nTC Kimlik Numarasi: ");
				scanf("%s",&tc);
				x=sorgulama(tc);
				if (x==1)
				{
					printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
					Sleep(3000);
				}
				if (x==0)
				{
					break;
				}
			}
			
			printf("\nSifreniz:");
			scanf("%s",&sifre);
			if ((strcmp(tc, "12345678911")==0) && (strcmp(sifre, "12345")==0))
			{
				secim2=menu2();
				switch (secim2)
				{
				case 1:
					
					system("cls");
					printf("Hangi statude uye kaydi yapacaksiniz?");
					printf("\n\n1) Ogrenci\n2) Personel\n");
					printf("Seciminiz : ");
					scanf_s("%d",&secim);
					if (secim==1)
					{
						ogruyeol();
					}
					else if(secim==2)
					{
						peruyeol();
					}
					break;
				case 2:
					uyesil();
					break;
				case 3:
					uyeguncelle();
					break;
				case 4:
					kitapekle();
					break;
				case 5:
					kitapsil();
					break;
				case 6 :
					kitapguncelle();
					break;
				case 7:
					odunckitap();
					break;
				case 8:
					rezervekitap();
					break;
				case 9:
					kitaparama();
					break;
				case 0:
					exit(1);
					break;
				case 11:
					kitapkatalogu();
					break;
				default:
					break;
				}
			}
		}
		else if (sayac!=0)
		{
			secim2=menu2();
			switch (secim2)
			{
			case 1:
				
				system("cls");
				printf("Hangi statude uye kaydi yapacaksiniz?");
				printf("\n\n1) Ogrenci\n2) Personel\n");
				printf("Seciminiz : ");
				scanf_s("%d",&secim);
				if (secim==1)
				{
					ogruyeol();
				}
				else if(secim==2)
				{
					peruyeol();
				}
				break;
			case 2:
				uyesil();
				break;
			case 3:
				uyeguncelle();
				break;
			case 4:
				kitapekle();
				break;
			case 5:
				kitapsil();
				break;
			case 6 :
				kitapguncelle();
				break;
			case 7:
				odunckitap();
				break;
			case 8:
				rezervekitap();
				break;
			case 9:
				kitaparama();
				break;
			case 0:
				exit(1);
				break;
			case 11:
				kitapkatalogu();
				break;
			default:
				break;
			}
		}		
	}

	if (secim1==2)
	{
		if(sayac1==0)
		{
			for(;;)
		{
			system("cls");
			printf("\nTC Kimlik Numarasi: ");
			scanf("%s",&tc);
			x=sorgulama(tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		printf("\nSifreniz:");
		scanf("%s",&sifre);
		x=ogruyemi(tc,sifre,Uye);
		if (x==1)
		{
			secim3=menu3();
			switch (secim3)
			{
			case 1:
				sayac1++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&oyedek);
				osifredegistir(oyedek);
				break;
			case 2:
				sayac1++;
				odunckitap();
				break;
			case 3:
				sayac1++;
				rezervekitap();
				break;
			case 4:
				sayac1++;
				kitaparama();				
				break;
			case 5:				
				sayac1++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}
		if (x==0)
		{
			system("cls");
			printf("Uye degilsiniz. Uye olmak istermisin?(e/h)");
			scanf("%s",&cevap);
			if (cevap=='e')
			{
				sayac1++;
				ogruyeol();
			}
			else if (cevap=='h')
			{
				main();
			}
			else
			{
				printf("Yanlis secim...");
				exit(1);
			}
		}
		}
		else if(sayac1!=0)
		{
			secim3=menu3();
			switch (secim3)
			{
			case 1:				
				sayac1++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&oyedek);
				osifredegistir(oyedek);
				break;
			case 2:
				sayac1++;
				odunckitap();
				break;
			case 3:
				sayac1++;
				rezervekitap();
				break;
			case 4:
				sayac1++;
				kitaparama();
				break;
			case 5:
				sayac1++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}		
	}
	if (secim1==3)
	{
		if(sayac2==0)
		{
			for(;;)
		{
			system("cls");
			printf("\nTC Kimlik Numarasi: ");
			scanf("%s",&tc);
			x=sorgulama(tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		printf("\nSifreniz:");
		scanf("%s",&sifre);
		x=peruyemi(tc,sifre,Uye);
		if (x==1)
		{
			secim3=menu3();
			switch (secim3)
			{
			case 1:
				sayac2++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&pyedek);
				osifredegistir(pyedek);
				break;
			case 2:
				sayac2++;
				odunckitap();
				break;
			case 3:
				sayac2++;
				rezervekitap();
				break;
			case 4:
				sayac2++;
				kitaparama();
				break;
			case 5:
				sayac2++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}
		if (x==0)
		{
			system("cls");
			printf("Uye degilsiniz. Uye olmak istermisin?(e/h)");
			scanf("%s",&cevap);
			if (cevap=='e')
			{
				sayac2++;
				peruyeol();
			}
			else if (cevap=='h')
			{
				main();
			}
			else
			{
				printf("Yanlis secim...");
				exit(1);
			}
		}
		}
		else if(sayac2!=0)
		{
			secim3=menu3();
			switch (secim3)
			{
			case 1:
				sayac2++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&pyedek);
				osifredegistir(pyedek);
				break;
			case 2:
				sayac2++;
				odunckitap();
				break;
			case 3:
				sayac2++;
				rezervekitap();
				break;
			case 4:
				sayac2++;
				kitaparama();
				break;
			case 5:
				sayac2++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}

	}
	if (secim1==4)
	{
		system("cls");
		printf("\n\t\t\t\n\nGule Gule");
		Sleep(2000);
		exit(1);
	}
}
int i;
int menu1()
{
	system("cls");
	int secim1;
	printf("Sisteme hangi statu ile erisimde bulunacaksiniz?\n\n");
	printf("1) Kutuphane Personeli\n\n2) Universite Ogrencisi\n\n3) Universite Personeli\n\n4) Cikis\n\n");
	printf("\tSeciminiz : ");
	scanf_s("%d",&secim1);
	return secim1;
}

int menu2()
{
	system("cls");
	int secim2;
	printf("\n1-Uye Ekle\n2-Uye Sil\n3-Uye Guncelle\n4-Kitap Ekle\n5-Kitap Sil\n6-Kitap Guncelle\n7-Odunc kitap al\n8-Kitap rezerve et\n9-Kitap arama\n0-Cikis\n11-Kitap Katalogu\n\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim2);
	return secim2;
}
j;
int menu3()
{
	system("cls");
	int secim3;
	printf("\n1-Sifre degistir\n");
	printf("\n2-Kitap odunc al\n");
	printf("\n3-Kitap rezerve et\n");
	printf("\n4-Kitap arama\n");
	printf("\n5-Kitap katalogu\n");
	printf("\n6-Cikis\n\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim3);
	return secim3;
}

void uyesil()
{
	system("cls");
	int secim;
	char cevap;
	printf("Hangi statude silme islemi yapacaksiniz?");
	printf("\n\n1) Ogrenci\n2) Personel\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim);
	if (secim==1)
	{
		char sil_tc[11];
		int denetleyici=0;
		char cevap;
		printf("Silinecek kisinin TC Kimlik Numarasini giriniz: ");
		scanf("%s",&sil_tc);
		Uye=fopen("ogrenci uyeler.dat","r+");
		int i=0;
		if (Uye == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  UYE KAYDI SILME\n");
			printf("********************************************************************************************************\n\n");
			while(fscanf(Uye, "%s%s%s%s%s%s%s%s", &ogrenciuye.adi, &ogrenciuye.soyad, &ogrenciuye.tckimlik, &ogrenciuye.email, &ogrenciuye.tel, &ogrenciuye.adres, &ogrenciuye.statu, &ogrenciuye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if(strcmp(ogrenciuye.tckimlik,sil_tc)==0)
				{	
					denetleyici=1;
					strcpy(uyesildir[i].adi," ");		
					strcpy(uyesildir[i].soyad," ");	
					strcpy(uyesildir[i].tckimlik," ");	
					strcpy(uyesildir[i].email," ");	
					strcpy(uyesildir[i].tel," ");	
					strcpy(uyesildir[i].adres," ");	
					strcpy(uyesildir[i].statu," ");	
					strcpy(uyesildir[i].sifre," ");	
				}
				else 
				{		
					strcpy(uyesildir[i].adi,ogrenciuye.adi);				//
					strcpy(uyesildir[i].soyad,ogrenciuye.soyad);		//
					strcpy(uyesildir[i].tckimlik,ogrenciuye.tckimlik);		//
					strcpy(uyesildir[i].email,ogrenciuye.email);		//Eğer isim yoksa o i değerine gore direk ismi uyesildir struct değişkenine kopyalar.
					strcpy(uyesildir[i].tel,ogrenciuye.tel);		//
					strcpy(uyesildir[i].adres,ogrenciuye.adres);		//
					strcpy(uyesildir[i].statu,ogrenciuye.statu);		//	
					strcpy(uyesildir[i].sifre,ogrenciuye.sifre);
				}
				i++;
			}
			fclose(Uye);
			if (denetleyici==0)
			{
				printf("Rehberde %s TC Kimlik numarali bir uye bulunamadi.",sil_tc);
				Sleep(1500);
				uyesil();
			}
			Uye=fopen("ogrenci uyeler.dat","w");
			for(j=0 ; j<i ; j++)
			{
				fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",uyesildir[j].adi, uyesildir[j].soyad, uyesildir[j].tckimlik, uyesildir[j].email, uyesildir[j].tel, uyesildir[j].adres, uyesildir[j].statu, uyesildir[j].sifre);
			}
			fclose(Uye);
			printf("%s TC Kimlik Numarali kisi basariyla silinmistir",sil_tc);
			Sleep(2500);
			system("cls");
		}
	}
	else if (secim==2)
	{
		char sil2_tc[11];
		int denetleyici1=0;
		char cevap1;
		printf("Silinecek kisinin TC Kimlik Numarasini giriniz: ");
		scanf("%s",&sil2_tc);
		Uye=fopen("personel uyeler.dat","r+");
		int i=0;
		if (Uye == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  UYE KAYDI SILME\n");
			printf("********************************************************************************************************\n\n");
			while(fscanf(Uye, "%s%s%s%s%s%s%s%s", &personeluye.adi, &personeluye.soyad, &personeluye.tckimlik, &personeluye.email, &personeluye.tel, &personeluye.adres, &personeluye.statu, &personeluye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if(strcmp(personeluye.tckimlik,sil2_tc)==0)
				{	
					denetleyici1=1;
					strcpy(uyesildir[i].adi," ");		
					strcpy(uyesildir[i].soyad," ");	
					strcpy(uyesildir[i].tckimlik," ");	
					strcpy(uyesildir[i].email," ");	// belirtilen tc kimlik numaradaki kişi yerine boşluk yazar
					strcpy(uyesildir[i].tel," ");	
					strcpy(uyesildir[i].adres," ");	
					strcpy(uyesildir[i].statu," ");	
					strcpy(uyesildir[i].sifre," ");	
				}
				else 
				{		
					strcpy(uyesildir[i].adi,personeluye.adi);				//
					strcpy(uyesildir[i].soyad,personeluye.soyad);		//
					strcpy(uyesildir[i].tckimlik,personeluye.tckimlik);		//
					strcpy(uyesildir[i].email,personeluye.email);		//Eğer isim yoksa o i değerine gore direk ismi uyesildir struct değişkenine kopyalar.
					strcpy(uyesildir[i].tel,personeluye.tel);		//
					strcpy(uyesildir[i].adres,personeluye.adres);		//
					strcpy(uyesildir[i].statu,personeluye.statu);		//	
					strcpy(uyesildir[i].sifre,personeluye.sifre);
				}
				i++;
			}
			fclose(Uye);
			if (denetleyici1==0)
			{
				printf("Rehberde %s TC Kimlik numarali bir uye bulunamadi.",sil2_tc);
				Sleep(1500);
				uyesil();
			}
			Uye=fopen("personel uyeler.dat","w");
			for(j=0 ; j<i ; j++)
			{
				fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",uyesildir[j].adi, uyesildir[j].soyad, uyesildir[j].tckimlik, uyesildir[j].email, uyesildir[j].tel, uyesildir[j].adres, uyesildir[j].statu, uyesildir[j].sifre);
			}
			fclose(Uye);
			printf("%s TC Kimlik Numarali kisi basariyla silinmistir",sil2_tc);
			Sleep(2500);
			system("cls");
			sayac++;
		}
	}
	else
	{
		printf("Yanlis secim");
		exit(1);
	}
	system("cls");
	printf("\n\n     Yeni bir kisi daha silmek istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		uyesil();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}
}

void uyeguncelle()
{
	int x;
	system("cls");
	int denetleyici=0;
	int k=0,denetleyici2=0;
	char cevap;
	char guncelle_tc[11];
	char guncelle2_tc[11];
	int secim;
	printf("Hangi statude guncelleme islemi yapacaksiniz?");
	printf("\n\n1) Ogrenci\n2) Personel\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim);
	if (secim==1)
	{		
		for(;;)
		{
			printf("\nGuncellenicek kisinin TC Kimlik numarasini giriniz:");
			scanf("%s",&guncelle_tc);
			x=sorgulama(guncelle_tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		system("cls");
		Uye = fopen("ogrenci uyeler.dat", "r+");//Dosyayi okuma+yazma modunda açiyoruz...
		if (Uye == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha once varsa guncelleme işlemi yapilabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  KAYIT GUNCELLEME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye, "%s%s%s%s%s%s%s%s", &ogrenciuye.adi, &ogrenciuye.soyad, &ogrenciuye.tckimlik, &ogrenciuye.email, &ogrenciuye.tel, &ogrenciuye.adres, &ogrenciuye.statu, &ogrenciuye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(ogrenciuye.tckimlik, guncelle_tc)==0)//Aranan isimle karşilaştirma yaptirip doğruysa bilgileri değiştiriyoruz
				{	
					//kişi bilgileri değiştirilerek k değerine gore olan struct değişkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					printf("\n%s TC Kimlik Numarali kisi hakkinda yeni bilgileri giriniz.\n",guncelle_tc);
					printf(" Adi:");
					scanf("%s",&uyeguncelleme[k].adi);	
					printf("\n Soyadi:");
					scanf("%s",&uyeguncelleme[k].soyad);				
					for(;;)
					{
						printf("\n TC Kimlik Numarasi: ");
						scanf("%s",&uyeguncelleme[k].tckimlik);	
						x=sorgulama(uyeguncelleme[k].tckimlik);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}			
					printf("\n E-mail Adresi: ");
					scanf("%s",&uyeguncelleme[k].email);
					for(;;)
					{				

						printf("\n Telefon Numarasi:");
						scanf("%s",&uyeguncelleme[k].tel);
						x=sorgulama(uyeguncelleme[k].tel);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}				
					printf("\n Adresi:");
					_flushall();
					gets(uyeguncelleme[k].adres);					
					printf("\n Statusu:");
					_flushall();
					gets(uyeguncelleme[k].statu);
					printf("\n Uyelik Sifresi:");
					scanf("%s",&uyeguncelleme[k].sifre);
					printf("\nKisi guncellenmistir.\n\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					strcpy(uyeguncelleme[k].adi,ogrenciuye.adi);			
					strcpy(uyeguncelleme[k].soyad,ogrenciuye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,ogrenciuye.tckimlik);
					strcpy(uyeguncelleme[k].email,ogrenciuye.email);	
					strcpy(uyeguncelleme[k].tel,ogrenciuye.tel);		
					strcpy(uyeguncelleme[k].adres,ogrenciuye.adres);		
					strcpy(uyeguncelleme[k].statu,ogrenciuye.statu);	
					strcpy(uyeguncelleme[k].sifre,ogrenciuye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s TC Kimlik Numarali biri bulunmamaktadir.",guncelle_tc);
			Sleep(1500);
			uyeguncelle();
		}
		Uye=fopen("ogrenci uyeler.dat","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
		for(j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s\n",uyeguncelleme[j].adi, uyeguncelleme[j].soyad, uyeguncelleme[j].tckimlik, uyeguncelleme[j].email, uyeguncelleme[j].tel, uyeguncelleme[j].adres, uyeguncelleme[j].statu, uyeguncelleme[j].sifre);
		}
		fclose(Uye);
	}
	else if (secim==2)
	{
		for(;;)
		{
			printf("\nGuncellenicek kisinin TC Kimlik numarasini giriniz:");
			scanf("%s",&guncelle2_tc);
			x=sorgulama(guncelle2_tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		system("cls");
		Uye = fopen("personel uyeler.dat", "r+");//Dosyayi okuma+yazma modunda açiyoruz...
		if (Uye == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha once varsa guncelleme işlemi yapilabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  KAYIT GUNCELLEME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye, "%s%s%s%s%s%s%s%s", &personeluye.adi, &personeluye.soyad, &personeluye.tckimlik, &personeluye.email, &personeluye.tel, &personeluye.adres, &personeluye.statu, &personeluye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(personeluye.tckimlik, guncelle2_tc)==0)//Aranan isimle karşilaştirma yaptirip doğruysa bilgileri değiştiriyoruz
				{	
					//kişi bilgileri değiştirilerek k değerine gore olan struct değişkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					printf("\n%s TC Kimlik Numarali kisi hakkinda yeni bilgileri giriniz.\n",guncelle_tc);
					printf(" Adi:");
					scanf("%s",&uyeguncelleme[k].adi);	
					printf("\n Soyadi:");
					scanf("%s",&uyeguncelleme[k].soyad);
					for(;;)
					{
						printf("\n TC Kimlik Numarasi: ");
						scanf("%s",&uyeguncelleme[k].tckimlik);	
						x=sorgulama(uyeguncelleme[k].tckimlik);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}			
					printf("\n E-mail Adresi: ");
					scanf("%s",&uyeguncelleme[k].email);				
					for(;;)
					{				

						printf("\n Telefon Numarasi:");
						scanf("%s",&uyeguncelleme[k].tel);
						x=sorgulama(uyeguncelleme[k].tel);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}					
					printf("\n Adresi:");
					_flushall();
					gets(uyeguncelleme[k].adres);				
					printf("\n Statusu:");
					_flushall();
					gets(uyeguncelleme[k].statu);
					printf("\n Statusu:");
					scanf("%s",&uyeguncelleme[k].sifre);
					printf("\nKisi guncellenmistir.\n\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					strcpy(uyeguncelleme[k].adi,personeluye.adi);			
					strcpy(uyeguncelleme[k].soyad,personeluye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,personeluye.tckimlik);
					strcpy(uyeguncelleme[k].email,personeluye.email);	
					strcpy(uyeguncelleme[k].tel,personeluye.tel);		
					strcpy(uyeguncelleme[k].adres,personeluye.adres);		
					strcpy(uyeguncelleme[k].statu,personeluye.statu);
					strcpy(uyeguncelleme[k].sifre,personeluye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s TC Kimlik Numarali biri bulunmamaktadir.",guncelle2_tc);
			Sleep(1500);
			uyeguncelle();
		}
		Uye=fopen("personel uyeler.dat","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
		for(j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",uyeguncelleme[j].adi, uyeguncelleme[j].soyad, uyeguncelleme[j].tckimlik, uyeguncelleme[j].email, uyeguncelleme[j].tel, uyeguncelleme[j].adres, uyeguncelleme[j].statu, uyeguncelleme[j].sifre);
		}
		fclose(Uye);
	}
	system("cls");
	printf("\n\n     Yeni bir kisi daha guncellemek istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		uyeguncelle();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}


}

void kitapekle()
{
	system("cls");
	int denetleyici = 0;
	char cevap;
	Kitap=fopen("kitaplar.dat","a");
	if(Kitap==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		rewind(Kitap);
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP EKLE\n");
		printf("********************************************************************************************************\n\n");
		printf("Kayit edilecek kitabin bilgilerini giriniz...\n\n");
		printf(" ISBN No:");
		scanf("%s",&kitap.isbnno);
		fprintf(Kitap,"%s	",kitap.isbnno);
		printf("\n Adi:");
		_flushall();
		gets(kitap.kitapad);
		fprintf(Kitap,"%s	",kitap.kitapad);
		printf("\n Yazarin Adi-Soyadi:");
		_flushall();
		gets(kitap.yazarad);	
		fprintf(Kitap,"%s	",kitap.yazarad);
		printf("\n Kitabin Turu:");
		_flushall();
		gets(kitap.tur);
		fprintf(Kitap,"%s	",kitap.tur);
		printf("\n Yayinlama Tarihi:");
		scanf("%s",&kitap.yayintarihi);
		fprintf(Kitap,"%s	",kitap.yayintarihi);
		printf("\n Yayinevi:");
		_flushall();
		gets(kitap.yayinevi);			
		fprintf(Kitap,"%s	\n",kitap.yayinevi);
		fclose(Kitap);
		printf("\n Girilen bilgiler dosyaya kaydediliyor...");
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha eklemek istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			kitapekle();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitapsil()
{
	system("cls");
	char sil_isbn[25];
	int denetleyici=0;
	char cevap;
	printf("Silinecek kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&sil_isbn);
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP KAYDI SILME\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if(strcmp(kitap.isbnno,sil_isbn)==0)
			{	
				denetleyici=1;
				strcpy(kitapsildir[i].isbnno," ");		
				strcpy(kitapsildir[i].kitapad," ");	
				strcpy(kitapsildir[i].yazarad," ");	
				strcpy(kitapsildir[i].tur," ");	
				strcpy(kitapsildir[i].yayintarihi," ");	
				strcpy(kitapsildir[i].yayinevi," ");	
			}
			else 
			{		
				strcpy(kitapsildir[i].isbnno,kitap.isbnno);				//
				strcpy(kitapsildir[i].kitapad,kitap.kitapad);		//
				strcpy(kitapsildir[i].yazarad,kitap.yazarad);		//
				strcpy(kitapsildir[i].tur,kitap.tur);		//Eğer isim yoksa o i değerine gore direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapsildir[i].yayintarihi,kitap.yayintarihi);		//
				strcpy(kitapsildir[i].yayinevi,kitap.yayinevi);	
			}
			i++;
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",sil_isbn);
			Sleep(1500);
			system("cls");
			kitapsil();
		}
		Kitap=fopen("kitaplar.dat","w");
		for(j=0 ; j<i ; j++)
		{
			fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapsildir[j].isbnno, kitapsildir[j].kitapad, kitapsildir[j].yazarad, kitapsildir[j].tur, kitapsildir[j].yayintarihi, kitapsildir[j].yayinevi);
		}
		fclose(Kitap);
		printf("%s ISBN Numarali kitap basariyla silinmistir",sil_isbn);
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha silmek istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			kitapsil();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitapguncelle()
{
	system("cls");
	int denetleyici=0;
	int k=0,denetleyici2=0;
	char cevap;
	char guncelle_isbn[25];
	printf("\nGuncellenicek kitabin ISBN numarasini giriniz:");
	scanf("%s",&guncelle_isbn);
	system("cls");
	Kitap = fopen("kitaplar.dat", "r+");
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha once varsa guncelleme işlemi yapilabilir.
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  KITAP BILGISI GUNCELLEME\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if (strcmp(kitap.isbnno, guncelle_isbn)==0)//Aranan isimle karşilaştirma yaptirip doğruysa bilgileri değiştiriyoruz
			{	
				//kişi bilgileri değiştirilerek k değerine gore olan struct değişkenine bilgilerimizi kaydediyoruz
				denetleyici2=1;
				printf("\n%s ISBN Numarali kitap hakkinda yeni bilgileri giriniz.\n",guncelle_isbn);
				printf("Kayit edilecek kitabin bilgilerini giriniz...\n\n");
				printf(" ISBN No:");
				scanf("%s",&kitapguncelleme[k].isbnno);
				printf("\n Adi:");
				_flushall();
				gets(kitapguncelleme[k].kitapad);
				printf("\n Yazarin Adi-Soyadi:");
				_flushall();
				gets(kitapguncelleme[k].yazarad);
				printf("\n Kitabin Turu:");
				_flushall();
				gets(kitapguncelleme[k].tur);
				printf("\n Yayinlama Tarihi:");
				scanf("%s",&kitapguncelleme[k].yayintarihi);
				printf("\n Yayinevi:");
				_flushall();
				gets(kitapguncelleme[k].yayinevi);			
				printf("\nKitap guncellenmistir.\n\n");
				Sleep(2500);
				system("cls");
			}
			else
			{
				strcpy(kitapguncelleme[k].isbnno,kitap.isbnno);				//
				strcpy(kitapguncelleme[k].kitapad,kitap.kitapad);		//
				strcpy(kitapguncelleme[k].yazarad,kitap.yazarad);		//
				strcpy(kitapguncelleme[k].tur,kitap.tur);		//Eğer isim yoksa o i değerine gore direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapguncelleme[k].yayintarihi,kitap.yayintarihi);		//
				strcpy(kitapguncelleme[k].yayinevi,kitap.yayinevi);			
			}
			k++;
		}
		fclose(Kitap);
	}
	if(denetleyici2==0)
	{
		printf("Kayitlar arasinda %s ISBN Numarali kitap bulunmamaktadir.",guncelle_isbn);
		Sleep(1500);
		kitapguncelle();
	}
	Kitap=fopen("kitaplar.dat","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
	for(j=0 ; j<k ; j++)
	{			
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapguncelleme[j].isbnno, kitapguncelleme[j].kitapad, kitapguncelleme[j].yazarad, kitapguncelleme[j].tur, kitapguncelleme[j].yayintarihi, kitapguncelleme[j].yayinevi);
	}
	fclose(Kitap);
	system("cls");
	printf("\n\n     Yeni bir kitap daha eklemek istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		kitapguncelle();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}
}

void odunckitap()
{

	system("cls");
	printf("********************************************************************************************************");
	printf("\n\t\t\t\tODUNC KITAP\n");
	printf("********************************************************************************************************\n\n");
	char odunc_isbn[25];
	char kisitc[11];
	int denetleyici=0;
	char cevap;
	char cevap2;
	int k=0;
	int m=0;
	printf("Odunc alacaginiz kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&odunc_isbn);
	printf("TC Kimlik Numaranizi giriniz:");
	scanf("%s",&kisitc);
	Kitap=fopen("odunckitap.dat","r+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitapodunc[k].isbnno, &kitapodunc[k].kitapad, &kitapodunc[k].yazarad, &kitapodunc[k].tur, &kitapodunc[k].yayintarihi, &kitapodunc[k].yayinevi, &o.o_tckimlik) != EOF)
	{
		if (strcmp(kitapodunc[k].isbnno,odunc_isbn)==0)
		{
			printf("Aradiginiz kitap zaten odunc alinmis...");
			Sleep(1500);
			odunckitap();
		}
		if(strcmp(o.o_tckimlik,kisitc)==0)
		{
			printf("Daha once kitap almissiniz. Yeni kitap almak icin diger kitabi iade ediniz...");
			Sleep(2000);
			main();
		}
		k++;
	}
	Kitap=fopen("rezervekitap.dat","r+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitaprezerve[m].isbnno, &kitaprezerve[m].kitapad, &kitaprezerve[m].yazarad, &kitaprezerve[m].tur, &kitaprezerve[m].yayintarihi, &kitaprezerve[m].yayinevi, &r.r_tckimlik) != EOF)
	{
		if (strcmp(kitaprezerve[m].isbnno,odunc_isbn)==0)
		{

			if(strcmp(r.r_tckimlik,kisitc)==0)
			{
				printf("Daha once kitap rezerve etmissiniz.\n");
				printf("\Bu kitabi almak istermisiniz?(e/h):");
				scanf("%s",&cevap2);
				if (cevap2=='e')
				{
					odunckitap();
				}
				else if (cevap2=='h')
				{
					main();
				}
				else
				{
					printf("\nYanlis secim yaptiniz...");
					Sleep(2000);
					exit(1);
				}
			}
			else
			{
				printf("\nAradiginiz kitap baskasi tarafindan rezerve edilmis...");
				printf("\nKitap aramak icin (a) tusuna basiniz...");
				printf("\nMenuye donmek icin (m) tusuna basiniz...");
				printf("\nCikis yapmak icin (c) tusuna basiniz...");
				printf("Seciminiz:");
				scanf("%s",&cevap);
				if (cevap=='a')
				{
					kitaparama();
				}
				else if (cevap=='m')
				{
					main();
				}
				else if (cevap=='c')
				{
					exit(1);
				}
				else
				{
					printf("Yanlis secim...");
					exit(1);
				}
			}
		}			
		m++;
	}
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		rewind(Kitap);
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{				
			if(strcmp(kitap.isbnno,odunc_isbn)==0)
			{
				denetleyici=1;
				strcpy(kitapodunc[i].isbnno,kitap.isbnno);				//
				strcpy(kitapodunc[i].kitapad,kitap.kitapad);		//
				strcpy(kitapodunc[i].yazarad,kitap.yazarad);		//
				strcpy(kitapodunc[i].tur,kitap.tur);		//Eğer isim yoksa o i değerine gore direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapodunc[i].yayintarihi,kitap.yayintarihi);		//
				strcpy(kitapodunc[i].yayinevi,kitap.yayinevi);
				printf("Tekrar TC Kimlik Numaranizi giriniz:");
				scanf("%s",&o.o_tckimlik);
			}
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",odunc_isbn);
			Sleep(1500);
			system("cls");
			odunckitap();
		}
		Kitap=fopen("odunckitap.dat","a+");
		rewind(Kitap);
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  %s  \n",kitapodunc[i].isbnno, kitapodunc[i].kitapad, kitapodunc[i].yazarad, kitapodunc[i].tur, kitapodunc[i].yayintarihi, kitapodunc[i].yayinevi,o.o_tckimlik);
		fclose(Kitap);
		printf("%s ISBN Numarali kitabiniz hayirli olsun...",odunc_isbn);
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void rezervekitap() // kitap odunç alinmiş mi onuda denetle
{
	system("cls");
	printf("********************************************************************************************************");
	printf("\n\t\t\t\tODUNC KITAP\n");
	printf("********************************************************************************************************\n\n");
	char rezerve_isbn[25];
	char kisitc[11];
	int denetleyici=0;
	char cevap;
	int k=0;
	printf("Rezerv edeceginiz kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&rezerve_isbn);
	printf("TC Kimlik Numaranizi giriniz:");
	scanf("%s",&kisitc);
	Kitap=fopen("rezervekitap.dat","a+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitapodunc[k].isbnno, &kitapodunc[k].kitapad, &kitapodunc[k].yazarad, &kitapodunc[k].tur, &kitapodunc[k].yayintarihi, &kitapodunc[k].yayinevi, &r.r_tckimlik) != EOF)
	{
		if (strcmp(kitapodunc[k].isbnno,rezerve_isbn)==0)
		{
			printf("Aradiginiz kitap zaten odunc alinmis...");
			Sleep(1500);
			odunckitap();
		}
		if(strcmp(r.r_tckimlik,kisitc)==0)
		{
			printf("Daha onca kitap almissiniz. Yeni kitap almak icin diger kitabi iade ediniz...");
			Sleep(2000);
			main();
		}
		k++;  
	}
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		rewind(Kitap);
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{				
			if(strcmp(kitap.isbnno,rezerve_isbn)==0)
			{
				denetleyici=1;
				strcpy(kitaprezerve[i].isbnno,kitap.isbnno);				//
				strcpy(kitaprezerve[i].kitapad,kitap.kitapad);		//
				strcpy(kitaprezerve[i].yazarad,kitap.yazarad);		//
				strcpy(kitaprezerve[i].tur,kitap.tur);		//Eğer isim yoksa o i değerine gore direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitaprezerve[i].yayintarihi,kitap.yayintarihi);		//
				strcpy(kitaprezerve[i].yayinevi,kitap.yayinevi);
				printf("Tekrar TC Kimlik Numaranizi giriniz:");
				scanf("%s",&r.r_tckimlik);
			}
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",rezerve_isbn);
			Sleep(1500);
			system("cls");
			rezervekitap();
		}
		Kitap=fopen("rezervekitap.dat","a+");
		rewind(Kitap);
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  %s  \n",kitapodunc[i].isbnno, kitapodunc[i].kitapad, kitapodunc[i].yazarad, kitapodunc[i].tur, kitapodunc[i].yayintarihi, kitapodunc[i].yayinevi,r.r_tckimlik);
		fclose(Kitap);
		printf("%s ISBN Numarali kitabiniz hayirli olsun...",rezerve_isbn);
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

int ogruyemi(char x[],char y[],FILE *fptr)
{
	int flag = 0;
	fptr=fopen("ogrenci uyeler.dat","r+");
	if(fptr==NULL)
	{
		printf("Dosyaya erisilemiyor.");
	}
	else 
	{
		while (fscanf(fptr, "%s%s%s%s%s%s%s%s", &ogrenciuye.adi, &ogrenciuye.soyad, &ogrenciuye.tckimlik, &ogrenciuye.email, &ogrenciuye.tel, &ogrenciuye.adres, &ogrenciuye.statu, &ogrenciuye.sifre) != EOF)
		{
			if ((strcmp(ogrenciuye.tckimlik, x)==0) && (strcmp(ogrenciuye.sifre, y)==0))
			{
				flag=1;
			}
		}
	}
	fclose(fptr);
	return flag;
}

int peruyemi(char x[],char y[],FILE *fptr)
{
	int flag = 0;
	fptr=fopen("personel uyeler.dat","r+");
	if(fptr==NULL)
	{
		printf("Dosyaya erisilemiyor.");
	}
	else 
	{
		while (fscanf(fptr, "%s%s%s%s%s%s%s%s", &personeluye.adi, &personeluye.soyad, &personeluye.tckimlik, &personeluye.email, &personeluye.tel, &personeluye.adres, &personeluye.statu, &personeluye.sifre) != EOF)
		{
			if ((strcmp(personeluye.tckimlik, x)==0) && (strcmp(personeluye.sifre, y)==0))
			{
				flag=1;
			}
		}
	}
	fclose(fptr);
	return flag;
}

void ogruyeol()
{
	int x;
	Uye=fopen("ogrenci uyeler.dat","a");
	if(Uye==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t UYE OL\n");
		printf("********************************************************************************************************\n\n");
		printf("Lutfen belirtilen sira ile bilgileri giriniz...\n\n");
		printf(" Adiniz:");
		scanf("%s",&ogrenciuye.adi);
		fprintf(Uye,"%s  ",ogrenciuye.adi);
		printf("\n Soyadiniz:");
		scanf("%s",&ogrenciuye.soyad);
		fprintf(Uye,"%s  ",ogrenciuye.soyad);
		for(;;)
		{
			printf("\n TC Kimlik Numaraniz: ");
			scanf("%s",&ogrenciuye.tckimlik);
			x=sorgulama(ogrenciuye.tckimlik);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}		
		fprintf(Uye,"%s  ",ogrenciuye.tckimlik);
		printf("\n E-mail Adresiniz: ");
		scanf("%s",&ogrenciuye.email);
		fprintf(Uye,"%s  ",ogrenciuye.email);
		printf("\n Telefon Numaraniz:");
		scanf("%s",&ogrenciuye.tel);
		fprintf(Uye,"%s  ",ogrenciuye.tel);
		printf("\n Adresiniz:");
		_flushall();
		gets(ogrenciuye.adres);		
		fprintf(Uye,"%s  ",ogrenciuye.adres);
		printf("\n Statunuz:");
		_flushall();
		gets(ogrenciuye.statu);	
		fprintf(Uye,"%s  ",ogrenciuye.statu);
		printf("\n Uyelik Sifreniz:");
		scanf("%s",&ogrenciuye.sifre);
		fprintf(Uye,"%s  \n",ogrenciuye.sifre);
		fclose(Uye);
		printf("\n Sisteme basariyla uye oldunuz...");
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void peruyeol()
{
	int x;
	Uye=fopen("personel uyeler.dat","a");
	if(Uye==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  UYE OL\n");
		printf("********************************************************************************************************\n\n");
		printf("Lutfen belirtilen sira ile bilgileri giriniz...\n\n");
		printf(" Adiniz:");
		scanf("%s",&personeluye.adi);
		fprintf(Uye,"%s	",personeluye.adi);
		printf("\n Soyadiniz:");
		scanf("%s",&personeluye.soyad);
		fprintf(Uye,"%s	",personeluye.soyad);
		for(;;)
		{
			printf("\n TC Kimlik Numaraniz: ");
			scanf("%s",&personeluye.tckimlik);
			x=sorgulama(personeluye.tckimlik);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		fprintf(Uye,"%s	",personeluye.tckimlik);
		printf("\n E-mail Adresiniz: ");
		scanf("%s",&personeluye.email);
		fprintf(Uye,"%s	",personeluye.email);
		printf("\n Telefon Numaraniz:");
		scanf("%s",&personeluye.tel);
		fprintf(Uye,"%s	",personeluye.tel);
		printf("\n Adresiniz:");
		_flushall();
		gets(personeluye.adres);		
		fprintf(Uye,"%s	",personeluye.adres);
		printf("\n Statunuz:");
		_flushall();
		gets(ogrenciuye.statu);	
		fprintf(Uye,"%s  ",personeluye.statu);
		printf("\n Uyelik Sifreniz");
		scanf("%s",&personeluye.sifre);
		fprintf(Uye,"%s  \n",personeluye.sifre);
		fclose(Uye);
		printf("\n Girilen bilgiler dosyaya kaydediliyor...");
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void kitapiade()
{
	system("cls");
	char sil_isbn[25];
	int denetleyici=0;
	char cevap;
	printf("Iade edilecek kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&sil_isbn);
	Kitap=fopen("odunckitap.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP IADE\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if(strcmp(kitap.isbnno,sil_isbn)==0)
			{	
				denetleyici=1;
				strcpy(kitapsildir[i].isbnno," ");		
				strcpy(kitapsildir[i].kitapad," ");	
				strcpy(kitapsildir[i].yazarad," ");	
				strcpy(kitapsildir[i].tur," ");	
				strcpy(kitapsildir[i].yayintarihi," ");	
				strcpy(kitapsildir[i].yayinevi," ");	
			}
			else 
			{		
				strcpy(kitapsildir[i].isbnno,kitap.isbnno);				//
				strcpy(kitapsildir[i].kitapad,kitap.kitapad);		//
				strcpy(kitapsildir[i].yazarad,kitap.yazarad);		//
				strcpy(kitapsildir[i].tur,kitap.tur);		//Eğer isim yoksa o i değerine gore direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapsildir[i].yayintarihi,kitap.yayintarihi);		//
				strcpy(kitapsildir[i].yayinevi,kitap.yayinevi);	
			}
			i++;
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",sil_isbn);
			Sleep(1500);
			system("cls");
			kitapsil();
		}
		Kitap=fopen("odunckitap.dat","w");
		for(j=0 ; j<i ; j++)
		{
			fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapsildir[j].isbnno, kitapsildir[j].kitapad, kitapsildir[j].yazarad, kitapsildir[j].tur, kitapsildir[j].yayintarihi, kitapsildir[j].yayinevi);
		}
		fclose(Kitap);
		printf("%s ISBN Numarali kitap iade edilmistir",sil_isbn);
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha almak istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			odunckitap();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitaparama()
{
	char kitapisim[25];
	char isbn[25];
	char turu[15];
	char yazarisim[20];
	int Secim, denetleyici = 0;
	char Secim2;
	Kitap=fopen("kitaplar.dat","r");
	if (Kitap == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha once varsa arama işlemi yapilabilir.
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  KITAP ARAMA\n");
		printf("********************************************************************************************************\n\n");
		printf(" 1-Ad ile arama\n");
		printf(" 2-ISBN No ile arama\n");
		printf(" 3-Yazar ismi ile arama\n");
		printf(" 4-Kitap turuna gore arama\n\n");
		printf("Seciminiz : ");
		scanf("%d", &Secim);
		switch (Secim)
		{
		case 1:
			{
				system("cls");
				printf("Aradiginiz kitabin adini giriniz:");
				_flushall();
				gets(kitapisim); // scanf ile almiyor burda gets ile aliyor 
				printf("\n");
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)
				{
					if (strcmp(kitap.kitapad, kitapisim)==0)//Aranan isimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tur, kitap.yayintarihi, kitap.yayinevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu isimde bir kitap kutuphanede kayitli degil!\n\n");
				}
				break;
			}
		case 2:
			{
				system("cls");
				printf("Aradiginiz kitabin ISBN Numarasini giriniz:");
				_flushall();
				gets(isbn); // scanf ile almiyor burda gets ile aliyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)
				{
					if (strcmp(kitap.isbnno, isbn)==0)//Aranan isimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tur, kitap.yayintarihi, kitap.yayinevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu ISBN No ile kayitli bir kitap mevcut değildir.\n\n");
				}
				break;
			}
		case 3:
			{
				system("cls");
				printf("Aradiginiz kitabin yazar ismini giriniz:");
				_flushall();
				gets(yazarisim); // scanf ile almiyor burda gets ile aliyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)
				{
					if (strcmp(kitap.yazarad, yazarisim)==0)//Aranan isimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tur, kitap.yayintarihi, kitap.yayinevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu isimde bir yazarin kitabi kutuphanede kayitli degil!\n\n");
				}
				break;
			}
		case 4:
			{
				system("cls");
				printf("Aradiginiz kitabin turunu giriniz:");
				_flushall();
				gets(turu); // scanf ile almiyor burda gets ile aliyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)
				{
					if (strcmp(kitap.tur, turu)==0)//Aranan isimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tur, kitap.yayintarihi, kitap.yayinevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu ture ait kitap mevcut değildir.\n\n");
				}
				break;			
			}
		}
	}	
	printf("\n");//İşleme devam edip etmeyeceği sorgulandmiştir.
	printf("Arama islemine devam etmek icin (A/a) tusuna basiniz\n");
	printf("Menuye donmek icin (M/m) tusuna basiniz \n");
	printf("Cikis  yapmak icin (C/c) tusuna basiniz\n\n");
	printf("Tercihiniz: ");
	scanf("%c", &Secim2); system("cls");
	if (Secim2 == 'a' || Secim2== 'A')
	{
		kitaparama();
	}
	else if (Secim2 == 'm' || Secim2 == 'M')
	{
		sayac++;
		main();
	}
	else if (Secim2 == 'c' || Secim2 == 'C')
	{
		exit(1);
	}
	else
	{
		printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		Sleep(2500);
		exit(1);
	}	
}
int sorgulama(char x[30]);
int sorgulama(char x[30])
{
	int a=0;
	for(i = 0; i < 11; i++) //Girilen numaranin 11 haneli olduğunu ve harf girilip girilmediğini kontrol eden kisim
	{
		if (isdigit(x[i])==0)
		{
			a=1;
		}
	}
	return a;
}

void kitapkatalogu()
{
	Kitap = fopen("kitaplar.dat", "r");	//Okuma modunda açiyoruz
	int Secim;
	if (Kitap == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else // Dosya onceden varsa kisi eklenebilir
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP KATALOGU\n");
		printf("********************************************************************************************************\n\n");
		printf("Kitap listemizde ekli olan tum kitaplari goruntuluyorsunuz \n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tur, &kitap.yayintarihi, &kitap.yayinevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{	
			printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tur, kitap.yayintarihi, kitap.yayinevi);
		}
		fclose(Kitap);//Dosyayi kapatiyoruz		
		//İşleme devam edip etmeyeceği sorgulanmiştir.
		printf("\n");
		printf("Menuye donmek icin (M/m) tusuna basin \n");
		printf("Cikis  yapmak icin (C/c) tusuna basin \n\n");
		printf("Tercihiniz: ");
		scanf("%s",&Secim);
		system("cls");
		if (Secim == 'm' || Secim == 'M')
		{
			sayac++;
			main(); //Ana fonksiyona gonderilir				
		}
		else if (Secim == 'c' || Secim == 'C')
		{
			exit(1);//proje sonlandirilir
		}
		else 
			printf("\n");
		printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
	}
}

void osifredegistir(char x[15])
{
		int k=0;
		int denetleyici = 0;
		char yenisifre[15];
		Uye = fopen("ogrenci uyeler.dat", "r+");//Dosyayi okuma+yazma modunda açiyoruz...
		if (Uye == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha once varsa guncelleme işlemi yapilabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  SIFRE DEGISTIRME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye,"%s%s%s%s%s%s%s%s",ogrenciuye.adi, ogrenciuye.soyad, ogrenciuye.tckimlik,ogrenciuye.email, ogrenciuye.tel, ogrenciuye.adres, ogrenciuye.statu, ogrenciuye.sifre)!=EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(ogrenciuye.sifre, x)==0)//Aranan isimle karşilaştirma yaptirip doğruysa bilgileri değiştiriyoruz
				{
					denetleyici=1;
					strcpy(uyeguncelleme[k].adi,ogrenciuye.adi);			
					strcpy(uyeguncelleme[k].soyad,ogrenciuye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,ogrenciuye.tckimlik);
					strcpy(uyeguncelleme[k].email,ogrenciuye.email);
					strcpy(uyeguncelleme[k].tel,ogrenciuye.tel);		
					strcpy(uyeguncelleme[k].adres,ogrenciuye.adres);		
					strcpy(uyeguncelleme[k].statu,ogrenciuye.statu);	
					printf("\n Yeni Uyelik Sifrenizi giriniz:");
					scanf("%s",&uyeguncelleme[k].sifre);
					
				}
				else
				{
					strcpy(uyeguncelleme[k].adi,ogrenciuye.adi);			
					strcpy(uyeguncelleme[k].soyad,ogrenciuye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,ogrenciuye.tckimlik);
					strcpy(uyeguncelleme[k].email,ogrenciuye.email);	
					strcpy(uyeguncelleme[k].tel,ogrenciuye.tel);		
					strcpy(uyeguncelleme[k].adres,ogrenciuye.adres);		
					strcpy(uyeguncelleme[k].statu,ogrenciuye.statu);	
					strcpy(uyeguncelleme[k].sifre,ogrenciuye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici==0)
		{
			printf("\n\nBu sifre ile kayitli bir uye bulunamadi...");
			Sleep(1500);
			main();
		}
		Uye=fopen("ogrenci uyeler.dat","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
		for(j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",uyeguncelleme[j].adi, uyeguncelleme[j].soyad, uyeguncelleme[j].tckimlik, uyeguncelleme[j].email, uyeguncelleme[j].tel, uyeguncelleme[j].adres, uyeguncelleme[j].statu, uyeguncelleme[j].sifre);
		}
		fclose(Uye);
		printf("\n\n Sifreniz basariyla degistirilmistir...");
		Sleep(5500);
		main();
}

void psifredegistir(char x[15])
{
	int k=0;
		int denetleyici = 0;
		char yenisifre[15];
		char sifretekrar[15];
		Uye = fopen("personel uyeler.dat", "r+");//Dosyayi okuma+yazma modunda açiyoruz...
		if (Uye == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha once varsa guncelleme işlemi yapilabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  SIFRE DEGISTIRME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye,"%s%s%s%s%s%s%s%s", &personeluye.adi, &personeluye.soyad, &personeluye.tckimlik, &personeluye.email, &personeluye.tel, &personeluye.adres, &personeluye.statu, &personeluye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(personeluye.sifre,x)==0)
				{
					denetleyici=1;
					strcmp(personeluye.sifre,yenisifre);
					strcpy(uyeguncelleme[k].adi,personeluye.adi);			
					strcpy(uyeguncelleme[k].soyad,personeluye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,personeluye.tckimlik);
					strcpy(uyeguncelleme[k].email,personeluye.email);	
					strcpy(uyeguncelleme[k].tel,personeluye.tel);		
					strcpy(uyeguncelleme[k].adres,personeluye.adres);		
					strcpy(uyeguncelleme[k].statu,personeluye.statu);
					printf("\n Yeni Uyelik Sifrenizi giriniz:");
					scanf("%s",&uyeguncelleme[k].sifre);
				}
				else
				{
					strcpy(uyeguncelleme[k].adi,personeluye.adi);			
					strcpy(uyeguncelleme[k].soyad,personeluye.soyad);		
					strcpy(uyeguncelleme[k].tckimlik,personeluye.tckimlik);
					strcpy(uyeguncelleme[k].email,personeluye.email);	
					strcpy(uyeguncelleme[k].tel,personeluye.tel);		
					strcpy(uyeguncelleme[k].adres,personeluye.adres);		
					strcpy(uyeguncelleme[k].statu,personeluye.statu);
					strcpy(uyeguncelleme[k].sifre,personeluye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici==0)
		{
			printf("\n\nBu sifre ile kayitli bir uye bulunamadi...");
			Sleep(1500);
			main();
		}
		Uye=fopen("personel uyeler.dat","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
		for(j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s\n",uyeguncelleme[j].adi, uyeguncelleme[j].soyad, uyeguncelleme[j].tckimlik, uyeguncelleme[j].email, uyeguncelleme[j].tel, uyeguncelleme[j].adres, uyeguncelleme[j].statu, uyeguncelleme[j].sifre);
		}
		fclose(Uye);
		printf("\n\n Sifreniz basariyla degistirilmistir...");
		Sleep(2500);
		main();
}
