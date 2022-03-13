#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int count;
	int input_number;
}check_num;
int main() {

			//�Է¹��� ������ ������ �迭�� ����Ű�� ������ ����
	int num;				//�Է¹��� ���� ����

	scanf_s("%d", &num, sizeof(num));

	int* input_nums = (int*)malloc(sizeof(num) * num);	//�Է¹��� ������ ������ �迭����

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &input_nums[i], sizeof(num));	//���ڸ� �迭�� ����
	}

	//1�� ������
	int total = 0;

	for (int i = 0; i < num; i++) {
		total += *(input_nums + i);
	}
	if (total > 0) {
		if ((((double)total / num) * 10) < (total / num) * 10 + 5)	//�Ҽ� ù°�ڸ����� �ݿø�
			printf("������ : %d\n", total / num);
		else
			printf("������ : %d\n", (total / num) + 1);
	}
	else if (total < 0){
		if ((((double)total / num) * 10) <= (total / num) * 10 - 5)
			printf("������ : %d\n", (total / num)-1);
		else
			printf("������ : %d\n", total / num);
	}

	//2�� �������� ������ �߾� ��
	for (int i = 0; i < num; i++) {
		int min = input_nums[i];
		int min_index = i;
		for (int index = i+1; index < num; index++) {
			if (input_nums[index] < min) {
				min = input_nums[index];		//�ּҰ� ����
				min_index = index;			//�ּҰ� �ε�����ȣ
			}
		}
		int temp = min;
		input_nums[min_index] = input_nums[i];
		input_nums[i] = min;
	}

	printf("�߰� ��:%d\n", input_nums[num / 2]);

	//3�� �ֺ�
	check_num* check = (check_num*)malloc(sizeof(check_num));
	check->input_number = input_nums[0];
	check->count = 1;
	int dif_num=1;		//���� �ٸ� ���� ����
	
	for (int i = 1; i < num; i++) {		//��� ���ڹ迭�� ���ؼ� �˻�
		int branch = 1;

		for (int j = 0; j < dif_num; j++) {		//����ü�� ���� �ִ� ���ڿ� ���� �˻�
			if (check[j].input_number == input_nums[i]) {
				check[j].count++;
				branch = 0;
				break;
			}
		}
		if (branch) {
			dif_num++;
			check_num* temp = (check_num*)malloc(sizeof(check_num) * dif_num);
			for (int j = 0; j < dif_num - 1; j++) {
				temp[j].input_number = check[j].input_number;
				temp[j].count = check[j].count;
			}
			temp[dif_num - 1].input_number = input_nums[i];
			temp[dif_num - 1].count = 1;
			free(check);
			check = temp;
		}
	}
		//check�� ���� �ٸ� ���ڰ� �� �� ���Դ��� �����س��� ����ü

	int many_num = check[0].count;				//�ֺ� - ���� ���� ���� ����
	int many_num_count = 0;						//�ֺ� ���� - ���� ���� ���� ������ ��
	int many_num_index = 0;						//�ֺ� �ε��� ��ȣ

	for (int i = 0; i < dif_num; i++) {
		if (many_num < check[i].count) {
			many_num = check[i].count;			//�ֺ� ã��
			many_num_index = i;					//�ֺ��� �ε��� ��ȣ
		}
	}
	for (int i = 0; i < dif_num; i++) {			//�ֺ� ���� Ȯ�� 
		if (many_num == check[i].count)
			many_num_count++;
	}
	if(many_num_count==1)
		printf("�ֺ�: %d\n", check[many_num_index].input_number);

	if (many_num_count > 1) {							//�ֺ��� ���� ���� ���
		int* check_many_num = (int*)malloc(sizeof(int) * many_num_count);
		int check_many_num_index = 0;
		
		for (int i = 0; i < dif_num; i++) {
			if (check[i].count == many_num) {
				check_many_num[check_many_num_index] = check[i].input_number;
				check_many_num_index++;
			}
		}

		for (int i = 0; i < many_num_count; i++) {
			int min = check_many_num[i];
			int min_index = i;
			for (int index = i + 1; index < many_num_count; index++) {
				if (check_many_num[index] < min) {
					min = check_many_num[index];		//�ּҰ� ����
					min_index = index;			//�ּҰ� �ε�����ȣ
				}
			}
			int temp = min;
			check_many_num[min_index] = input_nums[i];
			check_many_num[i] = min;
		}
		printf("�ֺ�: %d\n", check_many_num[1]);
	}
	
	//����
	printf("����: %d\n", check[num - 1].input_number - check[0].input_number);
}
