//bj2750.c : back joon no2750 with quick sort algorithm(non-decreasing order)
//2022.3.27 PARK JONGKI

#include <stdio.h>
#define MAX_SIZE 1000

void swap(int* k1, int* k2) {
	int temp = *k1;
	*k1 = *k2;
	*k2 = temp;
}

void quickSort(int arr[], int left, int right) {
	int pivot, i, j;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = arr[left];
		do {
			do { i++; } while (arr[i] < pivot);
			do { j--; } while (arr[j] > pivot);
			if (i < j) {
				swap(arr + i, arr + j);
			}
		} while (i < j);
		swap(&arr[left], arr + j);
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

int main() {
	int n;
	scanf_s("%d", &n);
	int arr[MAX_SIZE];
	int input;
	for (int p = 0; p < n; p++) {
		scanf_s(" %d", &input);
		arr[p] = input;
	}
	quickSort(arr, 0, n - 1);
	for (int p = 0; p < n; p++) {
		printf("%d\n", arr[p]);
	}
	return 0;
}