#include <stdio.h>
#include <math.h>
#define FNF(x) (exp(x)-1/x)
int main (void) {
	double a, b, c;
	int k;
	char z, zz;
	printf("Hello world\n");
	while(1){
		printf("f(a)+f(b)<0となる a,bを入力してください。\n\n");

		printf("第一区間[a,b]のa=");
		scanf("%lf%c", &a, &zz);
		printf("第一区間[a,b]のb=");
		scanf("%lf%c", &b, &zz);

		printf("\n正しく入力しましたか？(y/n)\n");
		scanf("%c%c",&z,&zz);
		if(z=='n'){
			continue;
		}
		if((z=='y')&&(a<b)&&(FNF(a)*FNF(b)<0)){
			break;
		}else{
			printf("\na>bかf(a)*f(b)>=0になります。\n");
			printf("データを入れなおしてね\n");
			printf("エンターキーを押してね\n");
			scanf("%c",&z);
			continue;
		}
	}
	k = 0;
	printf("回数　　　　左端A　　　　右端B　　区間幅B-A\n");
	while(b-a >= 0.000001){
		k=k+1;
		printf("%4d %8.5lf %8.5lf %8.5lf\n",k,a,b,b-a);
		c=(a+b)/2;
		if(FNF(a)*FNF(c)>0){
			a=c;
		}else{
			b=c;
		}
		if((k%10)==0){
			printf("\n計算過程を表示しています。\n表示を継続しますか？（y/n）:");
			scanf("%c%c",&z,&zz);
			if(z=='n'){
				printf("\n表示を終了します。\n");
				break;
			}else if(z=='y'){
				printf("回数　　　　左端A　　　　右端B　　区間幅B-A\n");
			}else{
				z='n';
				break;
			}
		}
	}
	if(z!='n'){
		printf("\n%3d回目で収束しました。\n", k);
		printf("\n収束値＝%10.6lf\n",(a+b)/2.0 );
	}
	return 0;
}
