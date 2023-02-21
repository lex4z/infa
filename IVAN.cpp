#include <stdio.h>
#include <locale>
struct person {
	char name[10];
	char surname[10];
	int phone;
}P[100] = { "Ivan", "Ivanov", 245 };

char areEqual(char* s1, char* s2) {
	int n = 0;
	while (s1[n] + s2[n] != 0 && s1[n] == s2[n]) n++;
	return (s1[n] == '\0' && s2[n] == '\0');
}

int strToNum(char* s) {
	int i = 0, ans = 0;
	while (s[i] != '\0') {
		ans = ans * 10 + s[i] - 48;
		i++;
	}
	return ans;
}

void createDB(person* db, int* dbSize){
	for (int i = 0; i < 10; i++) db[i] = {};
	*dbSize = 0;
}

void addLineDB(person* db, int* dbSize){
	printf("Имя(латиницей):");
	scanf("%s",db[*dbSize].name);
	printf("Фамилия(латиницей):");
	scanf("%s", db[*dbSize].surname);
	printf("Номер:");
	scanf("%d", &db[*dbSize].phone);
	*dbSize = *dbSize + 1;
}

void findLineDB(person* db, int dbSize){
	char temp[10];
	scanf("%s", temp);
	for (int i = 0; i < dbSize; i++) {
		if (areEqual(temp, db[i].name) || areEqual(temp, db[i].surname) || strToNum(temp) == db[i].phone) {
			printf("%d | %s\t%s\t%d\n", i + 1 , db[i].name, db[i].surname, db[i].phone);
		}
	}
}

void printDB(person* db, int dbSize){
	for (int i = 0; i < dbSize; i++) printf("%d | %s\t%s\t%d\n",i+1 , db[i].name, db[i].surname, db[i].phone);
}

void editLineDB(person* db, int dbSize){
	int lineNum, actionNum;
	printf("Укажите номер строчки:");
	do{
		scanf("%d", &lineNum);
		if(lineNum > dbSize) printf("введите номер существующей строчки\n:");
	}while(lineNum > dbSize || lineNum < 0);
	printf("Укажите что хотите изменить\n1)Имя\n2)Фамилия\n3)Номер\n");
	do {
		printf(":");
		scanf("%d", &actionNum);
		switch (actionNum) {
			case 1:
				printf("Новое имя:");
				scanf("%s", db[lineNum-1].name);
				break;
			case 2:
				printf("Новая фамилия:");
				scanf("%s", db[lineNum-1].surname);
				break;
			case 3:
				printf("Новый номер:");
				scanf("%d", &db[lineNum-1].phone);
				break;
		}
	} while (actionNum>3 || actionNum < 0);
}

void deleteLineDB(person* db, int* dbSize){
	int lineNum;
	printf("Укажите номер строчки:");
	scanf("%d",&lineNum);
	for(int i = lineNum - 1; i < *dbSize; i++) db[i] = db[i+1];
	*dbSize = *dbSize - 1;
}

void sortDB(person* db, int dbSize, int sortingColumn){
	char** t = new char*[dbSize];
	for(int i = 0; i < dbSize; i++){
		switch (sortingColumn) {
			case 1:
				t[i] = db[i].name;
				break;
			case 2:
				t[i] = db[i].surname;
				break;
			case 3:
				char* temp = new char[10];
				for(int i = 0; i < 10; i++) temp[i]='0';
				int e = db[i].phone, n = 0;
				while(e){
					e/=10;
					n++;
				}
				e = db[i].phone;
				for(int i = 0; i  < n; i++){
					temp[9-i] = temp[9 - i] +  e%10;
					e/=10;
				}
				t[i] = temp;
				break;
		}
	}
		char f = 0;
		for (int i = 0; i < dbSize - 1; i ++) {
			f = 0;
			for (int j = 0; j < dbSize - i - 1; j ++) {
				int k = 0;
				while(t[j][k] == t[j+1][k] && t[j][k] + t[j+1][k] != 0) k++;
				if(t[j][k] == 0 || t[j][k] > t[j+1][k]) {
					person temp = db[j];
					db[j] = db[j + 1];
					db[j + 1] = temp;
					f = 1;
				}
				
			}
			if (!f) break;
		}
	
}

int main() {
	setlocale(LC_ALL, "RUS");
	int actionNum, size = 3;
	P[1] = {"Petr","Petrov",45600};
	P[2] = {"Papus", "Yatonu", 999};
	FILE* f = fopen("DB.txt", "r+");
	
	createDB(P, &size);
	fscanf(f, "%d",&size);
	fseek(f, 1, SEEK_CUR);
	fread(P, sizeof(P), 1, f);
	
	do
	{
		puts("1. Создать новую БД\n2. Добавить запись\n3. Поиск\n4. Вывод\n5. Изменить\n6. Удалить\n7. Сортировка\n8. Выход");
		scanf("%d", &actionNum);
		switch (actionNum){
		case 1:
			createDB(P, &size);
			break;
		case 2:
			addLineDB(P, &size);
			break;
		case 3:
			findLineDB(P, size);
			break;
		case 4:
			printDB(P, size);
			break;
		case 5:
			editLineDB(P, size);
			break;
		case 6:
			deleteLineDB(P, &size);
			break;
		case 7:
			int columnNum;
			printf("Укажите столбец по которому сортировать\n1)Имя\n2)Фамилия\n3)Номер\n:");
			scanf("%d",&columnNum);
			sortDB(P, size, columnNum);
			break;
		}
	} while (actionNum != 8);
	
	fseek(f, 0, SEEK_SET);
	fprintf(f, "%d ",size);
	fwrite(P, sizeof(P), 1, f);
	
    return 0;
}

