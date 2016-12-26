#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

ElementType EvalPostfix( char *expr )
{
    int i,j,flag,k;
    double a[Max_Expr];
    double n,e;
    

    i=0;
    n=0;
    j=0;
    flag=0;
    while(expr[i]!=0||expr[i+1]!=0)
    {
      if(expr[i]=='-'&&('0'<=expr[i+1]&&expr[i+1]<='9'))
      {
        n=-1*(expr[i+1]-'0');
        i=i+2;
        a[j]=n;
      }
      while(('0'<=expr[i]&&expr[i]<='9')||expr[i]=='.')
      {
        if(flag>0)
          flag++;
        if(expr[i]=='.'){
          flag=1;
          e=expr[++i]-'0';
        }
        if(n>=0&&flag==0)
          n=10*n+expr[i]-'0';
        else if(flag==0)
          n=10*n-expr[i]+'0';
        else if(n>=0){
          for (k=1;k<=flag;k++)
            e=e/10;
          n=n+e;
        }
        else{
          for (k=1;k<=flag;k++)
            e=e/10;
          n=n-e;
        }
        a[j]=n;
        if(expr[i]!=0||expr[i+1]!=0)
          i++;
        else
          break;
      }
      if(expr[i]=='+')
      {
        if(j<2)
          return Infinity;
        a[j-2]=a[j-2]+a[j-1];
        j=j-3;
      }
      if(expr[i]=='-')
      {
        if(j<2)
          return Infinity;
        a[j-2]=a[j-2]-a[j-1];
        j=j-3;
      }
      if(expr[i]=='*')
      {
        if(j<2)
          return Infinity;
        a[j-2]=a[j-2]*a[j-1];
        j=j-3;
      }
      if(expr[i]=='/')
      {
        if(j<2||a[j-1]==0)
          return Infinity;
        a[j-2]=a[j-2]/a[j-1];
        j=j-3;
      }
      i++;
      j++;
      n=0;
      flag=0;
    }
    if(j!=0)
      return Infinity;
    else 
      return a[0];
}
