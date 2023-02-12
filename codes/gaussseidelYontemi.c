#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
	
	int c=0,p=1,l=1;
	float b[10];
	float a[10][10];
	float x[10];
	float y[10];
	float z,x1,y1,z1,sum,error;
	int i,j,h,k,n;
	printf("Denklem sayisi: ");
	scanf("%d",&n);
	printf("Matris: (capraz carpimlar max olacak sekilde) \n");
	printf("Bilinmeyenlerin baslangic degerleri: (verilmediyse 0 giriniz))\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
for(i=0;i<n;i++)
	{
		printf("%d. denklemin bilinmeyenlerinin  katsayilari: ",i+1);
				for(j=0;j<n;j++)
	    	{		
			scanf("%f",&a[i][j]);
	        }
			if(j==n)
			    {
				printf("%d. denklemin sonucu: ",i+1);
				scanf("%f",&a[i][n]);
			    }	
   }
   printf("hata miktari: \n");
	scanf("%f",&error);

	do{
		
		for(i=0;i<n;i++)
{
	sum=0;
	
	for(j=0;j<n;j++)
	{
	     if(i!=j)
	    {
	    	sum=sum+(a[i][j]*x[j]);
		}	
	}
	y[i]=x[i];
	x[i]=(1/a[i][i])*(a[i][n]-sum);	
	
	
}
printf("%d. iterasyon x[%d]=%f,x[%d]=%f,x[%d]=%f\n",l,p-1,x[p-1],p,x[p],p+1,x[p+1]);
	l++;
	}while	(fabs(y[i-1]-x[i-1])>error);	
	
   	
	
   
   
   
for(i=0;i<n;i++)
   {
   	printf("kokler: %f\n",x[i]);
   }




	
	return 0;}
