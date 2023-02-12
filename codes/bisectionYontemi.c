#include<stdio.h>
#include<stdlib.h>

float fonksiyon(float x) // fonksiyon tan�ml�yoruz.
{
	float y;
    	y = (x*x)-(4*x)-5; // x k�p + 8x -1 > 3 reel k�k� var, bir k�k� (0,1) aral���nda >>> 0.125 
        return y;
}

void bisectionYontemi(double a, double b)
{
    if (fonksiyon(a) * fonksiyon(b) >= 0)
    {
        printf("Bu aralikta kok yok\n");
        return;
    }

    double c, hataPayi=0.001;
    while ((b-a) >= hataPayi)

    {
        c = (a+b)/2; // Orta noktay� ald�k.

        if (fonksiyon(c) == 0.0) // Orta nokta k�k m�?
            break;

        else if (fonksiyon(c)*fonksiyon(a) < 0) // Devam edilecek taraf� se�iyoruz. (K�k negatif tarafta olmal�)
            b = c;
        else
            a = c;
    }

printf("Kok %f\n",c);
}

int main()

{
double a, b;
a=-5; b=-2;
bisectionYontemi(a,b);
return 0;
}
