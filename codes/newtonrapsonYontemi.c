#include<stdio.h>
#include<math.h> 


float fonksiyon(float x) // fonksiyon tan�ml�yoruz.
{
 return (x*x-2*x+1);
}
 
//definition of the function fd(x)
float fonksiyonTurevi(float x) // fonksiyonun t�revini tan�ml�yoruz.
{
 return (2*x-2);
}

int main()
{
 int k=0; // ad�m say�s�n� (iterasyon) giriyoruz.
 float x1,x0; // ba�lang�� de�erini giriyoruz.
 float hataPayi=0.001; // hata pay�n� tan�ml�yoruz.
 float fonksiyon(float x);
 float fonksiyonTurevi(float x);
 printf("\nBaslangic degerini girin: ");
 scanf("%f",&x0);
 x1=x0;
 while(1)
 {
 x0=x1;
 k++;
 x1=x0-fonksiyon(x0)/fonksiyonTurevi(x0);
 printf("%d. iterasyonda gelen deger %8.5f\n",k,x1);
 
 if (fabs(x1-x0) < hataPayi) // mutlak de�eri
	 break;
 }
return 0;
}

