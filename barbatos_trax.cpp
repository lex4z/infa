#include <stdio.h>

struct el{
	char c;
	int n;
	char code[20] = "";
};

int bart[255];

char areEqual(char* s1, char* s2){
	int n = 0;
	while(s1[n] + s2[n] != 0 && s1[n] == s2[n]) n++;
	return (s1[n]=='\0' && s2[n]=='\0');
}

void strSum(char* s1, char* s2){
	int n = 0, m = 0;
	while (s1[n] != '\0') n++;
	while (s2[m] != '\0'){
		s1[n+m] = s2[m];
		m++;
	}
	s1[n+m]='\0';
}

void addBack(char* str, char c){
	int n = 0;
	while(str[n]!='\0') n++;
	str[n]=c;
	str[n+1]='\0';
}

unsigned char binToChar(char* s){
	unsigned char c = 0;
	for(int i = 0; i < 8; i++)c+= (s[i] - 48) *  1<<(7-i);
	return c;
}

char* bin(unsigned char c){
	char* s = new char[9];
	for(int i = 0; i < 8; i++) s[i] = 48 + (c>>(7-i)&1);
	s[8] = '\0';
	return s;
}

void shannon(el* m, int first, int second) {
	if(second - first < 2) return;
	int summ = 0, k = 0;
	float s = 0;
	for(int i = first; i < second; i++) summ += m[i].n;
	for(int i = first; i < second; i++){
		if(s<0.5){
			addBack(m[i].code, '0');
			k++;
		}else{
			addBack(m[i].code, '1');
		}
		s+= (float) m[i].n/summ;
	}
	shannon(m, first, first + k);
	shannon(m, first + k,  second);
	
	
}

void encode(el* m, int n, FILE* s, FILE* f){
	int k = 0;
	char buffer[30] = "";
	unsigned char len;
	fseek(f, 0, SEEK_SET);
	fwrite(&n, sizeof(n), 1, f);
	fseek(s, 0, SEEK_SET);
	for(int i = 0; i < n; i++){
		unsigned char codeLen = 0;
		while(m[i].code[codeLen] != '\0') codeLen++;
		k += m[i].n;
		m[i].n = codeLen;
		fwrite(&m[i].c, sizeof(m[i].c), 1, f);
		fwrite(m[i].code, sizeof(m[i].c)*20, 1, f);
	}
	fwrite(&k, sizeof(k), 1, f);
	int ch;
	while((ch = getc(s)) != EOF){
		for(int i = 0; i < n; i++){
			if(m[i].c == ch){
				strSum(buffer, m[i].code);
				len += m[i].n;
				break;
			}
		}
		for(int i = 0; i < len/8; i++){
			unsigned char temp = binToChar(buffer);
			fwrite(&temp, 1, 1, f);
			temp = 0;
			for(int j = 8; j < len; j++) buffer[temp++] = buffer[j];
			buffer[len-8] = '\0';
			len-=8;
		}
	}
	if(len){
		for(int i = 0; i < 8 - len; i++) addBack(buffer, '0');
		unsigned char temp = binToChar(buffer);
		fwrite(&temp, 1, 1, f);

	}
}

char* decode(FILE* f){
	int n, strLen, ch, k = 0, charIndex = 0;
	char buffer[60] = "";
	fread(&n, sizeof(n), 1, f);
	el* m = new el[n];
	for(int i = 0; i < n; i++){
		fread(&m[i].c, sizeof(m[i].c), 1, f);
		fread(m[i].code, sizeof(m[i].c) * 20, 1, f);
	}
	fread(&strLen, sizeof(strLen), 1, f);
	char* ans = new char[strLen + 1];
	while((ch = getc(f)) != EOF){
		strSum(buffer, bin(ch));
		k+=8;
		if(k>=20){
			int j = 0, x = 0;
			char temp[20] = "";
			while(j < 24){
				addBack(temp, buffer[j]);
				for(int i = 0; i < n; i++){
					if(areEqual(temp, m[i].code)){
						ans[charIndex++] = m[i].c;
						temp[0] = '\0';
						x = j;
						break;
					}
				}
				j++;
			}
			j = 0;
			while(buffer[x] != '\0'){
				buffer[j++] = buffer[x++];
			}
			buffer[j] = '\0';
			k = j;
		}
	}
	ans[strLen] = '\0';
	return ans;
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
	
	for(int i = 0; i < k; i++) printf("%c - %d\n", m[i].c, m[i].n);
	
	shannon(m, 0, k);
	
	for(int i = 0; i < k; i++) printf("%c - %s\n", m[i].c, m[i].code);
	FILE* result = fopen("result.txt", "w");
	encode(m, k, f, result);
	fclose(result);
	result = fopen("result.txt", "r");
	puts(decode(result));
	//printf("%d\n",k);
	return 0;
}