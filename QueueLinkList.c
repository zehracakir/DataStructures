#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;

};

struct node* front = NULL;
struct node* rear = NULL;

void EnQueue(int x) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;

	if (front == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

int DeQueue() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (front == NULL)
	{
		printf("Queue is empty");
		return;
	}
	else if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
		free(temp);
}

void Print() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = front;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	EnQueue(1); 
	EnQueue(2); 
	EnQueue(3); 
	EnQueue(4); 
	EnQueue(5); 
	EnQueue(6); 
	EnQueue(7); 
	EnQueue(8);   
	DeQueue();  
	DeQueue();  
	DeQueue();  
	DeQueue();  
	Print();

	return 0;
}