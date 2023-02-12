#include <stdio.h>
#include <conio.h>
#define max 100
int main()
{
	int n,i,j;
	float x[max],y[max],F[max][max]={0},h,u,s,p=1,XP;
	printf("Kac nokta cifti oldugunu giriniz :"); // orn; 3
	scanf("%d",&n);
	printf("Xi degerlerini giriniz :\n"); // xi degerlerini girin; 0, 0.4, 0.8
	for(i=0;i<n;i++)
	{
		
		scanf("%f",&x[i]);
	}
	printf("f(xi) degerlerini giriniz :\n"); // f(xi) degerlerini girin; -2, -4, 6
	for(i=0;i<n;i++)
	{
		
		scanf("%f",&y[i]);
	}
	printf("Hangi f(y) degeri için yaklasim istediginizi girin :"); // orn; f(0.1)
	scanf("%f",&XP);
	for(i=0;i<n;i++)
	{
		F[0][i]=y[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			F[i][j]=F[i-1][j+1]-F[i-1][j];
		}
	}
	
	// matrisi yazdiriyoruz
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f\t",F[i][j]);
		}
		printf("\n");
	}
	h=x[1]-x[0];
	u=(XP-x[0])/h;
	s=y[0];
	p=1;
	for(i=1;i<n;i++)
	{
		p*=(u-i+1)/i;
		s=s+(p*F[i][0]);
	}
	printf("x= %f için karsilik gelen Y=%f",XP,s);
	
	getch();
	return 0;
}
