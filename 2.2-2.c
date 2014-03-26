/*2.2-2*/
#include<stdio.h>
int main(void)
{
   int i=0,j=0,key=0,least=0;
   int a[10]={3,4,6,7,5,1,2,0,9,8};

  for(i=0;i<=8;i++)
   {
       key=a[i];
       for(j=i;j<=9;j++)
           {
               if(key>a[j])
                 {
                     key=a[j];
                     least=j;
                  }
           }  
      a[least]=a[i];
      a[i]=key;
       printf("%d ",a[i]); 
   }
   printf("%d ",a[i]); 
  return 0;
}
