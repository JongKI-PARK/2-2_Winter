//bj11729.c : BACKJOON no11729 hannoi top
//2022.3.20 PARK JONGKI
#include <stdio.h>

void move(int k, int from, int to) {
	if (k == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	else if (k > 1) {
		int curr = from;
		int another = 6 - from - to;
		int destination = to;
		move(k - 1, curr, another);
		printf("%d %d\n", from, to);
		move(k - 1, another, destination);
	}
}
int main() {
	int n;
	scanf_s("%d", &n);
	int pow = n;
	int result = 1;
	while (pow > 0) {
		result *= 2;
		pow--;
	}
	printf("%d\n", result-1);
	move(n, 1, 3);
	return 0;
}