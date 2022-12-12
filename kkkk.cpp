#include <stdio.h>

struct el{
	unsigned char c;
	int n;
	char code[20];
};

unsigned char binToChar(char* s){
	unsigned char c = 0;
	for(int i = 0; i < 8; i++)c+= (s[i] - 48) *  1<<(7-i);
	return c;
}

char* bin(unsigned char c){
	char* s = new char[9];
	for(int i = 0; i < 8; i++) s[i] = 48 + (c>>(7-i)&1);
	s[8]='\0';
	return s;
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

void addBack(char* str, char c){
	int n = 0;
	while(str[n]!='\0') n++;
	str[n]=c;
	str[n+1]='\0';
}

void fano(el* a, int s, int f){
	if(f-s<2) return;
	int d = 0, l = 0;
	float k = 0;
	for(int i = s; i < f; i++) d += a[i].n;
	for(int i = s; i < f; i++){
		k += (float) a[i].n/d;
		addBack(a[i].code, 48 + (k > 0.5f + 1./(d+a[i].n)));
		l += 1 - (k > 0.5f + 1./(d+a[i].n));
	}
	
	fano(a, s,s+l);
	fano(a, s+l,f);
	
}

char* encodedStr(el* n, char* str, int k){
	char* ans = new char[200];
	int i = 0;
	while(str[i] != '\0'){
		for(int j = 0; j < k; j++) {
			if(n[j].c == str[i]){
				strSum(ans, n[j].code);
				break;
			}
		}
		i++;
	}
	for(int j = 0; j < k; j++) {
		if(n[j].c == '\0'){
			strSum(ans, n[j].code);
			break;
		}
	}
	addBack(ans, '\0');
	return ans;
}

char* compressedStr(char* str){
	int len = 0;
	char t[8]="";
	while(str[len]!='\0') len++;
	char* ans = new char[len/8+2];
	
	for(int i = 0; i < len/8 + 1; i++){
		char f = 0;
		for(int j = 0; j < 8; j++){
			if(str[i*8+j] == '\0') f = 1;
			t[j] = f ? '0':str[i*8+j];
		} 
		addBack(ans, binToChar(t));
	}

	ans[len/8+1]='\0';
	return ans;
}

int main() {
	char str[200] = "123455";
	int k = 0, m[256]={0}, len = 0;
	while(str[len] != '\0'){
		m[str[len]]++;
		len++;
	}
	m[0]++;
	
	for(int i = 0; i < 256; i++)if(m[i] != 0) k++;
	el* ans = new el[k];
	int h = 0;
	for(int i = 0; i < 256; i++){
		if(m[i] != 0) {
			ans[h].c = i;
			ans[h].n = m[i];
			h++;
		}
	}
	
	
	for(int i = 0; i < k - 1; i++){
		char f = 1;
		for(int j = 0; j < k - i - 1; j++){
			if(ans[j].n < ans[j+1].n){
				el t = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = t;
				f = 0;
			}
		}
		if(f) break;
	}
	
	fano(ans,0,k);
	
	for(int i = 0; i < k; i++)printf("%c - %s\n",ans[i].c, ans[i].code);
	
	int a = 0;
	
	char* ii = compressedStr(encodedStr(ans, str, k));
	while(ii[a] != '\0'){
		printf("%s\n",bin(ii[a]));
		a++;
	}
	
	
	return 0;
}