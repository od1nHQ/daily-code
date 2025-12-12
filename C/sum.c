#include <stdio.h>
#include <math.h>

int main() {
	int n, k = 1, N;
	double a, S = 0.0, y, x;
	printf("enter digit "); scanf_s("%d", &N);
	if(N <= 0)  {
		printf("error");
		return 1;
	}
	printf("enter x and y (x y) "); scanf_s("%lf %lf", &x, &y);
	for (n = 1; n <= N; n++) {
	
	S += k * (pow(x - y, n * 2) / ((2 * n - 1)*(2 * n + 1)));
	k = -k;
}
	printf("result %.5lf", S);
}

