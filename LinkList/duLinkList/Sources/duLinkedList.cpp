#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "dulinkedLIst.h"
#include<iostream>
using namespace std;
/*我首先进行了一些函数的定义*/
void CreateList(DuLinkedList* L, Status(*InitList)(DuLinkedList* L), int n)
{
	DuLinkedList p, r;
	int i;
	int input;
	InitList(L);/*初始化结点*/
	r = *L;  /*r指向尾部的结点*/
	for (i = 0; i < n; i++)
	{
		p = (DuLNode*)malloc(sizeof(DuLNode));/*生成新结点*/
		printf("请输入第%d个结点\n", (i + 1));
		scanf_s("%d", &input); /*输入结点数据*/
		p->data = input;
		r->next = p;           /*将当前新结点定义为表尾终端的指针*/
		p->prior = r;
		r = p;
	}
	r->next = (*L);/*让表尾的直接后驱指针指向头结点*/
	(*L)->prior = r;  /*让头结点的直接前驱指针指向表尾*/
}
void InsertElem(DuLinkedList* L, ElemType e)
{
	ElemType edata;  /*创建新结点的数据*/
	DuLinkedList p, q;/*p用作遍历，q创建新结点*/
	if ((*L)->next == (*L))/*判断链表是否为空*/
	{
		printf("当前无链表\n");
		return;
	}
	else
	{
		p = (*L)->next;
		/*下面的操作是为了找到链表中数据域为e的结点*/
		while ((p->data != e) && (p != (*L)))
		{
			p = p->next;
		}
		if ((p->data) == e && (p != (*L)))
		{
			q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("输入新结点数据：\n");
			scanf_s("%d", &edata);
			q->data = edata;
			InsertAfterList_DuL(p, q);
			printf("添加成功");
			system("pause");
			system("cls");
		}
		else
		{
			printf("该链表中不存在该数据\n");
		}
	}
}
void visit(ElemType e)
{
	printf("%d->", e);
}
void MENU()
{
	printf("\n");
	printf("\t**************操作界面**************\n");
	printf("\t------------------------------------\n");
	printf("\t  ********************************  \n");
	printf("\t  ##1.创建新链表****2.创建新结点##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##3.输出现链表****4.删除单结点##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     5.查询数据是否在表中   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     0.删除链表并退出界面   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t------------------------------------\n");
}
int main()
{
	/*初始化一些变量包括头结点*/
	int len = 0;
	int select;
	DuLinkedList L;
	InitList_DuL(&L);

	while (1)
	{
		system("cls");/*为了美观，每一次操作结束清屏*/
		MENU();
		printf("请选择操作编号：");
		scanf_s("%d", &select);
		system("cls");/*具体操作开始前统一清屏*/
		switch (select)
		{
		case 1:       /*1.创建新链表*/
			printf("请输入你要创建的链表长度：\n");
			scanf_s("%d", &len);
			CreateList(&L, &InitList_DuL, len);
			printf("创建成功\n");
			system("pause");
			system("cls");
			break;
		case 2:       /*2.创建新结点*/
		{
			if ((L)->next != L)/*判断链表是否为空*/
			{

				ElemType e;
				printf("请输入添加位置前一个结点的数据：");
				scanf_s("%d", &e);
				InsertElem(&L, e);
			}
			else
				printf("当前链表为空，不可操作\n");
			break;
		}
		case 3:        /*3.输出现链表*/
			TraverseList_DuL(L, &visit);
			printf("NULL\n");/*打印表尾*/
			system("pause");
			break;
		case 4:        /*4.删除单结点*/
			if ((L)->next != L)/*判断链表是否为空*/
			{
				DuLinkedList p;
				ElemType e, e2;/*创建两个数据，e存储删除结点前一个数据，e2返回删除结点数据*/
				printf("请输入要删除结点的前一结点的数据：\n");
				scanf_s("%d", &e);
				p = L->next;
				/*下面的操作是为了找到链表中数据域为e的结点*/
				while ((p->data != e) && (p != (L)))
				{
					p = p->next;
				}
				if ((p->data) == e && (p != (L)))
				{
					DeleteList_DuL(p, &e2);
					printf("删除数据为：%d\n", e2);
					printf("删除成功\n");
				}
				else
				{
					printf("该链表中不存在该数据\n");
				}
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 5:        /*5.查询数据是否在表中*/
			if ((L)->next != L)/*判断链表是否为空*/
			{
				DuLinkedList p;
				ElemType e, e2;/*创建两个数据，e存储删除结点前一个数据，e2返回删除结点数据*/
				printf("请输入要查询结点的数据：\n");
				scanf_s("%d", &e);
				p = L->next;
				/*下面的操作是为了找到链表中数据域为e的结点*/
				while ((p->data != e) && (p != (L)))
				{
					p = p->next;
				}
				if ((p->data) == e && (p != (L)))
				{
					printf("数据在循环链表中\n");
				}
				else
				{
					printf("该链表中不存在该数据\n");
				}
			}
			else
				printf("当前链表为空，不可操作\n");
			system("pause");
			break;
		case 0:     /*0.删除链表并退出界面*/
			DestroyList_DuL(&L);
			system("cls");
			printf("成功退出当前系统\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
}