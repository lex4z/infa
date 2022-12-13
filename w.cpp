#include <stdio.h>
struct my{
	char ch;
	int kol;
	char code[20];
};

void strSum(char* str1, char* str2){
	int n = 0, m = 0;
	while (str1[n]!='\0') n++;
	while (str2[m]!='\0'){
		str1[n+m] = str2[m];
		m++;
	}
	str1[n+m]='\0';
}

void google(my*hhh,int da , char*strstr, char* res){
	int i = 0;
	while(strstr[i] != '\0'){
		for(int f = 0; f < da; f++){
			if(strstr[i] == hhh[f].ch){
				strSum(res, hhh[f].code);
			}
		}
		i++;
	}
	
}

int main() {
	char str[200] = "12345";
	
	return 0;
}