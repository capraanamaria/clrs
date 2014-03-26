/*insertion sort 2.3-4*/
#include<stdio.h>

void insert(int *a,int p)
{
   int i=p-2,key=*(a+p-1);
   
   while(key<*(a+i)&&i>=0)
         {
             *(a+i+1)=*(a+i);
                i-=1;
         }
    
    *(a+i+1)=key;

   return 0;
}

void insertionsort(int *a,int n)
{
    if(n>1)
     {
         insertionsort(a,n-1);
         insert(a,n);       
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
