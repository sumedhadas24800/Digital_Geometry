#include<stdio.h>
void main()
{
	// total no of points
	int N=100;
	int x1,y1,z1,x,y,z,i,j=0,k,flag=0;	
	int points[N][3];
	x=0;
	y=0;
	z=0;
	i=0;
	points[i][0]=x;
	points[i][1]=y;
	points[i][2]=z;

	FILE *fp;
	fp=fopen("new.txt","w");


//random numbers
	srand(time(0));

	//generate numbers
	while(i<N-1)
	{
		if(i!=0)
			j=rand()%i;
		x=rand()%3;
		if(x==2)
			x=-1;
		y=rand()%3;
		if(y==2)
			y=-1;
		z=rand()%3;
		if(z==2)
			z=-1;
		x1=points[j][0]+x;
		y1=points[j][0]+y;
		z1=points[j][0]+z;
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
		else
		{
			i++;
			points[i][0]=x1;	
			points[i][1]=y1;
			points[i][2]=z1;
		}
	}
	// for printing
	for(k=0;k<=i;k++)
	{
		printf("%d \t %d \t %d\n",points[k][0],points[k][1],points[k][2]);
		fprintf(fp,"%d",points[k][0]);
		putc('\t',fp);
		fprintf(fp,"%d",points[k][1]);
		putc('\t',fp);
		fprintf(fp,"%d",points[k][2]);
		putc('\n',fp);
	}
}//end of main
