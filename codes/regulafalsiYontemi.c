#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

float returnValue(float k,int d,int a[MAX])
{
	int i,n,m,p;
	float j;
	float sum=0;
 n=d;
 j=k;
 for(m=0;m<n;m++)
 {
 	for(i=d-1;0<i;i--)
 	{
 		k=k*j;
	}
	k=k*a[d];
	sum=sum+k;
	d=d-1;
	k=j;
	if(d==0)
	{
		sum=sum+a[d];
	}	 
 }
return sum;
}


int main() {
		
	int a[MAX];
int i,d,p;
float u=2.0,x,y;
float z,k,l,first,second,error;
int h=1;


	printf("Fonksiyon derecesi: \n");
	scanf("%d",&d);
	for(i=d;0<=i;i--)
	{
		printf("%d.dereceden elemanin katsayisi: \n",i);
		scanf("%d",&a[i]);		
	}
			printf("fonksiyon araliginin ilk degeri: \n");
            scanf("%f",&k);
            first=returnValue(k,d,a);
            printf("fonksiyonun araliginin ikinci degeri: \n");
            scanf("%f",&l);
            second=returnValue(l,d,a);
            
            if(first==0 && second!=0)
            {
            	printf("Sinir degerlerinden birincisi koktur. (%f)",k);
			}
            else if(first!=0 && second==0)
            {
            		printf("Sinir degerlerinden ikincisi koktur. (%f)",l);
			}
			else if(first==0 && second==0)
			{
				printf("sinir degerleri koktur. (%f,%f)",k,l);
			}
			else
			{
            printf("hata miktari: \n");
	        scanf("%f",&error);
            
            while(first*second<0 && fabs(k-l)/u>error)
            {
            	x=((k*second)-(l*first))/(second-first);
            	if(returnValue(x,d,a)>0) l=x;
	            else k=x;
            	first=returnValue(k,d,a);
            	second=returnValue(l,d,a);
            	u=u*2;
            	printf("%d.iterasyondaki x degeri: %f\n",h,x);
            	h++;
			}
			printf("Kokun degeri: %f ",x);
		}
	return 0;}

