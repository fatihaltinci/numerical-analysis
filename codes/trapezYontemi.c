#include <stdio.h>
#include <conio.h>

float fonksiyon(float x)
{
	return( ((x) + (1/x)) * ((x) + (1/x))); // (x + 1/x)^2 ---- 1 ve 2 aralýðýnda cevap 5.125
}

int main()
{
	float x0,xn,h,s;
	int i,n;
	printf("Aralik sayisini girin :");
	scanf("%d",&n);
	printf("Integralin alt sinirini girin :");
	scanf("%f",&x0);
	printf("Integralin ust sinirini girin :");
	scanf("%f",&xn);
	h=(xn-x0)/n;
	s=fonksiyon(x0)+fonksiyon(xn);
	for(i=1;i<n;i++)
	{
		s=s+2*fonksiyon(x0+(i*h));
	}
	s=s*(h/2);
	printf("\nIntegralin degeri : %f",s);
	return 0;
}
