#include <stdio.h>

#define OK    1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

typedef struct LinkList
{
	int data;
	struct CLinkList *next;
}node;

void ds_Init(node **pNode)
{
	int item;
	node *temp;
	node *target;
	
	printf("输入结点的值，输入0完成初始化\n");
	
	while(1)
	{
		scanf("%d",&item);
		
		if(item == 0)
			return;
			
		if(*pNode == NULL)
		{
			*pNode = (node *)malloc(sizeof(struct LinkList));
			if(!(*pNode))
				exit(0);
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
	}
}

int main(void)
{
    return OK;
}