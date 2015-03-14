#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXV 1000

typedef struct{
	int y;
	int weight;
	struct edgenode *next;
}edgenode;

typedef struct{
	edgenode *edges[MAXV+1];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
	bool directed;
} graph;
void initialize_graph(graph *,bool);
void read_graph(graph *,bool);
void insert_edge(graph *, int, int, bool);
void initialize_graph(graph *g,bool directed)
{
	int i;
	g->nvertices=0;
	g->nedges=0;
	g->directed=directed;
	for(i=1;i<=MAXV;i++) g->degree[i]=0;
	for(i=1;i<=MAXV;i++) g->edges[i]=NULL;
}

void read_graph(graph *g,bool directed)
{
	int i;
	int m;
	int x,y;
	initialize_graph(g,directed);
	printf("Enter no of vertices and edges:\n");
	scanf("%d %d",&(g->nvertices),&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

void insert_edge(graph *g,int x,int y, bool directed)
{
	edgenode *p;
	p=(edgenode *)malloc(sizeof(edgenode));
	p->weight=NULL;
	p->y=y;
	p->next=g->edges[x];
	g->edges[x]=p;
	g->degree[x]++;
	if(directed==1)
		insert_edge(g,y,x,0);
	else
		g->nedges ++;
}

void print_graph(graph *g)
{
	int i;
	edgenode *p;
	for(i=1;i<=g->nvertices;i++)
	{
		printf("%d: ",i);
		p=g->edges[i];
		while(p!=NULL)
		{
			printf(" %d",p->y);
			p=p->next;
		}
		printf("\n");
	}
}

int main()
{
	graph *g;
	read_graph(g,0);
	print_graph(g);
}
