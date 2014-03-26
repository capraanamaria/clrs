/*Stack*/
#include<stdio.h>
#include<stdlib.h>
int max=5;
struct node
{
    char term;
    struct node *next,*prev;
};
struct node *getnode()
{
  return (struct node *)malloc(sizeof(struct node));
};
int main(void)
{
    int num=0;
    struct node *temp=NULL,*root=NULL,*old=NULL;
    char opt[2];
    while(1)
    {
        fflush(stdin);
        scanf("%s",opt);
        switch(opt[0])
          {
              case 'i':
                      fflush(stdin);
                      scanf("%s",opt);
                      temp=getnode();
                      temp->term=opt[0];
                      temp->next=NULL;
                      
                      if(num==0)
                        {
                            root=temp;
                            temp->prev=NULL;
                            
                        }
                      else if(num<max)
                        {
                            temp->prev=old;
                            old->next=temp;
                        }
                      else if(num==max)
                      {
                          printf("overflow\n");
                          break;
                      }
                        
                        
                      num+=1;
                      old=temp;    
                      break;
               
               case 'o':
                        if(num==0)
                         {
                             printf("underflow\n");
                             break;
                         }
                        else 
                         {
                             printf("%c\n",old->term);
                             old=old->prev;
                             num-=1;
                         }
                       break;
                       
              case 'n':
                    exit(0);
          }
    }
    
    
    
    
    
    return 0;
}
