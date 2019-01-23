#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10
/*** �s�̓���ւ����s���֐� ***/
void irekae(double a[][N+1], int i, int n)
	{ int m, j, k;
	double key;
	m = i;
/*** ��Βl�̍ő�̂��̂�T�� ***/
		for(k=i+1; k<=n; k++)
	{ if(fabs(a[m][i]) < fabs(a[k][i])) m = k; }
/*** �� m �s �Ƒ� i �s �����ւ��� ***/
	for(j=1; j<=n+1; j++)
	{ key=a[m][j]; a[m][j]=a[i][j]; a[i][j]=key; }
	}
int main(void)
	{ int n, i, j, k;
	char z, zz;
	static double a[N][N+1], x[N], p, q, s;
/*** a[N][N+1]: �g��W���s��, x[N]: �� ***/
	while( 1 ) {
		printf("�K�E�X�̏����@�ɂ��A���������̉�@\n");
		printf("�����A���������ł����H(1<n<9) n = ");
		scanf("%d%c",&n,&zz);
		if((n <= 1) || (9 <= n)) continue;
		printf("�W������͂��Ă�������\n\n");
/* �g��W���s��̓��́D�E�ӂ͑�n+1��ڂɓ���� */
		for(i=1; i<=n; i++) {
			for(j=1; j<=n+1; j++) {
				printf("a( %d , %d ) = ",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("\n���������͂��܂������H(y/n) ");
		scanf("%c%c",&z,&zz);
		if(z == 'y') break;
		}
/* �Ίp������艺��|���o���ď�O�p�s��̌`�ɕό` */
		for(i=1; i<=n; i++){
			irekae(a,i,n);
			p = a[i][i];
			if(fabs(p) < 1.0e-6) {
				printf("��Ӊ��������܂���D\n"); exit(-1);
			}
/*** �� i �s��(i,i)�����Ŋ��� ***/
			for(j=i; j<=n+1; j++)
				{ a[i][j] = a[i][j] / p; }
			for(k=i+1; k<=n; k++){
				q = a[k][i];
				for(j=i; j<=n+1; j++)
					{ a[k][j] = a[k][j] - a[i][j] * q; }
			}
		}
		for(i=n;i>=1;i--){
			s=0.0;
			for(j=i+1;j<=n;j++){
				s=s+a[i][j]*x[j];
			}
			x[i]=a[i][n+1]-s;
		}
		printf("\n%d���A���������̉�\n\n",n);
		for(i=1;i<=n;i++){
			printf("x(%d)=%10.6lf\n",i,x[i]);
		}
	return 0;
}
