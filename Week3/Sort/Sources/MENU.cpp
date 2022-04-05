#ifndef  MENU_C_INCLUDE
#define MENU_C_INCLUDE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"MENU.h"
#include"sort.h"
#include<string.h>

void menu()//实现基本操作
{
	char select;
	while (1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t***************测试系统***************\n");
		printf("\t\t--------------------------------------\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***1.不同排序在大数据量下的用时***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***2.不同排序在小数据量下的用时***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***     3.显示颜色排序的应用   ***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***     4.显示查找序号的应用   ***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $****    0. 退出系统并销毁队   ****$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t--------------------------------------\n");
		printf("\t\t**************************************\n");
		printf("请输入选择操作的编号：\n");
		select = getchar();
		getchar();
		system("cls");
		switch (select)
		{
		case'1':
			menu2();
			break;
		case'2'://2.不同排序在小数据量下的用时
			int* a;
			a = NULL;
			SortTime(a, 100, 100 * 1000);
			break;
		case '3': //3.显示颜色排序的应用
			a = NULL;
			int len;
			bool ERROR;
			printf("请输入长度\n");
			isSCANFsuccess(ERROR, len);
			Color(a, len);
			break;
		case'4':
			a = NULL;
			printf("请输入长度\n");
			isSCANFsuccess(ERROR, len);
			NUM(a, len);
			break;
		case'0':
			printf("退出成功\n");
			return;
			break;
		default:
			printf("%c", select);
			printf("输入错误，请重新输入\n");
			break;
		}
		system("pause");

	}
}

void menu2()
{
	char select;
	while (1)
	{
		system("cls");
		printf("\t\t***************  操作1 ***************\n");
		printf("\t\t--------------------------------------\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***1. 排序在10000个数据下的用时***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***2. 排序在50000个数据下的用时***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $***3.排序在200000个数据下的用时***$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t $****        0. 查看结束       ****$\n");
		printf("\t\t $**********************************$\n");
		printf("\t\t--------------------------------------\n");
		printf("\t\t**************************************\n");
		printf("请输入选择操作的编号：\n");
		select = getchar();
		getchar();
		system("cls");
		switch (select)
		{
		case'1'://1. 排序在10000个数据下的用时
			int *a;
			a = NULL;
			SortTime(a, 10000);
			system("pause");
			break;
		case'2'://2. 排序在50000个数据下的用时
			a = NULL;
			SortTime(a, 50000);
			system("pause");
			break;
		case'3'://3.排序在200000个数据下的用时
			a = NULL;
			SortTime(a, 200000);
			system("pause");
			break;
		case'0':
			return;
		default:
			printf("%c", select);
			printf("输入错误，请重新输入\n");
			break;
		}
	}

}

void SortTime(int* a, int size,int epoch)//计算时间用
{
	a = (int*)malloc(sizeof(int) * size);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	FILE* fp = NULL;
	fopen_s(&fp, "sort.txt", "w");
	for (int i = 0; i < size; i++)//写入文件
	{
		fprintf(fp, "%d ", a[i]);
	}
	
	clock_t start_time, end_time;
	start_time = clock();//开始时间
	for (int i = 0; i < epoch; i++)
	{
		insertSort(a, size);
	}
	
	end_time = clock();//结束时间
	printf("插入排序时间：%lf\n", (double)(end_time - start_time));
	for (int i = 0; i < size; i++)//随机初始化
	{
		fscanf_s(fp, "%d", &a[i]);
	}
	start_time = clock();//开始时间
	for (int i = 0; i < epoch; i++)
	{
		MergeSort(a, 0, size - 1,a);
	}
	
	end_time = clock();//结束时间
	printf("归并排序时间：%lf\n", (double)(end_time - start_time));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	start_time = clock();//开始时间
	for (int i = 0; i < epoch; i++)
	{
		QuickSort_Recursion(a, 0, size - 1);
	}
	end_time = clock();//结束时间
	printf("快速排序时间：%lf\n", (double)(end_time - start_time));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	start_time = clock();//开始时间
	
	for (int i = 0; i < epoch; i++)
	{
		CountSort(a, size, size);
	}
	end_time = clock();//结束时间
	printf("计数排序时间：%lf\n", (double)(end_time - start_time));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	start_time = clock();//开始时间
	for (int i = 0; i < epoch; i++)
	{
		RadixCountSort(a, size);
	}
	end_time = clock();//结束时间
	printf("基数排序时间：%lf\n", (double)(end_time - start_time));
	fclose(fp);
	free(a);
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
void copy(int* a, int* b, int len)//实现数组复制
{
	for (int i = 0; i < len; i++)
	{
		a[i] = b[i];
	}
}
void Color(int* a, int size)//颜色排序实现
{
	a = (int*)malloc(sizeof(int) * size);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % 3;
	}
	printf("排序前：\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	ColorSort(a, size);
	printf("排序后：\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}
void NUM(int* a, int size)//查找第K位
{
	a = (int*)malloc(sizeof(int) * size);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int K;
	bool ERROR;
	int num;//存放第K大的值
	printf("请输入要查找第几大的数据：\n");
	while(1)
	{ isSCANFsuccess(ERROR, K);
		if (K <= size)
		{
		num=FindNum(a, K - 1, 0, size - 1);
		printf("第%d大的元素为：%d\n", K, num);
		return;
		}
		printf("超出数组长度，请重新输入\n");
	}	
}
void Create(int* a, int size)
{
	a = (int*)malloc(sizeof(int) * size);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)//随机初始化
	{
		a[i] = rand() % size;
	}
	FILE* fp = NULL;
	fopen_s(&fp ,"sort.txt", "w");
	for (int i = 0; i < size; i++)//写入文件
	{
		fprintf(fp, "%d ", a[i]);
	}
	fclose(fp);
}
#endif // ! MENU_C_INCLUDE