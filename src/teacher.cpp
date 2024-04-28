#include"teacher.h"
using namespace std;


// 默认构造
Teacher::Teacher()
{

}


// 含参构造（职工编号、姓名、密码）
Teacher::Teacher(int empId, std::string name, std::string pwd)
{
	// 初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}


// 菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << endl;
	cout << "\t----------------------------\n";
	cout << "\t|                          |\n";
	cout << "\t|        1.查看所有预约    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        2.审核预约        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        0.退出登录        |\n";
	cout << "\t----------------------------\n";
	cout << "请输入您的选择：";
}


// 查看所有预约
void Teacher::showAllOrder()
{
	// 创造一个"预约文件管理者"对象
	OrderFile orderFileManager;

	// 零条记录
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n无预约记录\n" << endl;
		return;
	}

	// 不是零条记录
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：星期" << orderFileManager.m_orderData[i]["date"];
		cout << "   时段：" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "   学号：" << orderFileManager.m_orderData[i]["stuId"];
		cout << "   姓名：" << orderFileManager.m_orderData[i]["stuName"];
		cout << "   机房：" << orderFileManager.m_orderData[i]["roomId"];

		string status = "   状态：";		// 此行不能放到外面，每次循环起到重置的作用

		if (orderFileManager.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (orderFileManager.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (orderFileManager.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl << endl;
	}
}


// 审核预约
void Teacher::validOrder()
{
	// 创建一个"预约文件"管理对象
	OrderFile orderFileManager;

	// 零条记录
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n无预约记录\n" << endl;
		return;
	}
	cout << "待审核的预约记录如下：" << endl << endl;

	vector<int> v;		// 临时装下每一行数据的真实编号

	int index = 1;

	// 显示待审核的预约信息
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		if (orderFileManager.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);		// 记录真实编号
			cout << index++ << "、";
			cout << "预约日期：星期" << orderFileManager.m_orderData[i]["date"];
			cout << "   时段：" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "   机房：" << orderFileManager.m_orderData[i]["roomId"];

			string status = "   状态：";		// 此行不能放到外面，每次循环起到重置的作用

			if (orderFileManager.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl << endl;
		}
	}

	// 根据用户选择的内容，执行对应的功能
	int select = 0;
	int res = 0;
	cout << "请输入审核的预约记录：（0代表返回）" << endl;
	while (true)
	{
		cout << ">>> ";
		cin >> select;
		if (select < 0 || select > v.size())
		{
			cout << "\n输入有误，请重新输入\n" << endl;
			continue;
		}
		if (select == 0)	break;
		else
		{
			cout << "请输入审核结果" << endl;
			cout << "1.通过" << endl;
			cout << "2.不通过" << endl;
			cout << ">>> ";
			cin >> res;
		}

		// 执行审核
		if (res == 1) { orderFileManager.m_orderData[v[select - 1]]["status"] = "2"; }
		else { orderFileManager.m_orderData[v[select - 1]]["status"] = "-1"; }

		// 更新数据，同步数据到文件
		orderFileManager.updateOrder();

		// 输出提示信息
		cout << "审核完毕" << endl << endl;
		break;
	}





}