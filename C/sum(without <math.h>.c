#include <stdio.h>

int main() {
	int n, k = 1, N;
	double a, S = 0.0, parametr=1.0;
	printf("enter digit "); scanf_s("%d", &N);
	if(N <= 0)  {
		printf("error");
		return 1;
	}
	printf("enter parametr "); scanf_s("%lf", &a);
	for (n = 1; n <= N; n++) {
	parametr *= a;
	S += k * parametr / n;
	k = -k;
	}
	printf("result %.5lf", S);
}
