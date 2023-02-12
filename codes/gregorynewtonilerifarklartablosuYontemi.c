#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float fact(int a)
{
  float fac = 1;

  if (a == 0 || a==1)
   return (1);
  else
   fac = a * fact(a-1);

  return(fac);
}


int main()
{
    int n;
    printf("Kac nokta cifti oldugunu giriniz\n");
    scanf("%d",&n);
    float x[n],y[n][n],p;
    int i,j,k=0;
    printf("Sirayla x ve f(x) degerlerini girin \n");


    for(i=0; i<n; i++)
  {
   printf("\n\n x%d degerini girin: ",i);
   scanf("%f",&x[i]);
   printf("\n\n f(x%d) degerini girin: ",i);
   scanf("%f",&y[k][i]);
  }



  printf("\n\nHangi f(x) degeri icin yaklasim istiyorsaniz onu girin: ");
  scanf("%f",&p);



  for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
     y[i][j]=y[i-1][j+1]-y[i-1][j];
    }
  }


  for(i=0;i<n;i++)
  {
    printf("\n %.3f",x[i]);
    for(j=0;j<n-i;j++)
    {
     printf("   ");
     printf(" %.3f",y[j][i]);
    }
   printf("\n");
  }
  float a=x[0];
  printf("x0 degerimiz %f\n",a);
  float ans=y[0][0];
  printf("ilk farkimiz %f\n",ans);
  float h=x[1]-x[0];
  printf("h degerimiz (x''ler arasindaki fark) %f\n",h);
  float m=(p-a)/h;
  printf("k degerimiz ((x-x0)/h) %f\n",m);

  float arr_m[n];
  arr_m[1]=m;
  for(i=2;i<n;i++)
  {
      arr_m[i]=arr_m[i-1]*(m-1)/fact(i);
  }

  printf("\n#######\n");
  for(i=1;i<n;i++)
  {
      printf("%f \n",arr_m[i]);
  }

  printf("\n#######\n");
  printf("%f +",ans);

  for(i=1;i<n;i++)
  {

     float  temp=y[i][0]*arr_m[i];
      printf("%f +",temp);
      ans=ans+temp;

  }

  printf("\nGirilen f(x) degerine gore cevap %f ",ans);








return 0;

}
