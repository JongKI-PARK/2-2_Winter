//bj2309.cpp back joon no.2309 using bubble sort
//2022.2.4 KI

#include <stdio.h>

int main(void) {
	int sum = 0;
	int dwarf = 9;
	int p, q = 0;
	int aList[9] = { 0 };

	for (int i = 0; i < dwarf; i++) {
		scanf_s("%2d", &aList[i]);
		sum += aList[i];
	}

	int need_remove = sum - 100;
	for (int i = 0; i < dwarf - 1; ++i) {
		for (int j = i + 1; j < dwarf; ++j) {
			int result = aList[i] + aList[j];
			if (result == need_remove)
				p = i, q = j;
		}
	}
	aList[p] = aList[q] = 0;

	int nTmp = 0;
	for (int i = 0; i < dwarf-1; ++i){
		for (int j = i + 1; j < dwarf; ++j){
			if (aList[i] > aList[j]){
				nTmp = aList[i];
				aList[i] = aList[j];
				aList[j] = nTmp;
			}
		}
	}

	for (int i = 2; i < dwarf; i++) {
			printf("%d\n", aList[i]);
	}
	return 0;
}