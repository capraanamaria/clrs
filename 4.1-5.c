/*4.1-5 max subarray linear time */
#include<stdio.h>
int main(void)
{
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int maxsum=a[0],jsum=a[0],low=0,high=0,i=0,maxlow=0,maxhigh=0,n=16;
      
    for(i=1;i<=n-1;i++)
        {
            if(jsum<=0)
              {
                  jsum=a[i];
                  low=i;
                  high=i; 

              }
           else if(jsum>0)
             {
                jsum+=a[i];
                high=i;
            } 
          if(jsum>maxsum)
           {
              maxsum=jsum;
              maxlow=low;
              maxhigh=high;

          }
  


       }

    printf("%d %d %d",maxlow,maxsum,maxhigh);
    return 0;
}
