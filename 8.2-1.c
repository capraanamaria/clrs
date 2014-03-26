/*clrs 8.2-1*/
#include<stdio.h>
int length=11;
void countingsort(int *a,int *b,int k)
{
    int c[k+1],i=0,j=0;
    for(i=0;i<=k;i++)
     c[i]=0;
    for(j=0;j<length;j++)
     {
       c[*(a+j)]+=1;
       
     } 
     //c[i] contains no. of times i occurs in a
     for(i=1;i<=k;i++)
     {
         c[i]+=c[i-1];
         
     }
      
      //c[i] contains no. of elements that are less than or equal to i
      for(j=length-1;j>=0;j--)
       {
           *(b+c[*(a+j)]-1)=*(a+j);
           c[*(a+j)]-=1;
       }
       
};
int main(void)
{
    int a[11]={6,0,2,0,1,3,4,6,1,3,2},b[11],i=0;
    countingsort(a,b,6);
    for(i=0;i<=length-1;i++)
     printf("\n%d ",b[i]);
    return 0;
}
