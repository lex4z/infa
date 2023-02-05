#include <stdio.h>
#include <locale>
struct person {
	char name[10];
	char surname[10];
	int phone;
}P[10] = { "Ivan", "Ivanov", 245 };

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
int main() {
	setlocale(LC_ALL, "RUS");
	int actionNum, size = 1;
	do
	{
		puts("1. Создать новую БД\n2. Добавить запись\n3. Поиск\n4. Вывод\n5. Изменить\n6. Удалить\n7. Сортировка\n8. Выход");
		scanf("%d", &actionNum);
		switch (actionNum){
		case 1:
			for (int i = 0; i < 10; i++) P[i] = {};
			size = 0;
			break;
		case 2:
			printf("Имя(латиницей):");
			scanf("%s",P[size].name);
			printf("Фамилия(латиницей):");
			scanf("%s", P[size].surname);
			printf("Номер:");
			scanf("%d", &P[size].phone);
			size++;
			break;
		case 3:
			char temp[10];
			scanf("%s", temp);
			for (int i = 0; i < size; i++) {
				if (areEqual(temp, P[i].name) || areEqual(temp, P[i].surname) || strToNum(temp) == P[i].phone) {
					printf("%s\t%s\t%d\n", P[i].name, P[i].surname, P[i].phone);
				}
			}
			break;
		case 4:
			for (int i = 0; i < size; i++) printf("%s\t%s\t%d\n", P[i].name, P[i].surname, P[i].phone);
			break;
		default:
			break;
		}
		

	} while (actionNum != 8);


    return 0;
}

