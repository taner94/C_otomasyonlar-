
#include<stdio.h>
#include<stdlib.h>/*exit() için gerekli kütüphane*/
#include<string.h>/*strlen,strcmp gibi fonksiyonlar için gerekli kütüphane*/
#include<conio.h>/*getch(); için gerekli kütüphane*/
#include<ctype.h>/*isdigit için gerekli kütüphane*/
#define BOS 0/*BOS gördügünde 0 olarak taniyacak*/

/*FONKSIYONLAR*/
int parola();
int anamenu();
void notgiris();
void listele();
void ogrkyt();
void ogrsil();
void devamsizlik();
void arama();
void detay();
void duzelt();
void s_listesi();
void s_bul();
void ara_isim();
void ara_no();
long double f_no(char array[]);/*10 byte lik yer ayirir*/
char sinif[20],izin,ders[20];
int q=0;
struct kimlik {
	char ad[80];
	char s_ad[80];
	char no [13];
};/*kimlik ;ad,soyad ve no içerecek*/
struct ogrenci {
	struct kimlik bilgi;/*kimlikteki bilgilerin bilgi ye atanmasi*/
	int devamsizlik,not1[10];
	int kontrol[10];
};
struct as {
	struct ogrenci ogr[50];/*Ogrenci deki bilgiler ogr daki 50 adet ogrenci için kullanilir ve bu bilgiler as'a atanir. */
	char sinif_adi[20];
	int __mevcut;
} dos[10];
FILE *f;
/*PROGRAM BASLANGICI*/
int main() {
	int n,durum=0,i;
	char izin;
	parola();
	printf("DERS ADINI GIRINIZ: ");
	gets(ders);
	if ((f=fopen("c:ders1.txt","r+"))==BOS) { /*c:ders1.txt yi okur. Dosya yoksa yeni dosya olusturulur. Dosya varsa isleme devam edilir*/
		printf("*__%s__* DOSYA BULUNAMADI!!!\n Yeni Dosya Olusturmak Icin 'n' \n Cikis Icin Herhangi Bir Tus\n",ders);
		izin=getch();
		if(izin=='n') {
			if ((f=fopen("c:ders1.txt","w+"))==BOS) { /*ders1.txt yi write modunda açar.Dosya bossa ekrana "hata" yazar*/
				printf("HATA!!!\n");
				exit(0);
			}
		} else
			return 0;
	}
	fseek(f,0,SEEK_SET);/*Dosyanin Baslangicina Konumlanir*/
	for(i=0; i<10; i++)
		if(fread(&dos[i],sizeof(struct as),1,f)<1) { /*f nin gösterdigi dosyadan 1 kayit olmak üzere bilgiyi dos[i] ye koyar.Dosyada bilgi yoksa dosya okunamaz*/
			printf("\n\t-----***%d***-----\n",i);
			printf("Dosya Okunamiyor\n");
			s_listesi();
		}
	fseek(f,0,SEEK_SET);
	printf("Sinif Ismi Giriniz...\n");
	gets(sinif);
	for(i=0; i<10; i++) {
		if ((f=fopen("c:ders1.txt","r+"))==BOS) {
			printf("HATA!!!");
			exit (0);
		}
		if(strcmp(dos[i].sinif_adi,sinif)==BOS) { /*dos[i].sinif_adi ile klavyeden girilen sinif ismini karsilastirir.Eger esitse s_listesi fonksiyonuna yollar*/
			q=i;
			s_listesi();
			break;
		}
	}
	fclose(f);/*Dosyayi kapatir.*/
	char islem;
	while(1) {
		islem=anamenu();
		switch (islem) { /*Ana menüye göre olusturulan fonksiyonlar*/
			case '1' :
				notgiris();
				break;
			case '2' :
				listele();
				break;
			case '3' :
				ogrkyt();
				break;
			case '4' :
				ogrsil();
				break;
			case '5' :
				devamsizlik();
				break;
			case '6' :
				arama();
				break;
			case '7' :
				detay();
				break;
			case '8' :
				duzelt();
				break;
			default :
				printf("GECERSIZ SECENEK!..\n");/*Hiçbiri degilse geçersiz seçenek yazdirip tekrar ana menüye döner*/
		}
	}
	return 0;
}

