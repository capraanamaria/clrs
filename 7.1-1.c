/*clrs 7.1-1*/
#include<stdio.h>
int partition(int *a,int p,int r)
{
   int x=*(a+r),i=p-1,t=0,j=0;
   for(j=p;j<=r-1;j++)
      {
          if(*(a+j)<=x)
           {
              i+=1;
              t=*(a+i);
              *(a+i)=*(a+j);
              *(a+j)=t; 
           }

       }
     t=*(a+i+1);
     *(a+i+1)=*(a+r);
     *(a+r)=t;
   return i+1;
}

void quicksort(int *a,int p,int r)
 {
    int q=0;
    if(p<r)
     {
         q=partition(a,p,r);
         quicksort(a,p,q-1);
         quicksort(a,q+1,r);
     }
}
int main(void)
{
  int A[12]={13,19,9,5,12,8,7,4,21,2,6,11},i=0;
  quicksort(A,0,11);
  for(i=0;i<=11;i++)
  {
     printf("%d ",A[i]);
  }
  return 0;
}
