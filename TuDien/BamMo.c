#include<stdio.h>
#include<malloc.h>

#define B 100
typedef int ElementType;
struct Node {
	ElementType Data;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position Dictionary[B];

int H(ElementType D){
	return D % B;
}

void MakeNullSet(Dictionary *D){
	int i;
	for(i = 0; i < B; i++)
		(*D)[i] = NULL;
}

int Member(ElementType X, Dictionary D){
	Position P;
	int Found = 0;
	P = D[H(X)]; 
	while(P != NULL && !Found)
		if (P->Data == X) Found = 1;
		else P = P->Next;
	return Found;
}

void InsertSet(ElementType X, Dictionary *D){
	int Bucket;
	Position P;
	if (!Member(X, *D)){
		Bucket = H(X);
		P = (*D)[Bucket];
		(*D)[Bucket] = (struct Node*)malloc(sizeof(struct Node));
		(*D)[Bucket]->Data = X;
		(*D)[Bucket]->Next = P;
	}
}

void DeleteSet(ElementType X,Dictionary *D){
	int Bucket, Done;
	Position P,Q;
	Bucket = H(X);
	if((*D)[Bucket] != NULL){ 
		if((*D)[Bucket]->Data == X) { 
			Q = (*D)[Bucket];
			(*D)[Bucket] = (*D)[Bucket]->Next;
			free(Q);
		}
		else { 
			Done = 0;
			P = (*D)[Bucket];
			while(P->Next != NULL && !Done)
				if(P->Next->Data == X) Done = 1; 
				else P = P->Next;
			if (Done){ 
				Q = P->Next; 
				P->Next = Q->Next;
				free(Q);
			}
		}
	}
}

int isEmpty(Dictionary D){
	int i;
	for(i = 0; i < B; i++)
		if(D[i]->Next != NULL) return 0;
	return 1;
}