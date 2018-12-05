#include <stdio.h>
#include <math.h>

#define M 18
#define N 10
#define FNF(x) 0.05*x*(2.0-x)

int main(){
    int i,j,n;
    double a,b,h,c,k,t,x,z[N+1][M+1];
    char zz;

    a = 0.0;
    b = 2.0;
    h = 0.25;
    n = (int)(b-a) / h;
    c = 9.0;
    k = h / sqrt(c);

    for(i=0;i<=n;i++){
        x = a + h * i;
        z[i][0] = FNF(x);
    }

    for(j=0;j<=M;j++){
        z[0][j] = 0.0;
        z[n][j] = 0.0;
    }

    for(i=1;i<=n-1;i++){
        z[i][1] = (z[i+1][0] + z[i-1][0])/2.0;
    }

    for(j=1;j<=M-1;j++){
        for(i=1;i<=n-1;i++){
            z[i][j+1] = z[i+1][j] + z[i-1][j] - z[i][j-1];
        }
    }

    printf("波動方程式の差分による数値解\n\n波動方程式：Ztt=%1.01lfZxx\n",c);
    printf("\nD        : ");
    printf("%1.01lf");
}