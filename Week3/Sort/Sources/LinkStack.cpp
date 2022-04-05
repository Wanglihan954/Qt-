
#ifndef STACK_C_INCLUDE
#define STACK_C_INCLUDE

#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack* s)
{
	LinkStackPtr p;//创建头指针
	p = (LinkStackPtr)malloc(sizeof(StackNode));//初始化头指针地址
	if (!p)
	{
		return ERROR;//判断是否正确初始化
	}
	p = NULL;
	s->count = 0;//初始化栈的长度
	s->top = p;//初始化头指针
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0||s->top==NULL)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s->top == NULL)//判断栈是否存在
		return ERROR;
	*e = s->top->data;//e返回栈顶数据
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
		return ERROR;
	LinkStackPtr p,q;//创建一个指针p指向栈顶
	p = s->top;
	while (p)//直到栈底
	{
		q= p;
		p=p->next;//指向下一位
		free(q);//释放当前栈顶
	}
	s->count = 0;
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{
	clearLStack(s);//栈中数据
	if(!s->top)
		free(s->top);//释放栈顶指针
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) 
{
	if (!s)//判断栈是否存在
		return ERROR;
	*length= s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) 
{
	if (!s)//判断栈是否存在
		return ERROR;
	LinkStackPtr p;
	p= (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;/*把当前栈顶元素赋值给新结点的直接后继 */
	s->top = p;/*让栈顶指针指向p */
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data) 
{
	if (!s||isEmptyLStack(s))//判断栈是否存在或为栈为空
		return ERROR;
	*data = s->top->data;
	LinkStackPtr p;
	p= s->top;/*把当前栈顶结点赋值给p */
	s->top = s->top->next;/*让栈顶指针指向下一个结点 */
	free(p);
	s->count--;
	return SUCCESS;
}

#endif//STACK_C_INCLUDE