/*clrs divide and conquer matrix multiplication */
#include<stdio.h>
void add(int *a,int b,int *c,int n)
{
    int i=0,j=0;
     for(i=0;i<=n-1;i++)
          {
                 for(j=0;j<=n-1;j++)
                     {
                              if(b==1)
                                 *(c+i*n+j)=0;
                            *(c+i*n+j)+=*(a+i*n+j);
                             printf("%d add\n",*(c+i*n+j));
                      }
         }
     
};
int *smm(int *a,int *b,int n)
{
   int m=n/2,c[n*n];
   if(n==1)
    {
        *c=(*a)*(*b);
         printf("%d %d %d\n",*c,*a,*b);
    
    }
   else
     {
         add(smm(a,b,m),1,c,m);
         add(smm(a+m,b+m*n,m),2,c,m);
         add(smm(a,b+m,m),1,c+m,m);
         add(smm(a+m,b+m*n+m,m),2,c+m,m);
         add(smm(a+m*n,b,m),1,c+m*n,m);
         add(smm(a+m*n+m,b+m*n,m),2,c+m*n,m);
         add(smm(a+m*n,b+m,m),1,c+m*n+m,m);
         add(smm(a+m*n+m,b+m*n+m,m),2,c+m*n+m,m);
     }
   return c;

};
int main(void)
{
   int a[4]={1,3,7,5},b[4]={6,8,4,2},*c,i=0,j=0;
   c=smm(a,b,2); 
   for(i=0;i<=1;i++)
       {
            for(j=0;j<=1;j++)
                {
                      printf("%d ",*(c+2*i+j));
                 }
      }
   


return 0;

}
