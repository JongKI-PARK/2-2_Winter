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
	
	
	scanf_s("%d", &string_num, sizeof(string_num));		//단어개수 입력받기

	count = string_num;		//그룹단어의 최대 개수 설정
	
	for (int loop = 0; loop < string_num; loop++) {		//단어개수만큼 반복
		scanf_s("%s", input, sizeof(input));	//단어입력받기
		int escape = 0;
		int check_index = 0;
		for (index = check_index; index < strlen(input); index++) {
			find_index = strrchr(input, input[index]);	//index번째의 같은 마지막 문자 위치 찾기
			int compare_index = find_index - input;		//index번째와 같은 마지막 문자의 index번호

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
