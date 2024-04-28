#include<iostream>
#include<fstream>

#include"globalFile.h"

#include"manager.h"
#include"teacher.h"
#include"student.h"

using namespace std;



// 全局函数-声明
void showMainMenu();
void exitSystem();
void showComputerRoom();	// 展示机房信息
void login(string, int);
void managerMenu(Identity*&);
void studentMenu(Identity*&);
void teacherMenu(Identity*&);


// 程序入口
int main()
{
	// 获取用户选择
	int select = 0;

	while (true)
	{
		// 显示主菜单
		showMainMenu();

		// 获取用户选择
		cin >> select;

		// 执行对应功能
		switch (select)
		{
		case 1:		// 学生身份
			login(STUDENT_FILE, 1);
			break;
		case 2:		// 老师身份
			login(TEACHER_FILE, 2);
			break;
		case 3:		// 管理员身份
			login(ADMIN_FILE, 3);
			break;
		case 0:		// 退出系统
			exitSystem();
			break;
		default:
			cout << "\n选择错误，请重新选择！\n" << endl;
			break;
		}

		// 暂停让用户观看执行结果，观看完毕后清屏幕
		cout << endl << endl;
		system("pause");
		system("cls");
	}
}



// 全局函数-实现
// 显示主菜单
void showMainMenu()
{
	cout << "==================== 欢迎使用机房预约系统 ====================" << endl;
	cout << endl << "您的身份是？" << endl;
	cout << "\t ----------------------------------------\n";
	cout << "\t |					|\n";
	cout << "\t |		1. 学生代表		|\n";
	cout << "\t |					|\n";
	cout << "\t |		2. 老师	 		|\n";
	cout << "\t |					|\n";
	cout << "\t |		3. 管理员		|\n";
	cout << "\t |					|\n";
	cout << "\t |		0. 退出			|\n";
	cout << "\t |					|\n";
	cout << "\t ----------------------------------------\n";
	cout << "请输入您的选择：";
}


// 退出系统
void exitSystem()
{
	cout << "\n欢迎下次使用\n\n";
	system("pause");
	exit(0);
}


