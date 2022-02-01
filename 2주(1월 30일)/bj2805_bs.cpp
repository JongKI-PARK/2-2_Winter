//bj2805_bs.cpp 2805 using binary search 
//2022.2.1 KI

#include <stdio.h>
#include <stdlib.h>

int main() {
	int count, length;
	int array[1000]={0};
	scanf_s("%d %d", &count, &length);

	if (length <= 0) {
		printf("No cutting is needed\n");
		exit(0);
	}

	int max = 0;
	for (int i = 0; i < count; i++) {
		scanf_s("%2d", &array[i]);
		if (max < array[i])
			max = array[i];
	}
	int sum=0;
	int mid = max / 2;
	int min = 0;
	while (sum != length) {
		sum = 0;
		for (int i = 0; i < count; i++) {
			if (array[i] > mid)
				sum += array[i] - mid;
		}
		if (sum > length)
			min = mid;
		else if (sum < length)
			max = mid;
		mid = (max + min) / 2;
	}
	printf("%d\n", mid);
	return 0;
}