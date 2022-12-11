#include <stdio.h>
#include <locale.h>

int fib(int n){
	if(n<=2) return 1;
	return fib(n-1) + fib(n-2);
}



void m(int n){
	if(n>0){
		printf("%d",n%10);
		m(n/10);
	}
}

void sort(int *n, int len){
	for(int i = 0; i < len-1; i+=1){
		for(int j = 0; i < len - i - 1; j+=1){
			if(n[j]>n[j+1]){
				int temp = n[j];
				n[j]=n[j+1];
				n[j+1]=temp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	/*
	float sum = 0;
	for(int i = 0; i<100; i+=1){
		sum+=(float)1/(i+1);
	}
	*/
	//printf("%d\n");
	//int m[] = {1,2,5,4,6};
	//sort(m,5);
	//for(int i = 0; i < 5; i+=1){
	//	printf("%d\n",m[i]);
	//}
	
	

	return 0;
}