#include <stdio.h>
#include <math.h>

double f(double x, double y){
    // double e = 2.71828182846;
    return (x+y);
}

int main(){
    int i;
    double x, y, h, k1, k2, k3, k4, k;
    char zz;

    printf("\n\n4次のルンゲクッタ法により dy/dx=e^{-sin x}-ycos x を解きます。\n\n");
    printf("Returnキーを押してください。\n");
    scanf("%c",&zz);

    printf("  x          y\n");

    x = 0.0;
    y = 1.0;
    h = 0.4; //刻み幅は0.1

    printf("%10.6lf %10.6lf\n",x,y);

    for(i=1;i<=10;i++){
        k1 = h * f(x, y);
        k2 = h * f(x + (h / 2), y + (k1 / 2));
        k3 = h * f(x + (h / 2) , y + (k2 / 2));
        k4 = h * f(x + h, y + k3);
        k = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
        x = x + h;
        y = y + k;
        
        printf("%10.6lf %10.6lf\n",x,y);
    }
    return 0;
}
