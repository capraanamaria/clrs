/*clrs 8.3-1*/
#include<stdio.h>
#include<string.h>
int k=25,length=16,d=3;
void countingsort(char *a,char *b,int l)
{
  int c[k+1],i=0,j=0,t=0;
  for(i=0;i<=k;i++)
  {
      c[i]=0;
  }
  for(j=0;j<=length-1;j++)
  {
      t=*(a+(d+1)*j+l)-65;
      c[t]+=1;     
  }
  for(i=1;i<=k;i++)
  {
      c[i]+=c[i-1];
  }
  for(j=length-1;j>=0;j--)
  {
       t=*(a+(d+1)*j+l)-65;
       strcpy(b+(d+1)*c[t],a+(d+1)*j);
       c[t]-=1;
  }
  
};
void radixsort(char *a,char *b,int d)
{
  int i=0,j=0;
  for(i=d-1;i>=0;i--)
    {
        countingsort(&a[0],&b[0],i);
        for(j=0;j<length;j++)
          strcpy(a+(d+1)*j,b+(d+1)*j);
        
          
    }
};
int main(void)
{
    char a[16][4]={
                     "COW",
                     "DOG",
                     "SEA",
                     "RUG",
                     "ROW",
                     "MOB",
                     "BOX",
                     "TAB",
                     "BAR",
                     "EAR",
                     "TAR",
                     "DIG",
                     "BIG",
                     "TEA",
                     "NOW",
                     "FOX" 
                  },b[length][4];
    int i=0;
    radixsort(&a[0],&b[0],d);
    for(i=0;i<=length-1;i++)
      printf("%s ",&a[i]);
    return 0;
}
