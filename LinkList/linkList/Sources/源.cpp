#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "linkedLIst.h"
#include<iostream>
using namespace std;
/*我首先进行了一些函数的定义*/
void CreateList(LinkedList * L, Status (*InitList)(LinkedList* L),int n)
{
	LinkedList p, r;
	int i;
	int input;
	InitList(L);/*初始化结点*/
	r = *L;  /*r指向尾部的结点*/
	for (i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));/*生成新结点*/
		printf("请输入第%d个结点\n", (i + 1));
		scanf_s("%d", &input); /*输入结点数据*/
		p->data = input;       
		r->next = p;           /*将当前新结点定义为表尾终端的指针*/
		r = p;
	}
	r->next = NULL;  /*表示当前链表结束*/
}
void InsertElem(LinkedList* L, ElemType e)
{
	ElemType edata;  /*创建新结点的数据*/
	LinkedList p, q;/*p用作遍历，q创建新结点*/
	if (!(*L)->next)/*判断链表是否为空*/
	{
		printf("当前无链表\n");
		return;
	}
	if (!SearchList(*L, e))
	{
		printf("当前链表不存在输入结点");
	}
	else
	{
		q = (LNode*)malloc(sizeof(LNode));
		printf("输入新结点数据：\n");
		scanf_s("%d", &edata);
		q->data = edata;
		p = *L;
		while (p->data != e)
		{
			p = p->next;
		}
		InsertList(p, q);
		printf("添加成功");
		system("pause");
		system("cls");
	}
}
void visit(ElemType e)
{
   printf("%d->", e);
}
void LoopList(LinkedList*L)
{
	LinkedList p;
	if ((*L)->next)/*判断链表是否为空*/
	{
		p = *L;
		if (IsLoopList(*L))
			printf("当前链表已成环\n");
		else
		{
			while (p->next)
			{
				p = p->next;
			}
			p->next = (*L)->next;
			(*L)->next = p;
			printf("链表成环成功\n");
		}
	}
	else
		printf("当前链表为空，不可操作\n");
	system("pause");
	return;
}
void MENU()
{
	printf("\n");
	printf("\t**************操作界面**************\n");
	printf("\t------------------------------------\n");
	printf("\t  ********************************  \n");
	printf("\t  ##1.创建新链表****2.创建新结点##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##3.输出现链表****4. 链表反向 ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##5.找链表中点****6.判断成环否##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##7.删除单结点****8. 奇偶反转 ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     9.查询数据是否在表中   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     0.删除链表并退出界面   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##        10.构造循环链表     ##  \n");
	printf("\t  ********************************  \n");
	printf("\t------------------------------------\n");
}
int main()
{
	LinkedList L,p;
	int len=0;
	int select;
	InitList(&L);
	while (1)
	{
		system("cls");/*为了美观，每一次操作结束清屏*/
		MENU();
		printf("请选择操作编号：");
		scanf_s("%d",&select);
		system("cls");/*具体操作开始前统一清屏*/
		switch (select)
		{
		case 1:      /*1.创建新链表*/
			printf("请输入您要创建的链表的长度:\n" );
			scanf_s("%d",&len);
			CreateList(&L, &InitList, len);
			printf("创建成功\n");
			system("pause");
			system("cls");
			break;
		case 2:   /*2.创建新结点*/
		{
			if ((L)->next)/*判断链表是否为空*/
			{
				if (IsLoopList(L))
				{
					printf("当前不可操作\n");
					system("pause");
					break;
				}
				ElemType e;
				printf("请输入添加位置前一个结点的数据：");
				scanf_s("%d", &e);
				InsertElem(&L, e);
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		}
		case 3:   /*3.输出现链表*/
			if (IsLoopList(L))
			{
				printf("当前不可操作\n");
				system("pause");
				break;
			}
			TraverseList(L, &visit);
			printf("NULL\n");/*打印表尾*/
			system("pause");
			break;
		case 4:            /*4. 链表反向*/
			if (IsLoopList(L))
			{
				printf("当前不可操作\n");
				system("pause");
				break;
			}
			ReverseList(&L);
			printf("反转成功\n");
			system("pause");
			break;
		case 5:           /*5.找链表中点*/
			
			if ((L)->next)/*判断链表是否为空*/
			{ 
				if (IsLoopList(L))
				{
					printf("当前不可操作\n");
					system("pause");
					break;
				}
				p=FindMidNode(&L);
				printf("当前链表中点为；   %d\n",p->data);
			}
			
			system("pause");
			break;
		case 6:             /*6.判断成环否*/
			if ((L)->next)/*判断链表是否为空*/
			{
				if (IsLoopList(L))
					printf("当前链表成环\n");
				else
					printf("当前链表未成环\n");
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 7:            /*7.删除单结点*/
			if ((L)->next)/*判断链表是否为空*/
			{
				if (IsLoopList(L))
				{
					printf("当前不可操作\n");
					system("pause");
					break;
				}
				ElemType e,e2;/*创建两个数据，e存储删除结点前一个数据，e2返回删除结点数据*/
				printf("请输入要删除结点的前一结点的数据：\n");
				scanf_s("%d", &e);
				p = L;
				if(SearchList(L,e))
				{ 
					while (p->data != e)
					{
						p = p->next;
					}
					DeleteList(p, &e2);
					printf("删除数据为：%d\n", e2);
					printf("删除成功\n");
				}
				else
				{
					printf("链表不存在输入数据\n");
				}
				
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 8:            /*8. 奇偶反转 */
			if ((L)->next)/*判断链表是否为空*/
			{
				if (IsLoopList(L))
				{
					printf("当前不可操作\n");
					system("pause");
					break;
				}
				L=ReverseEvenList(&L);
				printf("奇偶反转成功/n");
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 9:               /*  9.查询数据是否在表中 */
			if ((L)->next)/*判断链表是否为空*/
			{
				if (IsLoopList(L))
				{
					printf("当前不可操作\n");
					system("pause");
					break;
				}
				ElemType e;
				printf("请输入查询结点的数据：");
				scanf_s("%d", &e);
				printf("\n");
				if (!SearchList(L, e))
				{
					printf("当前链表不存在输入结点\n");
				}
				else
				{
					printf("当前链表存在输入结点\n");
				}
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 10:            /*10.构造循环链表*/
			LoopList(&L);
			break;
		case 0:            /* 0.删除链表并退出界面 */
			DestroyList(&L);
			system("cls");
			printf("成功退出当前系统\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
	
	return 0;
}