int i,j,k;                    /*Alfabetik Siraya Göre Siralar Ve Ögrenciyle Ilgili Bilgileri Verir.*/
void listele() {
	struct ogrenci is;
	float toplam[10];
	char n;
	int durum=0;
	printf("Alfabetik siralama icin (n) tusuna bas\n ");
	n= getch();
	if(n=='n')/*Klavyeden girilen deger  'n' e esitse alttaki döngü baslar*/
		for (i = 0; i < dos[q].__mevcut-1 ; i++)
			for (k = 0; k < dos[q].__mevcut-1 ; k++)
				if (f_no(dos[q].ogr[k].bilgi.ad) > f_no(dos[q].ogr[k+1].bilgi.ad)) { /*Klasik siralama islemleri.*/
					is = dos[q].ogr[k];
					dos[q].ogr[k] = dos[q].ogr[k+1];
					dos[q].ogr[k+1] =is;
				}
	printf("AD \tSOYAD \tNO \t\t");
	for(j=0; j<dos[q].ogr[durum+2].kontrol[1]; j++)
		printf("not%d ",j+1);
	printf("\n********************************************************************************\n");
	fseek(f, 0, SEEK_SET);
	while(durum<50) { /*Asagidaki islemleri 50 kere yapar*/
		if(dos[q].ogr[durum].kontrol[0]!=1) {
			durum++;
			continue;
		}
		printf("%s %s %s ",dos[q].ogr[durum].bilgi.ad,dos[q].ogr[durum].bilgi.s_ad,dos[q].ogr[durum].bilgi.no);
		for(i=0; i<dos[q].ogr[durum].kontrol[1]; i++) { /*Ismi geçen ögrencinin sinav sonucunu yazar*/
			toplam[i]+=dos[q].ogr[durum].not1[i];
			printf("--(%.3d)-",dos[q].ogr[durum].not1[i]);
		}
		if(dos[q].ogr[durum].kontrol[1]==0)/*Ismi geçen ögrencinin dos[q].ogr[durum].kontrol[1] de kayitli bir sonucu yoksa asagidaki hatayi verir*/
			printf("_*BU KISIYE AIT SINAV SONUCU BULUNMAMAKTADIR.*_\n ");
		printf("\n");
		printf("/t _*_*_*_\n");
		durum++;
	}

	printf("Sinav Ortalamalari=");
	for(i=0; i<dos[q].ogr[0].kontrol[1]; i++) {
		printf("--(%2.1f)",toplam[i]/dos[q].__mevcut);/*Mevcut sayisina göre sinif ortalamasini bulur*/
		if(toplam[i]==0)
			printf("!!Ortalama Yok!! ");
	}
}                           /*KAYIT SISTEMI*/
void ogrkyt() {
	int s_farki=0;
	char sec;
	int ek=dos[q].__mevcut;
	while(1) {
		printf("AD: ");
		gets(dos[q].ogr[ek].bilgi.ad);
		if(dos[q].ogr[ek].bilgi.ad[0]==BOS)
			break;
		printf("SOYAD: ");
		gets(dos[q].ogr[ek].bilgi.s_ad);
		printf("NO: ");
		gets(dos[q].ogr[ek].bilgi.no);
		dos[q].ogr[ek].kontrol[0]=1;
		dos[q].ogr[ek].kontrol[1]=0;
		if(dos[q].ogr[ek].kontrol[1]!=dos[q].ogr[ek-1].kontrol[1]) {
			printf("Bu Sinif %d Sinava Girmis \n",dos[q].ogr[ek-1].kontrol[1]-dos[q].ogr[ek].kontrol[1]);
			s_farki=dos[q].ogr[ek-1].kontrol[1]-dos[q].ogr[ek].kontrol[1];
			for(k=0; k<s_farki; k++) {
				scanf("%d",&dos[q].ogr[ek].not1[k]);
				dos[q].ogr[ek].kontrol[1]++;
				dos[q].ogr[ek].kontrol[k+4]=dos[q].ogr[ek-1].kontrol[k+4];
			}
		}
		ek++;

	}
	dos[q].__mevcut=ek;
}
/*KAYIT SILME*/
void ogrsil() {
	char cg;
	char delname[20];
	int x=0;
	printf("Silinecek Ogrenci Adini Giriniz\n");
	gets(delname);
	for( x=0; x<dos[q].__mevcut; x++) { /*Mevcut sayisi kadar döndürür.Ögrencinin ismi x mevcut sayisindan bi eksik olana kadar(yani bütün herkes taraninca) kayit bulunamadi yazar.*/
		if(strcmp(delname,dos[q].ogr[x].bilgi.ad)==0) {
			break;
		}
		if(x==dos[q].__mevcut-1) {
			printf("SISTEME KAYITLI DEGIL!\n");
			anamenu();
		}
	}
	printf("**SILINMEK ISTENEN KAYIT**\n");
	printf("%s %s %s ",dos[q].ogr[x].bilgi.ad,dos[q].ogr[x].bilgi.s_ad,dos[q].ogr[x].bilgi.no);
	printf("\n");
	printf("**devam etmek icin (s)**\n");
	scanf("%c",&cg);
	if(cg=='s') {
		printf("_Kayit Silindi_");
		dos[q].ogr[x].kontrol[0]=0;
		dos[q].__mevcut-=1;/*Mevcut sayisi 1 azaltilir*/
	} else {
		printf("Yanlis Giris Ana Menuye Yonlendiriliyorsunuz\n");
		anamenu();
	}
}
/*DEVAMSIZLIK ISLEMLER*/
void devamsizlik() {
	int sayac=0,n=1;
	char konum;
	printf("Ogrenci Isimlerinin Karsisini (+)::(-) Olarak Isaretleyin\n");
	while(sayac<dos[q].__mevcut) { /*Mevcut sayisi kadar döner*/
		printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
		printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);/*Ögrencinin devamsizlik sayisi*/
		do {
			konum=getch();
			if(konum=='+') { /*Diger ögrenciye geçer*/
				break;
			}
			if(konum=='-') { /*Ögrencinin devamsizligina 1 ekler*/
				dos[q].ogr[sayac].devamsizlik+=1;
				break;
			}
			if(konum!='+'||konum!='-') { /*Yanlis seçenek durumu*/
				printf("HATA!!!!!");
			}
		} while(konum=='+'||konum=='-');
		if(konum=='-') {
			printf("+1=");/*1 eklendigi belirtilir*/
		}
		printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);
		sayac++;
	}
}           /*KAYIT ARAMA*/
void arama() {
	char l;
	printf("Aranacak Ogrenci \n\tIsmine Gore[1]\n\n\tNo ya Gore [2]\n");
	scanf("%s",&l);
	switch(l) {
		case'1':
			ara_isim();
			break;
		case'2':
			ara_no();
			break;
		default:
			printf("HATA!!!Lutfen 1 veya 2 ye Basin");
	}
	anamenu();
}
/*ISME GÖRE ARAMA*/
void ara_isim() {
	char ara_name[20];
	int index=0;
	printf("ISMI GIRIN...\n");
	scanf("%s",&ara_name);
	while(index<dos[q].__mevcut) { /*Mevcut kadar döner*/
		if(strcmp(ara_name,dos[q].ogr[index].bilgi.ad)==0) {
			printf("KAYIT BULUNDU\n");
			printf("%s %s %s ",dos[q].ogr[index].bilgi.ad,dos[q].ogr[index].bilgi.s_ad,dos[q].ogr[index].bilgi.no);
			for(i=0; i<dos[q].ogr[index].kontrol[1]; i++) {
				printf("--(%.3d)-",dos[q].ogr[index].not1[i]);
			}
			if(dos[q].ogr[index].kontrol[1]==0)
				printf("Sinav Sonucu Bulunmamaktadir \n");
			printf("DEVAMSIZLIK=%d Ders Saati\n",dos[q].ogr[index].devamsizlik);
		}
		if(strcmp(ara_name,dos[q].ogr[index].bilgi.ad)==1)
			printf("Bu Kisi Sisteme Kayitli Degildir.");
		index++;
	}

}
/*NO YA GÖRE ARAMA*/
void ara_no() {
	char arayici_no[15];
	int index=0;
	printf("Ogrenci Nosunu Girin\n");
	scanf("%s",&arayici_no);
	while(index<dos[q].__mevcut) {
		if(strcmp(arayici_no,dos[q].ogr[index].bilgi.no)==0) { /*No yu karsilastirir.*/
			printf("KAYIT BULUNMUSTUR\n");
			printf("%s %s %s ",dos[q].ogr[index].bilgi.ad,dos[q].ogr[index].bilgi.s_ad,dos[q].ogr[index].bilgi.no);
			for(i=0; i<dos[q].ogr[index].kontrol[1]; i++) {
				printf("--(%.3d)-",dos[q].ogr[index].not1[i]);
			}
			if(dos[q].ogr[index].kontrol[1]==0)
				printf("--sinav sonucu yok ");
			puts("\n");
			printf("DEVAMSIZLIK=%d Ders Saati\n",dos[q].ogr[index].devamsizlik);
		}
		if(strcmp(arayici_no,dos[q].ogr[index].bilgi.no)==1) {
			printf("Bu Kisi Sisteme Kayitli Degildir.");
		}
		index++;

	}

}
/*GENEL SONUÇLAR*/
void detay() {
	int not1=0;
	int sayac=0;
	int sinir;
	printf("SECILEN DERS ICIN MAKSIMUM DEVAMSIZLIK BILGISINI GIRIN:\n");
	scanf("%d",&sinir);/*Devamsizlik sayisina göre geçti kaldi belirlenir*/
	while(sayac<50) { /*50 kere yani maksimum mevcut kadar döner*/
		if(dos[q].ogr[sayac].kontrol[0]!=1) {
			sayac++;
			continue;
		}
		printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
		for(i=0; i<dos[q].ogr[sayac].kontrol[1]; i++) {
			not1+=dos[q].ogr[sayac].not1[i]*dos[q].ogr[sayac].kontrol[i+4]/100;
		}
		if(not1>=90) {
			printf("Notunuz %.3d____A1__GECTI",not1);
		} else if(90>not1>=85) {
			printf("Notunuz %.3d____A2__GECTI",not1);
		} else if(85>not1>=80) {
			printf("Notunuz %.3d____B1__GECTI",not1);
		} else if(80>not1>=75) {
			printf("Notunuz %.3d____B2__GECTI",not1);
		} else if(75>not1>=70) {
			printf("Notunuz %.3d____CC__GECTI",not1);
		} else if(70>not1>=50) {
			printf("Notunuz %.3d____CD__KALDI",not1);
		} else if(50>not1>=30) {
			printf("Notunuz %.3d____DD__KALDI",not1);
		} else
			printf("Notunuz %.3d____FF__ KALDI",not1);
		if(dos[q].ogr[sayac].devamsizlik>sinir)
			printf("DZ__ DEVAMSIZLIKTAN KALDI");
		printf("\n");
		printf("\t----------------------------------------\n");
		sayac++;
		not1=0;
	}
}
/*DÜZENLEME BÖLÜMÜ*/
void duzelt() {
	char konum;
	int sayac=0,i=0,n=1;
	printf("\tDegisiklik Yapilacak Kaydi Secin\n\n");
	printf("\tIlerlemek Icin [+] Geri Gitmek icin[-]ye Basin\n\n");
	printf("\tSecmek Icin[enter]\n");
	while(n) {
		printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
		for( i=0; i<dos[q].ogr[sayac].kontrol[1]; i++)
			printf("--(%.3d)",dos[q].ogr[sayac].not1[i]);
		if(dos[q].ogr[sayac].kontrol[1]==0)
			printf("**Sinav Sonucu Yok**\n ");
		printf("\t\\\\\\\\\\\\\\\\//////////////\n");
		do {
			konum=getch();
			if(konum=='+') {
				if(sayac==dos[q].__mevcut-1)
					sayac=-1;
				sayac++;
				break;
			}
			if(konum=='-') {
				if(sayac==0)
					sayac=dos[q].__mevcut;
				sayac--;
				break;
			}
			if(konum!='\n') {
				printf("Secildi\n");
				n=0;
				break;
			}
		} while(1);
	}
	printf("\t*_Ad Degisikligi Icin_*[1]\n");
	printf("\t*_Soyad Degisikligi Icin_*[2]\n");
	printf("\t*_No Degisikligi Icin_*[3]\n");
	printf("\t*_Not Degisikligi Icin_*[4]\n");
	printf("\t*_Devamsizlik Degisikligi Icin_*[5]\n");
	konum=getch();
	switch(konum) {
		case '1' : {
			printf("%s Degerini Degistir\n",dos[q].ogr[sayac].bilgi.ad);
			gets(dos[q].ogr[sayac].bilgi.ad);
			break;
		}
		case'2': {
			printf("%s Degerini Degistir",dos[q].ogr[sayac].bilgi.s_ad);
			gets(dos[q].ogr[sayac].bilgi.s_ad);
			break;
		}
		case'3': {
			printf("%d Degerini Degistir\n",dos[q].ogr[sayac].bilgi.no);
			gets(dos[q].ogr[sayac].bilgi.no);
			break;
		}
		case'4': {
			printf("Bu Ogrenci Icin %d Sinav Notu Bulunmaktadir\n",dos[q].ogr[sayac].kontrol[1]);/*Ögrenciye ait kayitli sinav no sayisi*/
			if(dos[q].ogr[sayac].kontrol[1]==0)/*Sinav kaydi yoksa yani 0 sa degisecek birsey bulunamaz*/
				printf("Degistirilecek Birsey Bulunamadi!!!\n");
			else {
				for(j=0; j<dos[q].ogr[sayac+2].kontrol[1]; j++)
					printf("not%d ",j+1);
				for( i=0; i<dos[q].ogr[sayac].kontrol[1]; i++)
					printf("--(%.3d)",dos[q].ogr[sayac].not1[i]);
				printf("Sinav Nosunu Girin:");
				scanf("%d",&i);
				printf("%3d Degerini Degistirin:");
				scanf("%d",&dos[q].ogr[sayac].not1[i]);
				break;
			}
		}
		case'5': {
			printf("Ogrencinin Devamsizligi__(%d)__ ders");
			printf("Yeni Deger=");
			scanf("%d",&dos[q].ogr[sayac].devamsizlik);
		}
		default:
			printf("HATA!!!\n");
	}
}
void s_listesi() {
	for(i=0; i<10; i++) {
		if(dos[i].__mevcut==0) { /*Mevcut sifirsa listelemez*/
			break;
		}
		int mevcut=0;
		for(mevcut=0; mevcut<=3; mevcut++) {
			printf("AD: ");
			gets(dos[i].ogr[mevcut].bilgi.ad);
			if(dos[i].ogr[mevcut].bilgi.ad[0]==BOS)
				break;
			puts("SOYAD: ");
			gets(dos[i].ogr[mevcut].bilgi.s_ad);
			puts("NO: ");
			gets(dos[i].ogr[mevcut].bilgi.no);
			dos[i].ogr[mevcut].kontrol[0]=1;
			dos[i].ogr[mevcut].kontrol[1]=0;
			mevcut++;
			dos[i].__mevcut=mevcut;
			esas();
		}
	}
}
void esas() {
	struct ogrenci is;
	int sayac=0;
	for ( i = 0; i < dos[q].__mevcut-1 ; i++)
		for ( k = 0; k < dos[q].__mevcut-1 ; k++)
			if (f_no(dos[q].ogr[k].bilgi.no) > f_no(dos[q].ogr[k+1].bilgi.no)) {
				is = dos[q].ogr[k];
				dos[q].ogr[k] = dos[q].ogr[k+1];
				dos[q].ogr[k+1] =is;
			}
	for(i=0; i<dos[q].__mevcut+1; i++) {
		if(dos[q].ogr[i].kontrol[0]!=1) {
			for(k=i; k<dos[q].__mevcut+1; k++) {
				dos[q].ogr[k]=dos[q].ogr[k+1];
			}
		}
	}
	if((f=fopen("c:ders1.txt","r+"))==BOS) {
		printf("HATA!!!\n");
		exit(1);
	}
	for(i=0; i<10; i++) {
		if(fwrite(&dos[i], sizeof(esas), 1, f)<1)/*as in boyutundaki bilgiyi 1 kayit olarak f dosyasina yaz*/
			printf("HATA!!!\n");
	}
	fclose(f);
	printf("***Guncelleme Gerceklesti***..");
}
long double f_no(char array[]) {
	long double g_no=0,carpan,t,k;
	int n=strlen(array);/*Verilen stringin uzunlugunu hesaplar*/
	if(!isdigit(array[1]))/*Rakam ise 0 dan farkli bir degere geri dondurur degilse 0 a dondurur*/
		n=3;
	int m;
	for(t=0; t<n; t++) {
		carpan=1;
		for(k=1; k<n-t; k++) {
			carpan*=10;
		}
		g_no+=m*carpan;
	}
	return g_no;
}                    /*PROGRAMIN ANA MENÜSÜ*/
int anamenu() {
	printf("********************************************************************************\n");
	esas();
	printf("Sinif Adi=%s\n",sinif);
	printf("MEVCUT= %d\n",dos[q].__mevcut);
	char ch;
	printf("********************OGRENCI BILGI SISTEMINE HOS GELDINIZ!***********************\n");
	printf("\t\t ***YENI NOT GIRISI ***(1)\n\n");
	printf("\t\t ***SIRALAMA***(2)\n\n");
	printf("\t\t ***OGRENCI EKLE***(3)\n\n");
	printf("\t\t ***OGRENCI SIL***(4)\n\n");
	printf("\t\t ***YOKLAMA***(5)\n\n");
	printf("\t\t ***OGRENCI ARAMA***(6)\n\n");
	printf("\t\t ***GENEL SONUCLAR***(7)\n\n");
	printf("\t\t ***BILGI DUZELTME***(8)\n\n");
	ch=getch();
	printf("\n\n\n");
	return ch;
}                             /* PAROLA ISLEMI*/
int parola() {
	char str[] = "1";
	char s[20];
	int i=0;
	printf("Programi Hazirlayanlar=\t***MEHMET ALI GOKMEN***\n\t\t\t***NURI YUNUS KOCADAG***\n\n\t\t\t<<Tum haklari saklidir©>>\n\n\t\t\tKirikkale Universitesi Elektrik-Elektronik Muhendisligi\n\n");
	printf("Parolayi Giriniz :\n ");
	printf("Parolayi dikkatli giriniz.Aksi taktirde sistem kilitlenecektir=");
	gets(s);
	if (!strcmp(str, s))

	{
		printf("Onaylandi...\n");
		return 1;
	} else {
		printf("HATA!!!.Lutfen programi tekrar baslatip sifreyi girmeyi tekrar deneyin\n");
		for(;;);
		return 0;
	}
}
/*NOT GIRIS SISTEMI*/
void notgiris() {
	/*Istenilen Yüzdeye Göre Sinav Notu Hesaplamasi*/
	int sayi=0,yuzde,kalan=0,pay_t=0,a;
	for(a=4; a<9; a++) {
		pay_t+=dos[q].ogr[0].kontrol[a];
	}
	printf("KALAN YUZDE=%d\n",100-pay_t);
	do {
		printf("GIRILECEK SINAVIN ETKIYECEGI YUZDEYI GIRIN=");
		scanf("%d",&yuzde);
	} while(yuzde>100-pay_t);
	printf("GIRILECEK SINAV ICIN YUZDE %d ETKIYECEK\n",yuzde);
	printf("LUTFEN 0-100 ARASI NOT GIRIN\n");
	int sinav_no= dos[q].ogr[0].kontrol[1];
	while(sayi<dos[q].__mevcut) {
		printf("%s\t%s SINAV NOTU",dos[q].ogr[sayi].bilgi.ad,dos[q].ogr[sayi].bilgi.s_ad);
		do {
			scanf("%d",&dos[q].ogr[sayi].not1[sinav_no]);
			if(dos[q].ogr[sayi].not1[sinav_no]<0||dos[q].ogr[sayi].not1[sinav_no]>100)
				printf("___***LUTFEN 0-100 ARASINDA NOT GIRIN***___ \n");
		} while(dos[q].ogr[sayi].not1[sinav_no]<0||dos[q].ogr[sayi].not1[sinav_no]>100);
		dos[q].ogr[sayi].kontrol[1]++;
		dos[q].ogr[sayi].kontrol[sinav_no+4]=yuzde;
		sayi++;
		continue;
	}
}
