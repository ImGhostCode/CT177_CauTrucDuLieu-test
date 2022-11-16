#include <stdio.h>
// mang vong

#define MaxLength 100
typedef int ElementType;
typedef struct{ 
	ElementType Elements[MaxLength];
	int Front, Rear;
} Queue;

void makenullQueue(Queue *Q) {
	(*Q).Front = -1;
	(*Q).Rear = -1;
}

int emptyQueue(Queue Q){
	return Q.Front==-1;
}

int fullQueue(Queue Q){
	return (Q.Rear-Q.Front+1) % MaxLength == 0;
}

ElementType front(Queue Q){
	return Q.Elements[Q.Front];
}

void deQueue(Queue *Q){
	if ((*Q).Front==(*Q).Rear) makenullQueue(Q);
	else (*Q).Front= ((*Q).Front+1)% MaxLength;
}

void enQueue(ElementType X, Queue *Q){
	if (fullQueue(*Q)) printf("Hang day\n");
	else{
		if (emptyQueue(*Q)) (*Q).Front=0;
		(*Q).Rear=((*Q).Rear + 1) % MaxLength;
		(*Q).Elements[(*Q).Rear] = X;
	}
}




