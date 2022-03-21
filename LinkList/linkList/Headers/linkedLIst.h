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
	(*L)->next = NULL;     //��ͷ���ָ��NULL
	(*L)->data = NULL;//��֤ͷ��������ݣ��Ǳ�Ҫ������Ҳ�ɷű�ĳ���
	printf("��ʼ���ɹ�\n");//��֤�ѵ���InitList
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
	LinkedList p, q;  //��������ָ�룬p����������qָ��p����һ��Ԫ��
	p = (*L)->next;
	while (p)         //��������β
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; //��ͷ���ָ����Ϊ��
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
	q->next = p->next; //��p�ĺ�̽�㸳ֵ��q�ĺ��
	p->next = q;       //��q��ֵ��p�ĺ��
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
	q = p->next;          //��p�ĺ�̸�ֵ��q
	p->next = q->next;    //��q�ĺ�̽�㸳ֵ��p�ĺ��
	*e = q->data;         //��q�����ݴ����e
	free(q);              //ϵͳ����q���ͷ��ڴ�
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
	LinkedList p;  /*�������p*/
	p = L->next;
	ElemType e;
	if (!p)
	{
		printf("��ǰ������\n");
		return;
	}
	while (p)
	{
		e = p->data;
		visit(e);  /*���ú���visit����ӡ����*/
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
	p = L->next; /*��pָ�������һ�����*/
	while (p)
	{
		if (p->data ==e)/*Ѱ�������е�һ�����������e�Ľ�㣬�ҵ����˳�ѭ��*/
			break;
		p = p->next;    /*pָ����һ�����*/
	}
	if (!p)          /*�ж��Ƿ������������ҵ�e*/
		return ERROR; /*�Ҳ���*/
	return SUCCESS;  
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)/*����ͷ�巨*/
{
	LinkedList p,q;  //��������ָ��
	p = (*L)->next;
	(*L)->next = NULL;//��ʼ��ͷ���
	if (!p)
		return ERROR;//�ж������Ƿ�Ϊ��
	while (p)
	{
		q = p->next;    //��q����p�ĺ�̽��
		p->next = (*L)->next;
		(*L)->next = p; //��p�����ͷ
		p = q;          //��p�ƶ�����һ��㣨q��
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
	p = L->next;       /*��pָ���һ�����*/
	q = L->next->next; /*��qָ������ڶ������*/
	while (q)         /*��������β������Ϊѭ������*/
	{
		p = p->next;   /*p��һλ*/
		q = q->next->next;/*q��2λ*/
		if (p == q)  /*�ж��Ƿ�ɻ�*/
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
		printf("��ǰ���ɲ���\n");
		return *L;
	}
		
	p = (*L)->next;/*��pָ����һ�����*/ 
	q = p->next;/*��qָ��ڶ������*/
	r = *L;/*rֱ��ָ���ͷ*/

	while (q&&p)
	{
		p->next = q->next;/*��q�ĺ�̽�㸳ֵ��p��ָ����*/
		q->next = p;/*��p��ֵ��q��ָ����*/
		r->next = q;/*��q��ֵ��r��ָ����*/
		r = p;      /*��rָ��p*/
		p = p->next;/*��pָ�����̽��*/
		if (p)
			q = p->next;/*��qָ��p�ĺ�̽��*/
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
		printf("��ǰ���ɲ���\n");
		return *L;
	}
	LinkedList p, q;
	p = (*L)->next;
	q = (*L)->next->next;
	while (q&&q->next)     /*��������β,��ôд��Ҫ��Ϊ�˷�ֹ��ָ�����*/
	{
		p = p->next;      /*p��һλ*/
		q = q->next->next;/*q��2λ*/
	}
	return p;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
#pragma once
