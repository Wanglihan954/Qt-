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
	(*L)->next = (*L);     //��ͷ����ֱ��ǰ��ָ��ָ����
	(*L)->data = NULL;//��֤ͷ��������ݣ��Ǳ�Ҫ������Ҳ�ɷű�ĳ���
	(*L)->prior = (*L);//��ͷ����ֱ�Ӻ���ָ��ָ����
	printf("��ʼ���ɹ�\n");//��֤�ѵ���InitDuList
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
	DuLinkedList p, q;  //��������ָ�룬p����ѭ������qָ��p����һ��Ԫ��
	p = (*L)->next;
	while (p != *L)         //��β�������е�βǰһ�����
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; //��ͷ���ָ����Ϊ��
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
	q->prior = p->prior;//��p�ĺ�̽�㸳ֵ��q�ĺ��
	p->prior = q;       //��q��ֵ��p�ĺ��
	q->next = q->prior->next;//��q��ǰ����㸳ֵ��q��ֱ��ǰ��ָ��
	q->prior->next = q;//��q��ֵ��q�ĺ�̽���ֱ��ǰ��ָ��
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
	q->next = p->next;//��p�ĺ�̽�㸳ֵ��q�ĺ��
	p->next = q;       //��q��ֵ��p�ĺ��
	q->prior = q->next->prior;//��q��ǰ����㸳ֵ��q��ֱ��ǰ��ָ��
	q->next->prior = q;//��q��ֵ��q�ĺ�̽���ֱ��ǰ��ָ��
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
	q = p->next;          //��p�ĺ�̸�ֵ��q
	p->next = q->next;    //��q�ĺ�̽�㸳ֵ��p�ĺ��
	p->next->prior = p;   //������p��ǰ��ָ��ָ��p
	*e = q->data;         //��q�����ݴ����e
	free(q);              //ϵͳ����q���ͷ��ڴ�
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
	DuLinkedList p;  /*�������p*/
	p = L->next;
	ElemType e;
	if (p->next == p)
	{
		printf("��ǰ������\n");
		return;
	}
	while (p != L)
	{
		e = p->data;
		visit(e);  /*���ú���visit����ӡ����*/
		p = p->next;
	}


}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
#pragma once
