#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"
#include"MENU.h"
using namespace std;
int main()
{
	LQueue s;//创建一个新的栈
	int select = 0;
	bool isERROR;
	int len;
	InitLQueue(&s);//完成初始化
	while (1)
	{
		system("cls");
		menu();
		printf("请输入选择操作的编号：\n");
		isSCANFsuccess(isERROR, select);
		system("cls");
		switch (select)
		{
		case 1:/*1.创建新队*/
			Creat_LQueue(&s);
			system("pause");
			break;
		case 2://2.清空现有队
			if (!IsEmptyLQueue(&s))
			{
				ClearLQueue(&s);
				printf("已清除\n");
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
		case 3://3.打印当前队
			if (!IsEmptyLQueue(&s))
			{
				TraverseLQueue(&s, &LPrint);
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
			break;
		case 4://4. 查看队头
			if (!IsEmptyLQueue(&s))
			{
				void* e=malloc(21);
				int type;
				GetHeadLQueue(&s, e, &type);
				LPrint(e, type);
				printf("*这是队头\n");
				free(e);
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
			system("pause");
			break;

		case 5://5. 入队操作
			if (!IsEmptyLQueue(&s))
			{
				One_EnLQueue(&s);
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
			system("pause");
			break;
		case 6://6. 出队操作
			if (!IsEmptyLQueue(&s))
			{
				int len;
				len = LengthLQueue(&s);
				DeLQueue(&s);
				if (len - LengthLQueue(&s) == 1)
				{
					printf("出队成功\n");
				}
				else
					printf("出队失败\n");
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
			system("pause");
			break;
		case 7://7. 查看当前队的长度
			if (!IsEmptyLQueue(&s))
			{
				printf("当前队列长度:%d\n", LengthLQueue(&s));
			}
			else
				printf("当前队列为空\n");
			system("pause");
			break;
		case 0:/*0. 退出系统并销毁队列*/
			DestoryLQueue(&s);
			printf("销毁成功，已退出\n");
			return 0;
			break;

		default:
			printf("请输入正确操作编号\n");
			system("pause");
			break;
		}

	}
	menu();
	return 0;
}