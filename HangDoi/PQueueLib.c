#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef struct {
	Position Front, Rear;
}Queue;

void makenullQueue(Queue *Q){
	Position Header;
	Header = (struct Node*)malloc(sizeof(struct Node));
	Header->Next = NULL;
	Q->Front = Header;
	Q->Rear = Header;
}

int emptyQueue(Queue Q){
	return (Q.Front == Q.Rear);
}

void enQueue(ElementType X, Queue *Q){
	Q->Rear->Next = (struct Node*)malloc(sizeof(struct Node));
	Q->Rear = Q->Rear->Next;
	Q->Rear->Element = X;
	Q->Rear->Next = NULL;
	
	/*
	Position H = (Node*)malloc(sizeof(Node));
	H->Element = X;
	H->Next = NULL;
	(*Q).Rear->Next = H;
	(*Q).Rear = H;
	*/
}

void deQueue(Queue *Q){
	Position Temp;
	Temp = Q->Front;
	Q->Front = Q->Front->Next;
	free(Temp);
}

ElementType Front(Queue Q){
	if(!emptyQueue(Q)) return Q.Front->Next->Element;
	else return printf("Hang rong\n");
}



