/*clrs 6.3-1*/
#include<stdio.h>
int heapsize=9;
void maxheapify(int *a,int i,int *left,int *right)
{
  int l=0,r=0,largest=0,temp=0;
  l=*(left+i);
  r=*(right+i);
  if((l<=heapsize-1)&&(*(a+l)>*(a+i)))
      largest=l;
  else
      largest=i;
  if((r<=heapsize-1)&&(*(a+r)>*(a+largest)))
      largest=r;
  if(largest!=i)
      {
          temp=*(a+i);
          *(a+i)=*(a+largest);
          *(a+largest)=temp;
          maxheapify(a,largest,left,right);
      }
};
void buildmaxheap(int *a,int *left,int *right) 
{
  int i=heapsize/2-1;
    for(;i>=0;i--)
       maxheapify(a,i,left,right);


};
int main(void)
{
    int a[9]={5,3,17,10,84,19,6,22,9},i=0;
    int left[9]={1,3,5,7,20,20,20,20,20};
    int right[9]={2,4,6,8,20,20,20,20,20};
    buildmaxheap(a,left,right);
    for(i=0;i<=heapsize-1;i++)
      printf("%d ",a[i]);
    return 0;
}
