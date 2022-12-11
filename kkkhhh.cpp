#include <stdio.h>

float z1(int a, int b){
	int t = 1;
	char h = 0;
	if(b<0){
		b = -b;
		h = 1;
	}
	for(int i = 0; i < b; i++) t*=a;
	
	if(h) return 1./t;
	else return  t;
}

int z2(int a){
	int r = 1;
	while(a) r *= a--;
	return r;
}

int z3(int a){
	return a<0 ? -a:a;
}

float z4(double x) {
	int n = 0;
	x = (x / 180) * 3.14;
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

void z5(){
	char c = 1;
	while (c > 0) c++;
	printf("min:%d\n", c);
	char t = c;
	printf("max:%d\n", --c);
	int n = 0;
	while((c-t)>>n) n++;
	printf("bytes:%d\n", n/8);
}

void z6(){
	float a = 1, b = 0;
	while(a){
		b = a;
		a/=2;
	}
	printf("%e\n", b);
}

int z7(int a){
	int t = 0;
	while(a){
		t *= 10;
		t += a%10;
		a /= 10;
	} 
	
	return t;
}

int main(){
	printf("%d\n", z7(23456));
	//z6();
	
	
	return 0;
}