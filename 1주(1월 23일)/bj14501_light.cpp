//back joon no.14501 lighter version of bj14501.cpp
//2022.1.23 KI 

#include <stdio.h>
#include <iostream>

int length;
int answer = 0;
int* Ti;
int* Pi;

int max(int a, int b) {
	return a>b ? a : b;
}

void sum(int date, int result) {
	if (date == length) {
		answer = max(answer, result);
	}
	if (date + Ti[date] <= length) {
		sum(date + Ti[date], result + Pi[date]);
	}
	sum(date + 1, result);
}

int main() {
	scanf_s("%d", &length);
	
	Ti = new int[length];
	Pi = new int[length];
	for (int i = 0; i < length; i++) {
		scanf_s("%3d %3d", &Ti[i], &Pi[i]);
	}

	sum(0, 0);
	printf("%d\n", answer);

	delete[] Ti;
	delete[] Pi;
	return 0;
}