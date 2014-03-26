/*clrs 2-4 problems*/
#include<stdio.h>
int count=0;
void countmerge(int *a,int p,int q,int r)
{
    int i=0,j=0,n1=q-p,n2=r-q-1,k=0,L[6],R[6];
    for(i=0;i<=n1;i++)
      L[i]=*(a+p+i);
     for(j=0;j<=n1;j++)
      R[j]=*(a+q+1+j);
      L[n1+1]=1000;
      R[n2+1]=1000;
      i=0;
      j=0;
      for(k=p;k<=r;k++)
         {
            if(L[i]>R[j])
              {
                 *(a+k)=R[j];
                   j++;
                   count+=n1-i+1;  
              }
           else if(L[i]<=R[j])
              {
                  *(a+k)=L[i];
                    i++;
              }
           
         }


};

void inversioncount(int *a,int p,int r)
{
    int q=0;
    if(p<r)
       { 
           q=(p+r)/2;
            inversioncount(a,p,q);
            inversioncount(a,q+1,r);
            countmerge(a,p,q,r);


       }


};

int main(void)
{
   int a[10]={9,8,7,6,5,4,3,2,1,0},i=0;
              inversioncount(a,0,9);
              for(i=0;i<=9;i++)
                  printf("%d ",a[i]);
            printf("%d ",count);
  return 0;
}
