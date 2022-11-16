#include <stdio.h>
#define Maxlength 100

typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType Elements[Maxlength];
    Position Last;
}List;	


//tạo danh sách rỗng
void makenullList(List *pL){
    pL->Last=0;
}


//kiểm tra danh sách rỗng
ElementType emptyList(List L){
    return (L.Last==0);
}


//kiểm tra danh sách đầy
ElementType fullList(List L){
    return (L.Last==Maxlength);
}


//trả về vị trí phần tử đầu tiên trong danh sáng
Position firstList(List L){
    return 1;
}


//trả về vị trí sau phần tử cuối cùng trong danh sách
Position endList(List L){
    return L.Last+1;
}


//trả về vị trí phần tử kế tiếp phần tử P
Position next(Position P,List L){
    return P+1;
}


//trả về vị trí phần tử trước phần tử P
Position previous(Position P,List L){
    return P-1;
}


//trả về nội dung phần tử tại vị trí P
ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}


//thêm phần tử  vào cuối danh sách
void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
}


//them phần tử có nội dung X vào tại vị trí P
void insertList(ElementType X, Position P, List *pL){
    ElementType i = 0;
    if(pL->Last == Maxlength)
        printf("\nDanh sach day!!!");
    else if(P < 1 || P > pL->Last+1)
        printf("\nVi tri khong hop le!!!");
    else{
        for(i = pL->Last;i >= P;i--){
        	pL->Elements[i] = pL->Elements[i-1];
		}
        pL->Last++;
        pL->Elements[P-1] = X;
    }
}


//xóa phần tử tại vị trí P
void deleteList(Position P,List *L){
    if(P > L->Last || P < 1)
        printf("\nVi tri khong hop le!!!");
    else if(L->Last == 0)
        printf("\nDanh sach rong!");
    else {
    	Position i;
        for(i = P;i < L->Last;i++){
        	L->Elements[i-1] = L->Elements[i];
        }
        L->Last--;           
    }
}


//in danh sách ra màng hình
void printList(List L){
    Position P = firstList(L);
    while(P != endList(L)){
        printf("%d ",retrieve(P,L));
        P = next(P,L);
    }
    printf("\n");
}


//nhap danh sách từ bàn phím
void readList(List *L){
    int i,N;
    ElementType X;
    makenullList(L);
    scanf("%d",&N);
    for(i = 1;i <= N;i++){
        scanf("%d",&X);
        insertList(X,endList(*L),L);
    }
}


//tìm ị trí phần tử đầu tiên có nội dung X
Position locate(ElementType X,List L){
    Position P;
    int found = 0;
    P = firstList(L);
    while ((P != endList(L)) && (found == 0)) {
        if(retrieve(P,L) == X)
            found = 1;
        else
            P = next(P,L);
    }
    return P;
}


//kiểm tra phần tử X có trong danh sách không
ElementType member(ElementType x, List L){
	ElementType i = 0;
	while (i < L.Last){
		if (L.Elements[i] == x) return 1;
		i++;
	}
	return 0;
}


//nhập một tập hợp từ phần phím
void readSet(List *pL){
	makenullList(&*pL);
	ElementType n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, *pL) == 0) insertSet(x, &*pL);
	}
}


//liệt kê các số lẻ trong danh sách
void printOddNumbers(List L){
	ElementType i = 0;
	for(i = 0; i < L.Last; i++){
		if(L.Elements[i] % 2 != 0 ) printf("%d ", L.Elements[i]);
	}
}


//xoa phân tử X xuất hiện đầu tiên 
void erase(ElementType x, List *pL){
	deleteList(locate(x, *pL), &*pL);	
}


