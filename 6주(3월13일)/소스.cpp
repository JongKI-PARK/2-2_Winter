#include <stdio.h>
#include <math.h>

int main() {

	int num, s;
	int n = 0;

	printf("�Է��� ������ ����: ");
	scanf_s("%d", &s);
	int arr1[5];


	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &num);
		arr1[i] = num;
	}

	/*for (int k = 0; k < sizeof(arr1) / 4; k++) {
		printf("%d ", arr1[k]);
	}*/

	printf("\n");
	//������
	double average;
	
	for	(int i = 0; i < sizeof(arr1) / 4; i++) {
		n += arr1[i];
	}
	
	average = n / s;
	if (average > -1 && average < 0)
		average = 0;
	printf("���: %.0f\n", round(average));


	//�߾Ӱ�
	int median;

	for (int i = 0; i < (sizeof(arr1) / 4) - 1; i++) {
		int least = i;
		for (int j = i + 1; j < sizeof(arr1) / 4; j++) {
			if (arr1[j] < arr1[least]) {
				least = j;
			}
		}
		int t = arr1[i];
		arr1[i] = arr1[least];
		arr1[least] = t;		
	}

	for (int i = 0; i < sizeof(arr1) / 4; i++)
		printf("%d\n", arr1[i]);

	median = arr1[(s - 1) / 2];
	printf("�߾Ӱ�: %d\n", median);

	
	//�ֺ�

	int mode, freq, count = 1;  
	
	for (int i = 0; i < s; i++)
	{
		freq = 1;						
		for (int j = i + 1; j < s; j++)
		{
			if (arr1[i] == arr1[j])		
				freq += 1;				
		}
		if (freq >= count)				
		{
			mode = arr1[i];
			count = freq;
		}
	
	}
	printf("�ֺ�: %d, Ƚ��: %d\n", mode, count);

	//����
	int range;
	
	range = arr1[s-1] - arr1[0];
	printf("����: %d\n", range);
	
	
	return 0;
}