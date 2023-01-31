void make_edge()
{
	vrtx *temp;
	slist *temp1;
				
	int i, xmin, ymin, zmin, xmax, ymax, zmax;
	int min;
	
	temp=vtf;
	xmin=temp->x;	
	xmax=temp->x;
	ymin=temp->y;	
	ymax=temp->y;	
	zmin=temp->z;	
	zmax=temp->z;

	printf("\n");
	while(temp!=NULL)
	{
		if(temp->x < xmin)
			xmin=temp->x;
		if(temp->y < ymin)
			ymin=temp->y;
		if(temp->z < zmin)
			zmin=temp->z;
		if(temp->x > xmax)
			xmax=temp->x;
		if(temp->y > ymax)
			ymax=temp->y;
		if(temp->z > zmax)
			zmax=temp->z;
		printf("%d\t %d\t %d\n",temp->x,temp->y, temp->z);
		temp=temp->next;
	}
	printf("%d %d %d %d %d %d\n", xmin,xmax,ymin,ymax,zmin,zmax);

	i=zmin;
	while(i<=zmax)
	{
		min=zmax;
		temp=vtf;
		while(temp!=NULL)
		{
			if(temp->z==i)
			{
				insert_lx(temp->x,temp->y,temp,temp->fz);
				insert_ly(temp->x,temp->y,temp,temp->fz);
			}
			else if(temp->z>i && temp->z<=min)
				min=temp->z;
			else if(i==zmax)
				min=zmax+1;
			temp=temp->next;
		}
		i=min;

		printf("List Lx ->xy plane\n");
		temp1=lx;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		printf("List Ly ->xy plane\n");
		temp1=ly;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		//create face
		make_elist(0);
		free(ly);
		ly=NULL;
		free(lx);
		lx=NULL;
	}// end of while

	i=ymin;
	while(i<=ymax)
	{
		min=ymax;
		temp=vtf;
		while(temp!=NULL)
		{
			if(temp->y==i)
			{
				insert_lx(temp->z,temp->x,temp,temp->fy);
				insert_ly(temp->z,temp->x,temp,temp->fy);
			}
			else if(temp->y>i && temp->y<=min)
				min=temp->y;
			else if(i==ymax)
				min=ymax+1;
			temp=temp->next;
		}
		i=min;

		printf("List Lx ->zx plane\n");
		temp1=lx;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		printf("List Ly ->zx plane\n");
		temp1=ly;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		//create face
		make_elist(1);
		free(ly);
		ly=NULL;
		free(lx);
		lx=NULL;
	}// end of while

	i=xmin;
	while(i<=xmax)
	{
		min=xmax;
		temp=vtf;
		while(temp!=NULL)
		{
			if(temp->x==i)
			{
				insert_lx(temp->y,temp->z,temp,temp->fx);
				insert_ly(temp->y,temp->z,temp,temp->fx);
			}
			else if(temp->x>i && temp->x<=min)
				min=temp->x;
			else if(i==xmax)
				min=xmax+1;
			temp=temp->next;
		}
		i=min;

		printf("List Lx ->yz plane\n");
		temp1=lx;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		printf("List Ly ->yz plane\n");
		temp1=ly;
		while(temp1!=NULL)
		{
			printf("%d\t %d\t %d\n",temp1->a,temp1->b,temp1->set);
			temp1=temp1->next;
		}
		//create face
		make_elist(2);
		free(ly);
		ly=NULL;
		free(lx);
		lx=NULL;
	}// end of while

}//end of function
