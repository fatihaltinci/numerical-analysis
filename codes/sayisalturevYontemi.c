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



int main()
{ 
float m,k,h;
int d,a[MAX],t,i;
	printf("Fonksiyon derecesi: \n");
	scanf("%d",&d);
	for(i=d;0<=i;i--)
	{
		printf("%d.dereceden elemanin katsayisi: \n",i);
		scanf("%d",&a[i]);		
	}
		printf("Turev noktasi: \n");
		scanf("%f",&k);
		printf("h: \n");
		scanf("%f",&h);
		printf("ileri fark:1 geri fark:2 merkezi fark:3 \n");
		scanf("%d",&t);
		if(t==1)
		{
			m=(returnValue(k+h,d,a)-returnValue(k,d,a))/h;
			printf("ileri fark: %f",m);
		}
		else if(t==2)
		{
			m=(returnValue(k,d,a)-returnValue(k-h,d,a))/h;
			printf("geri fark: %f",m);
		}
		else if(t==3)
		{
			
				m=(returnValue(k+h,d,a)-returnValue(k-h,d,a))/(h*2);
				printf("merkezi fark: %f",m);
		}
	
	
	
	
}

