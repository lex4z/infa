#include <stdio.h>
struct l{
	int ch;
	int n;
};
int niggers[256];

int main() {
	int ch;
	FILE* f = fopen("mama.txt", "r");
	
	while((ch = getc(f)) != EOF)niggers[ch]++;
	
	int maxNig, minNig = 0;
	for(int i = 0; i < 256; i++){
		if(niggers[i]) printf("%c: %d\n",i,niggers[i]);
		if(niggers[minNig] < niggers[i]) minNig = i;
		else if(niggers[minNig] == niggers[i]) maxNig = i;
	}
	printf("min:'%c'\tmax:'%c'\t\n",minNig,maxNig);
	
	int n = 0;
	unsigned char k = 0;
	for(int i = 0; i < 256; i++){
		if(niggers[i] == niggers[minNig]) {
			niggers[k] = i;
			k++;
			printf("%c\t",i);
		}
		n++;
	}
	
	fseek(f, 0, SEEK_SET);
	
	char flag = 1;
	while((ch = getc(f)) != EOF){
		for(int i = 0; i < n; i++){
			if(ch == niggers[i]){
				if(flag) minNig = ch;
				maxNig = ch;
				flag = 0;
			}
			
		}
	}
	printf("\nfirst:'%c'\tlast:'%c'\t\n",minNig,maxNig);
	
}