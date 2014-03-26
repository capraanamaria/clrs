/*clrs 6.2-1*/
#include<stdio.h>

int heapsize=14;
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
int main(void)
{
    int a[14]={27,17,3,16,13,10,1,5,7,12,4,8,9,0},i=0;
    int left[14]={1,3,5,7,9,11,13,20,20,20,20,20,20,20};
    int right[14]={2,4,6,8,10,12,20,20,20,20,20,20,20,20};
    maxheapify(a,2,left,right);
    for(i=0;i<=heapsize-1;i++)
      printf("%d ",a[i]);
    return 0;
}
