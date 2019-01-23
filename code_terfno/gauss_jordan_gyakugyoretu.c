#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
int main () {
	static double a[N][N];
	static double inv_a[N][N]; //ここに逆行列が入る
	double buf; //一時的なデータを蓄える
	int i,j,k; //カウンタ
	int n=4;  //配列の次数
	
	//単位行列を作る
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	 		inv_a[i][j]=(i==j)?1.0:0.0;
	 	}
	}
	//掃き出し法
	for(i=0;i<n;i++){
		buf=1/a[i][i];
	 	for(j=0;j<n;j++){
	 		a[i][j]*=buf;
	 		inv_a[i][j]*=buf;
		}
		for(j=0;j<n;j++){
	 		if(i!=j){
	  			buf=a[j][i];
	  			for(k=0;k<n;k++){
	   				a[j][k]-=a[i][k]*buf;
	   				inv_a[j][k]-=inv_a[i][k]*buf;
	  			}
	 		}
		}
	}
	
	//逆行列を出力
	for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
	  		printf(" %f",inv_a[i][j]);
	 	}
	 	printf("\n");
	}
	return 0;
}
