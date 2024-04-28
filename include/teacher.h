#pragma once
#include"identity.h"


// 老师类
class Teacher :public Identity
{
public:
	// 教师编号
	int m_EmpId;

	// 默认构造
	Teacher();

	// 含参构造（职工编号、姓名、密码）
	Teacher(int empId, std::string name, std::string pwd);

	// 菜单界面
	void operMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();
};