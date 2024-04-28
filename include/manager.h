#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"


// 管理者类
class Manager :public Identity
{
public:
	// 学生容器：用来存储从学生文件中读取的学生数据
	std::vector<Student> vStudent;

	// 老师容器：用来存储从老师文件中读取的老师数据
	std::vector<Teacher> vTeacher;

	// 默认构造
	Manager();

	// 有参构造（管理员姓名、密码）
	Manager(std::string, std::string);

	// 选择菜单
	void operMenu();

	// 添加用户
	void addUser();

	// 查看用户
	void showUser();

	// 查看机房
	void showComputer();

	// 清空预约记录
	void cleanFile();

	// 初始化容器
	void initVector();

	// 用户是否存在
	bool isExist(int, int);
};