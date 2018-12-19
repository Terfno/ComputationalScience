/***************************************************/
/* ガウスの消去法によるLU分解 gauss_lu.c */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define N 8
int main(void){
	int i, j, n, k;
	static double p, q, s, a[N][N], l[N][N], u[N][N];
	char z, zz;
	/*** 行列の入力 ***/
	while( 1 ) {
		printf("ガウスの消去法によるLU分解 \n");
		printf("行列の次数の入力 (1<n<7) n = ");
		scanf("%d%c",&n,&zz);
		if((n <= 1) || (7 <= n)) continue;
		printf("\n行列Aの成分を入力します\n\n");

		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				printf("a( %d , %d )= ",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("正しく入力しましたか？(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
	}
	/*** 入力された係数の表示 ***/
	printf("入力された行列A:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			printf(" %10.6lf",a[i][j]);
		}
		printf("\n");
	}
	/*** ガウスの消去法による下三角行列への掃き出し***/
	for(i=1; i<=n; i++) {
		p = a[i][i];
		if(fabs(p) < 1.0e-6) {
			printf("この行列はLU分解できません．\n");
			exit(-1);
		}
		for(j=i; j<=n+1; j++) {
			l[j][i] = a[j][i];
			a[i][j] = a[i][j] / p;
		}
		for(k=i+1; k<=n; k++) {
			q = a[k][i];
			for(j=i; j<=n+1; j++){
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
		for(j=i; j<=n; j++){
			u[i][j] = a[i][j];
		}
	}
	/*** 下三角行列Lの表示 ***/
	printf("\n下三角行列L:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++){
			printf(" %10.6lf",l[i][j]);
		}
		printf("\n");
	}
	/*** 上三角行列Uの表示 ***/
	printf("\n上三角行列U:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++){
			printf(" %10.6lf",u[i][j]);
		}
	printf("\n");
	}
	return 0;
}
