#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE];
int front=-1;
int rear=-1;

void EnQueue(int queue1[], int number) {
	if (rear == -1){
		front = rear = 0;
		queue1[rear] = number;		
	}
	else if (rear == SIZE - 1) {
		printf("Queue is full!\n");
		return;
	}
	else{
		rear++;
		queue[rear] = number;
	}
	
	printf("Element added\n");

}

void DeQueue(int queue1[]) {
	int number;
	if (front == -1) {
		printf("Queue is empty");
		return;
	}
	else if (rear == front) {
		number = queue1[SIZE];
		front = rear - 1;
	}
	else {
		number = queue1[front];
		front++;
	}
}

void screenPrint(int queue[]) {
	if (front == -1) {
		printf("Queue is empty");
		return;
	}
	for (int i = front; i <= rear; i++) {
		printf("%d  ", queue[i]);
	}
	printf("\n");
}

int main() {
	int number, choose;
	while (1) {
		printf("select the action you want to do\n");
		printf("1-Add an element\n");
		printf("2-Delete an element\n");
		printf("3-Print screen elements\n");
		scanf_s("%d", &choose);

		switch (choose) {
		case 1:
			printf("Enter the element you want to add\n");
			scanf_s("%d", &number);
			EnQueue(queue, number);
			break;
		case 2:
			DeQueue(queue);
			break;
		case 3:
			screenPrint(queue);
			break;


		}
	}
return 0;
}
