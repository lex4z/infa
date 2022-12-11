#include <stdio.h>
#include <locale>
#include <math.h>

float cs(double x) {
	int n = 0;
	x = (x / 180) * M_PI;
	float r = 0, a = 0, t = 1, l = 1;
	char sign = 1;
	do {
		a = t/l;
		r += sign * a;
		n += 1;
		t *= (x * x);
		l *= (n*2-1) * (2 * n);
		sign *= -1;
	} while (a>0);
	return r;
}

float sn(float x) {
	int n = 0;
	x = (x / 180) * 3.141597;
	float r = 0, a = 0, t = x, l = 1;
	char sign = 1;
	do {
		a = t/l;
		r += sign * a;
		n += 1;
		t *= (x * x);
		l *= (2 * n) * (2 * n+1);
		sign *= -1;
	} while (a);
	return r;
}
int main() {
	float n;
	scanf("%f",&n);
	printf("%f\n",sn
		(n));
	
	return 0;
}