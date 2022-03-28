#pragma once
#ifndef MENU_H_INCLUDE
#define MENU_H_INCLUDE
/*声明函数实际，实现在MENU.cpp中*/
void Menu();/*界面*/
bool isSCANFsuccess(bool& isERROR, int& input);//检查输入是否有误&&处理非法输入
void CreatStack(LinkStack* s);//1.创建新栈
void TraverseStack(LinkStack s, void(*visit)(ElemType e));/*3.打印当前栈*/
void visit(ElemType e);

#endif // !MENU_H_INCLUDE
