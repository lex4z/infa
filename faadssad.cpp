#include <stdio.h>
#include <locale>

struct p{
	unsigned char c;
	char n[10];
	float f;
};
struct q{
	p* m;
	int len;
};

void sort(p* n, int len) {
	char f = 0;
	for (int i = 0; i < len - 1; i += 1) {
		f = 0;
		for (int j = 0; j < len - i - 1; j += 1) {
			if(n[j+1].f>n[j].f){
				p temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
				f = 1;
			}
		}
		if (!f) break;
	}
	
}

void mprint(int* n, int len) {
	for (int i = 0; i < len; i += 1) {
		printf("%d\n", n[i]);
	}
}

void addFront(char* str, char c){
	char a = 0, b = str[0];
	int n = 0;
	while(str[n]!='\0') {
		a = b;
		b = str[n+1];
		str[n+1]=a;
		n+=1;
	}
	str[0]=c;
 }

void addBack(char* str, char c){
	int n = 0;
	while(str[n]!='\0')n+=1;
	str[n]=c;
	str[n+1]='\0';
}

void noSpaces(char* str){
	int a = 0, n = 0;
	while(str[n]!='\0'){
		if(str[n]!=' '){
			str[a] = str[n];
			a+=1;
		}
		n+=1;
	}
	str[a]='\0';
}

void strSum(char* str1, char* str2){
	int n = 0, m = 0;
	while (str1[n]!='\0') n++;
	while (str2[m]!='\0'){
		str1[n+m] = str2[m];
		m++;
	}
	str1[n+m]='\0';
}

char* bin(unsigned char c){
	char* s = new char[9];
	for(int i = 0; i < 8; i++) s[i] = 48 + (c>>(8-i)&1);
	return s;
}

q da(char* str){
	int n = 0, t = 0, m[256]={0};
	q r;
	while(str[n]!='\0'){
		m[str[n]]++;
		n++;
	}
	for(int i = 0; i < 256; i++) if(!m[i]) t++;
	p* ans = new p[t];
	for(int i = 0; i < t; i++){
		if(m[i]) {
			ans[i].c = i;
			ans[i].f = 100*m[i]/n;
		}
	}
	r.m = ans;
	r.len = t;
	return r;
}

void fano(p* a, int s, int f, int k = 1){
	if(f-s<2) return;
	float sum1 = 0, sum2 = 0;
	int e = 0;
	for(int i = s; i < f; i++) sum1+=a[i].f;
	for(int i = s; i < f; i++){
		sum2+=a[i].f;
		a[i].n[k-1] =  49 -  (sum1/2>sum2-sum1/(21/k));
		e += (sum1/2>sum2-sum1/(20/k));
	}
	fano(a,s,e,k+1);
	fano(a,s+e,f,k+1);
}

char* result(q n, char* str){
	char* ans = new char[200];
	int i = 0;
	while(str[i] != '\0'){
		for(int j = 0; j < n.len; j++) {
			if(n.m[j].c == str[i]){
				strSum(ans, n.m[j].n);
				break;
			}
		}
		i++;
	}
	
	return ans;
}

int main(){
	setlocale(LC_ALL, "RU");
	char str[200] = "sdfghjkl";
	
	//FILE *f = fopen("da.txt", "w");
	//fclose(f);
	
	noSpaces(str);
	
	q n = da(str);
	sort(n.m, n.len);
	fano(n.m,0,n.len);
	for(int i = 0; i < n.len; i++) printf("%c %s\n",n.m[i].c, n.m[i].n);
	puts(result(n,str));
	
	
	
	return 0;
}