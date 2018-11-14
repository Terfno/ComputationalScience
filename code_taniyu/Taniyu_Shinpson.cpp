#include<stdio.h>
#include<math.h>

//「元の計算式に値を当てはめたもの」をかえす
double OriginFormula(double x) {
	return (1.0 - x)*exp(-x);
}

int main() {
	int i;
	double Bunkatusu;
	double Sekibun_Kukan_First, Sekibun_Kukan_Last, KizamiHaba;
	double Atai[10000];
	double f_first = 0, f_second = 0, f_third = 0;
	double tmp;
	double Answer;
	char Nyuryoku_Answer,Tyousei;

	// 必要事項入力
	while (1) {
		printf("\nシンプソンの公式による積分計算\n");
		printf("f(x)=(1.0-x)*exp(-x)\n");
		printf("積分区間[a,b] a=");
		scanf("%lf%c", &Sekibun_Kukan_First,&Tyousei);
		printf("積分区間[a,b] b=");
		scanf("%lf%c", &Sekibun_Kukan_Last,&Tyousei);
		printf("分割数 n=");
		scanf("%lf%c", &Bunkatusu,&Tyousei);
		printf("\n正しく入力しましたか?(y/n):");
		scanf("%c", &Nyuryoku_Answer);
		if (Nyuryoku_Answer == 'y') break;
	}
	
	// 刻み幅導出
	KizamiHaba = (Sekibun_Kukan_Last - Sekibun_Kukan_First) / (2 * Bunkatusu);

	//一度値を移す
	tmp = Sekibun_Kukan_First;

	printf("\n");

	printf("刻み幅=%lf\n\n", KizamiHaba);

	//それぞれの値で代入したときの結果をAtai[i]に格納
	for (i = 0; i <= 2 * Bunkatusu; i++) {
		Atai[i] = OriginFormula(Sekibun_Kukan_First);// 元の式に代入して値を得る
		Sekibun_Kukan_First = Sekibun_Kukan_First + KizamiHaba;// +刻み幅
		printf("Atai[%d]=%lf\n", i, Atai[i]);// Atai[i]の値出力
		if (i % 2 == 1) f_second += Atai[i];// 奇数番目のデータの時、そのまま+する
		if (i % 2 == 0) {// 偶数番目のデータのとき
			if (i == 0 || i == 2 * Bunkatusu) {// Atai[0]やAtai[2*Bunkatusu]でなければ+する
			}
			else {
				f_third += Atai[i];
			}
		}
	}

	// 値を戻す
	Sekibun_Kukan_First = tmp;

	// fiを計算
	f_first = Atai[0] + Atai[int(2 * Bunkatusu)];

	// 近似値計算
	Answer = KizamiHaba * (f_first + 2 * f_third + 4 * f_second) / 3;

	printf("\n積分の近似値=%10.6lf\n", Answer);

	return 0;
}