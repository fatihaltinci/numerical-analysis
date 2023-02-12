#include<stdio.h>
#include<stdlib.h>
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
int a[MAX];
int i,d;
float h,down,up,n,S,j,v=0.0;
float b=0.0;
int c=1;


	printf("Fonksiyon derecesi:\n");
	scanf("%d",&d);
	for(i=d;0<=i;i--)
	{
		printf("%d.dereceden elemanin katsayisi: \n",i);
		scanf("%d",&a[i]);
    }
    printf("Alt ve ust degerler: \n");
    scanf("%f",&down);
    scanf("%f",&up);
    printf("n: \n");
    scanf("%f",&n);
	h=(up-down)/n;
	j=h;
	while(down+h!=up)
	{
		if(c%2==0)
		{
			v=v+(returnValue(down+h,d,a));
	h=h+j;
	c++;
		}
		else{
			b=b+(returnValue(down+h,d,a));
	h=h+j;
	c++;
		}	
	}
	v=v*2;
	b=b*4;
	
	S=(j/3)*(returnValue(down,d,a)+returnValue(up,d,a)+b+v);
	printf("Integral sonucu: %f",S);
}

