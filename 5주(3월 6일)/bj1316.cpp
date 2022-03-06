//backjoon 1316 
//2022.3.6 PARK JONGKI

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
	int n;
	scanf_s("%d", &n);
	char word[MAX_SIZE] = { NULL };
	int index;
	int flag = 0;
	int result = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%s", &word,sizeof(word));
		char alphabet[26] = { 0 };
		flag = 0;
		index = (int)(word[0]) - 97;
		alphabet[index] = 1;

		int j = 1;
		while(word[j] != NULL) {
			index = (int)(word[j]) - 97;
			if (alphabet[index] == 1) {
				if (word[j] != word[j - 1])
					flag = 1;
			}
			else
				alphabet[index] = 1;
			j++;
		}
		if (flag == 0) {
			result += 1;
		}
	}
	printf("%d\n", result);
	return 0;
}