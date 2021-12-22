#include<stdio.h>
#include<stdlib.h>
#include<minmax.h>

struct node 
{
	int data;
	struct node* next;

};

struct node* top = NULL;

void push(int x)
{
	struct node* newElement = (struct node*)malloc(sizeof(struct node));
	newElement->data = x;
	newElement->next = top;
	top = newElement;
}


int pop()
{
	struct node* temp;
	if (top == NULL)
		return INT_MIN;
	temp = top;
	int data1 = temp->data;
	top = top->next;
	free(temp);
	return data1;
}
//void push(int x)
//{
//	struct node* newElement = (struct node*)malloc(sizeof(struct node));
//	newElement->data = x;
//	printf("add element %d\n", x);
//	if (top == NULL)
//	{
//		top = newElement;
//		newElement->next = NULL;
//		return;
//	}
//	newElement->next = top;
//	top = newElement;
//}
//
//int pop()
//{
//	
//	if (top == NULL)
//	{
//		return INT_MIN;
//	}
//	struct node* temp = top;
//	struct node* temp2 = temp->next;
//	int data1 = top->data;
//	free(temp);
//	top = temp2;
//	return data1;
//}

int main() 
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	push(5);
	push(6);
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;

}