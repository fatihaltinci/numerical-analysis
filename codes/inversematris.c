#include<stdio.h>
#include<math.h>

float determinant(float [][25], float);
void kofaktor(float [][25], float);
void transpoz(float [][25], float [][25], float);


// Matrisin determinantını hesaplama
float determinant(float a[25][25], float k){
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1){
     return (a[0][0]);
    }
  else{
     det = 0;
     for (c = 0; c < k; c++){
        m = 0;
        n = 0;
        for (i = 0;i < k; i++){
            for (j = 0 ;j < k; j++){
                b[i][j] = 0;
                if (i != 0 && j != c){
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else{
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
    return (det);
}

// Matrisin kofaktörünü bulma
void kofaktor(float num[25][25], float f){
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++){
   for (p = 0;p < f; p++){
     m = 0;
     n = 0;
     for (i = 0;i < f; i++){
       for (j = 0;j < f; j++){
          if (i != q && j != p){
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else{
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpoz(num, fac, f);
}

// Matrisin transpozunu bulma
void transpoz(float num[25][25], float fac[25][25], float r){
  int i, j;
  float b[25][25], inverse[25][25], d;
  for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nMatrisin tersi: \n");
   for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }
}


int main()
{
  float a[25][25], k, d;
  int i, j;
  printf("Matrisin kaclik bir matris oldugunu girin: "); // NxN olduğu için 2lik 2x2, 3lük 3x3, 4lük 3x3
  scanf("%f", &k);
  printf("%.0fX%.0f matrisin elemanlarini sirayla girin: \n", k, k);
  for (i = 0;i < k; i++){
     for (j = 0;j < k; j++){
        scanf("%f", &a[i][j]);
        }
    }
  d = determinant(a, k);
  if (d == 0)
   printf("\nDeterminanti sifir oldugundan matrisin tersi yoktur.\n");
  else
   kofaktor(a, k);
}

