#include<stdio.h>
#define N 11
int main(){
	int i,j,k,n;
	double seki,xx,s,x[N],y[N];
	char z,zz;
	while(1){
		printf("���O�����W���̕ۊǑ�����\n");
		printf("�⊮�_�̌�����͂��Ă��������B(1<n<10)\n");
		scanf("%d%c",&n,&zz);
		if((n<=1)||(10<=n)){
			continue;
		}
		printf("�⊮�_�̍��W����͂��Ă��������B\n");
		for(i=1;i<=n;i++){
			printf("x(%d)=",i);
			scanf("%lf%c",&x[i],&zz);
			printf("y(%d)=",i);
			scanf("%lf%c",&y[i],&zz);
		}
		printf("\n���������͂��܂������H(��)(y/n)");
		scanf("%c%c",&z,&zz);
		if(z=='y'){
			break;
		}
	}
	printf("\n�w�肷��_�́H x=");
	scanf("%lf%c",&xx,&zz);
	s=0.0;
	
	for(k=1;k<=n;k++){
		seki=1.0;
		for(j=0;j<=n;j++){
			if(j!=k){
				seki *= (xx-x[j]) / (x[k]-x[j]);
			}
		}
		s += seki * y[k];
	}
	printf("\nx=%10.6lf�ɂ�����l y=%10.6lf\n",xx,s);
	return 0;
}
