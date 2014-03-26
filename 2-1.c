/*merge sort with insertion sort clrs problems 2-1*/

#include<stdio.h>

int k=2;
void insert(int *a,int p,int r)
{
   int i=0,key=*(a+r);
   for(i=r-1;i<=p&&*(a+i)>key;i--)
       *(a+i+1)=*(a+i);

    *(a+i+1)=key;

};

void insertionsort(int *a,int p,int r)
{
    if(p<r)
       {
           insertionsort(a,p,r-1);
            insert(a,p,r);
       }
};

void merge(int *a,int p,int q,int r)
{
    int i=0,j=0,k=0,n1=q-p,n2=r-q-1,L[6],R[6];
    for(k=p;k<=q;k++)
         {
            L[i]=*(a+k);
          i+=1;
        }
    for(k=q+1;k<=r;k++)
        {
          R[j]=*(a+k);
          j+=1;
        }
   i=0;j=0;L[n1+1]=1000,R[n2+1]=1000;
      for(k=p;k<=r;k++)
          {
              if(L[i]<=R[j])
                      {
                           *(a+k)=L[i];
                              i+=1;
                      }
               else
                     {
                         *(a+k)=R[j];
                            j+=1;
                     }
        
         }
};
void mergesort(int *a,int p,int r)
{
    int q=0;
    if(r-p+1>k)
       {
           q=(p+r)/2;
            mergesort(a,p,q);
            mergesort(a,q+1,r);
            merge(a,p,q,r);
       }

    else if(r-p+1<=k)
             insertionsort(a,p,r);

};
int main(void)
{
   int a[10]={3,41,52,26,38,57,9,49},i=0;
  
   mergesort(a,0,7);

   for(i=0;i<=7;i++)
        printf("%d ",a[i]);

   return 0;
}
