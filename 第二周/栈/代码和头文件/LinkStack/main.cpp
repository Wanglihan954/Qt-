#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"
#include"MENU.h"/*菜单中操作包括菜单本身均在其中实现*/
using namespace std;
int main()
{
	LinkStack s;//创建一个新的栈
	int select = 0;
	bool isERROR;
	int len;
	initLStack(&s);//完成初始化
	while (1)
	{
		system("cls");
		Menu();
		printf("请输入选择操作的编号：\n");
		isSCANFsuccess(isERROR, select);
		system("cls");
		switch (select)
		{
		case 1:/*1.创建新栈*/
			CreatStack(&s);
			system("pause");
			break;
		case 2://2.清空现有栈
			if (clearLStack(&s))
			{
				printf("清空栈成功\n");
				LStackLength(&s, &len);
				printf("当前栈的长度为：%d\n", len);
			}
			else
				printf("当前栈不存在\n");
			system("pause");
			break;
		case 3://3.打印当前栈
			TraverseStack(s, &visit);
			system("pause");
			break;
		case 4://4. 查看栈顶
			if (!isEmptyLStack(&s))
			{
				ElemType e;
				getTopLStack(&s, &e);
				printf("当前栈顶为：%d\n",e);
			 }
			system("pause");
			break;
			
		case 5://5. 入栈操作
			if (!isEmptyLStack(&s))
			{
				ElemType e;
				printf("请输入添加数据：\n");
				isSCANFsuccess(isERROR, e);
				pushLStack(&s, e);
				printf("当前栈顶为：%d\n", e);
				printf("当前栈的长度为：%d\n",s.count);
			}
			system("pause");
			break;
		case 6://6. 出栈操作
			if (!isEmptyLStack(&s))
			{
				ElemType e;
				popLStack(&s, &e);
				printf("出栈数据为：%d\n", e);
				TraverseStack(s, &visit);
			}
			system("pause");
			break;
		case 7://7. 查看当前栈的长度 
			if (LStackLength(&s, &len))
			{
				printf("当前栈的长度为：%d\n", len);
			}
			else
				printf("当前栈不存在\n");
			system("pause");
			break;
		case 0:/*0. 退出系统并销毁栈*/
			if (destroyLStack(&s) == 1)
			{
				printf("销毁成功，已退出\n");
				return 0;
			}
			else
				printf("销毁失败\n");
			break;
			
		default:
			printf("请输入正确操作编号\n");
			system("pause");
			break;
		}
		
	}
	
}