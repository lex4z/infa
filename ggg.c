#include <stdio.h>

int main() {
	//printf("%d %d",'0','9'); 48 57
	/*
	char str[] = "123410015FF54321g0g";
	int n = 0, k = 0;
	while(str[n] != '\0'){
		if(str[n] =='0' || str[n] =='1') str[k++] = str[n];
		n++;
	}
	str[k]='\0';
	puts(str);
	
	int r = 0;
	for(int i = 0; i<k; i++) r+= ((str[i] - '0') * 1<<(k-1-i));
	
	printf("%d\n",r);
	*/
	
	char str[] = "   21 22  55 hh  k      k";
	char f = 0;
	int i = 0, k = 0;
	while(str[i] != '\0'){
		if(str[i] != ' ') f = 1;
		if(f && (str[i]==' ' && str[i+1] != ' ' || str[i] != ' ')) str[k++] = str[i];
		i++;
	}
	str[k]='\0';
	puts(str);
	
	
	return 0;
}