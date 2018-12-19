/************************************************************/
/* ガウス・ジョルダンによる逆行列の解法 gyaku.c */
/************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10
void hyouji(double a[N][N+N], int n){ 	
	int i, j;
	/*** 行列の状態を印刷する ***/
	printf("\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n+n; j++) {
			printf("%6.2lf ",a[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int n, i, j, k;
	char z, zz;
	static double a[N][N+N], p, q;
	/*** a[N][N+N]: 係数行列 ***/
	while( 1 ){
		printf("ガウス・ジョルダン法による逆行列の解法\n");
		printf("行列のサイズはいくらですか？(1<n<9) n = ");
		scanf("%d%c",&n,&zz);
		if((n <= 1) || (9 <= n)) continue;
		printf("係数を入力してください\n");
		/* 係数行列の入力． */
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				printf("a( %d , %d ) = ",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("\n正しく入力しましたか？(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
	}
	/* 単位行列
	/* 対角成分より上下に掃き出して単位行列の形に変形 */
	for(i=1; i<=n; i++){
		p = a[i][i];
		if(fabs(p) < 1.0e-6) {
			printf("一意解をもちません．\n"); exit(-1);
		}
		/*** 第 i 行を(i,i)成分で割る ***/
		for(j=i; j<=n+n; j++){
			a[i][j] = a[i][j] / p;
		}
		hyouji(a,n);
		/*** 第 k 行を(i,i)成分で下方向に掃き出す ***/
		for(k=i+1; k<=n; k++){
			q = a[k][i];
			for(j=i; j<=n+n; j++){
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
		hyouji(a,n);
		/*** 第 k 行を(i,i)成分で上方向に掃き出す ***/
		for(k=i-1; k>=1; k--){
			q = a[k][i];
			for(j=i; j<=n+n; j++){
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
		hyouji(a,n);
	}
	/*** 解の表示 ***/
	printf("\n連立方程式の解\n\n");
	for(i=1; i<=n; i++){
		for(j=n+1; j<=n+n; j++){
			printf("A^(-1)[%3d][%3d] = %10.6lf\n",i,j-n,a[i][j]);
		}
	}
	return 0;
}
