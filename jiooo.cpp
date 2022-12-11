#include <stdio.h>
#include <random>
#include <time.h>

void randomArray(int *m, int len){
	for(int i = 0; i < len; i++) *(m+i) = rand()%10;
}

void printArray(int *m, int len){
	for(int i = 0; i < len; i++) printf("%d\t",*(m+i));
	printf("\n");
}

void sortArray(int *m, int len){
	char f;
	for(int i = 0; i < len-1; i++){
		f = 0;
		for(int j = 0; j < len - i - 1; j
			++){
			if(*(m+j) < *(m+j+1)){
				int t = *(m+j);
				*(m+j) = *(m+j+1);
				*(m+j+1) = t;
				f = 1;
			}
		}
		if(!f) break;
	}
}

class str{
private:
	char *s;
	
public:
	int length;
	
	str(int size){
		s = new char[size+1];
		length = size;
	}
	
	str(char *t){
		int n = 0;
		while(t[n]!='\0') n++;
		s = new char[n];
		length = n;
		n = 0;
		while(t[n] != '\0'){
			s[n]=t[n];
			n++;
		} 
		
	}
	
	str(const char t[]){
		int n = 0;
		while(t[n] != '\0') n++;
		s = new char[n];
		length = n;
		n = 0;
		while(t[n]!='\0'){
			s[n]=t[n];
			n++;
		} 
	}
	
	
	
	void print(){
		for (int i = 0; i < this->length; i++) {
			printf("%c", this->s[i]);
		}
		printf("\n");
	}
	
};
int main() {
	srand(time(0));
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	//printArray(a, 10);
	randomArray(a, 10);
	//printArray(a, 10);
	sortArray(a, 10);
	//printArray(a, 10);
	
	char s[30] = "123455555";
	str b = str("123456");
	b.print();
	//printf("%d\n");
	
	return 0;
}