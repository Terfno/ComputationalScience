#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10
void irekae(double a[][N+1],int i, int n){
	int m,j,k;
	double key;
	m=i;
	for(k=i+1;j<=n+1;j++){
		key=a[m][j];
		a[m][j]=a[i][j];
		a[i][j]=key;
	}
}
int main(){
	int n,i,j,k;
	char z,zz;
	static double a[N][N+1], x[N], p,q,s;
	while(1){
		printf("ガウスの消去法による連立方程式の解法\n");
		printf("何元連立方程式ですか？(1<n<9) n=");
		scanf("%d%c",&n,&zz);
		if((n<=1)||(9<=n)){
			continue;
		}
		printf("係数を入力してください\n\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n+1;j++){
				printf("a(%d,%d)=",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("\n正しく入力しましたか？(y/n):");
		scanf("%c%c",&z,&zz);
		printf("ほんとかな～～～～～～～？？？？？？？\n");
		printf("\nもう一度聞くよぉ～～？？？\n正しく入力しましたか？(y/n):");
		scanf("%c%c",&z,&zz);
		if(z=='y'){
			break;
		}
		for(i=1;i<=n;i++){
			irekae(a,i,n);
			p=a[i][i];
			if(fabs(p)<1.0e-6){
				printf("一意解をもちませぇ～～～～～～～ん！！！！\n");
				exit(-1);
			}
			for(j=i;j<=n+1;j++){
				a[i][j]=a[i][j]/p;
			}
			for(k=i+1;k<=n;k++){
				q=a[k][i];
				for(j=i;j<=n+1;j++){
					a[k][j]=a[k][j]-a[i][j]*q;
				}
			}
		}
	}
	for(i=n;i>=1;i--){
		s=0.0;
		for(j=i+1;j<=n;j++){
			s=s+a[i][j]*x[j];
		}
		x[i]=a[i][n+1]-s;
	}
	printf("\n%d元連立方程式の解\n\n",n);
	for(i=1;i<=n;i++){
		printf("x(%d)=%10.6lf\n",i,x[i]);
	}
	return 0;
}