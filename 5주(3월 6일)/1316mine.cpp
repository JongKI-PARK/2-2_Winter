#include<stdio.h>
#include<string.h>
#define MAX 100


int main() {
	int string_num = 0;
	char input[MAX] = { 0, };
	char* find_index = NULL;
	int index = 0;
	int check_index = 0;
	int count = 0;
	
	
	scanf_s("%d", &string_num, sizeof(string_num));		//�ܾ�� �Է¹ޱ�

	count = string_num;		//�׷�ܾ��� �ִ� ���� ����
	
	for (int loop = 0; loop < string_num; loop++) {		//�ܾ����ŭ �ݺ�
		scanf_s("%s", input, sizeof(input));	//�ܾ��Է¹ޱ�
		int escape = 0;
		int check_index = 0;
		for (index = check_index; index < strlen(input); index++) {
			find_index = strrchr(input, input[index]);	//index��°�� ���� ������ ���� ��ġ ã��
			int compare_index = find_index - input;		//index��°�� ���� ������ ������ index��ȣ

			for (check_index = index + 1; check_index < compare_index; check_index++) {
				if (input[index] != input[check_index]) {
					count--;
					escape = 1;
					break;
				}
			}
			if (escape)
				break;
		}
	}
	printf("%d", count);
	return 0;
}
