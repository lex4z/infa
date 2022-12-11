#include <stdio.h>
#include <random>
#include <time.h>
#define N 9
#define M 9

int main(){
	srand(time(0));
	int t[N][M] = { 0 }, t2[N][M] = { 0 }, strSum = 0, columnSum[N] = { 0 }, diagSum = 0, secDiagSum = 0, sum = 0;
	//заполнение массива
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			t[i][j] = rand() % 10;
			t2[i][j] = t[i][j];
		}
	}
	
	//нахождение сумм диагоналей, строк и столбцов; вывод массива 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d  ", t[i][j]);
			sum += t[i][j];
			strSum += t[i][j];
			columnSum[i] += t[j][i];
			
		}
		diagSum += t[i][i];
		secDiagSum += t[i][M - i - 1];
		printf("| %d\n", strSum);
		strSum = 0;
	}
	
	for (int i = 0; i < N*3; i++) printf("-");//красиво отделить массив хочу
	printf("\n");
	
	for (int i = 0; i < N; i++) printf("%d ", columnSum[i]);
	printf("\n\nsum: %d\ndiagSum: %d\nsecDiagSum: %d\n\n",sum,diagSum,secDiagSum);
	
	//сортировка пузырьком строк
	for (int l = 0; l < N; l++) {
		for (int o = 0; o < M - 1; o++) {
			char f = 0;
			for (int i = 0; i < M - 1; i++) {
				if (t[l][i] > t[l][i+1]) {
					int temp = t[l][i];
					t[l][i] = t[l][i+1];
					t[l][i+1] = temp;
					f = 1;
				}
			}
			if (!f) break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d  ", t[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	//сортировка пузырьком столбцов
	for (int l = 0; l < N; l++) {
		for (int o = 0; o < M - 1; o++) {
			char f = 0;
			for (int i = 0; i < M - 1; i++) {
				if (t2[i][l] > t2[i + 1][l]) {
					int temp = t2[i][l];
					t2[i][l] = t2[i + 1][l];
					t2[i + 1][l] = temp;
					f = 1;
				}
			}
			if (!f) break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d  ", t2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}