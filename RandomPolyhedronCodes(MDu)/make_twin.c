void make_twin()
{
	face *ft,*fs;
	edge *st,*ss,*t1,*t2;
	int vt1,vt2,vt3,vt4,vt5,vt6,flag=0;
	int arr[f_no+1],i;

	for(i=0;i<=f_no;i++)
		arr[i]=0;
	arr[0]=1;

	for(i=0;i<=f_no;i++)
	{
		if(arr[i]==1)
		{
			// to find the face
			ft=facef;
			while(ft!=NULL)
			{
				if(ft->index==i)
					break;
				ft=ft->next;
			}
			if(ft->orn==0)
			{
				arr[ft->index]=2;
				st=ft->start;
				t1=ft->end;
				while(st!=t1)
				{
					t1=ft->start;
					vt1=st->vtx1->x;
					vt2=st->vtx1->y;
					vt3=st->vtx1->z;
					vt4=st->vtx2->x;
					vt5=st->vtx2->y;
					vt6=st->vtx2->z;
					if(st->vtx1->x==st->vtx2->x)	// vertical edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==2)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if
					else	// horizontal edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==1)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if-else
					st=st->next;
				}	// end of while				
			}	//end of if orn
			//--------------------------------------------- // other faces y planes
			else if(ft->orn==1)
			{
				arr[ft->index]=2;
				st=ft->start;
				t1=ft->end;
				while(st!=t1)
				{
					t1=ft->start;
					vt1=st->vtx1->x;
					vt2=st->vtx1->y;
					vt3=st->vtx1->z;
					vt4=st->vtx2->x;
					vt5=st->vtx2->y;
					vt6=st->vtx2->z;
					if(st->vtx1->z==st->vtx2->z)	// vertical edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==0)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if
					else	// horizontal edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==2)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if-else
					st=st->next;
				}	// end of while				
			}	//end of if else orn 
			//------------------------------------------------- x plane
			else if(ft->orn==2)
			{
				arr[ft->index]=2;
				st=ft->start;
				t1=ft->end;
				while(st!=t1)
				{
					t1=ft->start;
					vt1=st->vtx1->x;
					vt2=st->vtx1->y;
					vt3=st->vtx1->z;
					vt4=st->vtx2->x;
					vt5=st->vtx2->y;
					vt6=st->vtx2->z;
					if(st->vtx1->z==st->vtx2->z)	// vertical edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==0)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if
					else	// horizontal edge
					{
						fs=facef;
						while(fs!=NULL)
						{
							if(arr[fs->index]!=0)
							{
								fs=fs->next;
								continue;
							}
							if(fs->orn==1)
							{
								ss=fs->start;
								t2=fs->end;
								while(ss!=t2 && flag==0)
								{
									t2=fs->start;
									if(ss->vtx1->x==vt1 && ss->vtx1->y==vt2 && ss->vtx1->z==vt3 && ss->vtx2->x==vt4 && ss->vtx2->y==vt5 && ss->vtx2->z==vt6)
									{
										printf("%d and %d\n",ft->index,fs->index);
										reverse(&fs->start,&fs->end);
										arr[fs->index]=1;
										flag=1;
									}
									ss=ss->next;
								}
							}
							if(flag==1)
							{
								flag=0;
								break;
							}
							fs=fs->next;
						}
					}	// end of if-else
					st=st->next;
				}	// end of while				
			}	//end of if else orn  
		}	// end of if
	} // end of for

}	// end of function
