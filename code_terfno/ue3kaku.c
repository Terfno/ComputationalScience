#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8//�T�C�Y�����߂Ă���
int main(){
	int k,j,n;
	char z,zz;
	static double p,s,a[N][N+1],x[N];
	while(1){
		printf("��O�p�^�̘A���������̉�@\n");
		printf("���m���̌�n����͂��Ă��������i1<n<7�j n=");
		scanf("%d%c",&n,&zz);
		if((n<=1) || (7<=n)){
			continue;
		}
		printf("�W������͂��Ă�������\n\n");
		for(k=1;k<=n;k++){
			for(j=k;j<=n+1;j++){
				printf("a(%d,%d)=",k,j );
				scanf("%lf%c",&a[k][j],&zz);
			}
			printf("\n");
		}
		printf("���������͂��܂������H(y/n):");
		scanf("%c%c",&z,&zz);
		if(z=='y'){
			break;
		}
	}
	for(k=1;k<=n;k++){
		p=a[k][k];
		if(fabs(p)<1.0e-6){
			printf("��Ӊ��������܂���B\n");
			exit(-1);
		}
		for(j=k;j<=n+1;j++){
			a[k][j]=a[k][j]/p;
		}
	}
	for(k=n;k>=1;k--){
		s=0.0;
		for(j=k+1;j<=n;j++){
			s=s+a[k][j]*x[j];
		}
		x[k]=a[k][n+1]-s;
	}
	printf("\n��O�p�^�̘A���������̉�\n\n");
	for(k=1;k<=n;k++){
		printf("x(%d)=%10.6lf\n",k,x[k]);
	}
	return 0;
}
