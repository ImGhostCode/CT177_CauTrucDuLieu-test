#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
struct Node {
	ElementType Element;
	struct Node *Prev, *Next;	
};
typedef struct Node *Position;
typedef Position Double_List;

void makenullDouble_List(Double_List *DL){
	DL= NULL;
}

int emptyDouble_List (Double_List DL){
	return (DL==NULL);
}

ElementType retrieve_Double_List (Position P, Double_List DL){
	return P->Element;
}

void insertDouble_List (ElementType X, Position p, Double_List DL){ 
	if(DL == NULL){ 
		DL= (struct Node*)malloc(sizeof(struct Node));
		DL->Element = X;
		DL->Prev = NULL;
		DL->Next =NULL;
	} 
	else {
		Position temp;
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->Element=X;
		temp->Next=p;
		temp->Prev=p->Prev;
		if (p->Prev!=NULL)
			p->Prev->Next=temp;
			p->Prev=temp;
	}
}

void deleteDouble_List (Position p, Double_List DL){ 
	if (DL == NULL)
		printf("Danh sach rong");
	else{
		if (p==DL)
			DL= DL->Next;
		else p->Prev->Next = p->Next;
		if (p->Next!=NULL)
			p->Next->Prev=p->Prev;
		free(p);
	}
}

