void insert_ly(int a,int b, vrtx *v, int f)
{
	slist *lt,*temp1,*pre;

	lt=malloc(sizeof(slist));
	lt->a=a;
	lt->b=b;
	lt->f=f;
	lt->vtx=v;
	lt->next=NULL;
	lt->prev=NULL;
	lt->set=1;
	lt->visit=0;
	if(ly==NULL)
		ly=lt;
	else
	{
		temp1=ly;
		if(lt->b<temp1->b)
		{
			lt->next=temp1;
			ly=lt;
		}
		else
		{
			while(temp1!=NULL && temp1->b<lt->b)
			{
				pre=temp1;		
				temp1=temp1->next;
			}
			while(temp1!=NULL && temp1->b==lt->b && temp1->a<lt->a)
			{
				pre=temp1;
				temp1=temp1->next;
			}
			if(ly==temp1)
			{
				lt->next=temp1;
				temp1->prev=lt;
				ly=lt;
			}
			else if(temp1==NULL)
			{			
				pre->next=lt;
				lt->prev=pre;
			}
			else 
			{
				pre->next=lt;
				lt->next=temp1;
				temp1->prev=lt;
				lt->prev=pre;
			}
		}
	}
}// end of function
