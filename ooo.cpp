#include <stdio.h>

void z1(int* m, int n){
	for(int i = 0; i < n/2; i++){
		int t = m[i];
		m[i] = m[n-i-1];
		m[n-i-1] = t;
	}
}
void printArray(int *m, int len){
	for(int i = 0; i < len; i++) printf("%d\t",*(m+i));
	printf("\n");
}

void z2(char* s){
	int n=0, b=0;
	while(*(s+n) != '\0'){
		if(*(s+n) == '0' || *(s+n) == '1') {
			*(s+b) = *(s+n);
			b++;
		}
		n++;
	}
	*(s+b) = '\0';
}

unsigned char z3(char* s){
	unsigned char c;
	for(int i = 0; i < 8; i++) c+= (*(s + i)-48)* 1<<(8-i-1);
	return c;
}
void z4(unsigned char c, char* str){
	for(int i = 0; i < 8; i++){
		str[i] = ((1<<(8-i-1))&c) ? '1':'0';
	}
}

int main() {
	int a[] = {1,2,3,4,5,6};
	char s[20] = "1230498712da1230";
	char k[10];
	z3('A',k);
	printf("%s\n", k);
	
	//puts(s);
	//z2(s);
	//puts(s);
	//printArray(a, 6);
	//z1(a,6);
	//printArray(a, 6);
	
	
	return 0;
}