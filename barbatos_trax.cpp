#include <stdio.h>

struct el{
	char c;
	int n;
	el* parent;
	char left;
};

int bart[255];

int main() {
	FILE* f = fopen("mama.txt", "r");
	int j, max = 0, k = 0;
	while((j = getc(f)) != EOF) bart[j]++;
	for(int i = 0; i < 255; i++){
		if(bart[i]) {
			printf("%c: %d\n",i,bart[i]);
			k++;
		}
	}
	
	printf("%d\n",k);
	return 0;
}