// 큐 문제 풀이 (미완성)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;
typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
} Queue;

int isEmpty(Queue q) {
	if (q.size == 0)
		return 1;
	else
		return 0;
}

void push(Queue q, int data) {
	Node* n = malloc(sizeof(Node));
	n->data = data;
	q.rear->next = &n;
}

void main()
{
	char cmd[10];
	int num;
}