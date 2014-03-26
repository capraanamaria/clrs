/*insertion sort with binary search clrs 2.3-6*/
#include<stdio.h>
void insert(int *a,int n,int q,int v)
{
   int k=0;
   for(k=n-1;k>=q;k--)
       *(a+k+1)=*(a+k);
   
  *(a+k+1)=v;
};

int bs(int *a,int p,int v,int r)
{
    int q=0;
    if(p<r)
      {
           q=(p+r)/2;
           if(*(a+q)<v)
               bs(a,q+1,v,r);
            else if(*(a+q)>v)
                bs(a,p,v,q);
            else if(*(a+q)==v)
                return q+1;   
       }
     else if(p==r)
          {
              if(*(a+p)<=v)
                 return p+1;
              else if(*(a+p)>v)
                 return p; 
         }
};

void insertionsort(int *a,int n)
{
    int q=0;
    if(n>1)
      {
         insertionsort(a,n-1);
         q=bs(a,0,*(a+n-1),n-2);
          insert(a,n-1,q,*(a+n-1));

      }


};


int main(void)
{
    int a[10]={9,8,7,6,5,4,3,2,1,0},i=0;
     insertionsort(a,10);
    
    for(i=0;i<=9;i++)
         printf("%d ",a[i]);
    


 return 0;
}
