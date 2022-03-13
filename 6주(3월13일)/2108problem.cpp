#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int count;
	int input_number;
}check_num;
int main() {

			//입력받은 수들을 저장할 배열을 가리키는 포인터 변수
	int num;				//입력받을 숫자 갯수

	scanf_s("%d", &num,sizeof(num));

	int* input_nums = (int*)malloc(sizeof(num) * num);	//입력받은 수들을 저장할 배열공간

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &input_nums[i],sizeof(num));	//숫자를 배열에 저장
	}

	//1번 산술평균
	int total = 0;

	for (int i = 0; i < num; i++) {
		total += *(input_nums + i);
	}
	if (total > 0) {
		if ((((double)total / num) * 10) < (total / num) * 10 + 5)	//소수 첫째자리에서 반올림
			//printf("산술평균 : %d\n", total / num);
			printf("%d\n", total / num);
		else
			//printf("산술평균 : %d\n", (total / num) + 1);
			printf("%d\n", (total / num) + 1);
	}
	else if (total < 0){
		if ((((double)total / num) * 10) <= (total / num) * 10 - 5)
			//printf("산술평균 : %d\n", (total / num)-1);
			printf("%d\n", (total / num) - 1);
		else
			//printf("산술평균 : %d\n", total / num);
			printf("%d\n", total / num);
	}

	//2번 오름차순 정렬후 중앙 값
	for (int i = 0; i < num; i++) {
		int min = input_nums[i];
		int min_index = i;
		for (int index = i+1; index < num; index++) {
			if (input_nums[index] < min) {
				min = input_nums[index];		//최소값 설정
				min_index = index;			//최소값 인덱스번호
			}
		}
		int temp = min;
		input_nums[min_index] = input_nums[i];
		input_nums[i] = min;
	}

	//printf("중간 값:%d\n", input_nums[num / 2]);
	printf("%d\n", input_nums[num / 2]);

	//3번 최빈값
	check_num* check = (check_num*)malloc(sizeof(check_num));
	check->input_number = input_nums[0];
	check->count = 1;
	int dif_num=1;		//서로 다른 숫자 갯수
	
	for (int i = 1; i < num; i++) {		//모든 숫자배열에 대해서 검사
		int branch = 1;

		for (int j = 0; j < dif_num; j++) {		//구조체가 갖고 있는 숫자에 대해 검사
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
		//check는 서로 다른 숫자가 몇 번 나왔는지 저장해놓은 구조체

	int many_num = check[0].count;				//최빈값 - 가장 많이 나온 숫자
	int many_num_count = 0;						//최빈값 갯수 - 가장 많이 나온 숫자의 수
	int many_num_index = 0;						//최빈값 인덱스 번호

	for (int i = 0; i < dif_num; i++) {
		if (many_num < check[i].count) {
			many_num = check[i].count;			//최빈값 찾기
			many_num_index = i;					//최빈값의 인덱스 번호
		}
	}
	for (int i = 0; i < dif_num; i++) {			//최빈값 갯수 확인 
		if (many_num == check[i].count)
			many_num_count++;
	}
	if(many_num_count==1)
		//printf("최빈값: %d\n", check[many_num_index].input_number);
		printf("%d\n", check[many_num_index].input_number);

	if (many_num_count > 1) {							//최빈값이 여러 개인 경우
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
					min = check_many_num[index];		//최소값 설정
					min_index = index;			//최소값 인덱스번호
				}
			}
			//int temp = min;
			check_many_num[min_index] = input_nums[i];
			check_many_num[i] = min;
		}
		//printf("최빈값: %d\n", check_many_num[1]);
		printf("%d\n", check_many_num[1]);
	}
	
	//printf("범위: %d\n", input_nums[num - 1] - input_nums[0]);
	printf("%d\n",input_nums[num-1]-input_nums[0]);
}
