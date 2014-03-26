/*2.1-1 pg 22*/

#include<stdio.h>

int main(void)
 {
    int a[6]={31,41,59, 26, 41,58};
    int i=0,j=0,key=0;
    
      for(i=1;i<=5;i++)
           {
                j=i-1;
                key=a[i];
                while(key<a[j]&&j>=0)
                       {
                            a[j+1]=a[j];
                            j-=1;
                        }
               a[j+1]=key;

           }
        for(i=0;i<=5;i++)
          printf("%d ",a[i]);

   return 0;
 }
