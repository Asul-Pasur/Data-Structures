#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;
    int a;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        scanf("%d",&a);
        switch( a ) {
        case 1: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case 2:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case 3:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Stack CreateStack( int MaxElements )
{
    Stack S;
    S=(Stack)malloc(sizeof(struct StackRecord));
    S->Array = (ElementType *)malloc(MaxElements*sizeof(ElementType));//重要//
    S->Top1=-1;
    S->Top2=MaxElements;
    S->Capacity=MaxElements;
    return S;
}

int IsEmpty( Stack S, int Stacknum )
{
    if(Stacknum == 1)
        return S->Top1 == -1;
    else
	return S->Top2 == S->Capacity;
}


int IsFull( Stack S )
{
    if(S->Top2-S->Top1>1)
        return 0;
    else 
        return 1;
}

int Push( ElementType X, Stack S, int Stacknum )
{
    if(IsFull(S))
        return 0;
    else{
        if (Stacknum==1){
            S->Top1++;
            S->Array[S->Top1]=X;
        }
        else if(Stacknum==2){
            S->Top2--;
            S->Array[S->Top2]=X;
        }
    }
    return 1;
}

ElementType Top_Pop( Stack S, int Stacknum )
{
    int n=Stacknum;
    int a;
    if (n==1){
        if(S->Top1==-1)
            return ERROR;
        else{
            a=S->Top1;
            S->Top1--;
             return S->Array[a];
        }
    }
    else if(n==2){
        if(S->Top2==S->Capacity)
            return ERROR;
        else{
            a=S->Top2;
            S->Top2++;
            return S->Array[a];
        }
    }
}

void PrintStack( Stack S, int Stacknum)
{
    if(Stacknum==1){
      printf("Pop from Stack 1: ");
      while(S->Top1!=-1){
        printf("%d ",S->Array[S->Top1]);
        S->Top1--;
      }
    }
    else{
      printf("Pop from Stack 2: ");
      while(S->Top2<S->Capacity){
        printf("%d ",S->Array[S->Top2]);
        S->Top2++;
      }
    }
    printf("\n");
}

