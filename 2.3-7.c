/*sum clrs 2.3-7*/
#include<stdio.h>
int bs(int *a,int p,int v,int r)
{
    int q=(p+r)/2;
    
    if(p<r)
      {
          if(*(a+q)<v)
             bs(a,q+1,v,r);
             
          else if(*(a+q)>v)
              bs(a,p,v,q);
           
           else if(*(a+q)==v)
               return q;  
      }


    else if(p==r)
            {
                  if(*(a+p)==v)
                      return p;
                  else
                       return -1;
            }
};
void sum(int *a,int n,int x)
{
   int i=0,key=0,j=-1;
  for(i=0;(i<=n-1)&&(j==-1);i++)
   {
      key=x-*(a+i);
      j=bs(a,i+1,key,n-1);
      
    }
  if(i<=n-1)
  printf("\n%d %d",i-1,j);
 else
  printf("not found");

};
int main (void)
{
   int a[10]={0,1,2,3,4,5,6,7,8,9},x=0;
   
    scanf("%d",&x);
    sum(a,10,x);
  return 0;
}
