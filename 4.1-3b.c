/*4.1-3 b max sub array divide and conquer*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int low,sum,high;
};
struct node *getnode()
{
   return (struct node *)malloc(sizeof(struct node));
};

struct node *crossmaxsum(int *a,int low,int mid,int high)
{
   int i,j,sum=0;
   struct node *left=getnode(),*right=getnode(),*cross=getnode();
   left->sum=-10000;
   right->sum=-10000;
    
   for (i=mid;i>=0;i--)
        {
             sum+=*(a+i);
             if(sum>left->sum)
                  {
                       left->sum=sum;
                       left->low=i;
                  }

         } 
    sum=0;

    for (j=mid+1;j<=high;j++)
        {
             sum+=*(a+j);
             if(sum>right->sum)
                  {
                       right->sum=sum;
                       right->high=j;
                  }

         } 
     cross->low=left->low;
     cross->sum=left->sum+right->sum;
     cross->high=right->high;
     return cross;


};
struct node *maxsubarray(int *a,int low,int high)
{
    int mid=0;
    struct node *left=getnode(),*right=getnode(),*cross=getnode();
    left->low=low;
    left->sum=*(a+low);
    left->high=high;
   
     if(low==high)
         return left;
     else if(high>low)
         {
            mid=(high+low)/2;
            left=maxsubarray(a,low,mid);
            right=maxsubarray(a,mid+1,high);
            cross=crossmaxsum(a,low,mid,high);
            
            if((left->sum>=right->sum)&&(left->sum>=cross->sum))
               return left;  

            else if((left->sum<right->sum)&&(right->sum>=cross->sum))
               return right; 
          
            else
                 return cross;
         }
 return NULL;
};

int main(void)
{
   int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
   struct node *max;
   max=maxsubarray(a,0,15);
    printf("%d %d %d",max->low,max->sum,max->high); 

return 0;
}
