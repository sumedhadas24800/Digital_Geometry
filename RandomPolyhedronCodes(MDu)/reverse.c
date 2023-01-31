void reverse(edge **fst, edge **lst)
{
	edge *temp,*t,*t1;
	int c=0,i=0,j;

	temp=*fst;
	while(temp!=*lst)
	{
		c++;
		temp=temp->next;
	}
	//printf("Total No %d\n",c);
	while(i<c)
	{
		temp=*fst;
		j=0;
		t=*lst;		
		while(j<i)
		{
			j++;
			//printf("j= %d\n",j);
			t=t->prev;
		}
		//temp will be placed after t
		if(i==0)
		{
			*fst=temp->next;
			*lst=temp;
		}
		else
		{
			*fst=temp->next;
			temp->next=NULL;
			temp->prev=NULL;
			(*lst)->next=*fst;
			(*fst)->prev=*lst;
			t1=t->next;
			t->next=temp;
			temp->prev=t;
			temp->next=t1;
			t1->prev=temp;
		}
		//printf("i= %d\n",i);
		i++;
		//vtx2 to change
		temp=*fst;
		t=*lst;	
		while(temp!=t)
		{
			t=*fst;
			t1=temp->next;
			temp->vtx2=t1->vtx1;
			temp=temp->next;
		}
	}
}//end of function
