/*clrs 6.5-6*/
void heapincreasekey(int *a,int i,int key,int *parent)
{
   int temp=0;
   if(key<*(a+i))
     printf("key is smaller\n");
  *(a+i)=key;
   for(i=heapsize-1;((i>0)&&(*(a+*(parent+i))<key));)
    {
         //temp=*(a+i);
         *(a+i)=*(a+*(parent+i));
         //*(a+*(parent+i))=temp;
         i=*(parent+i);
    }
    *(a+i)=key;
};
