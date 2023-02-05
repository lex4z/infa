#include <stdio.h>

int main() {
	/*
	char 
	str1[20] = "123 45",
	str2[20] = "123 45";
	
	int i = 0;
	while(str1[i] + str2[i] != 0 && str1[i] == str2[i]) i++;
	
	if(str1[i] + str2[i] == 0) puts("da");
	else puts("net");
	*/
	char ans[2000];
	char 
	a[200], 
	b[200];
	int i = 0, j = 0, c = 0;
	scanf("%s",a);
	scanf("%s",b);
	
	
	while(a[i]!='\0')i++;
	while(b[j]!='\0')j++;
	if(i>j){
		for(int k = 0; k < i+1; k++){
			if(j>=k) b[i-k]=b[j-k];
			else b[i-k]='0';
		}
		j=i;
	}else{
		for(int k = 0; k < j+1; k++){
			if(i>=k) a[j-k]=a[i-k];
			else a[j-k]='0';
		}
	}
	
	i = 1;
	while(i!=j+1){
		ans[1998-i] = (a[j-i] + b[j-i] - 48 * 2 + c)%10  + 48;
		c = (a[j-i] - 48 + b[j-i] - 48 + c)/10;
		i++; 
	}
	if(c) ans[1998-i] = c + 48;
	for(j = 0; j < i; j++){
		ans[j]=ans[1998 - i + j + !c];
	}
	ans[i]='\0';
	
	puts(a);
	puts(b);
	puts(ans);
	
	return 0;
}