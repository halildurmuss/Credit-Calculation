#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*  Fonksiyonun prototipleri*/
double aylikOdemeHesapla(double krediTutari, double faizOrani, double taksitSayisi);
double taksitTutariHesapla(double krediTutari, double faizOrani, double taksitSayisi);

int main(int argc, char *argv[]) 
{
	double krediTutari;  // Girilen kredi miktari
	double faizOrani;    // Girilen faiz orani
	double taksitSayisi; // Girilen taksit sayisi;
	
	// Toplam kredi miktar� kullan�c�dan al�n�r.

	printf("Toplam kredi miktari: ");
	scanf("%lf", &krediTutari);
	
	// Faiz oran� kullan�c�dan al�n�r.
	printf("Faiz orani: ");
	scanf("%lf", &faizOrani);
	
	// Taksit says�s� kullan�c�dan al�n�r.
    
	printf("Taksit sayisi: ");
	scanf("%lf", &taksitSayisi);
	
	// Verilen fonksiyonu �a��rarak ve i�lemler yap�l�r ve tablo ekranda g�sterilir.
	aylikOdemeHesapla(krediTutari, faizOrani, taksitSayisi);
	return 0;
}

/* Alt fonksiyon*/
double aylikOdemeHesapla(double krediTutari, double faizOrani, double taksitSayisi)
{
	
	int taksitNo = 1;     				// Taksit say�s�n� g�sterir.
	double taksitTutari; 				// Hesaplanan taksit tutarini saklar.
	double odenenFaizTutari; 	 		// �denen faiz tutar�n� saklar.
	double odenenAnaParaTutari; 		// �denen ana para tutar�n� saklar.
	double kalanAnaParaBorcu;			// Kalan ana para borcunu saklar.
	double toplamKrediOdemesi = krediTutari;    // Toplam kredi �demsini hesaplar ve tutar
	
	// Taksit tutar� hesaplayan alt fonksiyon �a�r�lmas�
	taksitTutari = taksitTutariHesapla(krediTutari,  faizOrani, taksitSayisi);
	
	odenenFaizTutari = krediTutari * faizOrani / 100;  		// �denen faiz tutar� hesab�
	odenenAnaParaTutari = taksitTutari - odenenFaizTutari; 	// �denen ana para tutar� hesab�
	kalanAnaParaBorcu = krediTutari - odenenAnaParaTutari;  // Kalan ana para borcu hesab�
	
	
	printf("\nTaksit No\tTaksit Tutari\tOdenen Faiz Tutari\tOdenen Ana Para Tutari\tKalan Ana Para Borcu\n");
	
	while(taksitNo <= taksitSayisi)
	{
	
		printf("%2d%20.2f%20.2f%25.2f%25.2f\n", taksitNo, taksitTutari, odenenFaizTutari, odenenAnaParaTutari, kalanAnaParaBorcu);
		
		toplamKrediOdemesi = toplamKrediOdemesi + odenenFaizTutari;           // Toplam kredi �demesi hesab�
	    odenenFaizTutari = kalanAnaParaBorcu * faizOrani / 100;   		      // �denen faiz tutar� hesab�
	    odenenAnaParaTutari = taksitTutari - odenenFaizTutari;    			 // �denen ana para tutar� hesab�
	    kalanAnaParaBorcu = kalanAnaParaBorcu - odenenAnaParaTutari; 		 // Kalan ana para borcu hesab�
		taksitNo = taksitNo + 1;
		
	
	}
	
	printf("\nAylik odemeniz:  %.2f\n", taksitTutari);
	printf("Toplam Kredi �demesi:  %.2f", toplamKrediOdemesi);

}


/* Verilen form�le g�re taksit tutar� hesab� yapan fonsksiyon*/
double taksitTutariHesapla(double krediTutari, double faizOrani, double taksitSayisi)
{
	return krediTutari * ( faizOrani / 100 * pow(1 + faizOrani  / 100, taksitSayisi) ) / ( pow(1 + faizOrani / 100, taksitSayisi) - 1) ;
}

