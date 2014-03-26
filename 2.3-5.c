/*binary search clrs 2.3-5*/
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

int main(void)
{
   int v=0,a[10]={10,11,12,13,14,15,16,17,18,19};
   scanf("%d",&v);
   
   v=bs(a,0,v,9);
   if(v!=-1)
    printf("\n%d",v); 
   else
     printf("Not found");
   

  return 0;
}
