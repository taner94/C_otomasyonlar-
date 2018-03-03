#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

struct Rehberim {

	char ad[20];
	char soyad[20];
	char evtel[11];
	char ceptel[11];
	char istel[11];
	char eposta[50];
	char dtarih[10];

} rehber,sildir[BUFSIZ],guncelle[BUFSIZ],yedekleyici[BUFSIZ]; //Struct değişkenlerimiz

void kayit_ekle(FILE *);
void kayit_guncelle(FILE *,char[]);
void kayit_sil(FILE *,char[]);
void kayit_goruntule(FILE *);
int menu();
void arama(FILE *);
int kontrolet(char []);
void yeniislem();
void baskaislem();


FILE *Rehber;	

int main()
{
	char sil_ad[30];
	char guncelle_ad[30];
	int secim;
	do	
	{
		secim=menu();
		switch (secim)
		{
		case 1:
			kayit_ekle(Rehber);
			break;
		case 2:
			printf("\nGuncellenicek ismi giriniz:");
			scanf("%s",&guncelle_ad);
			kayit_guncelle(Rehber,guncelle_ad);
			break;
		case 3:
			printf("Silinecek kisinin adini giriniz: ");
			scanf("%s",&sil_ad);
			kayit_sil(Rehber,sil_ad);		 	
			break;
		case 4:
			kayit_goruntule(Rehber);
			break;
		case 5:
			arama(Rehber);
			break;
		case 6 :
			system("CLS");
			printf("Gule Gule...");
			Sleep(2500);
			exit(1);
		default:
			system("cls");
			printf("\n\n\t\tYanlis secim yaptiniz...");
			Sleep(2500);
			main();
			break;
		}

	} while (secim <= 6 && secim >= 1);
	return 0;
}
int menu()
{

	int secim1;
	system("cls");
	
	printf("\n1-Kisi Ekle                ");	
	printf("\n2-Kayit Guncelleme         ");
	printf("\n3-Kayit Silme              ");
	printf("\n4-Kayit Goruntule          ");
	printf("\n5-Arama                    ");
	printf("\n6-Cikis                    ");
	printf("\n\nSeciminizi giriniz : ");
	scanf_s("%d",&secim1);
	return secim1;
}
void kayit_ekle(FILE *fptr)
{
	int x;
	int denetleyici = 0; // Girilen numaranin 11 haneli olup olmadiğini ve harf girilip girilmediğini kontrol eden denetçi
	fptr=fopen("rehberim.txt","a");//dosyayi ekleme modunda açiyoruz
	if(fptr==NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		printf("Dosyaya erisilemiyor.");
	else //dosya açilirsa kayit işlemi yapilabilir
	{
		system("cls");
		printf("Kayit edilecek kisinin bilgilerini giriniz...\n\n");
		printf(" Adi:");
		scanf("%s",rehber.ad);
		fprintf(fptr,"%s	",rehber.ad);
		printf("\n Soyadi:");
		scanf("%s",rehber.soyad);
		fprintf(fptr,"%s	",rehber.soyad);
		printf("\n Dogum tarihi: ");
		scanf("%s",rehber.dtarih);
		fprintf(fptr,"%s	",rehber.dtarih);
		printf("\n E-mail'ini giriniz: ");
		scanf("%s",rehber.eposta);
		fprintf(fptr,"%s	",rehber.eposta);
		for(;;)
		{
			printf("\n Ev no:");
			scanf("%s",&rehber.evtel);
			x=kontrolet(rehber.evtel);
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
		fprintf(fptr,"%s	",rehber.evtel);
		for(;;)
		{
			printf("\n Is no:");
			scanf("%s",&rehber.istel);
			x=kontrolet(rehber.istel);
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
		fprintf(fptr,"%s	",rehber.istel);
		for(;;)
		{
			printf("\n Cep no:");
			scanf("%s",&rehber.ceptel);
			x=kontrolet(rehber.ceptel);
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
		fprintf(fptr,"%s  \n",rehber.ceptel);
		fclose(fptr);
		printf("\n Girilen bilgiler Rehberinize kaydediliyor...");
		Sleep(2500);
		baskaislem();
	}
}
void kayit_goruntule(FILE *fptr)
{		
	fptr = fopen("rehberim.txt", "r");	//Okuma modunda açiyoruz
	int Secim;
	if (fptr == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		while (1)
		{
			printf("Suan rehberinizde hickimse ekli degil ekleme yapmak icin (E) tusuna basiniz : ");//Rehber oluşturulamamişsa veya daha once silinmişse bu uyari gosterilir
			Secim = _getche(); 
			system("cls");
			if (Secim == 'e' || Secim == 'E')
			{
				kayit_ekle(fptr); 
				break;
			}
			else
			{
				printf("\n");
				printf("Yanlis secim yaptiniz! Lutfen belirtilen tuslari kullaniniz\n");
				Sleep(2500);
				exit(1);
			}
		}
	}
	else // Dosya onceden varsa kisi eklenebilir
	{
		system("cls");
		printf("Telefon Rehberinde ekli olan tum kisileri goruntuluyorsunuz \n\n");
		while (fscanf(fptr, "%s%s%s%s%s%s%s", &rehber.ad, &rehber.soyad, &rehber.dtarih, &rehber.eposta, &rehber.evtel, &rehber.istel, &rehber.ceptel) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve ekrana yazdirilir.
		{	
			printf("Ad:  %s\nSoyad:  %s\nD.Tarihi:  %s\nE-Posta:  %s\nEv Telefonu:  %s\nIs Telefonu:  %s\nCep Telefonu:%s\n\n", rehber.ad, rehber.soyad, rehber.dtarih, rehber.eposta, rehber.evtel, rehber.istel, rehber.ceptel);
		}
		fclose(fptr);//Dosyayi kapatiyoruz		
		system("pause");
		//İşleme devam edip etmeyeceği sorgulanmiştir.
		baskaislem();
	}
}
void arama(FILE *fptr)
{
	char isim[30];
	char soyisim[30];
	char eposta[50];
	int Secim, denetleyici = 0;
	fptr = fopen("rehberim.txt", "r"); //Dosyayi okuma modunda açiyoruz.
	if (fptr == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha once varsa arama işlemi yapilabilir.
	{
		system("cls");
		printf(" 1-Ad ile arama\n");
		printf(" 2-SoyAd ile arama\n");
		printf(" 3-e-posta ile arama\n");
		scanf("%d", &Secim);
		switch (Secim)
		{
		case 1:// Ad ile sorgulama
			{
				system("cls");
				printf("Aranan kisinin adini giriniz:");
				_flushall();
				gets(isim); // scanf ile almiyor burda gets ile aliyor 
				printf("\n");
				rewind(fptr);
				while (fscanf(fptr, "%s", &rehber.ad) != EOF) //Dosyada bulunan adlari EOF a kadar okutuyoruz
				{
					fscanf(fptr, "%s", &rehber.soyad);		// 
					fscanf(fptr, "%s", &rehber.dtarih);		//
					fscanf(fptr, "%s", &rehber.eposta);		//Dosyadan okunan diğer bilgileri okutuyoruz
					fscanf(fptr, "%s", &rehber.evtel);		//
					fscanf(fptr, "%s", &rehber.istel);        //
					fscanf(fptr, "%s", &rehber.ceptel);	    //

					if (strcmp(rehber.ad, isim)==0)//Aranan isimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kisi Bilgileri\n");
						printf("--------------\n");
						printf("Ad:  %s\nSoyad:  %s\nD.Tarihi:  %s\nE-Posta:  %s\nEv Telefonu:  %s\nIs Telefonu:  %s\nCep Telefonu:%s\n\n", rehber.ad, rehber.soyad, rehber.dtarih, rehber.eposta, rehber.evtel, rehber.istel, rehber.ceptel);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu kisi rehberde kayitli degil!\n\n");
				}
				system("pause");
				break;
			}
		case 2:// Soyad ile sorgulama
			{
				system("cls");
				printf("Aranan kisinin soyadini giriniz:");
				_flushall();
				gets(soyisim);
				rewind(fptr);
				while (!feof(fptr))//Dosyada bulunan adlari EOF a kadar okutuyoruz
				{
					fscanf(fptr, "%s", &rehber.ad);
					fscanf(fptr, "%s", &rehber.soyad);
					fscanf(fptr, "%s", &rehber.dtarih);
					fscanf(fptr, "%s", &rehber.eposta);
					fscanf(fptr, "%s", &rehber.evtel);
					fscanf(fptr, "%s", &rehber.istel);
					fscanf(fptr, "%s", &rehber.ceptel);

					if (strcmp(rehber.soyad, soyisim)==0)//Aranan soyisimle karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kisi Bilgileri\n");
						printf("--------------\n");
						printf("Ad:  %s\nSoyad:  %s\nD.Tarihi:  %s\nE-Posta:  %s\nEv Telefonu:  %s\nIs Telefonu:  %s\nCep Telefonu:%s\n\n", rehber.ad, rehber.soyad, rehber.dtarih, rehber.eposta, rehber.evtel, rehber.istel, rehber.ceptel);
						denetleyici = 1;
						break;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu kisi kayitli degil\n");
				}
				system("pause");
				break;
			}
		case 3://E-posta ile sorgulama
			{
				system("cls");
				printf("Aranan kisinin eposta adresini giriniz:");
				_flushall();
				gets(eposta); // scanf ile almiyor burda gets ile aliyor
				rewind(fptr);
				while (!feof(fptr))//Dosyada bulunan adlari EOF a kadar okutuyoruz
				{
					fscanf(fptr, "%s", &rehber.ad);
					fscanf(fptr, "%s", &rehber.soyad);
					fscanf(fptr, "%s", &rehber.dtarih);
					fscanf(fptr, "%s", &rehber.eposta);
					fscanf(fptr, "%s", &rehber.evtel);
					fscanf(fptr, "%s", &rehber.istel);
					fscanf(fptr, "%s", &rehber.ceptel);

					if (strcmp(rehber.eposta, eposta)==0)//Aranan e-psta ile karşilaştirma yaptirip doğruysa ekrana yazidiriyoruz. 
					{
						printf("Kisi Bilgileri\n");
						printf("--------------\n");
						printf("Ad:  %s\nSoyad:  %s\nD.Tarihi:  %s\nE-Posta:  %s\nEv Telefonu:  %s\nIs Telefonu:  %s\nCep Telefonu:%s\n\n", rehber.ad, rehber.soyad, rehber.dtarih, rehber.eposta, rehber.evtel, rehber.istel, rehber.ceptel);
						denetleyici = 1; 
						break;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu kisi kayitli degil\n");
				}
				system("pause");
				break;
			}
		}

	}	
	//İşleme devam edip etmeyeceği sorgulandmiştir.
	baskaislem();	
}
void kayit_guncelle(FILE *fptr,char y[])
{	
	int x;
	int denetleyici=0;
	int k=0,denetleyici2=0;
	system("cls");
	fptr = fopen("rehberim.txt", "r+");//Dosyayi okuma+yazma modunda açiyoruz...
	if (fptr == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha once varsa guncelleme işlemi yapilabilir.
	{
		system("cls");
		while (fscanf(fptr, "%s  %s  %s  %s  %s  %s  %s  ", &rehber.ad, &rehber.soyad, &rehber.evtel, &rehber.ceptel, &rehber.istel, &rehber.eposta, &rehber.dtarih)!= EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if (strcmp(rehber.ad, y)==0)//Aranan isimle karşilaştirma yaptirip doğruysa bilgileri değiştiriyoruz
			{	
				//kişi bilgileri değiştirilerek k değerine gore olan struct değişkenine bilgilerimizi kaydediyoruz
				denetleyici2=1;
				printf("\n%s hakkinda yeni bilgileri giriniz.\n",y);
				printf("-------------\n");
				printf("\nAd: ");
				scanf("%s",&guncelle[k].ad);
				printf("\nSoyad: ");
				scanf("%s",&guncelle[k].soyad);
				printf("\nDogum tarihi: ");
				scanf("%s",&guncelle[k].dtarih);
				printf("\nE-posta: ");
				scanf("%s",&guncelle[k].eposta);
				for(;;)
				{
					printf("\n Ev Tel No:");
					scanf("%s",&guncelle[k].evtel);
					x=kontrolet(guncelle[k].evtel);
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
				for(;;)
				{
					printf("\n Is Tel No:");
					scanf("%s",&guncelle[k].istel);
					x=kontrolet(guncelle[k].istel);
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
				for(;;)
				{
					printf("\n Cep Tel No:");
					scanf("%s",&guncelle[k].ceptel);
					x=kontrolet(guncelle[k].ceptel);
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
				printf("\nKisi guncellenmistir.\n\n");
				Sleep(2500);
				system("cls");
			}
			else
			{
				strcpy(guncelle[k].ad,rehber.ad);
				strcpy(guncelle[k].soyad,rehber.soyad);
				strcpy(guncelle[k].dtarih,rehber.dtarih);
				strcpy(guncelle[k].eposta,rehber.eposta);
				strcpy(guncelle[k].evtel,rehber.evtel);			
				strcpy(guncelle[k].istel,rehber.istel);
				strcpy(guncelle[k].ceptel,rehber.ceptel);			
			}
			k++;
		}
		fclose(fptr);
	}
	if(denetleyici2==0)
	{
		printf("Rehberde %s isimli biri bulunmamaktadir.",y);
		Sleep(1500);
		system("cls");
	}
	fptr=fopen("rehberim.txt","w");//dosyayi sifirdan açip tekrar yazdirmak için yazma modunda açiyoruz.
	int j,i;
	for(j=0 ; j<k ; j++)
	{			
		fprintf(fptr, "%s  %s  %s  %s  %s  %s  %s  \n",guncelle[j].ad, guncelle[j].soyad, guncelle[j].dtarih, guncelle[j].eposta, guncelle[j].evtel, guncelle[j].istel, guncelle[j].ceptel);
	}
	fclose(fptr);
	// başka işlem sorgusu
	baskaislem();
}
void kayit_sil(FILE *fptr,char x[])
{
	int denetleyici=0;
	fptr=fopen("rehberim.txt","r+"); //Dosyamizi okuma+yazma modunda açiyoruz
	int i=0;
	if (fptr == NULL)//Dosya açilmassa(daha once açilmiş ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha once varsa guncelleme işlemi yapilabilir.
	{
		system("cls");
		while(fscanf(fptr, "%s%s%s%s%s%s%s", &rehber.ad, &rehber.soyad, &rehber.dtarih, &rehber.eposta, &rehber.evtel, &rehber.istel, &rehber.ceptel) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if(strcmp(rehber.ad,x)==0)
			{	
				denetleyici=1;
				strcpy(sildir[i].ad," ");		//
				strcpy(sildir[i].soyad," ");	//
				strcpy(sildir[i].evtel," ");	//
				strcpy(sildir[i].ceptel," ");	//	strcmp ile karşilaştirinca bulunan isim yerine boşluk kopyalanir
				strcpy(sildir[i].istel," ");	//
				strcpy(sildir[i].eposta," ");	//
				strcpy(sildir[i].dtarih," ");	//
			}
			else 
			{		
				strcpy(sildir[i].ad,rehber.ad);				//
				strcpy(sildir[i].soyad,rehber.soyad);		//
				strcpy(sildir[i].evtel,rehber.evtel);		//
				strcpy(sildir[i].ceptel,rehber.ceptel);		//Eğer isim yoksa o i değerine gore direk ismi sildir struct değişkenine kopyalar.
				strcpy(sildir[i].istel,rehber.istel);		//
				strcpy(sildir[i].eposta,rehber.eposta);		//
				strcpy(sildir[i].dtarih,rehber.dtarih);		//	
			}
			i++;
		}
		fclose(fptr);
		if (denetleyici==0)
		{
			printf("Rehberde %s isimli biri bulunamadi.",x);
			Sleep(1500);
			system("cls");
		}
		fptr=fopen("rehberim.txt","w");
		int j;
		for(j=0 ; j<i ; j++)
		{
			fprintf(fptr, "%s  %s  %s  %s  %s  %s  %s  \n",sildir[j].ad, sildir[j].soyad, sildir[j].dtarih, sildir[j].eposta, sildir[j].evtel, sildir[j].istel, sildir[j].ceptel);//dikkat et burasi sildir dizisi olmasi lazim
		}
		fclose(fptr);
		printf("%s kisisi basariyla silinmistir",x);
		Sleep(2500);
		system("cls");
		// başka işlem sorgusu
		baskaislem();
	}
}
int kontrolet(char x[30])
{
	int a=0,i;
	for (i = 0; i < 11; i++) //Girilen numaranin 11 haneli olduğunu ve harf girilip girilmediğini kontrol eden kisim
	{
		if (x[i] != '0' && x[i] != '1' && x[i] != '2' && x[i] != '3' && x[i] != '4' && x[i] != '5' && x[i] != '6' && x[i] != '7' && x[i] != '8' && x[i] != '9')
		{
			a=1;
		}
	}
	return a;
}
void baskaislem()
{
		char cevap;
		system("cls");
		printf("\n\n Baska bir islem yapmak istiyor musunuz(e/h) : "); // başka ekleme yapip yapmayacağimiz sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			system("cls");
			printf("Gule Gule");
			Sleep(2500);
			exit(1);
		}
		if (cevap=='e')
		{
			menu();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}

}

