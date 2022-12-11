#include <stdio.h>



int main() {
	int n = 12345, m = 0, t = 10000;
	while (n!=0) {
		m+=(n%10)*t;
		t/=10;
		n/=10;
	}
	printf("%d\n",m);
}