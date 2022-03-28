#pragma once
#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
#ifndef MENU_C_INCLUDE
#define MENU_C_INCLUDE
void Menu() /*界面*/
{
	printf("\n\n\n\n");
	printf("\t\t**************操作系统**************\n");
	printf("\t\t------------------------------------\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $*** 1.创建新栈 **2.清空现有栈***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***3.打印当前栈**4. 查看栈顶 ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***5. 入栈操作 **6. 出栈操作 ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***    7. 查看当前栈的长度   ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***    0. 退出系统并销毁栈   ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t------------------------------------\n");
	printf("\t\t************************************\n");
}
bool isSCANFsuccess(bool& isERROR, int& input)//检查输入是否有误&&处理非法输入
{
	while (1)
	{
		isERROR = (scanf_s("%d", &(input)) != 0);

		if (!isERROR)
		{
			printf("输入错误，请输入数字\n");
			printf("请重新输入：\n");
			getchar();
		}
		else
		{
			return true;
		}
	}
}


void CreatStack(LinkStack* s)//1.创建新栈
{
	ElemType e;
	int len, length;
	bool isERROR;
	clearLStack(s);
	printf("请输入创建的栈的长度:\n");
	isSCANFsuccess(isERROR, len);
	for (int i = 0; i < len; i++)
	{
		printf("请输入创建的栈的第%d数据:\n", len - i);
		isSCANFsuccess(isERROR, e);
		pushLStack(s, e);
	}
	LStackLength(s, &length);
	printf("当前栈的长度为： % d\n", length);
}

/*3.打印当前栈*/
void visit(ElemType e)
{
	printf("\t %d\n", e);
}
void TraverseStack(LinkStack s, void(*visit)(ElemType e))
{
	LinkStackPtr p;
	p = s.top;
	int len;
	LStackLength(&s, &len);
	if (!isEmptyLStack(&s))
	{
		printf("当前栈的长度为：%d\n", len);
		printf("\t栈顶\n");
		while (p)
		{
			
			visit(p->data);
			p = p->next;
		}
		printf("\t栈底\n");
	}
}
#endif // !MENU_C_INCLUDE
