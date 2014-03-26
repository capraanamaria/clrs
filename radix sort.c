/*radix sort */
#include<stdio.h>
int length=7,k=9,b[7];
void countingsort(int *a,int d)
{
  int c[k+1],i=0,j=0,t=0;
  
  for(i=0;i<=k;i++)
    c[i]=0;//all elements of array c are initialized to 0
  
  for(j=0;j<=length-1;j++)
    {
        switch(d)
        {
            case 0:
                  t=*(a+j)%10;
                  break;
            case 1:
                  t=*(a+j)/10;
                  t%=10;
                  break;
            default:
                  t=*(a+j)/100;
                  break;
        }
        c[t]+=1;//c[i] now contins no. of times t occurs in a
        
    }
    
    for(i=1;i<=k;i++)
      c[i]+=c[i-1];//c[i] contains no. of elements <=i
    
    for(j=length-1;j>=0;j--)
     {
          switch(d)
        {
            case 0:
                  t=*(a+j)%10;
                  break;
            case 1:
                  t=*(a+j)%100;
                  t/=10;
                  break;
            default:
                  t=*(a+j)/100;
                  break;
        }
        b[c[t]-1]=*(a+j);
       // printf("%d %d %d \n",*(a+j),t,c[t]-1);
        c[t]-=1;
        
     }
};
void radixsort(int *a,int d)
{
    int j=0,i=0;
    for(j=0;j<=d-1;j++)
      {
        //printf("%d\n",j);  
        countingsort(a,j);
        for(i=0;i<=length-1;i++)
         {
             *(a+i)=b[i];//copies partially sorted elements into array a
         }
      }
};
int main(void)
{
    int d=3,i=0,a[7]={122,100,155,978,234,456,765};
    radixsort(a,d);
    for(i=0;i<=length-1;i++)
      printf("%d ",a[i]);
    return 0;
}
