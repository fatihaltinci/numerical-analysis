#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#define MAX_DERECE 10
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

float determinant(float [][25], float);
void kofaktor(float [][25], float);
void transpoz(float [][25], float [][25], float);
float degeriGetir(float k, int d, int a[MAX]);

float cot(float x) {
    return 1.0 / tan(x);
}

float sec(float x) {
    return 1.0 / cos(x);
}

float csc(float x) {
    return 1.0 / sin(x);
}

float fonksiyon(float x, float katsayilar[MAX_DERECE+1], int derece) {
    float y = 0.0;
    for (int i = derece; i >= 0; i--) {
        y += katsayilar[i] * pow(x, i);
    }
    return y;
}


float fonksiyonTurevi(float x, float katsayilar[MAX_DERECE+1], int derece) {
    float y = 0.0;
    for (int i = derece; i >= 1; i--) {
        y += i * katsayilar[i] * pow(x, i - 1);
    }
    return y;
}

float trigoFonksiyon(float x, int TrigoFonksiyonTipi) {
    switch (TrigoFonksiyonTipi) {
        case 1: 
            printf("sin(%f) = %f\n", x, sin(x));
            return sin(x);
        case 2: 
            printf("cos(%f) = %f\n", x, cos(x));
            return cos(x);
        case 3: 
            printf("tan(%f) = %f\n", x, tan(x));
            return tan(x);
        case 4: 
            printf("cot(%f) = %f\n", x, cot(x));
            return cot(x);
        case 5:
            printf("sec(%f) = %f\n", x, sec(x));
            return sec(x);
        case 6:
            printf("csc(%f) = %f\n", x, csc(x));
            return csc(x);
        default:
            printf("Gecersiz fonksiyon tipi.\n");
            return 0.0;
    }
}


float ustelFonksiyon(float x, float a) {
    printf("%f^%f = %f\n", a, x, pow(a, x));
    return pow(a, x);
}

float logaritmikFonksiyon(float x, float a) {
    return log(x) / log(a);
}


void bisectionYontemi(float a, float b, float katsayilar[MAX_DERECE + 1], int derece)
{
    if (fonksiyon(a, katsayilar, derece) * fonksiyon(b, katsayilar, derece) >= 0)
    {
        printf("Bu aralikta kok yok\n");
        return;
    }

    printf("Hata payi girin (varsayilan: 0.001): \n");
    double c, hataPayi;
    scanf("%lf", &hataPayi);
    int iterasyon = 1;

    while ((b - a) >= hataPayi)
    {
        c = (a + b) / 2; // Orta noktayi aldik

        printf("Iterasyon %d: Aralik [%.6f, %.6f], Tahmin: %.6f\n", iterasyon, a, b, c);

        if (fonksiyon(c, katsayilar, derece) == 0.0)
        { // Orta nokta kok mu?
            printf("Kok: %.6f\n", c);
            return;
        }
        else if (fonksiyon(c, katsayilar, derece) * fonksiyon(a, katsayilar, derece) < 0)
        { // Devam edilecek tarafi seciyoruz. (Kok negatif tarafta olmali)
            b = c;
        }
        else
        {
            a = c;
        }

        iterasyon++;
    }

    printf("Yaklasik Kok: %.6f\n", c);
}

void trigoBisectionYontemi(float a, float b, int fonksiyonTipi) {
    // printf("%d", trigoFonksiyon(a, fonksiyonTipi) * trigoFonksiyon(b, fonksiyonTipi));
    if (trigoFonksiyon(a, fonksiyonTipi) * trigoFonksiyon(b, fonksiyonTipi) >= 0) {
        printf("Bu aralikta kok yok.\n");
        return;
    }
    printf("Hata payi girin (varsayilan: 0.001): \n");
    float c, hataPayi;
    scanf("%f", &hataPayi);
    int iteration = 0;

    do {
        iteration++;
        c = (a + b) / 2;

        if (fabs(trigoFonksiyon(c, fonksiyonTipi)) < hataPayi) {
            printf("Kok: %f\n", c);
            printf("Iterasyon sayisi: %d\n", iteration);
            return;
        }

        if (trigoFonksiyon(a, fonksiyonTipi) * trigoFonksiyon(c, fonksiyonTipi) < 0)
            b = c;
        else
            a = c;
    } while (fabs(b - a) >= hataPayi);

    printf("Kok: %f\n", c);
    printf("Iterasyon sayisi: %d\n", iteration);
} 

