#include <stdio.h>

double f(double x, double y){
    return (x + y);
}

int main(){
    int i;
    double x, y, h, k1, k2, k;
    char zz;

    printf("\n\n4次のルンゲクッタ法により dy/dx=x+y を解きます。\n\n");
    printf("Returnキーを押してください。\n");
    scanf("%c",&zz);

    printf("  x          y\n");

    x = 0.0;
    y = 1.0;
    h = 0.1; //刻み幅は0.1

    printf("%10.6lf %10.6lf\n",x,y);

    for(i=1;i<=40;i++){
        k1 = h * f(x, y);
        k2 = h * f(x + h, y + k1);
        x = x + h;
        y = y + k;
        
        printf("%10.6lf %10.6lf\n",x,y);
    }
    return 0;
}
