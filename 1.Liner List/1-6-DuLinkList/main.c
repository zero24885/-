#include <stdio.h>
#include <stdlib.h>

#define OK	  1
#define ERROR 0
#define TURE  1
#define FALSE 0


typedef int Status;
typedef char ElemType;

typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DuLinkList;

//初始化链表
Status InitList(DuLinkList *L)
{
	DualNode *p, *q;
	int i;
	
	*L = (DuLinkList)malloc(sizeof(DualNode));
	if(!(*L))
	{
		return ERROR;
	}
	
	(*L)->next = (*L)->prior = NULL;
	p = (*L);
	
	for(i = 0; i < 26; i++)
	{
		q = (DualNode *)malloc(sizeof(DualNode));
		if(!q)
		{
			return ERROR;
		}
		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next;
		p->next = q;
		
		p = q;
	}
	
	p->next = (*L)->next;
	(*L)->next->prior = p;
	
	return OK;
}


void Caesar(DuLinkList *L, int i)
{
	if(i > 0)
	{
		do
		{
			(*L) = (*L)->next;
		}while(--i);
	}
	
	if(i < 0)
	{    
		(*L) = (*L)->next->prior;
		do
		{
			(*L) = (*L)->prior;
		}while(++i);
	}
}

//链表长度
int ListLength(DuLinkList L)
{
	DuLinkList temp = L->next,temp1 = L->next->next;
	int i = 0;
	while(temp)
	{
		i++;
		temp = temp->next;
		temp1 = temp1->next->next;
		if(temp == temp1)
		{
			i++;
			break;
		}
	}
	return i;
}

//插入某个结点
Status ListInsert(DuLinkList *L, char e,int n)
{
	DuLinkList temp, p;
	temp = (*L);

	p = (DualNode *)malloc(sizeof(DualNode));
	if(!p)
	{
		return ERROR;
	}
	
	p->data = e;
	for(int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	
	p->next = temp->next;
	temp->next->prior = p;
	p->prior = temp;
	temp->next = p;
	
	return OK;
}

//删除某个结点
Status ListDelete(DuLinkList *L, int n)
{
	DuLinkList temp;
	temp = (*L);
	
	for(int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	
	temp->prior->next = temp->next;
	temp->next->prior = temp->prior;
	
	free(temp);
	
	return OK;
}

//清除链表
void ListClear(DuLinkList *L)
{
	if((*L) != NULL)
	{
	DuLinkList p;
	p = (*L)->next;
	
	while(p != (*L))
	{
		DuLinkList temp = p->next;
		free(p);
		p = temp;
	}
	
	free(*L);
	*L = NULL;		
	}
}

void ShowList(DuLinkList L)
{
	int length = ListLength(L);
	for(int i = 0; i < length; i++)
	{
		L = L->next;
		printf("%c",L->data);
	}	
}

int main(void)
{
	DuLinkList L;
	int n;
	
	printf("1.初始化并显示26字母元素的链表\n");
	printf("2.将链表前后移动\n");
	printf("3.插入一个元素\n");
	printf("4.删除一个元素\n");
	printf("5.释放内存\n");
	printf("6.链表长度\n");
	printf("0.退出\n");
	
	printf("--------------------------------\n");
	
	while(1)
	{
		printf("请输入一个命令：");
		scanf("%d", &n);
		
		if(n == 1)
		{
			InitList(&L);
			ShowList(L);
			printf("\n");	
		}
		else if(n == 2)
		{
			int m;
			printf("请输入一个整数：\n");
			scanf("%d", &m);
			Caesar(&L, m);
			ShowList(L);
			printf("\n");
		}
		else if(n == 3)
		{
			char p;
			int q;
			printf("请输入一个字母和插入的位置：\n");
			//scanf在读取 %c 格式时可能会读取前一个输入操作后留在输入缓冲区中的换行符,在 %c 前面加一个空格来清除缓冲区中的任何残留字符。
			scanf(" %c", &p);         
			scanf("%d", &q);			
			ListInsert(&L, p , q);
			ShowList(L);
			printf("\n");
		}	
		else if(n == 4)
		{
			int k;
			printf("请输入要删除字母的位置：\n");
			scanf("%d", &k);				
			ListDelete(&L, k);
			ShowList(L);
			printf("\n");			
		}	
		else if(n == 5)
		{
			ListClear(&L);	
			if(L == NULL)
			{
				printf("\n");
				printf("链表已清空");
			}
			else
			{
				printf("\n");
				printf("链表未清空");
			}
			printf("\n");
		}
		else if(n == 6)
		{
			int length = ListLength(L);
			printf("链表长度：%d", length);
			printf("\n");
		}
		else if(n == 0)
		{
			break;
		}
		else
		{
			printf("输入一个错误的整数\n");
			printf("\n");
		}
	}
	
	return OK;
}