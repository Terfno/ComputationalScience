#　情報システム実験実習レポート

<div style="text-align:center;">マイクロこんぴゅーたー応用(4)</div>

## 目的
寝る練習

## 装置
まくら


## 実験
### 最終課題
まくらによる睡眠をとる

#### ソースコード
ソースコードを表1.1に示す。
<div style="text-align:center;">表1.1　私を眠りへいざなったソースコード</div>

```cpp
#include<stdio.h>

double MotoShiki(double x, double y) {
	return (y - 12.0*x + 3.0);
}

int main() {

	int i;
	double x, y, h, k1, k2, k3, k4, k;
	char zz;

	printf("ルンゲ・クッタ4次公式により \n\n");
	printf("dy/dx=y-12.0*x+3.0 を解きます");
	printf("\n\nエンターキーを押してください。\n");
	scanf("%c",&zz);
	printf("    X           Y\n");

	x = 0.0; y = 1.0; h = 0.1;

	printf("%10.6lf         %10.6lf\n", x, y);

	for (i = 1; i <= 20; i++) {
		k1 = h * MotoShiki(x, y);
		k2 = h * MotoShiki(x + h / 2, y + k1 / 2);
		k3 = h * MotoShiki(x + h / 2, y + k2 / 2);
		k4 = h * MotoShiki(x + h, y + k3);
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
		x = x + h;
		y = y + k;
		printf("%10.6lf         %10.6lf\n", x, y);
	}
	return 0;
}
```

#### 実験結果
寝た

## 考察課題
c言語を書いたときとPythonを書いたときに、どちらが眠くなるか

### 考察
c言語
