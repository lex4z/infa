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
	
	el* m = new el[k];
	k = 0;
	for(int i = 0; i < 255; i++){
		if(bart[i]){
			m[k].c = i;
			m[k].n = bart[i];
		}
	}
	
	for(int i = 0; i < k -1; i++){
		for(int j = 0; j < k - i - 1){
			if(m[j].n < m[j+1].n){
				el temp = m[j];
				m[j] = m[j+1];
				m[j+1] = temp;
			}
		}
	}
	
	printf("%d\n",k);
	return 0;
}