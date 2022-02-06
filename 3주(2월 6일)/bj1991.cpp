//bj1991.cpp : tree traverse preorder,inorder,postorder
//2022.2.6 KI

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node {
	char data;
	struct node* lchild;
	struct node* rchild;
};

typedef struct node node;


void Preorder(node* tree) {
	if (tree != NULL) {
		printf("%c", tree->data);
		Preorder(tree->lchild);
		Preorder(tree->rchild);
	}
}
void Inorder(node* tree) {
	if (tree != NULL) {
		Inorder(tree->lchild);
		printf("%c", tree->data);
		Inorder(tree->rchild);
	}
}
void Postorder(node* tree) {
	if (tree != NULL) {
		Postorder(tree->lchild);
		Postorder(tree->rchild);
		printf("%c", tree->data);
	}
}

int main() {
	int node_number = 0;
	cin >> node_number;

	int index = 0;
	char root, left, right;
	node* tree = (node*)malloc(node_number * sizeof(node));
	for (int i = 0; i < node_number; i++) {
		cin >> root >> left >> right;

		index = root - 'A';
		tree[index].data = root;

		if (left == '.')
			tree[index].lchild = NULL;
		else
			tree[index].lchild = &tree[left - 'A'];

		if (right == '.')
			tree[index].rchild = NULL;
		else
			tree[index].rchild = &tree[right - 'A'];
	}
	Preorder(&tree[0]);
	printf("\n");
	Inorder(&tree[0]);
	printf("\n");
	Postorder(&tree[0]);

	free(tree);
	return 0;
}