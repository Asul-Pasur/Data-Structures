#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

Polynomial Add ( Polynomial a, Polynomial b )
{
    if(a->Next==NULL)
      return b;
    else if(b->Next==NULL)
      return a;
    Polynomial c,d,e,f;
    c=(Polynomial)malloc(sizeof(struct Node));
    d=a;
    e=b;
    f=c;
    while(d->Next!=NULL&&e->Next!=NULL)
    {
      if(d->Next->Exponent>e->Next->Exponent)
      {
        d=d->Next;
        f->Next=(Polynomial)malloc(sizeof(struct Node));
        f->Next->Coefficient=d->Coefficient;
        f->Next->Exponent=d->Exponent;
        f=f->Next;
      }
      else if(d->Next->Exponent<e->Next->Exponent)
      {
        e=e->Next;
        f->Next=(Polynomial)malloc(sizeof(struct Node));
        f->Next->Coefficient=e->Coefficient;
        f->Next->Exponent=e->Exponent;
        f=f->Next;
      }
      else if(d->Next->Exponent=e->Next->Exponent)
      {
        e=e->Next;
        d=d->Next;
        f->Next=(Polynomial)malloc(sizeof(struct Node));
        f->Next->Coefficient=e->Coefficient+d->Coefficient;
        f->Next->Exponent=e->Exponent;
        f=f->Next;
      }
    }
    if(d->Next==NULL)
      f->Next=e->Next;
    else if(e->Next==NULL)
      f->Next=d->Next;
    return c;
}

Polynomial Read()
{
    Polynomial p,S;
    int n;
    p=(Polynomial)malloc(sizeof(struct Node));
    S=p;
    scanf("%d",&n);
    for(;n>0;n--){
      p->Next=(Polynomial)malloc(sizeof(struct Node));
      p=p->Next;
      scanf("%d%d",&p->Coefficient,&p->Exponent);
    }
    return S;
}

void Print(Polynomial p)
{
    Polynomial S;
    S=p;
    while(S->Next!=NULL){
      S=S->Next;
      printf("%d %d ",S->Coefficient,S->Exponent);
    }
}
