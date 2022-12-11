#include <stdio.h>
#include <random>
#include <time.h>

int main() {
	srand(time(0));
	int a[10], *p = a;
	for(int i = 0; i < 10; i++){
		*(a+i) = rand()%10;
		printf("%d\n", *(a+i));
	}
	
	return 0;
} 