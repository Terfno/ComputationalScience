#include <stdio.h>
#include <math.h>
#define FNF(x) (x*x*x - 3*x*x + x + 3)
#define FNG(x) (3*x*x -6*x + 1)
int main (void){
	double x, xn;
	int k;
	char z,zz;
	printf("�֐�FNF(��)=x*x*x - 3*x*x + x + 3\n�̍����j���[�g���@�ŋ��߂܂�\n\n");
	printf("���ߎ��l����͂��Ă�������");
	scanf("%lf%c",&x,&zz);
	k=1;
	printf("�񐔁@�@�ߎ��l�@�@�O�̋ߎ��l�Ƃ̍�\n");
	printf("  1 %10.6lf\n",x );
	while(1){
		k=k+1;
		xn=x-FNF(x)/FNG(x);
		printf("%4d %10.6lf  %10.6lf\n",k,xn,xn-x );
		if(fabs(xn-x)<0.000001){
			break;
		}
		x=xn;
		if(k%10!=0){
			continue;
		}
		printf("\n�v�Z�ߒ���\�����Ă��܂��B\n\n�\�����p�����܂����H�iy/n�j:");
		scanf("%c%c",&z,&zz);
		if(z=='n'){
			printf("\n�\�����I���܂�\n");
			break;
		}else if(z=='y'){
			printf("�񐔁@�@�ߎ��l�@�@�O�̋ߎ��l�Ƃ̍�\n");
		}else{
			z='n';
			break;
		}
	}
	if(z!='n'){
		printf("\n%3d��ڂŎ������܂���\n",k );
		printf("\n�����l��%10.6lf\n",xn);
	}
	return 0;
}
