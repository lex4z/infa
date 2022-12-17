#include <stdio.h>

void sort(int* m, int n) {
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(m[j] > m[j+1]){
				int t = m[j];
				m[j] = m[j+1];
				m[j+1] = t;
			}
		}
	}
}



int main() {
	
	return 0;
}