//back joon no.14501 using struct
//2022.1.23 KI

#include <stdio.h>
#include <iostream>

struct pair {
	int T;
	int P;
};
typedef struct pair array;
array* pa;

int length;
int answer=0;

int max(int a, int b) {
	return a > b ? a : b;
}

void sum(int date, int result) {
	if (date == length) {
		answer = max(answer, result);
		return;
	}
	if (date + pa[date].T <= length) {
		sum(date + pa[date].T, result + pa[date].P);
	}
	sum(date + 1, result);
}

int main() {

	scanf_s("%d", &length);
	pa = (array*)malloc(length * sizeof(pair));

	for (int i = 0; i < length; i++) {
		scanf_s("%2d %2d", &pa[i].T, &pa[i].P);
	}

	sum(0, 0);
	printf("%d", answer);
	//printf("%d : %d", pa[10].T, pa[10].P);
	
	free(pa);
	return 0;
}