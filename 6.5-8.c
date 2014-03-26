/*clrs 6.5-8*/
#include<stdio.h>
int heapsize=12;
void heapdelete(int *a,int i,int *left,int *right)
{
   int l=*(left+i),r=*(right+i),j=0;
   if((l<=heapsize-1)||(r<=heapsize-1))
     {
         if((l<=heapsize-1)&&(r<=heapsize-1))
           {
               if(*(a+l)>*(a+r))
                {
                    *(a+i)=*(a+l);
                      heapdelete(a,l,left,right);
                }
                else
                 {
                     *(a+i)=*(a+r);
                     heapdelete(a,r,left,right);
                 }
           }
           else if(l<=heapsize-1)
             {
                 *(a+i)=*(a+l);
                 heapdelete(a,l,left,right);
             }
           else
             {
                 *(a+i)=*(a+r);
                 heapdelete(a,r,left,right);
             }
     }
     else
       {
           for(j=i;j<=heapsize-2;j++)
             *(a+j)=*(a+j+1);
            if((heapsize-1)%2==0)
              *(right+(heapsize-3)/2)=20;
             else
              *(left+(heapsize-2)/2)=20;
             heapsize-=1;    
             
       }

};
int main(void)
{
    int a[12]={15,13,9,5,12,8,7,4,0,6,2,1},i=0,heaps=heapsize;
    int left[12]={1,3,5,7,9,11,20,20,20,20,20,20};
    int right[12]={2,4,6,8,10,20,20,20,20,20,20,20};
    int parent[12]={20,0,0,1,1,2,2,3,3,4,4,5};
    heapdelete(a,4,left,right);
    heaps=heapsize;
    for(i=0;i<=heaps-1;i++)
       printf("%d ",a[i]);
       
    return 0;
}
