#ifndef LQueue_C_INCLUDE
#define LQueue_C_INCLUDE
#include "LQueue.h" 
#include"MENU.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) 
{
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));/*初始化队尾，队头指针.创建头结点*/
	if (!Q->front)/*内存分配失败*/
		exit(-1);
	Q->length = 0;
	Q->front->next = NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) 
{
	while (Q->front)/*直到队尾*/
	{
		Q->rear = Q->front->next;/*这里用尾指针进行遍历（反正都要销毁了，不需要明确队尾*/
		free(Q->front);
		Q->front = Q->rear;
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) 
{
	if (Q->front == Q->rear)
		return TRUE;
	else
	{
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e,int*type)
{
	Node* p;
	if (Q->front == Q->rear)
		return FALSE;
	p = Q->front->next;
	memcpy(e,p->data,21);
	*type = p->type;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q)
{
	int i = 0;
	Node* p;
	p = Q->front;
	while (Q->rear != p)/*队头到队尾*/
	{
		i++;
		p = p->next;
	}
	return i;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data,size_t type) 
{
	Node* p = (Node*)malloc(sizeof(Node));
	bool isERROR;
	if (!p)/*内存分配失败*/
		exit(-1);
	p->type = type;
	switch (p->type)
	{
	case INT:
		p->data = (void*)malloc(sizeof(int));
		memcpy(p->data, data, 4);
		break;
	case DOUBLE:
		p->data = (void*)malloc(sizeof(double));
		memcpy(p->data, data, 8);
		break;
	case CHAR:
		p->data = (void*)malloc(sizeof(char));
		memcpy(p->data, data, 1);
		break;
	case STRING:
		p->data = (void*)malloc(21);/*为了防止问题，字符串最多只能20个字符*/
		memcpy(p->data, data, 20);
		break;
	default:
		break;
	}
	p->next = NULL; 
	Q->rear->next = p;/*将p赋值给原队尾的直接后继*/
	Q->rear = p;/*让队尾指针指向p*/
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q)
{
	Node* p;
	if (IsEmptyLQueue(Q))
		return FALSE;
	else
	{
		p = Q->front->next;/*将需要出队的头结点暂时存放于p*/
		Q->front->next = p->next;
		if (Q->rear == p)/*若队头就是队尾，删除后将rear指向头结点*/
		{
			Q->rear = Q->front;
		}
		free(p);
		Q->length--;
		return TRUE;
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) 
{
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->length = 0;
	return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, size_t type))
{
	Node* p;
	p = Q->front->next;//让p指向第一个结点
	while (p)
	{
		foo(p->data,p->type);
		p = p->next;
		
	}
	printf("*END\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q,size_t type) 
{
	switch (type)
	{
	case INT:
		printf("%d<-",*(int*)q);
		break;
	case DOUBLE:
		printf("%.2lf<-", *(double*)q);
		break;
	case CHAR:
		printf("%c<-", *(char*)q);
		break;
	case STRING:
		printf("%s<-", (char*)q);
		break;
	default:
		break;
	}
	
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // !LQueue_C_INCLUDE
