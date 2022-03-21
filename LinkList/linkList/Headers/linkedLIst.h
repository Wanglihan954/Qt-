/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	(*L) = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;     //让头结点指向NULL
	(*L)->data = NULL;//保证头结点无数据，非必要操作，也可放表的长度
	printf("初始化成功\n");//保证已调用InitList
	return SUCCESS;
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{
	LinkedList p, q;  //创建两个指针，p遍历单链表，q指向p的下一个元素
	p = (*L)->next;
	while (p)         //运行至表尾
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; //让头结点指针域为空
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
	q->next = p->next; //将p的后继结点赋值给q的后继
	p->next = q;       //将q赋值给p的后继
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)
{
	LinkedList  q;
	q = p->next;          //将p的后继赋值给q
	p->next = q->next;    //将q的后继结点赋值给p的后继
	*e = q->data;         //将q中数据传输给e
	free(q);              //系统回收q，释放内存
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LinkedList p;  /*声明结点p*/
	p = L->next;
	ElemType e;
	if (!p)
	{
		printf("当前无链表\n");
		return;
	}
	while (p)
	{
		e = p->data;
		visit(e);  /*调用函数visit，打印数据*/
		p = p->next;
	}
	
	
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
	LinkedList p;
	p = L->next; /*让p指向链表第一个结点*/
	while (p)
	{
		if (p->data ==e)/*寻找链表中第一个数据域等于e的结点，找到即退出循环*/
			break;
		p = p->next;    /*p指向下一个结点*/
	}
	if (!p)          /*判断是否在链表中有找到e*/
		return ERROR; /*找不到*/
	return SUCCESS;  
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)/*运用头插法*/
{
	LinkedList p,q;  //创建两个指针
	p = (*L)->next;
	(*L)->next = NULL;//初始化头结点
	if (!p)
		return ERROR;//判断链表是否为空
	while (p)
	{
		q = p->next;    //让q保存p的后继结点
		p->next = (*L)->next;
		(*L)->next = p; //让p插入表头
		p = q;          //让p移动到下一结点（q）
	}
	return SUCCESS;
}
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
	LinkedList p, q;
	p = L->next;       /*让p指向第一个结点*/
	q = L->next->next; /*让q指向链表第二个结点*/
	while (q)         /*运行至表尾（若不为循环链表）*/
	{
		p = p->next;   /*p走一位*/
		q = q->next->next;/*q走2位*/
		if (p == q)  /*判断是否成环*/
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)
{
	LinkedList p, q,r;
	if (!((*L)->next))
	{ 
		printf("当前不可操作\n");
		return *L;
	}
		
	p = (*L)->next;/*令p指向表第一个结点*/ 
	q = p->next;/*令q指向第二个结点*/
	r = *L;/*r直接指向表头*/

	while (q&&p)
	{
		p->next = q->next;/*将q的后继结点赋值给p的指针域*/
		q->next = p;/*将p赋值给q的指针域*/
		r->next = q;/*将q赋值给r的指针域*/
		r = p;      /*将r指向p*/
		p = p->next;/*将p指向其后继结点*/
		if (p)
			q = p->next;/*将q指向p的后继结点*/
	}
	return *L;
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)
{
	if (!((*L)->next))
	{
		printf("当前不可操作\n");
		return *L;
	}
	LinkedList p, q;
	p = (*L)->next;
	q = (*L)->next->next;
	while (q&&q->next)     /*运行至表尾,这么写主要是为了防止空指针出现*/
	{
		p = p->next;      /*p走一位*/
		q = q->next->next;/*q走2位*/
	}
	return p;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
#pragma once
