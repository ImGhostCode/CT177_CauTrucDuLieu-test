#include <stdio.h>
#define MaxSize 100
typedef char ElementType;
typedef struct {
 	ElementType Element[MaxSize];
 	int Front, Rear;
} Queue;

// Tao mot hang doi rong
void makenullQueue(Queue *pQ){
 	pQ->Front = -1;
	pQ->Rear = -1;
}

//kiem tra hang doi rong hay khong
int emptyQueue(Queue Q){
 	return Q.Front == -1;
} 

//kiem tra hang doi co day hay khong
int fullQueue(Queue Q){
 	return (Q.Rear - Q.Front + 1) == MaxSize;
}

//tra ve phan tu dau hang
ElementType front(Queue Q){
	return Q.Element[Q.Front];
}

//xoa phan tu dau hang
void deQueue(Queue *Q){
	if(Q->Front == Q->Rear) makenullQueue(&*Q);
	else Q->Front++;
}

//them phan tu vao cuoi hang 
void enQueue(ElementType X, Queue *Q){
	if(fullQueue(*Q)) printf("Hang day\n");
	else {
		if(emptyQueue(*Q)) Q->Front = 0;
		if(Q->Rear == MaxSize - 1){
			int i;
			for(i = Q->Front; i < Q->Rear; i++) {
				Q->Element[i - Q->Front] = Q->Element[i];
			}
			Q->Rear = Q->Rear - Q->Front;
			Q->Front = 0;
		}
		Q->Rear = Q->Rear + 1;
		Q->Element[Q->Rear] = X; 
	}
} 

//
int count(Queue Q1, Queue Q2){
	int dem = 0;
	while (!emptyQueue(Q1)){
		if (front(Q1) == front(Q2)){
			dem++;
			deQueue(&Q1);
			deQueue(&Q2);
		} else {
			enQueue(front(Q1), &Q1);
			deQueue(&Q1);
			dem++;
		}
	}
	return dem;
}


