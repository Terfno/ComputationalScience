#include <stdio.h>
#include <math.h>
#define FNF(x) (exp(x)-1/x)
int main (void) {
	double a, b, c;
	int k;
	char z, zz;
	printf("Hello world\n");
	while(1){
		printf("f(a)+f(b)<0�ƂȂ� a,b����͂��Ă��������B\n\n");

		printf("�����[a,b]��a=");
		scanf("%lf%c", &a, &zz);
		printf("�����[a,b]��b=");
		scanf("%lf%c", &b, &zz);

		printf("\n���������͂��܂������H(y/n)\n");
		scanf("%c%c",&z,&zz);
		if(z=='n'){
			continue;
		}
		if((z=='y')&&(a<b)&&(FNF(a)*FNF(b)<0)){
			break;
		}else{
			printf("\na>b��f(a)*f(b)>=0�ɂȂ�܂��B\n");
			printf("�f�[�^�����Ȃ����Ă�\n");
			printf("�G���^�[�L�[�������Ă�\n");
			scanf("%c",&z);
			continue;
		}
	}
	k = 0;
	printf("�񐔁@�@�@�@���[A�@�@�@�@�E�[B�@�@��ԕ�B-A\n");
	while(b-a >= 0.000001){
		k=k+1;
		printf("%4d %8.5lf %8.5lf %8.5lf\n",k,a,b,b-a);
		c=(a+b)/2;
		if(FNF(a)*FNF(c)>0){
			a=c;
		}else{
			b=c;
		}
		if((k%10)==0){
			printf("\n�v�Z�ߒ���\�����Ă��܂��B\n�\�����p�����܂����H�iy/n�j:");
			scanf("%c%c",&z,&zz);
			if(z=='n'){
				printf("\n�\�����I�����܂��B\n");
				break;
			}else if(z=='y'){
				printf("�񐔁@�@�@�@���[A�@�@�@�@�E�[B�@�@��ԕ�B-A\n");
			}else{
				z='n';
				break;
			}
		}
	}
	if(z!='n'){
		printf("\n%3d��ڂŎ������܂����B\n", k);
		printf("\n�����l��%10.6lf\n",(a+b)/2.0 );
	}
	return 0;
}
