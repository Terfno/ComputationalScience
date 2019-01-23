#include <stdio.h>
#include <math.h>

double f(double x, double y){
    return (x + y);
}

int main(){
    int i;
    double x, y, h, k;
    char zz;

    printf("\n\n4次のオイラー法により dy/dx=x+y を解きます。\n\n");
    printf("Returnキーを押してください。\n");
    scanf("%c",&zz);

    printf("  x          y\n");

    x = 0.0;
    y = 1.0;
    h = 0.1; //刻み幅は0.1とする

    printf("%10.6lf %10.6lf\n",x,y);

    for(i=0;i <= 10;i++){
        k = h * f(x, y);
        x = x + h;
        y = y + k;

        printf("%10.6lf %10.6lf\n",x,y);
    }
    return 0;
}
