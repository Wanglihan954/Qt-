/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->next = (*L);     //让头结点的直接前驱指针指向本身
	(*L)->data = NULL;//保证头结点无数据，非必要操作，也可放表的长度
	(*L)->prior = (*L);//让头结点的直接后驱指针指向本身
	printf("初始化成功\n");//保证已调用InitDuList
	return SUCCESS;
}
/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList p, q;  //创建两个指针，p遍历循环链表，q指向p的下一个元素
	p = (*L)->next;
	while (p != *L)         //从尾出发运行到尾前一个结点
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; //让头结点指针域为空
}
/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->prior = p->prior;//将p的后继结点赋值给q的后继
	p->prior = q;       //将q赋值给p的后继
	q->next = q->prior->next;//将q的前驱结点赋值给q的直接前驱指针
	q->prior->next = q;//将q赋值给q的后继结点的直接前驱指针
	return SUCCESS;
}
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p->next;//将p的后继结点赋值给q的后继
	p->next = q;       //将q赋值给p的后继
	q->prior = q->next->prior;//将q的前驱结点赋值给q的直接前驱指针
	q->next->prior = q;//将q赋值给q的后继结点的直接前驱指针
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLinkedList  q;
	q = p->next;          //将p的后继赋值给q
	p->next = q->next;    //将q的后继结点赋值给p的后继
	p->next->prior = p;   //将现在p的前驱指针指向p
	*e = q->data;         //将q中数据传输给e
	free(q);              //系统回收q，释放内存
	return SUCCESS;
}
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p;  /*声明结点p*/
	p = L->next;
	ElemType e;
	if (p->next == p)
	{
		printf("当前无链表\n");
		return;
	}
	while (p != L)
	{
		e = p->data;
		visit(e);  /*调用函数visit，打印数据*/
		p = p->next;
	}


}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
#pragma once
