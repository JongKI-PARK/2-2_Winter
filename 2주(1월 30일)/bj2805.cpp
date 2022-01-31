//bj2805.cpp back joon algorithm
//2022.1.31 KI

#include <stdio.h>
#include <iostream>

int check(int array[], int count, int offset) {
	int result = 0;
	for (int i = 0; i < count; i++) {
		if ((array[i] - offset) > 0)
			result = result + array[i] - offset;
	}
	return result;
}

int main() {
	int count,length; //N for count of trees, M for needed length
	int* array;
	int sum=0;
	int mean=0;
	int offset = 0;

	scanf_s("%d %d", &count, &length);
	array = new int[count];

	if (length <= 0) {
		printf("No cutting is needed\n");
		exit(0);
	}

	for (int i = 0; i < count; i++) {
		scanf_s("%2d", &array[i]);
		sum += array[i];
	}

	mean = (sum / count);
	offset = (length / count);
	int newOffset = (mean - offset);

	int height = check(array,count, newOffset);

	while (height != length) {
		if (height < length) {
			height = check(array, count, newOffset - 1);
			newOffset -=1;
		}
		else {
			height = check(array, count, newOffset + 1);
			newOffset += 1;
		}
	}

	printf("%d\n", newOffset);
	return 0;
}
