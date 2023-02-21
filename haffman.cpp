#include <stdio.h>

struct el{
	char c[20];
	int n;
	char code[20];
};

void addBack(char* str, char c){
	int n = 0;
	while(str[n]!='\0') n++;
	str[n]=c;
	str[n+1]='\0';
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

void sort(el* ans, int k){
	for(int i = 0; i < k - 1; i++){
		char f = 1;
		for(int j = 0; j < k - i - 1; j++){
			if(ans[j].n > ans[j+1].n){
				el t = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = t;
				f = 0;
			}
		}
		if(f) break;
	}
}

void haffman(el* a, int f, int k){
	if(f<2) return;
	
	
	
	
	
	
}

int main() {
	char str[200] = "baraban";
	int k = 0, m[256]={0}, len = 0;
	while(str[len] != '\0'){
		m[str[len]]++;
		len++;
	}
	
	for(int i = 0; i < 256; i++) if(m[i] != 0) k++;
	el* ans = new el[k];
	int h = 0;
	for(int i = 0; i < 256; i++){
		if(m[i] != 0) {
			ans[h].c[0] = i;
			ans[h].n = m[i];
			h++;
		}
	}
	
	sort(ans, k);
	for(int i = 0; i < k; i++)printf("%s - %d\n",ans[i].c, ans[i].n);
	
	return 0;
}