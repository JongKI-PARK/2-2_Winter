//bj2108.c
//2022.3.13 PARK JONGKI

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 500000

int compare(const int* vp, const int* vq) {
	const int* p = vp;
	const int* q = vq;
	int diff = *p - *q;
	return ((diff >= 0) ? ((diff > 0) ? -1 : 0) : +1);
}
int main() {
	int n;
	scanf_s("%d", &n);
	int min, max;
	int arr[MAX_SIZE];
	int counter[8001] = { 0, };
	scanf_s("%d", &arr[0]);
	min = max = arr[0];
	int sum = arr[0];
	counter[arr[0] + 4000] = 1;

	for (int i = 1; i < n; i++) {
		scanf_s("%d", &arr[i]);
		sum += arr[i];
		counter[arr[i] + 4000]++;
	}

	int max_count = 0;
	for (int i = 0; i < 8001; i++) {
		if (max_count <= counter[i])
			max_count = counter[i];
	}
	int check = 0;
	int max_num_index = 0;
	for (int i = 0; i <8001; i++) {
		if (counter[i] == max_count) {
			check++;
			if (check < 3) {
				max_num_index = i - 4000;
			}
		}
		
	}

	qsort(arr,n,sizeof(int),compare);

	printf("%d\n", (int)round((double)sum / n));
	printf("%d\n", arr[n / 2]);
	printf("%d\n", max_num_index);
	printf("%d\n", arr[0] - arr[n - 1]);
	return 0;
}