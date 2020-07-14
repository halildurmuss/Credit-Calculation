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
	
	// Toplam kredi miktarý kullanýcýdan alýnýr.

	printf("Toplam kredi miktari: ");
	scanf("%lf", &krediTutari);
	
	// Faiz oraný kullanýcýdan alýnýr.
	printf("Faiz orani: ");
	scanf("%lf", &faizOrani);
	
	// Taksit saysýsý kullanýcýdan alýnýr.
    
	printf("Taksit sayisi: ");
	scanf("%lf", &taksitSayisi);
	
	// Verilen fonksiyonu çaðýrarak ve iþlemler yapýlýr ve tablo ekranda gösterilir.
	aylikOdemeHesapla(krediTutari, faizOrani, taksitSayisi);
	return 0;
}

/* Alt fonksiyon*/
double aylikOdemeHesapla(double krediTutari, double faizOrani, double taksitSayisi)
{
	
	int taksitNo = 1;     				// Taksit sayýsýný gösterir.
	double taksitTutari; 				// Hesaplanan taksit tutarini saklar.
	double odenenFaizTutari; 	 		// Ödenen faiz tutarýný saklar.
	double odenenAnaParaTutari; 		// Ödenen ana para tutarýný saklar.
	double kalanAnaParaBorcu;			// Kalan ana para borcunu saklar.
	double toplamKrediOdemesi = krediTutari;    // Toplam kredi ödemsini hesaplar ve tutar
	
	// Taksit tutarý hesaplayan alt fonksiyon çaðrýlmasý
	taksitTutari = taksitTutariHesapla(krediTutari,  faizOrani, taksitSayisi);
	
	odenenFaizTutari = krediTutari * faizOrani / 100;  		// Ödenen faiz tutarý hesabý
	odenenAnaParaTutari = taksitTutari - odenenFaizTutari; 	// Ödenen ana para tutarý hesabý
	kalanAnaParaBorcu = krediTutari - odenenAnaParaTutari;  // Kalan ana para borcu hesabý
	
	
	printf("\nTaksit No\tTaksit Tutari\tOdenen Faiz Tutari\tOdenen Ana Para Tutari\tKalan Ana Para Borcu\n");
	
	while(taksitNo <= taksitSayisi)
	{
	
		printf("%2d%20.2f%20.2f%25.2f%25.2f\n", taksitNo, taksitTutari, odenenFaizTutari, odenenAnaParaTutari, kalanAnaParaBorcu);
		
		toplamKrediOdemesi = toplamKrediOdemesi + odenenFaizTutari;           // Toplam kredi ödemesi hesabý
	    odenenFaizTutari = kalanAnaParaBorcu * faizOrani / 100;   		      // Ödenen faiz tutarý hesabý
	    odenenAnaParaTutari = taksitTutari - odenenFaizTutari;    			 // Ödenen ana para tutarý hesabý
	    kalanAnaParaBorcu = kalanAnaParaBorcu - odenenAnaParaTutari; 		 // Kalan ana para borcu hesabý
		taksitNo = taksitNo + 1;
		
	
	}
	
	printf("\nAylik odemeniz:  %.2f\n", taksitTutari);
	printf("Toplam Kredi Ödemesi:  %.2f", toplamKrediOdemesi);

}


/* Verilen formüle göre taksit tutarý hesabý yapan fonsksiyon*/
double taksitTutariHesapla(double krediTutari, double faizOrani, double taksitSayisi)
{
	return krediTutari * ( faizOrani / 100 * pow(1 + faizOrani  / 100, taksitSayisi) ) / ( pow(1 + faizOrani / 100, taksitSayisi) - 1) ;
}

