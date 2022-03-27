#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int sort(int* arr, int start, int end) {
	int pivot = (start + end) / 2;
		
	int pivot_value = arr[pivot];		//기준이 될 피봇값
	
	int temp = arr[start];			//첫번째 원소 값과 피봇 인덱스의 값을 변경-> for문의 편리함을 위함
	arr[start] = pivot_value;
	arr[pivot] = temp;
	int pivot_index = start;

	for (int i = start+1; i <= end; i++) {		//arr의 모든 원소에 대해서 확인
		if (arr[i] <= pivot_value) {
			pivot_index++;				//피봇값이 들어갈 위치
			int temp2 = arr[i];			//피봇값 보다 작은 원소의 값
			arr[i] = arr[pivot_index];		//값 교환
			arr[pivot_index] = temp2;
		}
	}

	temp = arr[start];
	arr[start] = arr[pivot_index];		//기준으로 잡았던 pivot값과 pivot_index에 위치하는 원소 교환
	arr[pivot_index] = temp;

	return pivot_index;
}

void quick_sort(int* arr, int start, int end) {
	if (start >=end)
		return ;
	int pivot = sort(arr, start, end);

	quick_sort(arr, start, pivot - 1);
	quick_sort(arr, pivot + 1, end);
	
}
int main() {
	int number;
	scanf("%d", &number);
	int* num_arr = (int*)malloc(sizeof(int) * number);

	for (int i = 0; i < number; i++) {
		fflush(stdin);
		scanf("%d",&(num_arr[i]));
	}

	int length = number;
	quick_sort(num_arr,0,length-1);					//모든 원소

	for (int i = 0; i < length; i++) {
		printf("%d\n", num_arr[i]);
	}
	return 0;
	
}
