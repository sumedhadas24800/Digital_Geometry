int search_vertex(int x, int y, int z)
{
	int res=0;
	vrtx *temp;
	
	if(vtf==NULL)
		return res;
	else
	{
		temp=vtf;
		while(temp!=NULL)
		{
			if(temp->x==x && temp->y==y && temp->z==z)
			{
				res= 1;
				break;
			}
			else
				temp=temp->next;
		}
	}	
	return res;
}