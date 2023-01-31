void rand6(int points[][4], int N)
{
	int x1,y1,z1,val,select,i,j=0,k,l,flag=0,count=0;
	int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
	int ncount=0;

	i=0;
	points[i][0]=0;
	points[i][1]=0;
	points[i][2]=0;
	points[i][3]=0;
	
//random numbers
	srand(time(0));

	//generate numbers
	while(i<N-1)
	{
		if(i!=0)
			j=rand()%i;
		val=rand()%2;
		if(val==0)
			val=-1;
		select=rand()%3;
		if(select==0)
		{
			x1=points[j][0]+val;
			y1=points[j][1];
			z1=points[j][2];
		}
		else if(select==1)
		{
			x1=points[j][0];
			y1=points[j][1]+val;
			z1=points[j][2];
		}	
		else	
		{
			x1=points[j][0];
			y1=points[j][1];
			z1=points[j][2]+val;
		}	
		for(k=0;k<=i;k++)
		{
			if(points[k][0]==x1 && points[k][1]==y1 && points[k][2]==z1)
				flag=1;
		}	
		if(flag==1)
		{
			flag=0;
			continue;
		}
		//-----------------------------------------------------------
		for(k=0;k<=i;k++)
		{
			//to check vertex connectivity 111
			if(points[k][0]==x1+1 && points[k][1]==y1+1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1+1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity -111
			if(points[k][0]==x1-1 && points[k][1]==y1+1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1+1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity 11-1
			if(points[k][0]==x1+1 && points[k][1]==y1+1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1-1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity -11-1
			if(points[k][0]==x1-1 && points[k][1]==y1+1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1-1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------
			//to check vertex connectivity 1-11
			if(points[k][0]==x1+1 && points[k][1]==y1-1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1+1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity -1-11
			if(points[k][0]==x1-1 && points[k][1]==y1-1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1+1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1+1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity 1-1-1
			if(points[k][0]==x1+1 && points[k][1]==y1-1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1+1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1-1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------
			//to check vertex connectivity -1-1-1
			if(points[k][0]==x1-1 && points[k][1]==y1-1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1)
					{
						c1++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1-1)
					{
						c1++;
						c4++;
						c6++;
					}
					if(points[l][0]==x1-1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c4++;
						c5++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1-1)
					{
						c2++;
						c3++;
						c6++;
					}
					if(points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1)
					{
						c2++;
						c3++;
						c5++;
					}
				}
				if(c1!=3 && c2!=3 && c3!=3 && c4!=3 && c5!=3 && c6!=3)
					flag=1;
				c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
			}
			//-----------------------------------------------------------------
			// to check 18 connectivity
			if(points[k][0]==x1+1 && points[k][1]==y1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1-1 && points[k][1]==y1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1+1 && points[k][1]==y1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1-1 && points[k][1]==y1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1+1 && points[k][1]==y1+1 && points[k][2]==z1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1-1 && points[k][1]==y1+1 && points[k][2]==z1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1 && points[k][1]==y1+1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1 && points[k][1]==y1+1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1 && points[l][1]==y1+1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1+1 && points[k][1]==y1-1 && points[k][2]==z1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1+1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1-1 && points[k][1]==y1-1 && points[k][2]==z1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1-1 && points[l][1]==y1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1 && points[k][1]==y1-1 && points[k][2]==z1+1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1+1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
			if(points[k][0]==x1 && points[k][1]==y1-1 && points[k][2]==z1-1)
			{
				for(l=0;l<=i;l++)
				{
					if((points[l][0]==x1 && points[l][1]==y1-1 && points[l][2]==z1) || (points[l][0]==x1 && points[l][1]==y1 && points[l][2]==z1-1))
						ncount++;

				}
				if(ncount==0)
					flag=1;
				else
					ncount=0;
			}
		}// end of for loop

		if(flag==1)
		{
			flag=0;
			continue;
		}
		else
		{
			i++;
			points[i][0]=x1;	
			points[i][1]=y1;
			points[i][2]=z1;
			points[i][3]=0;
			//printf("%d\t %d\t %d\n", points[i][0],points[i][1],points[i][2]);
		}
	}// end of while

	//check for interior voxel
	for(k=0;k<N;k++)
	{
		j=0;
		while(j<N)	
		{
			if((points[k][0]+1==points[j][0] && points[k][1]==points[j][1] && points[k][2]==points[j][2]))
				count++;
			if((points[k][0]-1==points[j][0] && points[k][1]==points[j][1] && points[k][2]==points[j][2]))
				count++;
			if((points[k][0]==points[j][0] && points[k][1]+1==points[j][1] && points[k][2]==points[j][2]))
				count++;
			if((points[k][0]==points[j][0] && points[k][1]-1==points[j][1] && points[k][2]==points[j][2]))
				count++;
			if((points[k][0]==points[j][0] && points[k][1]==points[j][1] && points[k][2]+1==points[j][2]))
				count++;
			if((points[k][0]==points[j][0] && points[k][1]==points[j][1] && points[k][2]-1==points[j][2]))
				count++;
			j++;	
		}
		if(count==6)
		{
			points[k][3]=1;
		}
		count=0;
	}

}//end of function
