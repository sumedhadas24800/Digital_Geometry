void delete()
{
	slist *l1,*l2;
	l1=lx;
	while(l1!=NULL)
	{
		if(l1->visit==1)
		{
			if(l1==lx)	//first node
			{
				l2=lx;
				l1=l1->next;
				l1->prev=NULL;
				lx=l1;
				l2->next=NULL;
				free(l2);
				continue;
			}
			else
			{
				l2=l1;
				l1=l1->next;
				if(l1==NULL)	//last node
				{
					l2->prev=NULL;
					free(l2);
					break;
				}	
				else
				{
					l1->prev=l2->prev;
					(l2->prev)->next=l1;
					l2->next=NULL;
					l2->prev=NULL;
					free(l2);
					continue;			
				}
			}
		}
		l1=l1->next;
	}// end of while
	l1=ly;
	while(l1!=NULL)
	{
		if(l1->visit==1)
		{
			if(l1==ly)	//first node
			{
				l2=ly;
				l1=l1->next;
				l1->prev=NULL;
				ly=l1;
				l2->next=NULL;
				free(l2);
				continue;
			}
			else
			{
				l2=l1;
				l1=l1->next;
				if(l1==NULL)	//last node
				{
					l2->prev=NULL;
					free(l2);
					break;
				}	
				else
				{
					l1->prev=l2->prev;
					(l2->prev)->next=l1;
					l2->next=NULL;
					l2->prev=NULL;
					free(l2);
					continue;			
				}
			}
		}
		l1=l1->next;
	}// end of while
} //end of function
