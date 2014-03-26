/*2.1-4*/
#include<stdio.h>
int main(void)
{
        
      int i=0,a[5]={1,0,0,1,1},b[5]={1,1,0,0,1},c[6],carry=0;
        
       
      for(i=0;i<5;i++)
       {
         c[i]=((a[i] ^ b[i]) ^ carry)?1:0;
         carry=((a[i] & b[i]) | (b[i] & carry) | (carry & a[i]))?1:0; 
         printf("%d",c[i]);
       }
 
       c[i]=carry;
       printf("%d",c[i]);
     return 0;
}
