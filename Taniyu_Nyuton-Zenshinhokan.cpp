#include<stdio.h>
#define N 10

int main() {

	int i, j, n, mm;
	double a[N][N], s[1000], t, x, k;
	char z, zz;
	int l;

	//入力させる
	while (1) {
		printf("ニュートンの差商公式による補間\n");
		printf("補間点の個数nは?(1<n<9) n=");
		scanf_s("%d%c", &n, &zz);

		mm = n;

		if ((n <= 1) || (9 <= n)) {
			continue;
		}

		printf("\n補間点の座標を入力してください.\n");

		for (i = 0; i < n; i++) {
			printf("x(%d)=", i);
			scanf_s("%lf%c", &a[i][0], &zz);
			printf("y(%d)=", i);
			scanf_s("%lf%c", &a[i][1], &zz);
		}

		printf("\n正しく入力しましたか?(y/n):");
		scanf_s("%c", &z);

		if (z == 'y') {
			break;
		}
	}

	//計算
	for (j = 1; j <= n; j++) {
		for (i = 0; i <= n - j; i++) {
			a[i][j + 1] = a[i + 1][j] - a[i][j];
		}
	}

	//差商表
	printf("\n差商表\n");
	i = 0;
	l = n;
	for (j = 1; j <= n; j++) {
		printf("%10.6lf\t", a[i][j]);
		if (j == n) {
			i = i + 1;
			printf("\n");
			j = 0;
			n = n - 1;
		}
		if (i == l) {
			break;
		}
	}
	n = l;

	printf("\n終了するにはctrl+cを押してください\n");
    
	//計算
	while (1) {
		printf("\n指定する点は? X=");
		scanf_s("%lf%c", &x, &zz);
		
		s[0] = a[0][1];
		k = (x - a[0][0]) / (a[1][0]-a[0][0]);
		j = 2;
		for (n = 1; n <=mm; n++) {		 
			t = 1;
			for (i = 1; i <= n; i++) {
				t =t* ((k - (i - 1)) / i);
			}
			s[n] = s[n - 1] + a[0][j] * t;
			j = j + 1;
		}
		printf("\n f(%10.6lf)=%10.6lf\n",x,s[mm-1]);
	}
	return 0;
 }