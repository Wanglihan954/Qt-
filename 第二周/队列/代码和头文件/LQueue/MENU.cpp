#ifndef MENU_C_INCLUDE
#define MENU_C_INCLUDE
#include"LQueue.h"
#include"MENU.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void menu()
{
	printf("\n\n\n\n");
	printf("\t\t**************操作系统**************\n");
	printf("\t\t------------------------------------\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***1.整体入队列**2.清空现队列***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***3.打印当前队**4. 查看队头 ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***5. 单独入队 **6. 出队操作 ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***    7. 查看当前队的长度   ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t $***    0. 退出系统并销毁队   ***$\n");
	printf("\t\t $********************************$\n");
	printf("\t\t------------------------------------\n");
	printf("\t\t************************************\n");
}
bool isSCANFsuccess(bool& isERROR, int& input)//检查输入是否有误&&处理非法输入(仅仅针对整型）
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
void Creat_LQueue(LQueue* Q)
{
	int len = 0;
	int select;
	int error;
	bool isERROR;
	if (IsEmptyLQueue(Q))
	{
		printf("创建成功\n");
		printf("请输入创建队列长度:\n");
	}
	else
	{
		printf("*******当前队列长度:%d********\n", LengthLQueue(Q));
		printf("当前从第%d位开始创建\n", Q->length + 1);
		printf("请输入添加队列长度:\n");
	}

	
	isSCANFsuccess(isERROR, len);
	int type=0;
	/*提示语*/
	printf("\t\t1.整型int\n");
	printf("\t\t2.浮点型double\n");
	printf("\t\t3.字符型char\n");
	printf("\t\t4.字符串型string\n");
	printf("请注意字符串中字符不能超过20个否则只取前20个\n");
	printf("请输入添加的数据的类型:\n");
		isSCANFsuccess(isERROR, type);
		while (type < 1 || type>4)
		{
			printf("请输入1——4之间数字\n");
			isSCANFsuccess(isERROR, type);
		}
	for (int i = 0; i < len; i++)
	{
		printf("请输入数据No.%d:\n",i+1);

		switch (type)
		{
		case INT:
			int data1;
			error = scanf_s("%d", &data1);
			while (!error)
			{
				printf("ERROR:correct format of input\n");
				error = scanf_s("%d", &data1);
			}
			EnLQueue(Q, &data1, type);
			break;
		case DOUBLE:
			double data2;
			error = scanf_s("%lf", &data2);
			while (!error)
			{
				getchar();
				printf("ERROR:correct format of input\n");
				error = scanf_s("%lf", &data2);
			}
			EnLQueue(Q, &data2, type);
			break;
		case CHAR:
			char data3;
			char extra;
			if (i == 0)
			{
				getchar();
			}
			data3=getchar();
			while ((extra = getchar()) != EOF && extra != '\n');//清空缓冲区
			EnLQueue(Q, &data3, type);
			break;
		/*几乎所有的输入都可以成为字符串，不需要特地报错*/
		case STRING:
			char data4[21];
			scanf_s("%s", data4,21);
			EnLQueue(Q, data4, type);
			break;
		default:
			break;
		}
	}
	
}
void One_EnLQueue(LQueue* Q)//一个一个入队
{
	printf("*******当前队列长度:%d********\n", LengthLQueue(Q));
	bool isERROR;
	int type = 0;
	int error;
	printf("\t\t1.整型int\n");
	printf("\t\t2.浮点型double\n");
	printf("\t\t3.字符型char\n");
	printf("\t\t4.字符串型string\n");
	printf("请输入添加的数据的类型:\n");
	isSCANFsuccess(isERROR, type);
	while (type < 1 || type>4)
	{
		printf("请输入1——4之间数字\n");
		isSCANFsuccess(isERROR, type);
	}
	

	printf("请输入数据:\n" );
	switch (type)
	{
	case INT:
		int data1;
		error = scanf_s("%d", &data1);
		while (!error)
		{
			printf("ERROR:correct format of input\n");
			error = scanf_s("%d", &data1);
		}
		EnLQueue(Q, &data1, type);
		break;
	case DOUBLE:
		double data2;
		error = scanf_s("%lf", &data2);
		while (!error)
		{
			getchar();
			printf("ERROR:correct format of input\n");
			error = scanf_s("%lf", &data2);
		}
		EnLQueue(Q, &data2, type);
		break;
	case CHAR:
		char data3;
		char extra;
		getchar();
		data3 = getchar();
		while ((extra = getchar()) != EOF && extra != '\n');
		EnLQueue(Q, &data3, type);
		break;
		/*几乎所有的输入都可以成为字符串，不需要特地报错*/
	case STRING:
		char data4[21];
		scanf_s("%s", data4, 21);
		EnLQueue(Q, data4, type);
		break;
	default:
		break;
	}
	
}
#endif // !MENU_C_INCLUDE
