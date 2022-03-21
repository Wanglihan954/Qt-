#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "linkedLIst.h"
#include<iostream>
using namespace std;
/*�����Ƚ�����һЩ�����Ķ���*/
void CreateList(LinkedList * L, Status (*InitList)(LinkedList* L),int n)
{
	LinkedList p, r;
	int i;
	int input;
	InitList(L);/*��ʼ�����*/
	r = *L;  /*rָ��β���Ľ��*/
	for (i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));/*�����½��*/
		printf("�������%d�����\n", (i + 1));
		scanf_s("%d", &input); /*����������*/
		p->data = input;       
		r->next = p;           /*����ǰ�½�㶨��Ϊ��β�ն˵�ָ��*/
		r = p;
	}
	r->next = NULL;  /*��ʾ��ǰ�������*/
}
void InsertElem(LinkedList* L, ElemType e)
{
	ElemType edata;  /*�����½�������*/
	LinkedList p, q;/*p����������q�����½��*/
	if (!(*L)->next)/*�ж������Ƿ�Ϊ��*/
	{
		printf("��ǰ������\n");
		return;
	}
	if (!SearchList(*L, e))
	{
		printf("��ǰ��������������");
	}
	else
	{
		q = (LNode*)malloc(sizeof(LNode));
		printf("�����½�����ݣ�\n");
		scanf_s("%d", &edata);
		q->data = edata;
		p = *L;
		while (p->data != e)
		{
			p = p->next;
		}
		InsertList(p, q);
		printf("��ӳɹ�");
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
	if ((*L)->next)/*�ж������Ƿ�Ϊ��*/
	{
		p = *L;
		if (IsLoopList(*L))
			printf("��ǰ�����ѳɻ�\n");
		else
		{
			while (p->next)
			{
				p = p->next;
			}
			p->next = (*L)->next;
			(*L)->next = p;
			printf("����ɻ��ɹ�\n");
		}
	}
	else
		printf("��ǰ����Ϊ�գ����ɲ���\n");
	system("pause");
	return;
}
void MENU()
{
	printf("\n");
	printf("\t**************��������**************\n");
	printf("\t------------------------------------\n");
	printf("\t  ********************************  \n");
	printf("\t  ##1.����������****2.�����½��##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##3.���������****4. ������ ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##5.�������е�****6.�жϳɻ���##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##7.ɾ�������****8. ��ż��ת ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     9.��ѯ�����Ƿ��ڱ���   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     0.ɾ�������˳�����   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##        10.����ѭ������     ##  \n");
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
		system("cls");/*Ϊ�����ۣ�ÿһ�β�����������*/
		MENU();
		printf("��ѡ�������ţ�");
		scanf_s("%d",&select);
		system("cls");/*���������ʼǰͳһ����*/
		switch (select)
		{
		case 1:      /*1.����������*/
			printf("��������Ҫ����������ĳ���:\n" );
			scanf_s("%d",&len);
			CreateList(&L, &InitList, len);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 2:   /*2.�����½��*/
		{
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{
				if (IsLoopList(L))
				{
					printf("��ǰ���ɲ���\n");
					system("pause");
					break;
				}
				ElemType e;
				printf("���������λ��ǰһ���������ݣ�");
				scanf_s("%d", &e);
				InsertElem(&L, e);
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		}
		case 3:   /*3.���������*/
			if (IsLoopList(L))
			{
				printf("��ǰ���ɲ���\n");
				system("pause");
				break;
			}
			TraverseList(L, &visit);
			printf("NULL\n");/*��ӡ��β*/
			system("pause");
			break;
		case 4:            /*4. ������*/
			if (IsLoopList(L))
			{
				printf("��ǰ���ɲ���\n");
				system("pause");
				break;
			}
			ReverseList(&L);
			printf("��ת�ɹ�\n");
			system("pause");
			break;
		case 5:           /*5.�������е�*/
			
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{ 
				if (IsLoopList(L))
				{
					printf("��ǰ���ɲ���\n");
					system("pause");
					break;
				}
				p=FindMidNode(&L);
				printf("��ǰ�����е�Ϊ��   %d\n",p->data);
			}
			
			system("pause");
			break;
		case 6:             /*6.�жϳɻ���*/
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{
				if (IsLoopList(L))
					printf("��ǰ����ɻ�\n");
				else
					printf("��ǰ����δ�ɻ�\n");
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 7:            /*7.ɾ�������*/
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{
				if (IsLoopList(L))
				{
					printf("��ǰ���ɲ���\n");
					system("pause");
					break;
				}
				ElemType e,e2;/*�����������ݣ�e�洢ɾ�����ǰһ�����ݣ�e2����ɾ���������*/
				printf("������Ҫɾ������ǰһ�������ݣ�\n");
				scanf_s("%d", &e);
				p = L;
				if(SearchList(L,e))
				{ 
					while (p->data != e)
					{
						p = p->next;
					}
					DeleteList(p, &e2);
					printf("ɾ������Ϊ��%d\n", e2);
					printf("ɾ���ɹ�\n");
				}
				else
				{
					printf("����������������\n");
				}
				
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 8:            /*8. ��ż��ת */
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{
				if (IsLoopList(L))
				{
					printf("��ǰ���ɲ���\n");
					system("pause");
					break;
				}
				L=ReverseEvenList(&L);
				printf("��ż��ת�ɹ�/n");
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 9:               /*  9.��ѯ�����Ƿ��ڱ��� */
			if ((L)->next)/*�ж������Ƿ�Ϊ��*/
			{
				if (IsLoopList(L))
				{
					printf("��ǰ���ɲ���\n");
					system("pause");
					break;
				}
				ElemType e;
				printf("�������ѯ�������ݣ�");
				scanf_s("%d", &e);
				printf("\n");
				if (!SearchList(L, e))
				{
					printf("��ǰ��������������\n");
				}
				else
				{
					printf("��ǰ�������������\n");
				}
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 10:            /*10.����ѭ������*/
			LoopList(&L);
			break;
		case 0:            /* 0.ɾ�������˳����� */
			DestroyList(&L);
			system("cls");
			printf("�ɹ��˳���ǰϵͳ\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
	
	return 0;
}