#include<stdio.h>
#include <string.h>
#include <malloc.h>


typedef int DataType;
struct Node {
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//Tao danh sach rong
void makenullTree(Tree *pT){ 
	(*pT) = NULL; 
}

//kiem tra rong
int emptyTree(Tree T){
	return T == NULL;
}

//xac dinh con Left
Tree leftChild(Tree n){
	if(n != NULL) return n->Left;
	else return NULL;
}

//xac dinh con Right
Tree rightChild(Tree n){
	if (n != NULL) return n->Right;
	else return NULL;
}

//kiem tra nut co phai là nút lá 
int isLeaf(Tree n){
	if(n != NULL)
	return(leftChild(n) == NULL)&&(rightChild(n) == NULL);
	else return 0;
} 

//duyet tien tu
void preOrder(Tree T){
	printf("%c ",T->Data);
	if (leftChild(T) != NULL) preOrder(leftChild(T));
	if(rightChild(T) != NULL) preOrder(rightChild(T));
}

//duyet trung tu
void inOrder(Tree T){
	if (leftChild(T) != NULL)inOrder(leftChild(T));
	printf("%c ",T->Data);
	if(rightChild(T) != NULL) inOrder(rightChild(T));
}

//duyet hau tu
void posOrder(Tree T){
	if(leftChild(T) != NULL) posOrder(leftChild(T));
	if(rightChild(T) != NULL) posOrder(rightChild(T));
	printf("%c ", T->Data);
}



typedef Tree Type;
typedef struct {
	Type data[100]; 
	int Topdix; 
} NStack;

//Tao danh sach rong
void makenullNStack(NStack *S){
	S->Topdix = 100;
}

//Kiem tra ngan xep rong
int emptyNStack(NStack S){
	return S.Topdix  == 100;
}

//Kiem tra ngan xap day
int fullNStack(NStack S){
	return S.Topdix == 0;
}

//Gia tri dinh stack
Type topNStack(NStack S){
	return S.data[S.Topdix];
}

//Xoa phan tu tai dinh Stack
void popNStack(NStack *S){
	S->Topdix++;
}

//Them phan tu X vao stack
void pushNStack(Type X, NStack *S){
	if(fullNStack(*S)) {
		printf("Stack day");
	} else {
		S->Topdix--;
		S->data[S->Topdix] = X;
	}
}


#define SoPhanTu 100
typedef char ElementType;
typedef struct {
	ElementType DuLieu[SoPhanTu]; 
	int Dinh; 
} CStack;

//Tao danh sach rong
void makenullCStack(CStack *S){
	S->Dinh = SoPhanTu;
}

//Kiem tra ngan xep rong
int emptyCStack(CStack S){
	return S.Dinh == SoPhanTu;
}

//Kiem tra ngan xap day
int fullCStack(CStack S){
	return S.Dinh == 0;
}

//Gia tri dinh stack
ElementType topCStack(CStack S){
	return S.DuLieu[S.Dinh];
}

//Xoa phan tu tai dinh Stack
void popCStack(CStack *S){
	S->Dinh++;
}

//Them phan tu X vao stack
void pushCStack(ElementType X, CStack *S){
	if(fullCStack(*S)) {
		printf("Stack day");
	} else {
		S->Dinh--;
		S->DuLieu[S->Dinh] = X;
	}
}









