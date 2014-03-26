/*clrs 6.5-1*/
#include<stdio.h>
int heapsize=12;
void maxheapify(int *a,int i,int *left,int *right)
{
  int l=0,r=0,largest=0,temp=0;
  l=*(left+i);
  r=*(right+i);
  if((*(a+l)>*(a+i))&&(l<heapsize-1))
    largest=l;
  else
    largest=i;
  if((*(a+r)>*(a+largest))&&(r<heapsize-1)) 
    largest=r;
  if(largest!=i)
    {
        temp=*(a+i);
        *(a+i)=*(a+largest);
        *(a+largest)=temp;
        maxheapify(a,largest,left,right);
    }
};
int heapextractmax(int *a,int *left,int *right)
{
  int max=0;
  if(heapsize<1)
    printf("underflow\n");
  max=*a;
  *a=*(a+heapsize-1);
  heapsize-=1;
  maxheapify(a,0,left,right);
  return max;

};
int main(void)
{
    int a[12]={15,13,9,5,12,8,7,4,0,6,2,1},i=0,max=0,heaps=heapsize;
    int left[12]={1,3,5,7,20,20,20,20,20,20,20,20};
    int right[12]={2,4,6,8,20,20,20,20,20,20,20,20};
    max=heapextractmax(a,left,right);
    for(i=0;i<=heaps-1;i++)
       printf("%d ",a[i]);
       printf("max=%d ",max);
    return 0;
}