void ustelBisectionYontemi(float a, float b, float parametre) {
    float hataPayi;
    printf("Hata payini girin (varsayilan: 0.001): ");
    scanf("%f", &hataPayi);

    while (fabs(b - a) >= hataPayi) {
        float c = (a + b) / 2.0;
        float fc = ustelFonksiyon(c, parametre);

        if (fc == 0.0) {
            printf("Kok: %f\n", c);
            return;
        } else if (fc * ustelFonksiyon(a, parametre) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Yaklasik kok: %f\n", (a + b) / 2.0);
}

void logaritmikBisectionYontemi(float a, float b, float parametre) {
    float hataPayi;
    printf("Hata payini girin (varsayilan: 0.001): ");
    scanf("%f", &hataPayi);

    while (fabs(b - a) >= hataPayi) {
        float c = (a + b) / 2.0;
        float fc = logaritmikFonksiyon(c, parametre);

        if (fc == 0.0) {
            printf("Kok: %f\n", c);
            return;
        } else if (fc * logaritmikFonksiyon(a, parametre) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Yaklasik kok: %f\n", (a + b) / 2.0);
}

void regulaFalsi(){
	int dizi[MAX];
    int i, d, p;
    float u=2.0, x, y, z, e, f, birinci, ikinci, hataMiktari;
    int h=1;

    printf("Fonksiyon derecesi: \n");
    scanf("%d", &d);
    for(i=d; 0<=i; i--){
        printf("%d.dereceden elemanin katsayisi: \n",i);
        scanf("%d", &dizi[i]);		
    }
        printf("fonksiyon araliginin ilk degeri: \n");
        scanf("%f", &e);
        birinci = degeriGetir(e, d, dizi);
        printf("fonksiyonun araliginin ikinci degeri: \n");
        scanf("%f", &f);
        ikinci = degeriGetir(f, d, dizi);
        
        if(birinci==0 && ikinci!=0){
            printf("Sinir degerlerinden birincisi koktur. (%f)", e);
        }
        else if(birinci!=0 && ikinci==0){
                printf("Sinir degerlerinden ikincisi koktur. (%f)", f);
        }
        else if(birinci==0 && ikinci==0){
            printf("Sinir degerleri koktur. (%f,%f)", e, f);
        }
        else{
        printf("hata miktari: \n");
        scanf("%f",&hataMiktari);
        
        while(birinci*ikinci<0 && fabs(e-f)/u>hataMiktari){
            x = ((e * ikinci) - (f * birinci)) / (ikinci - birinci);
            if (degeriGetir(x, d, dizi) > 0)
                f = x;
            else
                e = x;
            birinci = degeriGetir(e, d, dizi);
            ikinci = degeriGetir(f, d, dizi);
            u = u * 2;

            printf("%d.iterasyondaki x degeri: %f\n", h, x);
            printf("Yapilan islemler: Yeni x degeri=%f, Diger aralik degeri=%f, Yeni f(x) degeri=%f, Diger aralik degeri=%f\n", e, f, birinci, ikinci);

            h++;
        }
        printf("Kokun degeri: %f \n", x);
    }
}


float degeriGetir(float k, int d, int a[MAX]){

    int i,n,m,p;
    float j;
    float sum=0;
    n=d;
    j=k;
    for(m=0;m<n;m++){

        for(i=d-1;0<i;i--){
            k=k*j;
        }

        k=k*a[d];
        sum=sum+k;
        d=d-1;
        k=j;

        if(d==0){
            sum=sum+a[d];
        }

    }

return sum;
}

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

void gaussEliminasyon(){
	float a[20][20],x[30],s,m;
	int i,j,n,k;
	printf("Denklem sayisini girin:"); // Lineer denklem sistemlerini ��zd���m�z i�in denklem say�s�n� belirliyoruz
	scanf("%d",&n);
	printf("Genisletilmis katsayilar matrisi formatinda denklemlerin katsayilarini sirayla girin:\n"); // Lineer denklemlerin katsay�lar�n� giriyoruz (geni�letilmi� katsay�lar matrisi format�nda) >>>> x + y = z
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
		printf("\nX[%d]:%.2f\n\n",i,x[i]);
	}
	
}

void gaussSeidel() {
    int c=0,p=1,l=1;
	float b[10];
	float a[10][10];
	float x[10];
	float y[10];
	float z,x1,y1,z1,sum,error;
	int i,j,h,k,n;
	printf("Denklem sayisi: ");
	scanf("%d",&n);
	printf("Bilinmeyenlerin baslangic degerleri: (verilmediyse 0 giriniz))\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("Matris: (capraz carpimlar max olacak sekilde) \n");
    for(i=0;i<n;i++){
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
		
	for(i=0;i<n;i++){
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
	}while	(fabs(y[i-1]-x[i-1])>=error);	
   
   
    for(i=0;i<n;i++){
   	printf("kokler: %f\n",x[i]);
    }
}

void sayisalTurev(){
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
			m=(degeriGetir(k+h,d,a)-degeriGetir(k,d,a))/h;
			printf("ileri fark: %f",m);
		}
		else if(t==2)
		{
			m=(degeriGetir(k,d,a)-degeriGetir(k-h,d,a))/h;
			printf("geri fark: %f",m);
		}
		else if(t==3)
		{
			
				m=(degeriGetir(k+h,d,a)-degeriGetir(k-h,d,a))/(h*2);
				printf("merkezi fark: %f",m);
		}
}

void simpson1_3(float a, float b, float katsayilar[MAX_DERECE+1], int derece, int n) {
    float h = (b - a) / n;
    float x, fx;
    float integral = 0.0;

    printf("x\t\tf(x)\n");
    printf("--------------------\n");
    
    for (int i = 0; i <= n; i++) {
        x = a + i * h;
        fx = fonksiyon(x, katsayilar, derece);
        printf("%.2f\t%.2f\n", x, fx);

        if (i == 0 || i == n)
            integral += fx;
        else if (i % 2 == 1)
            integral += 4 * fx;
        else
            integral += 2 * fx;
    }

    integral *= h / 3;
    printf("--------------------\n");
    printf("Integral: %.2f\n", integral);
}

void simpson3_8(float a, float b, float katsayilar[MAX_DERECE+1], int derece){
    float h = (b - a) / 3;
    float fa = fonksiyon(a, katsayilar, derece);
    float fb = fonksiyon(b, katsayilar, derece);
    float fx1 = fonksiyon(a + h, katsayilar, derece);
    float fx2 = fonksiyon(a + 2 * h, katsayilar, derece);

    printf("Integral = (b-a/8) * (fa + 3 * fx1 + 3 * fx2 + fb) \n");
    printf("Integral = (%f/8) * (%f + 3 * %f + 3 * %f + %f) \n", b - a, fa, fx1, fx2, fb);

    float integral = fonksiyon(a, katsayilar, derece) + 3 * fonksiyon(a + h, katsayilar, derece) + 3 * fonksiyon(a + 2 * h, katsayilar, derece) + fonksiyon(b, katsayilar, derece);

    integral *= 3 * h / 8; 

    printf("Integral: %f\n", integral);

}

void trapez(float katsayilar[MAX_DERECE+1], int derece){

    float x0,xn,h,s;
	int i,n;
	printf("Aralik sayisini girin :");
	scanf("%d",&n);
	printf("Integralin alt sinirini girin :");
	scanf("%f",&x0);
	printf("Integralin ust sinirini girin :");
	scanf("%f",&xn);
	h=(xn-x0)/n;
	s=fonksiyon(x0, katsayilar, derece)+fonksiyon(xn, katsayilar, derece);
	for(i=1;i<n;i++){
		float xi = x0 + (i * h);
		s += 2 * fonksiyon(xi, katsayilar, derece);
    	printf("x%d: %f, f(x%d): %f\n", i, xi, i, fonksiyon(xi, katsayilar, derece));
	}
	s *= (h / 2);
	printf("\nIntegralin degeri : %f",s);

}

void gregoryNewton(){
    float F[MAX][MAX] = {0};
    int i, j, n;
    float h, u, s, p = 1;
    float x[MAX], y[MAX], XP;

    printf("Kac nokta cifti oldugunu giriniz: ");
    scanf("%d", &n);
    
    printf("x degerlerini giriniz:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    
    printf("f(x) degerlerini giriniz:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }
    
    printf("Hangi x degeri icin yaklasim istediginizi giriniz: ");
    scanf("%f", &XP);

    for (i = 0; i < n; i++) {
        F[0][i] = y[i];
    }
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            F[i][j] = F[i - 1][j + 1] - F[i - 1][j];
        }
    }
    
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f\t",F[i][j]);
		}
		printf("\n");
	}
    
    h = x[1] - x[0];
    u = (XP - x[0]) / h;
    s = y[0];
    p = 1;
    
    for (i = 1; i < n; i++) {
        p *= (u - i + 1) / i;
        s += p * F[i][0];
    }

    printf("x = %f icin karsilik gelen Y = %f\n", XP, s);
    
    printf("f(x) = %f", F[0][0]);
    for (i = 1; i < n; i++) {
        if (F[i][0] != 0) {
            if (F[i][0] > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
            printf("%.2f", fabs(F[i][0]));
            
            for (j = 0; j < i; j++) {
                printf("(x - %.2f)", x[j]);
            }
            printf(" / %d!", i);
        }
    }
    printf("\n");
}

int main() {
    int secim, derece, fonksiyonTipi, iterasyon = 0;
    float katsayilar[MAX_DERECE+1];

    while (1) {
        printf("\n\n----- Sayisal Analiz Projesi -----\n");
        printf("1- Bisection\n");
        printf("2- Regula Falsi\n");
        printf("3- Newton Raphson\n");
        printf("4- NxN'lik Matrisin Tersi\n");
        printf("5- Gauss Eliminasyon\n");
        printf("6- Gauss Seidel\n");
        printf("7- Sayisal Turev (merkezi, ileri, geri farklar)\n");
        printf("8- Simpson\n");
        printf("9- Trapez\n");
        printf("10- Gregory Newton (degisken donusumsuz)\n");
        printf("---------------------------------\n");
        printf("0- Cikis\n");
    
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 0:
                printf("------------------Cikis--------------. \n");
            	printf("Cikis yapildi.");
                return 0;
            case 1:
                printf("------------------Bisection--------------. \n");
                printf("Fonksiyon Tipi (1- Polinom, 2- Trigonometrik, 3- Ustel, 4- Logaritmik): \n");
                printf("Fonksiyon Tipini girin: \n");
                scanf("%d", &fonksiyonTipi);
                if(fonksiyonTipi == 1){
                    printf("Araligin baslangic noktasini girin: ");
                    float a, b;
                    scanf("%f", &a);
                    printf("Araligin bitis noktasini girin: ");
                    scanf("%f", &b);
                    printf("Fonksiyonun kacinci dereceden oldugunu girin: ");
                    scanf("%d", &derece);
                    printf("Fonksiyonun katsayilarini sirasiyla girin: \n");
                    for (int i = derece; i >= 0; i--) {
                        printf("x^%d katsayisi: ", i);
                        scanf("%f", &katsayilar[i]);
                    }
                    bisectionYontemi(a, b, katsayilar, derece);
                }
                else if(fonksiyonTipi == 2){
                    int TrigoFonksiyonTipi;
                    float a, b;
                    printf("Trigonometrik Fonksiyon Tipi (1- sin, 2- cos, 3- tan, 4- cot, 5- sec, 6- csc): \n");
                    scanf("%d", &TrigoFonksiyonTipi);
                    printf("Baslangic derecesini girin: ");
                    scanf("%f", &a);
                    printf("Bitis derecesini girin: ");
                    scanf("%f", &b);
                    trigoBisectionYontemi(a * PI / 180, b * PI / 180, TrigoFonksiyonTipi);
                }
                else if(fonksiyonTipi == 3){
                    float a, b, parametre;
                    printf("Araligin baslangic noktasini girin: ");
                    scanf("%f", &a);
                    printf("Araligin bitis noktasini girin: ");
                    scanf("%f", &b);
                    printf("Ustel fonksiyonun parametresini (tabanini) girin: ");
                    scanf("%f", &parametre);
                    ustelBisectionYontemi(a, b, parametre);
                }
                else if(fonksiyonTipi == 4){
                    float a, b, parametre;
                    printf("Araligin baslangic noktasini girin: ");
                    scanf("%f", &a);
                    printf("Araligin bitis noktasini girin: ");
                    scanf("%f", &b);
                    printf("Logaritmik fonksiyonun parametresini (tabanini) girin: ");
                    scanf("%f", &parametre);
                    logaritmikBisectionYontemi(a, b, parametre);
                }
                fflush(stdin);
                break;
            case 2:
                printf("------------------Regula Falsi--------------. \n");
                regulaFalsi();
                fflush(stdin);
                break;
            case 3:
                printf("------------------Newton Raphson--------------. \n");
                float x1, x0; 
                double hataPayi; 
                printf("Fonksiyonun kacinci dereceden oldugunu girin: ");
                scanf("%d", &derece);
                
                printf("Fonksiyonun katsayilarini sirasiyla girin: \n");
                for (int i = derece; i >= 0; i--) {
                    printf("x^%d katsayisi: ", i);
                    scanf("%f", &katsayilar[i]);
                }
                printf("Hata payi girin (varsayilan: 0.001): \n");
                scanf("%lf", &hataPayi);
                printf("\nBaslangic degerini girin (aralik veriliyorsa kucugu alin): ");
                scanf("%f",&x0);
                x1=x0;
                while(1){
                x0=x1;
                iterasyon++;
                float fx = fonksiyon(x0, katsayilar, derece);
			    float fpx = fonksiyonTurevi(x0, katsayilar, derece);
			    x1 = x0 - fx / fpx;
			    printf("%d. iterasyonda:\n", iterasyon);
			    printf("xn: %8.5f\n", x0);
			    printf("xn+1: %8.5f\n", x1);
			    printf("f(xn): %8.5f\n", fx);
			    printf("f'(xn): %8.5f\n", fpx);
                
                if (fabs(x1-x0) < hataPayi){
					printf("Sonuc: %8.5f\n", x1); // mutlak degeri
                    return x1;
                }
                
                }
                fflush(stdin);
                break;
            case 4:
                printf("------------------NxN'lik Matrisin Tersi--------------. \n");
                float matris[25][25], k, determinantDegeri;
                int j, i;
                printf("Matrisin kaclik bir matris oldugunu girin: "); // NxN oldugu icin 2lik 2x2, 3lük 3x3, 4lük 3x3
                scanf("%f", &k);
                printf("%.0fX%.0f matrisin elemanlarini sirayla girin: \n", k, k);
                for (i = 0;i < k; i++){
                    for (j = 0;j < k; j++){
                    	printf("Matris[%d][%d]: ", i, j);
                        scanf("%f", &matris[i][j]);
                    }
                }
                printf("Girilen Matris:\n");
				for (i = 0; i < k; i++) {
				    for (j = 0; j < k; j++) {
				        printf("%8.2f ", matris[i][j]);
				    }
				    printf("\n");
				}
                determinantDegeri = determinant(matris, k);
                if (determinantDegeri == 0)
                printf("\nDeterminanti sifir oldugundan matrisin tersi yoktur.\n");
                else
                kofaktor(matris, k);
                fflush(stdin);
                break;
            case 5:
                printf("------------------Gauss Eliminasyon--------------. \n");
                gaussEliminasyon();
                fflush(stdin);
                break;
            case 6:
                printf("------------------Gauss Seidel--------------. \n");
                gaussSeidel();
                fflush(stdin);
                break;
            case 7:
                printf("------------------Sayisal Turev (merkezi, ileri, geri farklar)--------------. \n");
                sayisalTurev();
                fflush(stdin);
                break;
            case 8:
                printf("------------------Simpson--------------. \n");
                int simpsonSecim;
                printf("1- 1/3\n");
                printf("2- 3/8\n");
                printf("Secim: ");
                scanf("%d", &simpsonSecim);
                if(simpsonSecim == 1){
                	float a, b;
                    printf("Integralin baslangic noktasini girin: ");
                    scanf("%f", &a);
                    printf("Integralin bitis noktasini girin: ");
                    scanf("%f", &b);
                    printf("Fonksiyonun kacinci dereceden oldugunu girin: ");
                    scanf("%d", &derece);
                    printf("Fonksiyonun katsayilarini sirasiyla girin: \n");
                    for (int i = derece; i >= 0; i--) {
                        printf("x^%d katsayisi: ", i);
                        scanf("%f", &katsayilar[i]);
                    }
                    int n;
                    printf("Parca sayisini giriniz (N): \n");
                    scanf("%d", &n);
                    simpson1_3(a, b, katsayilar, derece, n);
                    fflush(stdin);
                }
                else if(simpsonSecim == 2){
                	float a, b;
                    printf("Integralin baslangic noktasini girin: ");
                    scanf("%f", &a);
                    printf("Integralin bitis noktasini girin: ");
                    scanf("%f", &b);
                    printf("Fonksiyonun kacinci dereceden oldugunu girin: ");
                    scanf("%d", &derece);
                    printf("Fonksiyonun katsayilarini sirasiyla girin: \n");
                    for (int i = derece; i >= 0; i--) {
                        printf("x^%d katsayisi: ", i);
                        scanf("%f", &katsayilar[i]);
                    }
                    simpson3_8(a, b, katsayilar, derece);
                    fflush(stdin);
                }
                else{
                    printf("Gecersiz secim!");
                }
                fflush(stdin);
                break;
            case 9:
                printf("------------------Trapez--------------. \n");
                printf("Fonksiyonun kacinci dereceden oldugunu girin: ");
                scanf("%d", &derece);
                printf("Fonksiyonun katsayilarini sirasiyla girin: \n");
                for (int i = derece; i >= 0; i--) {
                    printf("x^%d katsayisi: ", i);
                    scanf("%f", &katsayilar[i]);
                }
                trapez(katsayilar, derece);
                fflush(stdin);
                break;
            case 10:
                printf("------------------Gregory Newton (degisken donusumsuz)--------------. \n");
                gregoryNewton();
                fflush(stdin);
                break;
            default:
                printf("Gecersiz! Lutfen tekrar deneyin.\n");
                fflush(stdin);
                break;
        }
    }

    return 0;
}
