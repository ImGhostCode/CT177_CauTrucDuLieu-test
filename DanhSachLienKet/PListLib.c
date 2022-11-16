#include <stdio.h>
#include <malloc.h> 
typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;


//khởi tạo một danh sách rỗng
void makenullList(List *L){
    (*L) = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
} 


//phần tử x có tồn tại trong danh sách các số nguyên hay không
ElementType member(ElementType X, List L){
	Position P = L;
	while (P->Next != NULL){
		if(P->Next->Element == X) return 1;
		P = P->Next;
	}
	return 0;
}


//hàm trả về vị trí đầu tiên
Position first(List L){
    return L;
}


//kiểm tra danh sách có rổng không
int emptyList(List L){
    return (L->Next == NULL);
}


//vị trí phần tử cuối cùng
Position endList(List L){
    Position P = L;
    while (P->Next != NULL){
        P = P->Next;
    }
    return P;
}


//vị trí phần tử kế tiếp
Position next(Position P,List L){
    return (P->Next);
}


//chèn phần tử x vào đầu danh sách
void addFirst(ElementType X, List *pL){
	Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = X;
	T->Next = (*pL)->Next;
	(*pL)->Next = T;	
}


//Nhập các các phần tử của một tập hợp từ bàn phím
List readSet(){
	List L;
	ElementType n, i, x;
	makenullList(&L);
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, L) == 0) addFirst(x, &L);
	}
	return L;
}


//trả về vị trí phần tử trước P
Position previous(Position P,List L){
    if(P == first(L))
        return NULL;
    else{
        Position T = first(L);
            while(T->Next != P)
                T = T->Next;
    	return T;
    }
}


// lấy nội dung phần tử tại vị trí P trong danh sách
ElementType retrieve(Position P,List L){
    return P->Next->Element;
}


//tìm vị trí xuất hiện đầu tiên của x trong danh sách
Position locate(ElementType X, List L){
    Position P = L;
    ElementType found = 0;
    while ((P->Next != NULL)&&(found == 0)){
        if ((P->Next->Element) == X)
            found = 1;
        else P = P->Next;
    }
    return P;
}


//xen phần tử x vào vị trí p trong danh sách
void insertList(ElementType X,Position P, List *L){
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}


//Cho phép xóa phần tử ở vị trí p trong danh sách
void deleteList(Position P,List *L){
    Position Temp;
    if(P->Next != NULL){
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    } 
	else printf("\nLoi! Danh sach rong khong the xoa");
}


//nhập danh sách từ bàn phím
void readList(List *L){
    ElementType i, n, X;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&X);
        insertList(X,endList(*L),L);
    }
}


//nhập danh sách từ bàn phím mà gia trị không trùng nhau
void Nhap(List *L){
	makenullList(&*L);
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		int j;
		scanf("%d", &j);
		if(member(j, *L) == 0){
			addFirst(j, &*L);
		}
	}
}


//in danh sách ra màn hình
void printList(List L){
    Position P;
    P=first(L);
    while(P != endList(L)){           
        printf("%d\t",retrieve(P,L));
        P = P->Next;
    }
    printf("\n");
}


//tính tổng tất cả phần tử trong danh sách
ElementType sumList(List L){
	Position P = first(L), E = endList(L);
	ElementType S = 0;
	while(P != E){
		S = S + retrieve(P, L);
		P = next(P, L); 
	}
}


//tính trung bình cộng giá trị các phần tử trong danh sách
float getAvg(List L){
	Position P = L;
	float S = 0, i = 0;
	if(P->Next == NULL) S = -10000;
	else {
		while(P->Next != NULL){
			S = S + P->Next->Element;
			P = P->Next; 
			i++;
		}
		S = S/i;
	}
	return S;
}


//nối phần tử x vào trong danh sách
void append(ElementType X,List *L){
	insertList(X,endList(*L), &*L);
}


//Tính tập hợp hiệu của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2;
List difference(List L1, List L2){
	Position pL;
	makenullList(&pL);
	while(L1->Next != NULL){
		if(member(L1->Next->Element, L2) == 0){
			insertList(L1->Next->Element, endList(pL), &pL);
		}
	L1 = L1->Next;
	}
	return pL;
}


//tìm tập hơp hợp của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2
List unionSet(List L1, List L2){
	Position(L);
	makenullList(&L);
	L = L1;
	while (L2->Next != NULL){
		if(member(L2->Next->Element, L) == 0){
			append(L2->Next->Element, &L);
		}
		L2 = L2->Next;
	}
	return L;
}


//Tính tập hợp giao của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2
List intersection(List L1, List L2){
	Position pL;
	makenullList(&pL);
	while(L1->Next != NULL){
		if(member(L1->Next->Element, L2) == 1){
			insertList(L1->Next->Element, endList(pL), &pL);
		}
	L1 = L1->Next;
	}
	return pL;
}


//Xóa phần tử đầu tiên có giá trị là x trong danh sách
void erase(ElementType X, List *pL){
	if(locate(X, *pL)->Next == NULL) printf("Not found 5000\n");
	else deleteList(locate(X, *pL), &(*pL));
}


//xóa tất cả phần tử có giá trị x trong danh sách đặc các số nguyên
void removeAll(ElementType X, List *pL){
	while(locate(X, *pL)->Next != NULL ){
		deleteList(locate(X, *pL), &*pL);
	}
}


//liệt kê tất cả các phần tử là số chẳn trong danh sách
void copyEvenNumbers(List L, List *pL){
	makenullList(&*pL);
	while(L->Next != NULL){
		if(L->Next->Element % 2 ==0){
			append(L->Next->Element, &*pL);
		}
		L = L->Next;
	}
}


//liệt kê tất cả các phần tử là số lẻ trong danh sách
void printOddNumbers(List L){
	while(L->Next != NULL){
		if(L->Next->Element % 2 != 0){
			printf("%d ", L->Next->Element);
		}
		L = L->Next;
	}
}


//sắp xếp danh sách tăng dần
void sort(List *pL){
	Position i, j;
	for(i = *pL; i->Next != NULL; i = i->Next){
		for(j = *pL; j->Next != NULL; j = j->Next){
			if(i->Next->Element < j->Next->Element){
				ElementType temp = i->Next->Element;
				i->Next->Element = j->Next->Element;
				j->Next->Element = temp;
			}
		}
	}
	
}


//các phần tử trong danh sách nếu trùng nhau thì chỉ giữ lại 1 phần tử, các phần tử khác bị xóa bỏ
void normalize(List *L){
	Position P = *L;
	while (P->Next != NULL){
		Position Q = P->Next;
		while(Q->Next != NULL){
			if(P->Next->Element == Q->Next->Element){
				deleteList(Q, &*L);
			} else {
				Q = Q->Next;
			}
		}
		P = P->Next;
	}		
}


//chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả
void copyEvenNumbers(List L, List *pL){
	makenullList(&*pL);
	while(L->Next != NULL){
		if(L->Next->Element % 2 ==0){
			append(L->Next->Element, &*pL);
		}
		L = L->Next;
	}
}

