#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
int main () {
	static double a[N][N];
	static double inv_a[N][N]; //�����ɋt�s�񂪓���
	double buf; //�ꎞ�I�ȃf�[�^��~����
	int i,j,k; //�J�E���^
	int n=4;  //�z��̎���
	
	//�P�ʍs������
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	 		inv_a[i][j]=(i==j)?1.0:0.0;
	 	}
	}
	//�|���o���@
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
	
	//�t�s����o��
	for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
	  		printf(" %f",inv_a[i][j]);
	 	}
	 	printf("\n");
	}
	return 0;
}
