/************************************************************/
/* �K�E�X�E�W�����_���ɂ��t�s��̉�@ gyaku.c */
/************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10
void hyouji(double a[N][N+N], int n){ 	
	int i, j;
	/*** �s��̏�Ԃ�������� ***/
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
	/*** a[N][N+N]: �W���s�� ***/
	while( 1 ){
		printf("�K�E�X�E�W�����_���@�ɂ��t�s��̉�@\n");
		printf("�s��̃T�C�Y�͂�����ł����H(1<n<9) n = ");
		scanf("%d%c",&n,&zz);
		if((n <= 1) || (9 <= n)) continue;
		printf("�W������͂��Ă�������\n");
		/* �W���s��̓��́D */
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				printf("a( %d , %d ) = ",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("\n���������͂��܂������H(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
	}
	/* �P�ʍs��
	/* �Ίp�������㉺�ɑ|���o���ĒP�ʍs��̌`�ɕό` */
	for(i=1; i<=n; i++){
		p = a[i][i];
		if(fabs(p) < 1.0e-6) {
			printf("��Ӊ��������܂���D\n"); exit(-1);
		}
		/*** �� i �s��(i,i)�����Ŋ��� ***/
		for(j=i; j<=n+n; j++){
			a[i][j] = a[i][j] / p;
		}
		hyouji(a,n);
		/*** �� k �s��(i,i)�����ŉ������ɑ|���o�� ***/
		for(k=i+1; k<=n; k++){
			q = a[k][i];
			for(j=i; j<=n+n; j++){
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
		hyouji(a,n);
		/*** �� k �s��(i,i)�����ŏ�����ɑ|���o�� ***/
		for(k=i-1; k>=1; k--){
			q = a[k][i];
			for(j=i; j<=n+n; j++){
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
		hyouji(a,n);
	}
	/*** ���̕\�� ***/
	printf("\n�A���������̉�\n\n");
	for(i=1; i<=n; i++){
		for(j=n+1; j<=n+n; j++){
			printf("A^(-1)[%3d][%3d] = %10.6lf\n",i,j-n,a[i][j]);
		}
	}
	return 0;
}
