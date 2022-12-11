#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	n -= 1;
	for (int i = 0; i <=n; i += 1) {
		for (int j = 0; j < n - i; j += 1) {
			printf(" ");
		}
		for (int j = 0; j <= i; j += 1) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}