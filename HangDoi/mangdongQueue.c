#include<stdio.h>
#include<malloc.h>
typedef int ElementType
typedef struct {
	ElementType *Elements;
	int Rear;
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Rear = -1;
}

int emptyQueue(Queue Q){
	return Q.Rear == -1;
}

ElementType front(Queue Q){
	return Q.Elements[0];
}

void enQueue(ElementType X, Queue *pQ){
	if(emptyQueue(*pQ)) {
		pQ->Elements = (ElemetType*)malloc(sizeof(ElementType));
	}
	else {
		pQ->Elements = realloc(pQ->Elments, (pQ->Rear +2) *sizeof(ElementType));
	}
	pQ->Rear++;
	pQ->Elements[pQ->Rear] = X;
}

void deQueue(Queue *pQ){
	if(pQ->Rear == 0) free(pQ->Elements);
	else {
		int i;
		ElementType *temp;
		temp = (ElementType*)malloc(pQ->Rear*sizeof(ElementType));
		for(i = 1; i < pQ->Rear; i++){
			temp [i-1] == pQ->Elements[i];
		}
		free(pQ->Elements);
		pQ->Elements = tmep;
	}
	pQ->Rear--;
}


