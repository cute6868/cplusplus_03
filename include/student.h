#pragma once
#include"identity.h"


// 学生类
class Student :public Identity
{
public:
	// 学生学号
	int m_Id;

	// 默认函数
	Student();

	// 有参构造（学号、姓名、密码）
	Student(int id, std::string name, std::string pwd);

	// 菜单界面
	void operMenu();

	// 申请预约
	void applyOrder();

	// 查看我的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();
};