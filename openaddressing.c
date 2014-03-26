/*open addressing using double hashing*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NIL -1
#define DELETED -2
int m=11;
int h(int key,int i)
{
	return (key%m+i*(1+key%(m-1))%m);
};
int hash_insert(int *T,int key)
{
	int i=0,j=0;
	while(i<m)
	{
		j=h(key,i);
		if((*(T+j)==NIL)||(*(T+j)==DELETED))
		{
			*(T+j)=key;
			printf("\nKEY inserted\n");
			return key;
		}
		else if(*(T+j)==key)
		{
			printf("\nKEY already present\n");
			return NIL;
		}
		else
			i+=1;
	}
	printf("\nHash Table overflow\n");
	return NIL;
};

int hash_search(int *T,int key)
{
	int i=0,j=0;
	do
	{
		j=h(key,i);
		if(*(T+j)==key)
		{
			printf("\nSearch successful...\nKEY found at %d\n",j);
			return j;
		}
		else 
			i+=1;

	}while((i<m)&&(*(T+j)!=NIL));
	printf("\nSearch unsuccessful\n");
	return NIL;
};

int hash_delete(int *T,int key)
{
	int j=hash_search(T,key);
	if(j!=NIL)
	{
		*(T+j)=DELETED;
		printf("\nKEY deleted\n");
		return j;
	}
	return NIL;

};
int main(void)
{
	int i=0,T[m],key=0;
	memset(T,NIL,sizeof(T));
	while(1)
	{
		printf("\nEnter the following:\n1.Insert\n2.Search\n3.Delete\n4.Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("\nEnter key ");
				scanf("%d",&key);
				hash_insert(T,key);
				break;
			case 2:
				 printf("\nEnter key ");
				 scanf("%d",&key);				                                                           hash_search(T,key);
				 break;
			case 3:
				 printf("\nEnter key ");
	                         scanf("%d",&key);							                                   hash_delete(T,key);
				 break;
			case 4:
				exit(0);

		
		}
	
	
	}

	return 0;

}
