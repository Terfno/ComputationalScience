#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10
void irekae(double a[][N+1],int i, int n){
	int m,j,k;
	double key;
	m=i;
	for(k=i+1;j<=n+1;j++){
		key=a[m][j];
		a[m][j]=a[i][j];
		a[i][j]=key;
	}
}
int main(){
	int n,i,j,k;
	char z,zz;
	static double a[N][N+1], x[N], p,q,s;
	while(1){
		printf("ƒKƒEƒX‚ÌÁ‹Ž–@‚É‚æ‚é˜A—§•û’öŽ®‚Ì‰ð–@\n");
		printf("‰½Œ³˜A—§•û’öŽ®‚Å‚·‚©H(1<n<9) n=");
		scanf("%d%c",&n,&zz);
		if((n<=1)||(9<=n)){
			continue;
		}
		printf("ŒW”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n+1;j++){
				printf("a(%d,%d)=",i,j);
				scanf("%lf%c",&a[i][j],&zz);
			}
			printf("\n");
		}
		printf("\n³‚µ‚­“ü—Í‚µ‚Ü‚µ‚½‚©H(y/n):");
		scanf("%c%c",&z,&zz);
		printf("‚Ù‚ñ‚Æ‚©‚È```````HHHHHHH\n");
		printf("\n‚à‚¤ˆê“x•·‚­‚æ‚§``HHH\n³‚µ‚­“ü—Í‚µ‚Ü‚µ‚½‚©H(y/n):");
		scanf("%c%c",&z,&zz);
		if(z=='y'){
			break;
		}
		for(i=1;i<=n;i++){
			irekae(a,i,n);
			p=a[i][i];
			if(fabs(p)<1.0e-6){
				printf("ˆêˆÓ‰ð‚ð‚à‚¿‚Ü‚¹‚¥```````‚ñIIII\n");
				exit(-1);
			}
			for(j=i;j<=n+1;j++){
				a[i][j]=a[i][j]/p;
			}
			for(k=i+1;k<=n;k++){
				q=a[k][i];
				for(j=i;j<=n+1;j++){
					a[k][j]=a[k][j]-a[i][j]*q;
				}
			}
		}
	}
	for(i=n;i>=1;i--){
		s=0.0;
		for(j=i+1;j<=n;j++){
			s=s+a[i][j]*x[j];
		}
		x[i]=a[i][n+1]-s;
	}
	printf("\n%dŒ³˜A—§•û’öŽ®‚Ì‰ð\n\n",n);
	for(i=1;i<=n;i++){
		printf("x(%d)=%10.6lf\n",i,x[i]);
	}
	return 0;
}
