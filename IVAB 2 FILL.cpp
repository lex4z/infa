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

void addLineDB(FILE* db, int* dbSize) {
	person temp;
	printf("Имя(латиницей):");
	scanf_s("%s", temp.name,10);
	printf("Фамилия(латиницей):");
	scanf_s("%s", temp.surname, 10);
	printf("Номер:");
	scanf_s("%d", &temp.phone);
	fseek(db, sizeof(temp) * (*dbSize), SEEK_SET);
	fwrite(&temp, sizeof(temp), 1, db);
	*dbSize = *dbSize + 1;
}

void findLineDB(FILE* f, int dbSize) {
	char temp[10];
	person db;
	scanf_s("%s", temp, 10);
	fseek(f, 0, SEEK_SET);
	for (int i = 0; i < dbSize; i++) {
		fread(&db, sizeof(person), 1, f);
		if (areEqual(temp, db.name) || areEqual(temp, db.surname) || strToNum(temp) == db.phone) {
			printf("%d | %s\t%s\t%d\n", i + 1, db.name, db.surname, db.phone);
		}
	}
}

void printDB(FILE* f, int dbSize) {
	person db;
	fseek(f, 0, SEEK_SET);
	for (int i = 0; i < dbSize; i++) {
		fread(&db, sizeof(person), 1, f);
		printf("%d | %s\t%s\t%d\n", i + 1, db.name, db.surname, db.phone);
	}
}

void editLineDB(FILE* f, int dbSize) {
	int lineNum, actionNum;
	printf("Укажите номер строчки:");
	do {
		scanf_s("%d", &lineNum);
		if (lineNum > dbSize) printf("введите номер существующей строчки\n:");
	} while (lineNum > dbSize || lineNum < 0);
	printf("Укажите что хотите изменить\n1)Имя\n2)Фамилия\n3)Номер\n");
	fseek(f, sizeof(person) * (lineNum - 1), SEEK_SET);
	person db;
	fread(&db, sizeof(person), 1, f);
	fseek(f, -24, SEEK_CUR);
	do {
		printf(":");
		scanf_s("%d", &actionNum);
		switch (actionNum) {
		case 1:
			printf("Новое имя:");
			scanf_s("%s", db.name, 10);
			break;
		case 2:
			printf("Новая фамилия:");
			scanf_s("%s", db.surname, 10);
			break;
		case 3:
			printf("Новый номер:");
			scanf_s("%d", &db.phone);
			break;
		}
	} while (actionNum > 3 || actionNum < 0);
	fwrite(&db, sizeof(person), 1, f);
}

void deleteLineDB(FILE* f, int* dbSize) {
	int lineNum;
	person t;
	printf("Укажите номер строчки:");
	scanf_s("%d", &lineNum);
	fseek(f, sizeof(person) * lineNum, SEEK_SET);
	for (int i = 0; i < *dbSize - lineNum; i++) {
		fread(&t, sizeof(person), 1, f);
		fseek(f, -48, SEEK_CUR);
		fwrite(&t, sizeof(person), 1, f);
		fseek(f, sizeof(person), SEEK_CUR);
	}
	*dbSize = *dbSize - 1;
}

void sortDB(FILE* f, int dbSize, int sortingColumn) {
	char** t = new char* [dbSize];
	person db;
	fseek(f, 0, SEEK_SET);
	for (int i = 0; i < dbSize; i++) {
		char* temp = new char[10];
		fread(&db, sizeof(person), 1, f);
		switch (sortingColumn) {
		case 1:
			for (int j = 0; j < 10; j++) temp[j] = db.name[j];
			break;
		case 2:
			for (int j = 0; j < 10; j++) temp[j] = db.surname[j];
			break;
		case 3:
			for (int j = 0; j < 10; j++) temp[j] = '0';
			int e = db.phone, n = 0;
			while (e) {
				e /= 10;
				n++;
			}
			e = db.phone;
			for (int j = 0; j < n; j++) {
				temp[9 - j] = temp[9 - j] + e % 10;
				e /= 10;
			}
			t[i] = temp;
			break;
		}
		t[i] = temp;
	}

	char flag;
	for (int i = 0; i < dbSize - 1; i++) {
		flag = 1;

		for (int j = 0; j < dbSize - i - 1; j++) {
			int k = 0;
			fseek(f, sizeof(person) * j, SEEK_SET);
			while (t[j][k] == t[j + 1][k] && t[j][k] + t[j + 1][k] != 0) k++;
			if (t[j][k] == 0 || t[j][k] > t[j + 1][k]) {
				char* p = t[j];
				t[j] = t[j + 1];
				t[j + 1] = p;
				person temp1, temp2;
				fread(&temp1, sizeof(person), 1, f);
				fread(&temp2, sizeof(person), 1, f);
				fseek(f, -48, SEEK_CUR);
				fwrite(&temp2, sizeof(person), 1, f);
				fwrite(&temp1, sizeof(person), 1, f);
				flag = 0;
			}

		}
		if (flag) break;
	}


}

int main() {
	setlocale(LC_ALL, "RUS");
	int actionNum, size = 0;
	FILE* f;
	FILE* sizeF;
	fopen_s(&f, "DB.txt", "r+");
	fopen_s(&sizeF,"size.txt", "r+");

	fscanf_s(sizeF, "%d", &size);

	do
	{
		puts("1. Создать новую БД\n2. Добавить запись\n3. Поиск\n4. Вывод\n5. Изменить\n6. Удалить\n7. Сортировка\n8. Выход");
		scanf_s("%d", &actionNum);
		fseek(f, 0, SEEK_SET);
		fseek(sizeF, 0, SEEK_SET);
		fprintf(sizeF, "%d ", size);
		switch (actionNum) {
		case 1:
			size = 0;
			break;
		case 2:
			addLineDB(f, &size);
			break;
		case 3:
			findLineDB(f, size);
			break;
		case 4:
			printDB(f, size);
			break;
		case 5:
			editLineDB(f, size);
			break;
		case 6:
			deleteLineDB(f, &size);
			break;
		case 7:
			int columnNum;
			printf("Укажите столбец по которому сортировать\n1)Имя\n2)Фамилия\n3)Номер\n");
			do {
				printf(":");
				scanf_s("%d", &columnNum);
			} while (columnNum > 3 || columnNum < 0);
			sortDB(f, size, columnNum);
			break;
		}
	} while (actionNum != 8);



	return 0;
}
