#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "dulinkedLIst.h"
#include<iostream>
using namespace std;
/*�����Ƚ�����һЩ�����Ķ���*/
void CreateList(DuLinkedList* L, Status(*InitList)(DuLinkedList* L), int n)
{
	DuLinkedList p, r;
	int i;
	int input;
	InitList(L);/*��ʼ�����*/
	r = *L;  /*rָ��β���Ľ��*/
	for (i = 0; i < n; i++)
	{
		p = (DuLNode*)malloc(sizeof(DuLNode));/*�����½��*/
		printf("�������%d�����\n", (i + 1));
		scanf_s("%d", &input); /*����������*/
		p->data = input;
		r->next = p;           /*����ǰ�½�㶨��Ϊ��β�ն˵�ָ��*/
		p->prior = r;
		r = p;
	}
	r->next = (*L);/*�ñ�β��ֱ�Ӻ���ָ��ָ��ͷ���*/
	(*L)->prior = r;  /*��ͷ����ֱ��ǰ��ָ��ָ���β*/
}
void InsertElem(DuLinkedList* L, ElemType e)
{
	ElemType edata;  /*�����½�������*/
	DuLinkedList p, q;/*p����������q�����½��*/
	if ((*L)->next == (*L))/*�ж������Ƿ�Ϊ��*/
	{
		printf("��ǰ������\n");
		return;
	}
	else
	{
		p = (*L)->next;
		/*����Ĳ�����Ϊ���ҵ�������������Ϊe�Ľ��*/
		while ((p->data != e) && (p != (*L)))
		{
			p = p->next;
		}
		if ((p->data) == e && (p != (*L)))
		{
			q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("�����½�����ݣ�\n");
			scanf_s("%d", &edata);
			q->data = edata;
			InsertAfterList_DuL(p, q);
			printf("��ӳɹ�");
			system("pause");
			system("cls");
		}
		else
		{
			printf("�������в����ڸ�����\n");
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
	printf("\t**************��������**************\n");
	printf("\t------------------------------------\n");
	printf("\t  ********************************  \n");
	printf("\t  ##1.����������****2.�����½��##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##3.���������****4.ɾ�������##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     5.��ѯ�����Ƿ��ڱ���   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t  ##     0.ɾ�������˳�����   ##  \n");
	printf("\t  ********************************  \n");
	printf("\t------------------------------------\n");
}
int main()
{
	/*��ʼ��һЩ��������ͷ���*/
	int len = 0;
	int select;
	DuLinkedList L;
	InitList_DuL(&L);

	while (1)
	{
		system("cls");/*Ϊ�����ۣ�ÿһ�β�����������*/
		MENU();
		printf("��ѡ�������ţ�");
		scanf_s("%d", &select);
		system("cls");/*���������ʼǰͳһ����*/
		switch (select)
		{
		case 1:       /*1.����������*/
			printf("��������Ҫ�����������ȣ�\n");
			scanf_s("%d", &len);
			CreateList(&L, &InitList_DuL, len);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 2:       /*2.�����½��*/
		{
			if ((L)->next != L)/*�ж������Ƿ�Ϊ��*/
			{

				ElemType e;
				printf("���������λ��ǰһ���������ݣ�");
				scanf_s("%d", &e);
				InsertElem(&L, e);
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			break;
		}
		case 3:        /*3.���������*/
			TraverseList_DuL(L, &visit);
			printf("NULL\n");/*��ӡ��β*/
			system("pause");
			break;
		case 4:        /*4.ɾ�������*/
			if ((L)->next != L)/*�ж������Ƿ�Ϊ��*/
			{
				DuLinkedList p;
				ElemType e, e2;/*�����������ݣ�e�洢ɾ�����ǰһ�����ݣ�e2����ɾ���������*/
				printf("������Ҫɾ������ǰһ�������ݣ�\n");
				scanf_s("%d", &e);
				p = L->next;
				/*����Ĳ�����Ϊ���ҵ�������������Ϊe�Ľ��*/
				while ((p->data != e) && (p != (L)))
				{
					p = p->next;
				}
				if ((p->data) == e && (p != (L)))
				{
					DeleteList_DuL(p, &e2);
					printf("ɾ������Ϊ��%d\n", e2);
					printf("ɾ���ɹ�\n");
				}
				else
				{
					printf("�������в����ڸ�����\n");
				}
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 5:        /*5.��ѯ�����Ƿ��ڱ���*/
			if ((L)->next != L)/*�ж������Ƿ�Ϊ��*/
			{
				DuLinkedList p;
				ElemType e, e2;/*�����������ݣ�e�洢ɾ�����ǰһ�����ݣ�e2����ɾ���������*/
				printf("������Ҫ��ѯ�������ݣ�\n");
				scanf_s("%d", &e);
				p = L->next;
				/*����Ĳ�����Ϊ���ҵ�������������Ϊe�Ľ��*/
				while ((p->data != e) && (p != (L)))
				{
					p = p->next;
				}
				if ((p->data) == e && (p != (L)))
				{
					printf("������ѭ��������\n");
				}
				else
				{
					printf("�������в����ڸ�����\n");
				}
			}
			else
				printf("��ǰ����Ϊ�գ����ɲ���\n");
			system("pause");
			break;
		case 0:     /*0.ɾ�������˳�����*/
			DestroyList_DuL(&L);
			system("cls");
			printf("�ɹ��˳���ǰϵͳ\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
}