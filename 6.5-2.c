/*clrs 6.5-2*/
#include<stdio.h>
int heapsize=12;
void heapincreasekey(int *a,int i,int key,int *parent)
{
   int temp=0;
   if(key<*(a+i))
     printf("key is smaller\n");
  *(a+i)=key;
   for(i=heapsize-1;((i>0)&&(*(a+*(parent+i))<*(a+i)));)
    {
         temp=*(a+i);
         *(a+i)=*(a+*(parent+i));
         *(a+*(parent+i))=temp;
         i=*(parent+i);
    }

};
int maxheapinsert(int *a,int key,int *left,int *right,int *parent)
{
  
  heapsize+=1;
  *(a+heapsize-1)=-1000;
  *(left+heapsize-1)=20;
  *(right+heapsize-1)=20;
  if((heapsize-1)%2==0)
  right[(heapsize-3)/2]=heapsize-1;
  else
  left[(heapsize-2)/2]=heapsize-1;
  heapincreasekey(a,heapsize-1,key,parent);
};
int main(void)
{
    int a[13]={15,13,9,5,12,8,7,4,0,6,2,1},i=0,heaps=heapsize;
    int left[13]={1,3,5,7,20,20,20,20,20,20,20,20};
    int right[13]={2,4,6,8,20,20,20,20,20,20,20,20};
    int parent[13]={20,0,0,1,1,2,2,3,3,4,4,5};
    maxheapinsert(a,45,left,right,parent);
    heaps=heapsize;
    for(i=0;i<=heaps-1;i++)
       printf("%d ",a[i]);
       
    return 0;
}


