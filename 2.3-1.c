/*merge sort clrs 2.3-1*/
#include <stdio.h>

//p=0,q=4,r=9,n1=4,n2=4


void merge(int *a,int p,int q,int r)
{
     int n1=q-p,n2=r-q-1,i=0,j=0,k=0;
     int L[6],R[6];
     
     for(i=0;i<=n1;i++)
          L[i]=*(a+p+i);

     for(j=0;j<=n2;j++)
          R[j]=*(a+j+q+1);

     i=0;j=0;
      L[n1+1]=1000;R[n2+1]=1000;   
     for(k=p;k<=r;k++)
      {
         if(L[i]<=R[j])
          {
             *(a+k)=L[i];
               i++;
          }
        else
          {
              *(a+k)=R[j];
                j++;
          
          }
      
     }

};



void mergesort(int *a,int p,int r)
{
    int q=(p+r)/2;
    if(p<r)
      {
          mergesort(a,p,q);
          mergesort(a,q+1,r);
           merge(a,p,q,r);
      }
};


int main(void)
{
   int a[10]={3,41,52,26,38,57,9,49},i=0;
  
   mergesort(a,0,7);

   for(i=0;i<=7;i++)
        printf("%d ",a[i]);

      
   return 0;
}
