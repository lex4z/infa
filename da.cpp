#include <stdio.h>

void k(int n){
	if(n == 0) return;
	k(n/10);
	printf("%d\n",n%10);
	
}

int main() {
	
	
	return 0;
}