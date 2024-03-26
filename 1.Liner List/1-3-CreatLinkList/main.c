#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK    1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

void CreatHead(LinkList *L, int n)
{
	int i;
	LinkList p;
	
	srand(time(0));
	
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 10 + 1;
		p->next = (*L)->next;
		(*L)->next = p;	
	}
}

void ShowList(LinkList L)
{
	LinkList p;
	p = L->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	
}

int main(void)
{
    LinkList p;
	CreatHead(&p,6);
	ShowList(p);

    return OK;
}