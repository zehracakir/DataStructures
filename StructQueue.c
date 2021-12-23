#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Queue {
	unsigned capacity;
	int front;
	int rear;
	int* array;
	int size;
};

struct Queue* createQueue(unsigned capacity) {
	struct Queue* newQueue = (struct Queue*)malloc(sizeof (struct Queue));
	newQueue->size = 0;
	newQueue->front = 0;
	newQueue->rear = 0;
	newQueue->array = (int*) malloc(sizeof(int) * newQueue->capacity);
	return newQueue;

}
bool isFull(struct Queue* queue) {
	if (queue->size == queue->capacity)
		return true;

	return false;
}
bool isEmpty(struct Queue* queue) {
	if (queue->size == 0)
		return true;

	return false;
}
void enQueue(int x, struct Queue* newQueue) {
	if (isFull(newQueue)) {
		printf("Array is full\n");
		return;
	}
	newQueue->array[newQueue->rear] = x;
	newQueue->rear = (newQueue->rear + 1) % newQueue->capacity;
	newQueue->size++;
	printf("queued element = %d\n", x);
}

void deQueue(struct Queue* newQueue) {
	if (isEmpty(newQueue)) {
		printf("Array is empty\n");
		return;
	}
	int data = newQueue->array[newQueue->front];
	newQueue->front = (newQueue->front + 1)%newQueue->capacity;
	newQueue->size--;
	printf("Delete : %d\n", data);
}


int main() {
	struct Queue* newQueue = createQueue(5);
	enQueue(0,newQueue);
	enQueue(1, newQueue);
	enQueue(2, newQueue);
	enQueue(3, newQueue);
	enQueue(4, newQueue);
	deQueue(newQueue);
	deQueue(newQueue);
	deQueue(newQueue);
	deQueue(newQueue);
	deQueue(newQueue);
	enQueue(5, newQueue);
	enQueue(6, newQueue);
	deQueue(newQueue);

	return 0;
}