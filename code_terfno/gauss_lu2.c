/***************************************************/
/* �K�E�X�̏����@�ɂ��LU���� gauss_lu.c */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define N 8
int main(void){
	int i, j, n, k;
	static double p, q, s, a[N][N], l[N][N], u[N][N];
	char z, zz;
	/*** �s��̓��� ***/
	while( 1 ) {
		printf("�K�E�X�̏����@�ɂ��LU���� \n");
		printf("�s��̎����̓��� (1<n<7) n = ");
		scanf("%d%c",&n,&zz);
		if((n <= 1) || (7 <= n)) continue;
		printf("\n�s��A�̐�������͂��܂�\n\n");

		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				printf("a( %d , %d )= ",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("���������͂��܂������H(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
	}
	/*** ���͂��ꂽ�W���̕\�� ***/
	printf("���͂��ꂽ�s��A:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			printf(" %10.6lf",a[i][j]);
		}
		printf("\n");
	}
	/*** �K�E�X�̏����@�ɂ�鉺�O�p�s��ւ̑|���o��***/
	for(i=1; i<=n; i++) {
		p = a[i][i];
		if(fabs(p) < 1.0e-6) {
			printf("���̍s���LU�����ł��܂���D\n");
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
	/*** ���O�p�s��L�̕\�� ***/
	printf("\n���O�p�s��L:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++){
			printf(" %10.6lf",l[i][j]);
		}
		printf("\n");
	}
	/*** ��O�p�s��U�̕\�� ***/
	printf("\n��O�p�s��U:\n");
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++){
			printf(" %10.6lf",u[i][j]);
		}
	printf("\n");
	}
	return 0;
}
