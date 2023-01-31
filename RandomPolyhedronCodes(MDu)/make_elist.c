void make_elist(int o)
{
	edge *t,*t1,*pt,*estart=NULL;
	face *f,*f1,*p=NULL;
	slist *l1,*lt;
	int c=0,i,val;
	int xx,yy;

	l1=lx;
	c=0;
	while(l1!=NULL)
	{
		c++;
		if(c%2==1)
			l1->set=0;
		if(l1->f==1)
		{
			l1->set=2;
			c++;
		}
		l1=l1->next;
	}

	l1=ly;
	c=0;
	while(l1!=NULL)
	{
		c++;
		if(c%2==1)
			l1->set=0;
		if(l1->f==1)
		{
			l1->set=2;
			c++;
		}
		l1=l1->next;
	}

	printf("List Lx\n");
	l1=lx;
	while(l1!=NULL)
	{
		printf("%d\t %d\t %d\n",l1->a,l1->b,l1->set);
		l1=l1->next;
	}
	printf("List Ly\n");
	l1=ly;
	while(l1!=NULL)
	{
		printf("%d\t %d\t %d\n",l1->a,l1->b,l1->set);
		l1=l1->next;
	}

	l1=lx;
	xx=l1->a;
	yy=l1->b;
	l1->visit=1;
	l1->next->visit=1;
	t=malloc(sizeof(edge));
	f=malloc(sizeof(face));

	t->vtx1=l1->vtx;
	t->vtx2=l1->next->vtx;
	t->prev=NULL;
	t->twin=NULL;
	t->next=NULL;
	estart=t;

	no++;
	f->index=no;
	f->orn=o;
	f->prev=NULL;
	f->next=NULL;
	f->start=NULL;
	f->end=NULL;

	if(facef==NULL)
		facef=f;
	else
	{
		f1=facef;
		while(f1!=NULL)
		{
			p=f1;
			f1=f1->next;
		}
		p->next=f;
		f->prev=p;
	}

	lt=l1->next;
	c=0;
	while(lt->a!=xx || lt->b!=yy)
	{
		if(lt->set==2)
			c++;
		//printf("In Face: %d \t %d \t %d\n",lt->a, lt->b, lt->set);
		if(c%2==0)
		{
			l1=ly;
			while(l1!=NULL)
			{
				if(l1->a==lt->a && l1->b==lt->b)
					break;
				l1=l1->next;	
			}	
			t=malloc(sizeof(edge));	
			t->vtx1=l1->vtx;
			l1->visit=1;
			if((l1->set==0)|| (l1->set==2 && val==0))
			{
				t->vtx2=l1->next->vtx;
				lt=l1->next;
				l1->next->visit=1;
				val=0;
			}
			else
			{
				t->vtx2=l1->prev->vtx;
				lt=l1->prev;
				l1->prev->visit=1;
				val=1;
			}
			t->prev=NULL;
			t->twin=NULL;
			t->next=NULL;
			c++;
		}
		else
		{
			l1=lx;
			while(l1!=NULL)
			{
				if(l1->a==lt->a && l1->b==lt->b)
					break;
				l1=l1->next;	
			}	
			t=malloc(sizeof(edge));	
			t->vtx1=l1->vtx;
			l1->visit=1;
			if((l1->set==0)|| (l1->set==2 && val==0))
			{
				t->vtx2=l1->next->vtx;
				lt=l1->next;
				l1->next->visit=1;
				val=0;
			}
			else
			{
				t->vtx2=l1->prev->vtx;
				lt=l1->prev;
				l1->prev->visit=1;
				val=1;
			}
			t->prev=NULL;
			t->twin=NULL;
			t->next=NULL;
			c++;
		}

		t1=estart;
		while(t1!=NULL)
		{
			pt=t1;
			t1=t1->next;
		}
		pt->next=t;
		t->prev=pt;		
	}

	f->start=estart;
	f->end=t;
	estart->prev=t;
	t->next=estart;
	
	//if more vertices
	l1=lx;
	while(l1!=NULL)
	{
		if(l1->visit==0)
		{
			delete();
			make_elist(o);
		}
		l1=l1->next;
	}	
}//end of function
