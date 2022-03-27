#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int sort(int* arr, int start, int end) {
	int pivot = (start + end) / 2;
		
	int pivot_value = arr[pivot];		//������ �� �Ǻ���
	
	int temp = arr[start];			//ù��° ���� ���� �Ǻ� �ε����� ���� ����-> for���� ������ ����
	arr[start] = pivot_value;
	arr[pivot] = temp;
	int pivot_index = start;

	for (int i = start+1; i <= end; i++) {		//arr�� ��� ���ҿ� ���ؼ� Ȯ��
		if (arr[i] <= pivot_value) {
			pivot_index++;				//�Ǻ����� �� ��ġ
			int temp2 = arr[i];			//�Ǻ��� ���� ���� ������ ��
			arr[i] = arr[pivot_index];		//�� ��ȯ
			arr[pivot_index] = temp2;
		}
	}

	temp = arr[start];
	arr[start] = arr[pivot_index];		//�������� ��Ҵ� pivot���� pivot_index�� ��ġ�ϴ� ���� ��ȯ
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
	quick_sort(num_arr,0,length-1);					//��� ����

	for (int i = 0; i < length; i++) {
		printf("%d\n", num_arr[i]);
	}
	return 0;
	
}