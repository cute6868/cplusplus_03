#include"manager.h"
using namespace std;

// 声明
void showComputerRoom();	// 展示机房信息


// 默认构造
Manager::Manager()
{

}


// 有参构造（管理员姓名、密码）
Manager::Manager(std::string name, std::string pwd)
{
	// 初始化对象属性
	this->m_Name = name;
	this->m_Password = pwd;

	// 初始化容器
	this->initVector();
}


// 选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << endl;
	cout << "\t--------------------------\n";
	cout << "\t|                        |\n";
	cout << "\t|        1.添加账号      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        2.查看账号      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        3.查看机房      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        4.清空预约      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        0.退出登录      |\n";
	cout << "\t--------------------------\n";
	cout << "\n请输入您的选择：";
}


// 添加用户
void Manager::addUser()
{
	int select = 0;
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	cout << ">>> ";
	cin >> select;

	ofstream file;		// 创建一个输出流文件对象
	string fileName;	// 文件名，操作学生文件和老师文件需要用
	string tip;			// 学生和老师的提示信息
	int id;				// 学号 或 职工编号
	string name;		// 用户名
	string pwd;			// 职工编号
	string errorTip;	// 错误提示

	// 根据用户的选择，确定不同的文件名和提示信息
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入";
	}

	// 获取用户的信息
	while (true)
	{
		cout << endl << endl << tip;
		cin >> id;
		bool ret = this->isExist(id, select);
		if (ret) { cout << errorTip << endl; }
		else { break; }
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	// 打开文件
	file.open(fileName, ios::out | ios::app);

	// 将数据输入到文件中
	file << id << " " << name << " " << pwd << endl;

	// 输出提示信息
	cout << "添加成功" << endl;

	// 更新容器数据
	this->initVector();

	// 关闭文件
	file.close();
}


// 显示账号 (普通函数)
void printStudent(Student& s)
{
	cout << "|   学号：" << s.m_Id << "   姓名：" << s.m_Name << "   密码：" << s.m_Password << endl;
}
void printTeacher(Teacher& t)
{
	cout << "|   职工编号：" << t.m_EmpId << "   姓名：" << t.m_Name << "   密码：" << t.m_Password << endl;
}


// 查看用户
void Manager::showUser()
{
	int select = 0;
	cout << "请选择查看的内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	cout << ">>> ";
	cin >> select;

	if (select == 1)
	{
		cout << "\n所有学生信息如下：\n" << endl;
		cout << "-------------------------------------------" << endl;
		for_each(vStudent.begin(), vStudent.end(), printStudent);
		cout << "-------------------------------------------" << endl;
		cout << endl;
	}
	else
	{
		cout << "\n所有老师信息如下：\n" << endl;
		cout << "-------------------------------------------" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
		cout << "-------------------------------------------" << endl;
		cout << endl;
	}
}


// 查看机房
void Manager::showComputer()
{
	// 调用全局函数——展示机房
	showComputerRoom();
}


// 清空预约记录
void Manager::cleanFile()
{
	// 创建文件输出流对象，并以trunc方式打开(特点：每次打开都是清空文件)
	ofstream file(ORDER_FILE, ios::trunc);		// 借助这个特性，来达到清空文件的目的
	file.close();	// 关闭文件

	cout << "清空记录成功!" << endl << endl;
}


// 初始化容器
void Manager::initVector()
{
	// 创建文件输入流对象
	ifstream file;

	// ---------------- 读取学生文件中的信息 ----------------
	file.open(STUDENT_FILE, ios::in);
	// 如果不能读取
	if (!file.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	// 如果可以读取
	vStudent.clear();	// 清空容器
	Student s;
	while (file >> s.m_Id && file >> s.m_Name && file >> s.m_Password)
	{
		vStudent.push_back(s);
	}
	file.close();

	// ---------------- 读取老师文件中的信息 ----------------
	file.open(TEACHER_FILE, ios::in);
	// 如果不能读取
	if (!file.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	// 如果可以读取
	vTeacher.clear();	// 清空容器
	Teacher t;
	while (file >> t.m_EmpId && file >> t.m_Name && file >> t.m_Password)
	{
		vTeacher.push_back(t);
	}
	file.close();
}


// 用户是否存在
bool Manager::isExist(int id, int type)
{
	if (type == 1)
	{
		// 判断学生是否已经存在
		for (vector<Student>::iterator iterator = vStudent.begin(); iterator != vStudent.end(); iterator++)
		{
			if (id == iterator->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		// 判断老师是否已经存在
		for (vector<Teacher>::iterator iterator = vTeacher.begin(); iterator != vTeacher.end(); iterator++)
		{
			if (id == iterator->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
