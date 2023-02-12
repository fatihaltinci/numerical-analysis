#include <stdio.h>
#include <conio.h>

int main()
{
	float a[20][20],x[30],s,m;
	int i,j,n,k;
	printf("Denklem sayisini girin:"); // Lineer denklem sistemlerini çözdüðümüz için denklem sayýsýný belirliyoruz
	scanf("%d",&n);
	printf("Genisletilmis katsayilar matrisi formatinda denklemlerin katsayilarini sirayla girin:\n"); // Lineer denklemlerin katsayýlarýný giriyoruz (geniþletilmiþ katsayýlar matrisi formatýnda) >>>> x + y = z
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
	printf("\nGenisletilmis Katsayilar Matrisi:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	// genisletilmis katsayilar matrisi ust ucgen matrise donusturuyoruz
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			m=a[j][i]/a[i][i];
			for(k=i;k<=n+1;k++)
			{
				a[j][k]=a[j][k]-m*a[i][k];
			}
		}
	}
	printf("\nUst Ucgen Matrisi:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	x[n]=a[n][n+1]/a[n][n];
	for(i=n-1;i>=1;i--)
	{
		s=0.0;
		for(j=i+1;j<=n;j++)
		{
			s=s+a[i][j]*x[j];
		}
		x[i]=(a[i][n+1]-s)/a[i][i];
	}
	for(i=1;i<=n;i++)
	{
		printf("\nX[%d]:%.2f",i,x[i]);
	}
	return 0;
}
