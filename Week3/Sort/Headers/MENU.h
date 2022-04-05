#ifndef  MENU_H_INCLUDE
#define MENU_H_INCLUDE
void menu();//实现基本操作
void menu2();//实现操作1下操作
void SortTime(int* a, int size, int epoch=1);//计算时间用同时读写文件也在其中进行
void copy(int* a, int* b, int len);//实现数组复制
void Color(int* a, int size);//颜色排序实现
bool isSCANFsuccess(bool& isERROR, int& input);//检查输入是否有误&&处理非法输入(仅仅针对整型）
void NUM(int* a, int size);//查找第K位
void Create(int* a, int size);//同时把它保存在文件中
#endif // ! MENU_H_INCLUDE




#pragma once
