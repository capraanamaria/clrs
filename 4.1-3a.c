/*4.1-3 a brute force max. subarray*/
#include<stdio.h>
int main(void)
{
   int i,j,maxlow=0,maxhigh=0,maxsum=0,sum=0,n=16;

     int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
     for(i=0;i<=n-1;i++)
        {
              for(j=i;j<=n-1;j++)
                    {
                         sum+=a[j];
                         if(sum>maxsum)
                                {
                                     maxsum=sum;
                                     maxlow=i;
                                      maxhigh=j;

                               }
                     }
             sum=0;

         }
  printf("%d %d %d",maxlow,maxsum,maxhigh); 
  return 0;
}