// 展示机房信息
void showComputerRoom()
{
	// 创建文件输入流对象，并打开它
	ifstream file(COMPUTERROOM, ios::in);

	// 如果不能读取数据
	if (!file.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	// 如果可以读取数据
	int id;
	int capacity;
	cout << "\n机房信息如下：\n" << endl;
	cout << "-------------------------------------------" << endl;
	while (file >> id && file >> capacity)
	{
		cout << "|   机房编号：" << id << "   机房最大容量：" << capacity << endl;
	}
	cout << "-------------------------------------------" << endl;
	cout << endl;

	// 关闭文件
	file.close();
}


// 登录功能
void login(string fileName, int type)
{
	// 先准备好一个通用的身份指针，可以装下管理员、老师、学生
	Identity* person = NULL;


	// 创建文件输入流对象，以输入的方式打开文件
	ifstream file;
	file.open(fileName, ios::in);


	// 文件不存在，直接结束
	if (!file.is_open())
	{
		cout << "文件不存在" << endl;
		file.close();
		return;
	}


	// 文件存在，执行更多操作
	// 1. 获取登录信息
	int id = 0;
	string name;
	string pwd;

	// --- 学生、老师都有id，管理员没有id
	if (type == 1)	// 学生登录
	{
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2)	// 教师登录
	{
		cout << "请输入你的职工号：";
		cin >> id;
	}

	// --- 学生、老师、管理员都有用户名和密码
	cout << "请输入用户名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;


	// 2. 进行登录验证
	int fId;			// 从文件中读取保存的id
	string fName;		// 从文件中读取保存的用户名
	string fPwd;		// 从文件中读取保存的密码
	if (type == 1)
	{
		// 学生登录验证
		while (file >> fId && file >> fName && file >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// 提示信息
				cout << "登录成功！" << endl << endl;

				// 实例化一个学生
				person = new Student(id, name, pwd);

				// 进入学生的子菜单
				system("pause");	// 让用户看清登录的提示信息
				system("cls");		// 清空主菜单显示的内容
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师登录验证
		while (file >> fId && file >> fName && file >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// 提示信息
				cout << "登录成功！" << endl << endl;

				// 实例化一个老师
				person = new Teacher(id, name, pwd);

				// 进入老师的子菜单
				system("pause");	// 让用户看清登录的提示信息
				system("cls");		// 清空主菜单显示的内容
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		// 管理员登录验证
		while (file >> fName && file >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				// 提示信息
				cout << "登录成功！" << endl << endl;

				// 实例化一个管理员
				person = new Manager(name, pwd);

				// 进入管理员的子菜单
				system("pause");	// 让用户看清登录的提示信息
				system("cls");		// 清空主菜单显示的内容
				managerMenu(person);

				return;
			}
		}
	}

	file.close();
	cout << "登录验证失败！" << endl;
}


// 管理员菜单
void managerMenu(Identity*& manager)
{
	// 将父类的指针强行转换为子类的指针
	// 原因：不强行转换的话，只能调用子类和父类都有的公共接口，而不能使用自己独有的功能
	Manager* man = (Manager*)manager;

	while (true)
	{
		// 1. 显示管理员菜单
		manager->operMenu();

		// 2. 获取用户选择，然后根据用户的选择，执行具体的功能

		// 获取用户选择
		int select = 0;
		cin >> select;

		// 执行具体功能
		if (select == 1)
		{
			system("cls");
			cout << "\t\t<<< 添加账号 >>>\n" << endl;
			man->addUser();
		}
		else if (select == 2)
		{
			system("cls");
			cout << "\t\t<<< 查看账号 >>>\n" << endl;
			man->showUser();
		}
		else if (select == 3)
		{
			system("cls");
			cout << "\t\t<<< 查看机房 >>>\n" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			system("cls");
			cout << "\t\t<<< 清空预约 >>>\n" << endl;
			man->cleanFile();
		}
		else
		{
			system("cls");
			delete manager;
			cout << "\n\t\t你已成功退出登录!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}


// 学生菜单
void studentMenu(Identity*& student)
{
	// 将父类的指针强行转换为子类的指针
	// 原因：不强行转换的话，只能调用子类和父类都有的公共接口，而不能使用自己独有的功能
	Student* stu = (Student*)student;

	while (true)
	{
		// 1. 显示学生菜单
		stu->operMenu();

		// 2. 获取用户选择，然后根据用户的选择，执行具体的功能

		// 获取用户选择
		int select = 0;
		cin >> select;

		// 执行具体功能
		if (select == 1)
		{
			system("cls");
			cout << "\t\t<<< 申请预约 >>>\n" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			system("cls");
			cout << "\t\t<<< 我的预约 >>>\n" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			system("cls");
			cout << "\t\t<<< 所有预约 >>>\n" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			system("cls");
			cout << "\t\t<<< 取消预约 >>>\n" << endl;
			stu->cancelOrder();
		}
		else
		{
			system("cls");
			delete stu;
			cout << "\n\t\t你已成功退出登录!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}


// 教师菜单
void teacherMenu(Identity*& teacher)
{
	// 将父类的指针强行转换为子类的指针
	// 原因：不强行转换的话，只能调用子类和父类都有的公共接口，而不能使用自己独有的功能
	Teacher* tea = (Teacher*)teacher;

	while (true)
	{
		// 展示菜单内容
		tea->operMenu();

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 查看所有预约
			system("cls");
			cout << "\t\t<<< 所有预约 >>>\n" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			// 审核预约
			system("cls");
			cout << "\t\t<<< 审核预约 >>>\n" << endl;
			tea->validOrder();
		}
		else
		{
			system("cls");
			delete tea;
			cout << "\n\t\t你已成功退出登录!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}