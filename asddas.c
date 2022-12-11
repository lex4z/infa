#include <stdio.h>
#include <math.h>
#include <locale.h>



float sqrtGeron(float a){
	float x = a;
	do{
		x = 0.5 * (x+(a/x));
		printf("%e %e\n",a/x,x*x);
	}while (a != x*x);
	return x;
}

void da(){
	float n=0;
	for(int i= 0; i<=100;i+=1){
		if((int)i%2==0){
			n+=1/(i*2.+1);
		}else{
			n-=1/(i*2.+1);
		}
	}
	printf("%f", n*4);
}

float fact(int n){
	float r = 1;
	for(int i = 1; i<=n; i+=1){
		r*=i;
	}
	return r;
}

float sn(float x){
	int n = 0;
	x=(x/180)*M_PI;
	float r = 0, a = 0, t = x;
	char sign = 1;
	do {
		a=r;
		r+= sign*t/fact(n*2+1);
		t*=x*x;
		sign*=-1;
		n+=1;
	} while (fabs(r-a)>0.000001);
	return r;
}

void kolvoCifr(int n){
	int c[10]={0};
	while(n!=0){
		c[n%10]+=1;
		n/=10;
	}
	for(int i = 0; i<10;i+=1){
		if(c[i]){
			printf("%d - %d\n",i,c[i]);
		}
	}
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "RU");
	float n = 0;
	scanf("%f",&n);
	printf("%f\n",sqrtGeron(n));
	
	//float n = 0, a = 1, t1 = 0;
	//double g = 1, t2 = 0;
	//int b = 0, c = 0;
	//scanf("%f",&n);
	//printf("%f\n%f\n",sn(n),sinf((n/180)*M_PI));
	/*
	while(a!=0){
		t1 = a;
		a/=2;
		b+=1;
	}
	while(g!=0){
		t2 = g;
		g/=2;
		c+=1;
	}
	printf("%f\n",sn(30));
	
	//int n = 0;
	//scanf("%d",&n);
	kolvoCifr(n);
	*/
	
	return 0;
}