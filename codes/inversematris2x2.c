#include<stdio.h>

int main()
{
    int i,j,x,y;
    double matris[2][2];
    double inv_matris[2][2];
    double katsayi, katsayi2;
    for(i = 0; i<2; i++) {
        for (j=0; j<2; j++) {
            scanf("%lf", &matris[i][j]);
        }
    }

    katsayi = -1*(matris[1][0] / matris[0][0]);
    inv_matris[1][0] = katsayi / ((matris[0][1] * katsayi) + matris[1][1]);
    inv_matris[0][0] = (1 - (matris[0][1] * inv_matris[1][0]))/matris[0][0];

    inv_matris[1][1] = 1 / (matris[1][1] + katsayi*matris[0][1]);
    inv_matris[0][1] = (matris[0][1] * inv_matris[1][1]) / matris[0][0];


    for(i = 0; i<2; i++) {

        for (j=0; j<2; j++) {

            printf("%f ", inv_matris[i][j]);
        }
        printf("\n");
    }
}
