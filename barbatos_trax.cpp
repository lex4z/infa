#include <stdio.h>

struct el{
	char c;
	int n;
	el* parent;
	char left;
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

int main() {
	FILE* f = fopen("mama.txt", "r");
	int ch, k = 0;
	while((ch = getc(f)) != EOF) bart[ch]++;
	el* m = new el[k];
	for(int i = 0; i < 255; i++){
		if(bart[i]) {
			//printf("%c: %d\n",i,bart[i]);
			el* t = new el[k++];
			for(int j = 0; j < k-1; j++) t[j]=m[j];
			t[k-1].c = i;
			t[k-1].n = bart[i];
			delete [] m;
			m = t;
		}
	}
	
	//el* m = new el[k];
	//k = 0;
	/*
	for(int i = 0; i < 255; i++){
		if(bart[i]){
			m[k].c = i;
			m[k].n = bart[i];
		}
	}
	*/
	for(int i = 0; i < k -1; i++){
		for(int j = 0; j < k - i - 1; j++){
			if(m[j].n < m[j+1].n){
				el temp = m[j];
				m[j] = m[j+1];
				m[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i < k; i++) printf("%c: %d\n",m[i].c, m[i].n);
	
	
	printf("%d\n",k);
	return 0;
}