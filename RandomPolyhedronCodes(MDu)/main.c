/************** Define the Node ***************/
typedef struct vertex
{
	struct vertex *prev;
	int x;
	int y;
	int z;
	int fx;
	int fy;
	int fz;
	struct vertex *next;
}vrtx;
vrtx *vtf; 

typedef struct l_list
{
	struct l_list *prev;
	int a;
	int b;
	int f;
	vrtx *vtx;
	int set;
	int visit;
	struct l_list *next;
}slist;
slist *lx,*ly;

typedef struct edges
{
	struct edges *prev;
	vrtx *vtx1;
	vrtx *vtx2;
	struct edges *twin;
	struct edges *next;
}edge;

typedef struct faces
{
	struct faces *prev;
	edge *start,*end; 
	int index;
	int orn;
	struct faces *next;
}face;
face *facef;

int no=-1;
int f_no;

#include<stdio.h>
#include<stdlib.h>
#include"rand6.c"
#include"search_vertex.c"
#include"lists.c"
#include"insert_lx.c"
#include"insert_ly.c"
#include"delete.c"
#include"make_elist.c"
#include"make_edge.c"
#include"reverse.c"
#include"make_twin.c"

int main()
{
	// total no of points
	int N=15;
	int k;
	int points[N][4];
	FILE *fp,*fp1;
	fp=fopen("set-1.txt","w");
	fp1=fopen("file-1.txt","w");
	rand6(points,N);
	
	vtf=NULL;
	facef=NULL;
	lx=NULL;
	ly=NULL;

	face *ft;
	edge *st;

// for printing
	for(k=0;k<N;k++)
	{
		printf("%d \t %d \t %d \t %d \n",points[k][0],points[k][1],points[k][2],points[k][3]);
		if(points[k][3]==0)
		{
			fprintf(fp,"%d",points[k][0]);
			putc('\t',fp);
			fprintf(fp,"%d",points[k][1]);
			putc('\t',fp);
			fprintf(fp,"%d",points[k][2]);
			putc('\n',fp);
		}
	}
	printf("\n\n");
// to create grid model duel are created
	lists(points, N);
	make_edge();
	// to print faces
	ft=facef;
	while(ft!=NULL)
	{
		f_no=ft->index;
		printf("Index:%d Orientation: %d\n",ft->index,ft->orn);
		st=ft->start;
		while(st!=ft->end)
		{
			printf("%d %d %d and %d %d %d\n",st->vtx1->x,st->vtx1->y,st->vtx1->z,st->vtx2->x,st->vtx2->y,st->vtx2->z);
			st=st->next;
		}
			printf("%d %d %d and %d %d %d\n",st->vtx1->x,st->vtx1->y,st->vtx1->z,st->vtx2->x,st->vtx2->y,st->vtx2->z);
		ft=ft->next;
	}	
	make_twin();

	// to print faces
	ft=facef;
	while(ft!=NULL)
	{
		printf("Index:%d Orientation: %d\n",ft->index,ft->orn);
		st=ft->start;
		while(st!=ft->end)
		{
			fprintf(fp1,"%d",ft->index);
			putc('\t',fp1);
			fprintf(fp1,"%d",ft->orn);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->x);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->y);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->z);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->fx);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->fy);
			putc('\t',fp1);
			fprintf(fp1,"%d",st->vtx1->fz);
			putc('\n',fp1);
			printf("%d %d %d and %d %d %d\n",st->vtx1->x,st->vtx1->y,st->vtx1->z,st->vtx2->x,st->vtx2->y,st->vtx2->z);
			st=st->next;
		}
		fprintf(fp1,"%d",ft->index);
		putc('\t',fp1);
		fprintf(fp1,"%d",ft->orn);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->x);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->y);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->z);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->fx);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->fy);
		putc('\t',fp1);
		fprintf(fp1,"%d",st->vtx1->fz);
		putc('\n',fp1);
		printf("%d %d %d and %d %d %d\n",st->vtx1->x,st->vtx1->y,st->vtx1->z,st->vtx2->x,st->vtx2->y,st->vtx2->z);		
		ft=ft->next;
	}	
	return(0);
}//end of main
