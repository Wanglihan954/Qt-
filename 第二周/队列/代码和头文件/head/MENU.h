#pragma once
#define	INT  1
#define	DOUBLE 2
#define	CHAR 3
#define	STRING 4
#define INT_size 4
#define DOUBLE_size 8
#define CHAR_size 1
#define STRING_size 20

; void menu();/*界面*/
bool isSCANFsuccess(bool& isERROR, int& input);//检查输入是否有误&&处理非法输入
void Creat_LQueue(LQueue* Q);//创建队列(多数据入队）
void One_EnLQueue(LQueue* Q);//一个一个入队