#include <stdio.h>
#include <stdlib.h>

#include "cQueue.h"

QueueType* createCQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

// Check whether queue is empty
int isEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

// Check whether queue is full
int isFull(QueueType* cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
		return 1;
	}
	else {
		return 0;
	}
}

// Push item at rear
void push(QueueType* cQ, element item) {
	if (isFull(cQ)) {
		return;
	}
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

// Return item at front and delete
element pop(QueueType* cQ) {
	if (isEmpty(cQ)) {
		return -1;
	}
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

// Return item at front
element front(QueueType* cQ) {
	if (isEmpty(cQ)) {
		return -1;
	}
	else {
		return cQ->queue[(cQ->front + 1) % cQ_SIZE];
	}
}

// Return item at rear
element back(QueueType* cQ) {
	if (isEmpty(cQ)) {
		return -1;
	}
	else {
		return cQ->queue[cQ->rear];
	}
}

// Print all items
void print(QueueType* cQ) {
	int front = cQ->front;

	while (front != cQ->rear) {
		front = (front + 1) % cQ_SIZE;
		printf("%d ", cQ->queue[front]);
	}
	printf("\n");
}
