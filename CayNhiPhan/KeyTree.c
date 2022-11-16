#include<stdio.h>
#include<malloc.h>
//#include<string.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//tìm kiếm khóa x trong cây tìm kiếm nhị phân
Tree search(KeyType x,Tree Root){
	if (Root == NULL) return NULL;
	else if (Root->Key == x) return Root;
	else if (Root->Key < x) return search(x,Root->Right);
	else return search(x,Root->Left);
}

//thêm khóa X vào cây tìm kiếm nhị phân
void insertNode(KeyType x, Tree *pT){
	if((*pT) == NULL){
		(*pT) = (struct Node*)malloc(sizeof(struct Node));
		(*pT)->Key = x;
		(*pT)->Left = NULL;
		(*pT)->Right = NULL;
	} 
	else if((*pT)->Key == x) printf("Da ton tai khoa x");
	else if((*pT)->Key > x) insertNode(x,&(*pT)->Left);
	else insertNode(x,&(*pT)->Right);
}

//xoa khoa x trong cay T
KeyType deleteMin(Tree *pT){
	KeyType k;
	if((*pT)->Left == NULL){
		
		k = (*pT)->Key;
		
		(*pT) = (*pT)->Right;
		
		return k;
	}
	
	else return deleteMin(&(*pT)->Left);
}

void deleteNode(KeyType x, Tree *pT){
	if((*pT)!=NULL) {
		
		if(x <(*pT)->Key) deleteNode(x,&(*pT)->Left);
		
		else if(x >(*pT)->Key) deleteNode(x,&(*pT)->Right);
		
		else if(((*pT)->Left==NULL) && ((*pT)->Right==NULL)) (*pT)=NULL; 
		
		else if((*pT)->Left==NULL) (*pT) = (*pT)->Right;
		
		else if((*pT)->Right==NULL) (*pT) = (*pT)->Left;
		
		else (*pT)->Key = deleteMin(&(*pT)->Right);
	}	
}

//liet ke cac gia tri khoa tren duong di tim kiem khoa X
void printPath(int x,Tree root){
	if (root == NULL) printf("-> Khong thay");
	else if (root->Key == x) printf("%d -> Tim thay", root->Key);
	else if (root->Key < x){
		printf("%d ", root->Key);
		printPath(x,root->Right);
	}		
	else {
		printf("%d ", root->Key);
		printPath(x,root->Left);
	}	
}

//hàm duyệt tien tự cây tìm kiếm nhị phân T
void preOrder(Tree T){
	printf("%d ", T->Key);
	if(T->Left != NULL) preOrder(T->Left);
	if(T->Right != NULL) preOrder(T->Right);
}

//duyệt hậu tự cây tìm kiếm nhị phân T
void posOrder(Tree T){
	if(T->Left != NULL) posOrder(T->Left);
	if(T->Right != NULL) posOrder(T->Right);
	printf("%d ", T->Key);
}

//hàm duyệt trung tự cây tìm kiếm nhị phân T
void inOrder(Tree T){
	if(T->Left != NULL) inOrder(T->Left);
	printf("%d ", T->Key);
	if(T->Right != NULL) inOrder(T->Right);
}

// kiem tra cay goc co rong khong
int isEmpty(Tree T){
	return T == NULL ;
}

//tìm kiếm nút anh em ruột phải của nút có khóa x trong cây tìm kiếm nhị phân
Tree rightSibling(int X, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == X) {
			if(pt != P) return pt;
			else return NULL;
		}
		pt = P->Right;
		if(P->Key > X) P = P->Left;
		else P = P->Right;
	}
	return NULL;	
}

//tìm kiếm nút cha của nút có khóa x trong cây tìm kiếm nhị phân
Tree getParent(int x, Tree T){
	Tree P = T, parent = NULL;
	while(P != NULL){
		if(P->Key == x) return parent;
		parent = P;
		if(P->Key > x) P = P->Left;
		else P = P->Right;
	}
	return NULL;
}

//tính chiều cao của nút có khóa x trong cây T
int hNode(int X, Tree T){
    if(T == NULL) return -1;
	if(T->Key == X){
	    if(T->Left == NULL && T->Right == NULL) return 0;
	    int l = 0, r = 0;
	    if(T->Left != NULL) l = hNode(T->Left->Key, T-> Left);
	    if(T->Right != NULL) r = hNode(T->Right->Key, T->Right);
	    return l > r ? l + 1 : r + 1;
	}
	else if(T->Key < X) return hNode(X, T->Right);
	else return hNode(X, T->Left);
}

//khởi tạo và trả về một cây rỗng
Tree initTree(){
    Tree T = NULL;
    return T;
}

//tính chiều cao cây T
int getHeight(Tree T){
	if(T == NULL) return -1;
	int l = 0, r = 0;
	if(T->Left != NULL) l = 1 + getHeight(T-> Left);
	if(T->Right != NULL) r = 1 +  getHeight(T->Right);
	return l > r ? l: r;
}

//nút đứng sau nút có khóa x trong cây TKNP trong phép duyệt trung tự
Tree getMin(Tree T){
	if(T==NULL) return NULL;
	if(T->Left == NULL) return T;
	return getMin(T->Left);
}

Tree getNext(KeyType x, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == x){
			if(T->Right == NULL) return pt;
			else return getMin(P->Right);
		}
		else if(P->Key > x){
			pt = P;
			P =P->Left;
		}
		else P = P->Right;
	}
	return NULL;
}

//nút đứng trước nút có khóa x cho trước trong phép duyệt trung tự
Tree getMax(Tree T){
	if(T == NULL) return NULL;
	if(T->Right == NULL) return T;
	return getMax(T->Right);
}

Tree getPrevious(KeyType x, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == x){
			if(P->Left == NULL) return pt;
			else return getMax(P->Left);
		}
		else if(P->Key < x){
			pt = P;
			P = P->Right;
		}
		else P= P->Left;
	}
	return NULL;
}
