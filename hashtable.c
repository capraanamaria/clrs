#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
const int m=10;
struct node
{
	int key;
	char data;
	struct node *next,*last;
};
struct node *getnode()
{
	return (struct node *)malloc(sizeof(struct node));
}
int h(int key)
{
	return key%m;
};
void insert(struct node **table)
{
	int k=0;
	char item[2];
	struct node *temp=NULL,*link=NULL;
	printf("\nEnter key and data ");
	scanf("%d %s",&k,item);
	temp=getnode();
	temp->key=k;
        temp->data=item[0];
       	temp->last=NULL;
	link=*(table+h(temp->key));
	if(link==NULL)
		temp->next=NULL;
	else
	{
		temp->next=link;
		link->last=temp;
	}
	*(table+h(temp->key))=temp;
	printf("\nInsert successful...\n");

};

struct node *search(struct node **table)
{
	int k=0,found=0;
        struct node *temp=NULL;
        
	printf("\nEnter key ");
	scanf("%d",&k);
	temp=*(table+h(k));
	while(temp!=NULL)
	{
		if(temp->key!=k)
	       	{
		 	temp=temp->next;
			found=0;
		}
		else if(temp->key==k)
		{
			found=1;
			break;
		}
	}
	if(found==1)
	{	
		printf("\nFound:key=%d,data=%c\n",temp->key,temp->data);
		return temp;
	}
	else
		printf("\nCould not Find:key=%d\n",k);
	return NULL; 	

};

struct node *delete(struct node **table)
{
	int k=0;
        struct node *link=NULL,*temp=NULL;
    
	if((temp=search(table))!=NULL)
	{
		if((temp->last!=NULL)&&(temp->next!=NULL))
		{
			link=temp->last;
			link->next=temp->next;
			link=temp->next;
			link->last=temp->last;
		}
		else if((temp->last==NULL)&&(temp->next!=NULL))
		{
			*(table+h(temp->key))=temp->next;
			link=temp->next;
			link->last=NULL;
		}
		else if((temp->last==NULL)&&(temp->next==NULL))
		{
			 *(table+h(temp->key))=NULL;
		}	
		else if((temp->last!=NULL)&&(temp->next==NULL))
		{
			link=temp->last;
			link->next=NULL;
		}
		printf("\nDeleted:key=%d,data=%c\n",temp->key,temp->data);	
	}


};
int main(void)
{
	int i=0,n=0,k=0,option;
	char item[2];
	struct node *table[m],*temp=NULL,*link=NULL;
	//bzero(table,m);
        for(i=0;i<m;i++)
	{
		table[i]=NULL;
	}
	printf("\nEnter no. of keys ");
	scanf("%d",&n);
	//printf("\nEnter key and data\n");
	for(i=0;i<n;i++)
	{
		//fflush(stdin);
	        printf("\nEnter key and data ");
		scanf("%d%s",&k,item);
		temp=getnode();
		temp->key=k;
		temp->data=item[0];
		temp->last=NULL;
		link=table[h(temp->key)];
		if(link==NULL)
		 	temp->next=NULL;
		else
		{
			temp->next=link;
			link->last=temp;
		}

		table[h(temp->key)]=temp;
		
	}
	
	while(1)
	{
		printf("\nEnter any of the following options:\n1.Insert\n2.Search\n3.Delete\n4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insert(table);
				break;	      
			case 2:
				search(table);
				break;
			case 3:
				delete(table);
				break;
		        case 4:
				exit(4);
		
		}
	
	}


	return 0;
}
