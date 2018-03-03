#include<stdio.h>/*PROGRAM:BENZİN İSTASYONU TAKİP OTOMASYONU*/
#include<stdlib.h> 

int main() {



	int numara;
	char tip;
	char D,d,L,l,B,b;
	float dizel=5.15,benzin=3.20,lpg=1.85,dlitre,blitre,llitre;
	int dmiktar,bmiktar,lmiktar;
	int toplamdizel=1000;
	float kalanlitred=1000,toplamlitred=0,kalanfiyatd=0,toplamfiyatd=0;
	int toplambenzin=1000;
	float kalanlitreb=1000,toplamlitreb=0,kalanfiyatb=0,toplamfiyatb=0;
	int toplamlpg=1000;
	float kalanlitrel=1000,toplamlitrel=0,kalanfiyatl=0,toplamfiyatl=0;




	printf("\t--------------BENZiN iSTASYONU TAKiP OTOMASYONU--------------\n");
	printf("\n1. BiRiM FiYATi GOSTER");
	printf("\n2. BiRiM FiYATi GUNCELLE");
	printf("\n3. AKARYAKiT SATiSi YAP");
	printf("\n4. DEPO DURUMUNU GOSTER");
	printf("\n5. TOPLAM SATiSLARi GOSTER");
	printf("\n7. CiKiS");
	printf("\n----------------------------");






	while(numara>=0) { /*ana while*/


		scanf("%d",&numara);





		switch(numara) {

			case 1:  /*akaryakıt fiyatları*/


				printf("\n\n---BiRiM FiYATLAR LiSTESi---\n\n");
				printf("DiZEL(D) = %.2f YTL\n",dizel);
				printf("BENZiN(B)= %.2f YTL\n",benzin);
				printf("LPG(L)   = %.2f YTL\n",lpg);
				printf("\n----------------------------");
				break;


			case 2:/*FİATLARI GÜNCELLEME*/



				printf("\n\n---BiRiM FiYATLARI GUNCELLE---\n\n");
				printf("AKARYAKiT TiPiNi SECiN(D-B-L)=");
				getchar();
				scanf("%s",&tip);



				switch(tip) {

					case 'D':
					case 'd':

						printf("DiZEL(D) = %.2f YTL\n",dizel);
						printf("YENi FiYATi GiRiN=",dizel);
						scanf("%f",&dizel);
						printf("\nYENi DiZEL FiYATiNiZ=%.2f",dizel);
						printf("\nGUNCELLEME TAMAM");
						printf("\n\n\n2.MENUDEN CiKMAK iCiN BiR SAYi GiRiN=");
						scanf("%d",&numara);
						break;



					case 'B':
					case 'b':

						printf("\nBENZiN(B)= %.2f YTL\n",benzin);
						printf("YENi FiYATi GiRiN=",benzin);
						scanf("%f",&benzin);
						printf("YENi BENZiN FiYATiNiZ=%.2f",benzin);
						printf("\nGUNCELLEME TAMAM");
						printf("\n\n\n2.MENUDEN CiKMAK iCiN BiR SAYi GiRiN=");
						scanf("%d",&numara);
						break;



					case 'L':
					case 'l':


						printf("LPG(L)= %.2f YTL\n",lpg);
						printf("YENi FiYATi GiRiN=",lpg);
						scanf("%f",&lpg);
						printf("YENi LPG FiYATiNiZ=%.2f",lpg);
						printf("\nGUNCELLEME TAMAM");
						printf("\n\n\n2.MENUDEN CiKMAK iCiN BiR SAYi GiRiN=");
						scanf("%d",&numara);
						break;

					default:
						printf("\n\n!!HATA!! YANLiS SECiM.");


				}/*switch(tip)in parantezi*/

				break;







			case 3:  /*akaryakıt satış işlemi*/

				printf("\n\n----AKARYAKiT SATiS iSLEMi---");
				printf("\n\nAKARYAKiT TiPiNi SECiN(D-B-L)=");
				getchar();
				scanf("%s",&tip);




				switch(tip) {
					case 'd':
					case 'D':


						printf("KAC YTL'LiK DiZEL ALACAKSiNiZ=");
						scanf("%d",&dmiktar);


						dlitre=dmiktar/dizel;
						toplamlitred=toplamlitred+dlitre;
						kalanlitred=toplamdizel-toplamlitred;
						kalanfiyatd=kalanlitred*dizel;
						toplamfiyatd=toplamfiyatd+(toplamlitred*dizel)-toplamfiyatd;

						if(kalanfiyatd>toplamfiyatd) {
							printf("\n<<<<DEPOMUZDA %4.f YTL'LiK DiZEL KALMiSTiR>>>>\n",kalanfiyatd);
							printf("\n****iSLEM TAMAM DOLUM YAPiLMMiSTiR****\n");
							printf("\n----MUSTERiMiZE HAYiRLi YOLCULUKLAR----");

						}



						else
							printf("\nUZGUNUZ DEPOMUZDA O KADAR YOK\n");
						break;




					case 'b':
					case 'B':


						printf("KAC YTL'LiK BENZiN ALACAKSiNiZ=");
						scanf("%d",&bmiktar);


						blitre=bmiktar/benzin;
						toplamlitreb=toplamlitreb+blitre;
						kalanlitreb=toplambenzin-toplamlitreb;
						kalanfiyatb=kalanlitreb*benzin;
						toplamfiyatb=toplamfiyatb+(toplamlitreb*benzin)-toplamfiyatb;

						if(kalanfiyatb>toplamfiyatb) {
							printf("\n<<<<DEPOMUZDA %4.f YTL'LiK BENZiN KALMiSTiR>>>>\n",kalanfiyatb);
							printf("\n****iSLEM TAMAM DOLUM YAPiLMMiSTiR****\n");
							printf("\n----MUSTERiMiZE HAYiRLi YOLCULUKLAR----");
						}

						else
							printf("\nUZGUNUZ DEPOMUZDA O KADAR YOK\n");

						break;




					case 'l':
					case 'L':


						printf("KAC YTL'LiK LPG ALACAKSiNiZ=");
						scanf("%d",&lmiktar);


						llitre=lmiktar/lpg;
						toplamlitrel=toplamlitrel+llitre;
						kalanlitrel=toplamlpg-toplamlitrel;
						kalanfiyatl=kalanlitrel*lpg;
						toplamfiyatl=toplamfiyatl+(toplamlitrel*lpg)-toplamfiyatl;

						if(kalanfiyatl>toplamfiyatl) {
							printf("\n<<<<DEPOMUZDA %4.f YTL'LiK LPG KALMiSTiR>>>>\n",kalanfiyatl);
							printf("\n****iSLEM TAMAM DOLUM YAPiLMMiSTiR****\n");
							printf("\n----MUSTERiMiZE HAYiRLi YOLCULUKLAR----");
						}

						else
							printf("\nUZGUNUZ DEPOMUZDA O KADAR YOK\n");
						break;



					default:
						printf("\n!HATALi SECiM!\n");
						break;



				}
				break;/*3.menunun*/












				/*<<<<<FOR DÖNGÜSÜ İLE COK UGRAŞTIM AMA YAPAMADIM>>>>>*/
				/*<<<<SON ÇARE BU ŞEKİLDE YAPTIM>>>>*/
			case 4:
				if(toplamlitred<=100) {
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}



				if(toplamlitred<=200&&toplamlitred>100) {
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}

				if(toplamlitred<=300&&toplamlitred>200) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}

				if(toplamlitred<=400&&toplamlitred>300) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}

				if(toplamlitred<=500&&toplamlitred>400) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}

				if(toplamlitred<=600&&toplamlitred>500) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}

				if(toplamlitred<=700&&toplamlitred>600) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}
				if(toplamlitred<=800&&toplamlitred>700) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}
				if(toplamlitred<=900&&toplamlitred>800) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}
				if(toplamlitred<=1000&&toplamlitred>900) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]\n");
					printf("\n    DiZEL\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitred);

				}






				/*benzin depo kontrol*/
				if(toplamlitreb<=100) {
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}



				if(toplamlitreb<=200&&toplamlitreb>100) {
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}

				if(toplamlitreb<=300&&toplamlitreb>200) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}

				if(toplamlitreb<=400&&toplamlitreb>300) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}

				if(toplamlitreb<=500&&toplamlitreb>400) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}

				if(toplamlitreb<=600&&toplamlitreb>500) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}

				if(toplamlitreb<=700&&toplamlitreb>600) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}
				if(toplamlitreb<=800&&toplamlitreb>700) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}
				if(toplamlitreb<=900&&toplamlitreb>800) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n  BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}
				if(toplamlitreb<=1000&&toplamlitreb>900) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]\n");
					printf("\n   BENZiN\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitreb);

				}




				/*lpg depo kontrol*/
				if(toplamlitrel<=100) {
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=200&&toplamlitrel>100) {
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=300&&toplamlitrel>200) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=400&&toplamlitrel>300) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=500&&toplamlitrel>400) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=600&&toplamlitrel>500) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}

				if(toplamlitrel<=700&&toplamlitrel>600) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}
				if(toplamlitrel<=800&&toplamlitrel>700) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}
				if(toplamlitrel<=900&&toplamlitrel>800) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}
				if(toplamlitrel<=1000&&toplamlitrel>900) {
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[          ]");
					printf("\n[**********]\n");
					printf("\n    LPG\n");
					printf("\nKALAN=%2.f LiTRE\n",kalanlitrel);

				}





				break;









			case 5:/*toplam satışlar*/

				printf("\n------TOPLAM SATiSLAR-------\n\n");

				printf("\nSATMiS OLDUGUNUZ TOPLAM <<<DiZEL>>> LiTRE=%3.f lt\n",toplamlitred);
				printf("\nKAZANMiS OLDUGUNUZ TOPLAM YTL=%3.f YTL\n",toplamfiyatd);
				printf("\n\nSATMiS OLDUGUNUZ TOPLAM <<<BENZiN>>> LiTRE=%3.f lt\n",toplamlitreb);
				printf("\nKAZANMiS OLDUGUNUZ TOPLAM YTL=%3.f YTL\n",toplamfiyatb);
				printf("\n\nSATMiS OLDUGUNUZ TOPLAM <<<LPG>>> LiTRE=%3.f lt\n ",toplamlitrel);
				printf("\nKAZANMiS OLDUGUNUZ TOPLAM YTL=%3.f YTL\n",toplamfiyatl);


				break;



			case 7:/*programı bitirme*/

				printf("\n\n\n----PROGRAM SONLANDiRiLDi----\n\n");

				system("PAUSE");
				return 0;

			default:
				printf("\n!!HATALi NUMARA!!\n");
				break;





		}/*ana switch*/

	}/*ana while'in*/






	system("PAUSE");

	return 0;
}
