#include <stdio.h>

struct Person{
	char surname[10];
	int age;
}people[] = {
	"Ivanov", 20,
	"Petrov", 21,
	"Sidorov", 19,
	"Abramova", 17,
	"Avramov", 17,
	"Abramov", 17
};


int main() {
	char f = 0;
	int len = sizeof(people)/sizeof(people[0]);
	
	for (int i = 0; i < len - 1; i ++) {
		f = 0;
		for (int j = 0; j < len - i - 1; j ++) {
			int k = 0;
			while(people[j].surname[k] == people[j+1].surname[k] && people[j].surname[k] + people[j+1].surname[k] != 0) k++;
			if(people[j].surname[k] == 0 || people[j].surname[k] > people[j+1].surname[k]) {
				Person temp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = temp;
				f = 1;
			}
			
		}
		if (!f) break;
	}
	for (int i = 0; i < len; i ++) {
		printf("%s, %d\n",people[i].surname, people[i].age);
	}
	return 0;
}