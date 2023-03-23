#include <stdio.h>

struct el{
	char c;
	int n;
	char code[20];
};

int bart[255];

void addBack(char* str, char c){
	int n = 0;
	while(str[n]!='\0') n++;
	str[n]=c;
	str[n+1]='\0';
}

char* bin(unsigned char c){
	char* s = new char[9];
	for(int i = 0; i < 8; i++) s[i] = 48 + (c>>(8-i)&1);
	s[8] = '\0';
	return s;
}

void generateCodes(el* m, int s, int e){
	if(e - s < 2) return;
	int summ = 0, k = 0;
	float probSum = 0;
	for(int i = s; i < e; i++) summ += m[i].n;
	for(int i = s; i < e; i++){
		if(s<0.5){
			addBack(m[i].code, '0');
			k++;
		}else addBack(m[i].code, '1');
		s+= (float) m[i].n/summ;
	}
	generateCodes(m, s, s+k);
	generateCodes(m, s+k, e);
	
}

int main() {
	FILE* f = fopen("mama.txt", "r");
	int ch, k = 0;
	while((ch = getc(f)) != EOF) bart[ch]++;
	el* m = new el[k];
	for(int i = 0; i < 255; i++){
		if(bart[i]) {
			el* t = new el[++k];
			for(int j = 0; j < k-1; j++) t[j]=m[j];
			t[k-1].c = i;
			t[k-1].n = bart[i];
			delete[] m;
			m = t;
		}
	}
	
	for(int i = 0; i < k - 1; i++){
		for(int j = 0; j < k - i - 1; j++){
			if(m[j].n < m[j+1].n){
				el temp = m[j];
				m[j] = m[j+1];
				m[j+1] = temp;
			}
		}
	}
	
	
	//printf("%d\n",k);
	return 0;
}