#include <stdio.h>
#include <time.h>
#include <random>

struct da{
	int a, n;
}b[10];

int main() {
	long long x = 224447777;
	
	while(x>0){
		b[x%10].n++;
		b[x%10].a = x%10;
		x/=10;
	}
	
	char f = 0;
	for (int i = 0; i < 9; i++) {
		f = 0;
		for (int j = 0; j < 9 - i; j++) {
			if(b[j+1].n>b[j].n){
				da temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				f = 1;
			}
		}
		if (!f) break;
	}
	
	int i = 0;
	while(b[i].n != 0){
		printf("%d : %d\n", b[i].a,b[i].n);
		i++;
	}
	
	return 0;
}