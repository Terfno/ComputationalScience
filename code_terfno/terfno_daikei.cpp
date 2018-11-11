#include <stdio.h>
#include <math.h>
#define FNF(x)  (1.0-x)*exp(-x)

int main(){
    int i,n;
    double a,b,h,s,x;
    char z,zz;
    while(1){
        printf("だいけいこうしき による積分計算\n\n");
        printf("f(x)=(1.0-x)*exp(-x)\n\n");
        printf("積分区間[a,b]のa= ");
        scanf("%lf%c",&a,&zz);
        printf("積分区間[a,b]のb= ");
        scanf("%lf%c",&b,&zz);
        printf("分割数n= ");
        scanf("%d%c",&n,&zz);
        printf("\n\n正しく入力しましたか?(y/n)");
        scanf("%c%c",&z,&zz);
        if(z=='y'){
            break;
        }
    }
    h=(b-a)/n;
    s=FNF(a)*h/2.0+FNF(b)*h/2.0;
    for(i=1;i<=n-1;i++){
        x=a+h*i;
        s+=FNF(x)*h;
    }
    printf("\n積分の近似値=%10.6lf\n\n",s);
    return 0;
}
