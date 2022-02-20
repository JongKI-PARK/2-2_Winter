//bj10828 : stack 
//2022.2.20 PARK JONGKI

#include <stdio.h>
#include <string.h>
//#include <stdbool.h> //is needed in C99
#define MAX_SIZE 1000

typedef struct stack {
	int array[MAX_SIZE];
	int top_index;
}stack;


void Initialize(stack* sp) {
	sp->top_index = -1;
}
bool IsEmpty(stack* sp) {
	if (sp->top_index == -1)
		return true;
	else
		return false;
}
bool IsFull(stack* sp) {
	if (sp->top_index == MAX_SIZE)
		return true;
	else
		return false;
}
void Push(stack* sp, int data) {
	if (IsFull(sp) == true)
		return;
	else
		sp->array[++(sp->top_index)] = data;
}
int Pop(stack* sp) {
	if (IsEmpty(sp) == true)
		return -1;
	else
		return sp->array[(sp->top_index)--];
}
int Size(stack* sp) {
	return sp->top_index + 1;
}
int Top(stack* sp) {
	if (IsEmpty(sp) == true)
		return -1;
	else
		return sp->array[sp->top_index];
}
int main() {
	stack stack={0};
	char str[10]={NULL};
	int n = 0;
	int iternum;

	scanf_s("%d", &iternum);
	fflush(stdin);
	Initialize(&stack);
	for (int i = 0; i < iternum;i++) {
		scanf_s(" %s",str,5);

		if (strcmp(str, "push")==0) {
			scanf_s(" %d", &n);
			Push(&stack, n);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", Pop(&stack));
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", Size(&stack));
		}
		else if(strcmp(str, "empty") == 0) {
			printf("%d\n", IsEmpty(&stack));
		}
		else if (strcmp(str, "top") == 0) {
			printf("%d\n", Top(&stack));
		}
	}
	return 0;
}