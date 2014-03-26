/*bucket sort*/
#include<stdio.h>
#include<stdlib.h>
int length=10;
struct bucket
{
    float node;
    struct bucket *next,*prev;
};

struct bucket *getnode()
{
    return (struct bucket *)malloc(sizeof(struct bucket));
}

void insertionsort(struct bucket *b)
{
    float key=0;
    struct bucket *temp=b,*current=NULL,*old=NULL;
    while(temp!=NULL)
      {
          if(temp->prev!=NULL)
             {
                 key=temp->node;
                 current=temp->prev;
                 old=temp;
                 while(current!=NULL)
                    {
                        if(current->node>key)
                          {
                              old->node=current->node;
                              current->node=key;
                              
                          }
                        
                        old=current;
                        current=current->prev;
                    }
                 
             }
          
          temp=temp->next;
        
      }
     
};

void bucketsort(float *a)
{
   struct bucket *b[length],*last[length],*temp=NULL;
   int t=0,i=0,n=length;
   
   for(i=0;i<=n-1;i++)//initializes every element of b to null
     {
         b[i]=NULL; 
         last[i]=NULL;
     }
   
   for(i=0;i<=n-1;i++)// puts every element of a in buckets
     {
         
         t=*(a+i)*n;
         temp=getnode();
         temp->node=*(a+i);
         temp->next=NULL;
         temp->prev=NULL;
         if(b[t]==NULL)
          {
              temp->prev=NULL;
              b[t]=temp;
          }
         else
         {
             temp->prev=last[t];   
             last[t]->next=temp;
         }
        
        last[t]=temp; 
         
     }
     
   for(i=0;i<=n-1;i++) //sorts every bucket
     {
         if(b[i]!=NULL)
           insertionsort(b[i]);
     }
   
      t=0;
   
   for(i=0;i<=n-1;i++)//concatenates every bucket into a
     {
         if(b[i]!=NULL)
         {
             temp=b[i];
          while(temp!=NULL)
            {
                *(a+t)=temp->node;
                temp=temp->next;
                t++;
            
            
            }
          
         }
          
        
     }

};

int main(void)
{
    float a[10]={.78,.17,.39,.26,.72,.94,.21,.12,.23,.68};
    int i=0;
    bucketsort(a);
    for(i=0;i<=length-1;i++)
      printf("%.2f ",a[i]);
    return 0;
}
