#ifndef SORT_C_INCLUDE
#define SORT_C_INCLUDE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"
#include<string.h>
#include"LinkStack.h"
#define MAXSIZE 2000000
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n)
{
	
	int i, j;
	int temp;
	for (i = 0; i < n; i++)
	{
		if (a[i] < a[i - 1]) /* 需将L->r[i]插入有序子表 */
		{
			temp = a[i]; /* 设置哨兵 */
			for (j = i - 1; a[j] > temp; j--)
				a[j + 1] = a[j]; /* 记录后移 */
			a[j + 1] = temp; /* 插入到正确位置 */
		}
	}	
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int j, k, l;
	for (j = mid + 1, k = begin; begin<= mid && j <= end; k++)	/* 将a中记录由小到大地并入temp */
	{
		if (a[begin] < a[j])
			temp[k] = a[begin++];
		else
			temp[k] = a[j++];
	}
	if (begin <= mid)
	{
		for (l = 0; l <= mid - begin; l++)
			temp[k + l] = a[begin + l];		/* 将剩余的a[begin..mid]复制到temp */
	}
	if (j <= end)
	{
		for (l = 0; l <= end - j; l++)
			temp[k + l] = a[j + l];		/* 将剩余的a[j..end]复制到temp */
	}
}



/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp)
{
	int mid;
	int *temp2;
	temp2 = (int*)malloc(MAXSIZE);
	if (begin == end)
		temp[begin] = a[begin];
	else
	{
		mid = (begin + end) / 2;				/* 将a[begin..end]平分为a[begin...m]和a[mid+1...end] */
		MergeSort(a, begin, mid, temp2);		/* 递归地将a[begin..mid]归并为有序的temp2[begin..mid */
		MergeSort(a, mid + 1, end, temp2);	/* 递归地将a[mid+1..t]归并为有序的temp2[m+1..end] */
		MergeArray(temp2, begin, mid, end, temp);	/* 将temp2[begin..mid]和temp2[mid+1..end]归并到temp[begin..end] */

	}
	free(temp2);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int pivot;
	if ((end - begin) > 7)
	{
		pivot = Partition(a, begin, end); /*  将a[begin..end]一分为二，算出枢轴值pivot */
		QuickSort_Recursion(a, begin, pivot - 1);		/*  对低子表递归排序 */
		QuickSort_Recursion(a, pivot + 1, end);		/*  对高子表递归排序 */
	}
	else
		insertSort(a, end - begin + 1);
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size)
{
	LinkStack s;
	int pivot;
	int begin = 0;
	int end = 0;
	initLStack(&s);
	pushLStack(&s, 0);
	pushLStack(&s, size);
	while (!isEmptyLStack(&s))
	{
		popLStack(&s, &end);
		popLStack(&s, &begin);
		pivot = Partition(a, begin, end - 1);
		if ((end - begin) > pivot + 1)
		{
			pushLStack(&s, pivot + 1);
			pushLStack(&s, end - begin);
		}
		if (pivot > 0)
		{
			pushLStack(&s, 0);
			pushLStack(&s, pivot);
		}
	}
	destroyLStack(&s);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end)
{
	int pivotkey;

	int mid = (begin + end) / 2; /* 计算数组中间的元素的下标 */
	if (a[begin] > a[end])/* 交换左端与右端数据，保证左端较小 */
	{
		int temp;
		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
	}
	if (a[mid] > a[end])/* 交换中间与右端数据，保证中间较小 */
	{
		int temp;
		temp = a[mid];
		a[mid] = a[end];
		a[end] = temp;
	}
	
	if (a[mid] > a[begin])/* 交换中间与左端数据，保证左端较小 */
	{
		int temp;
		temp = a[mid];
		a[mid] = a[begin];
		a[begin] = temp;
	}
	pivotkey = a[begin]; /* 用子表的第一个记录作枢轴记录 */
	int start= pivotkey;  /* 将枢轴关键字备份到start */
	while (begin < end) /*  从表的两端交替地向中间扫描 */
	{
		while (begin < end && a[end] >= pivotkey)
			end--;
		a[begin] = a[end];
		while (begin < end&& a[begin] <= pivotkey)
			begin++;
		a[end] = a[begin];
	}
	a[begin] = start;/*中间位置*/
	return begin; /* 返回枢轴所在位置 */
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
	int* b, * c;
	int i;
	c = (int*)malloc(sizeof(int) * (max+1));/*临时数组，大小是待排序序列中值最大的那个*/
	b = (int*)malloc(sizeof(int) * size);/*存放排序结果的数组*/
	for (i = 0; i <= max; i++)
		c[i] = 0;
	for (i = 0; i < size; i++)
		c[a[i]]++;/*统计*/
	for ( i = 1; i <= max; i++)
	{
		c[i] = c[i - 1] + c[i];/*确定值为i的元素在c中出现位置*/
	}
	for (i = size - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	for (i = 0; i < size; i++)
		a[i] = b[i];/*返回a数组作为有序序列*/
	free(b);
	free(c);
}
/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	/*利用基数排序为稳定排序特征*/
	if (size < 2)
		return;
	int exp = 1;
	int* buf;/*存放排序结果的数组*/
	buf = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		buf[i] = 0;
	}
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (max <= a[i])
			max = a[i];
	}
	while(max>=exp)
	{ 
		int cnt[10];/*临时数组，大小是十进制的总体数字*/
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < size; i++)/*统计*/
		{
			int digit = (a[i] / exp) % 10;
			cnt[digit]++;
		}
		for (int i = 1; i <= 9; i++)
		{
			cnt[i] += cnt[i-1];/*确定值为i的元素在cnt中出现位置*/
		}
		for (int i = size - 1; i >= 0; i--)
		{
			int digit = (a[i] / exp) % 10;
			buf[cnt[digit] - 1] = a[i];
			cnt[digit]--;
		}
		memcpy(a, buf, sizeof(int) * size);/*返回a数组作为有序序列*/
		exp *= 10;
	}
} 


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	int Zero = 0;//查0
	int p;//遍历
	int One = 0;//查1
	int t = 0;
	for (p = 0; p <size; p++)
	{
		t = a[p];
		a[p] = 2;
		if (t < 2)
		{
			a[One++] = 1;
		}
		if (t == 0)
		{
			a[Zero++] = 0;
		}
	}
}

/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int FindNum(int *a,int k,int begin,int end)
{
	int pivot;
	pivot = Partition(a, begin, end);
	if (k == pivot)
		return a[k];
	else if (k < pivot)
		FindNum(a, k, begin, pivot - 1);
	else if (k > pivot)
		FindNum(a,k, pivot+1, end);
}
#endif//SORT_C_INCLUDE