#include <stdio.h>
#include <math.h>

#define e 2.71828182846

double f(double x, double y, double z){
    return z;
}

double g(double x, double y, double z){
    return ((x * z) - y) / (x*x);
}

int main(){
    int i;
    double x, y, z, h, k1, k2, k3, k4, l1, l2, l3, l4, l, k;
    char zz;

    printf("\n\n4次のルンゲクッタ法により 連立微分方程式を解きます。\n\n");
    printf("Returnキーを押してください。\n");
    scanf("%c",&zz);

    printf("  x          y          z          k          j\n");

    x = 1.0;
    y = 2.0;
    z = 0.0;
    h = 0.1; //刻み幅は0.1

    printf("%10.6lf %10.6lf %10.6lf\n", x, y, z);

    for(i=1;i<=10;i++){
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);
        k2 = h * f(x + (h / 2), y + (k1 / 2), z + (l1 / 2));
        l2 = h * g(x + (h / 2), y + (k1 / 2), z + (l1 / 2));
        k3 = h * f(x + (h / 2), y + (k2 / 2), z + (l2 / 2));
        l3 = h * g(x + (h / 2), y + (k2 / 2), z + (l2 / 2));
        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);
        k = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
        l = (l1 + (2 * l2) + (2 * l3) + l4) / 6;
        x = x + h;
        y = y + k;
        z = z + l;
        printf("%10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",x, y, z, k, l);
    }
    return 0;
}
