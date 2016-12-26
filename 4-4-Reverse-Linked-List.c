#include<stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    int Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int n;
    Position L,P;
    L=(List)malloc(sizeof(struct Node));
    P=L;
    scanf("%d",&n);
    for(n;n>0;n--){
      P->Next=(Position)malloc(sizeof(struct Node));
      P=P->Next;
      scanf("%d",&P->Element);
    }
    return L;
}


void Print( List L )
{
    Position P;
    P=L;
    if(!P||!P->Next)
      return 0;
    for(;P->Next;P=P->Next)
      printf("%d ",P->Next->Element);
    printf("\n");
    return 0;
}

List Reverse( List L )
{
    List L2=(List)malloc(sizeof(struct Node));
    if(!L->Next)
      return 0;
    Position P,T;
    int n=0;
    int a[10];
    for(P=L->Next;P;P=P->Next){
      a[n]=P->Element;
      n++;
    }
    P=L2;
    for(n--;n>=0;n--){
      P->Next=(Position)malloc(sizeof(struct Node));
      P=P->Next;
      P->Element=a[n];
    }
    T=L;
    for(T;T->Next&&T->Next->Next;T=P){
      T=T->Next;
      P=T->Next;
      free(T);
    }
    free(T->Next);
    free(T);
    L->Next=L2->Next;
    return L2;
}   
