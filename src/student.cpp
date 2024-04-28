#include"student.h"
using namespace std;


// 默认函数
Student::Student()
{

}


// 有参构造
Student::Student(int id, std::string name, std::string pwd)
{
	// 初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = pwd;
}


// 菜单界面
void Student::operMenu()
{
	cout << "欢迎学生：" << this->m_Name << endl;
	cout << "\t----------------------------\n";
	cout << "\t|                          |\n";
	cout << "\t|        1.申请预约        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        2.查看我的预约    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        3.查看所有预约    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        4.取消预约        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        0.退出登录        |\n";
	cout << "\t----------------------------\n";
	cout << "请输入您的选择：";
}


// 申请预约
void Student::applyOrder()
{
	// 获取数据
	cout << "机房开放时间为周一到周五" << endl;
	cout << "\n请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;		// 时间
	int interval = 0;	// 间隔
	int room = 0;		// 机房号

	while (true)
	{
		cout << ">>> ";
		cin >> date;
		if (date >= 1 && date <= 5) { break; }
		cout << "输入有误，请重新输入" << endl << endl;
	}

	cout << "\n请输入选择预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true)
	{
		cout << ">>> ";
		cin >> interval;
		if (interval >= 1 && interval <= 2) { break; }
		cout << "输入有误，请重新输入" << endl << endl;
	}

	cout << "\n请选择机房：" << endl;
	cout << "1.一号机房" << endl;
	cout << "2.二号机房" << endl;
	cout << "3.三号机房" << endl;

	while (true)
	{
		cout << ">>> ";
		cin >> room;
		if (room >= 1 && room <= 3) { break; }
		cout << "输入有误，请重新输入" << endl << endl;
	}

	cout << "\n成功提交预约申请！请耐心等待审核\n" << endl;

	// 将数据写入文件
	ofstream file(ORDER_FILE, ios::app);
	file << "date:" << date << " ";
	file << "interval:" << interval << " ";
	file << "stuId:" << this->m_Id << " ";
	file << "stuName:" << this->m_Name << " ";
	file << "roomId:" << room << " ";
	file << "status:" << 1 << endl;
	file.close();
}


// 查看我的预约
void Student::showMyOrder()
{
	// 实例化一个预约文件管理对象
	OrderFile orderFileManager;

	// 如果orderFileManager里面的m_Size为零，说明里面只有零条数据（即：无数据）
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n无预约记录\n" << endl;
		return;
	}

	// 如果有数据，展示出来
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		// 如果id匹配的上，说明是自己的数据，可以输出
		if (atoi(orderFileManager.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期：星期" << orderFileManager.m_orderData[i]["date"];
			cout << "   时段：" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "   机房：" << orderFileManager.m_orderData[i]["roomId"];

			// 这里的status变量不能放到循环外面，每一次重新定义，起到了初始化清理的作用！
			string status = "  状态：";		// 0 取消预约		1 审核中		2 已预约		-1 预约失败
			
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
}


// 查看所有预约
void Student::showAllOrder()
{
	// 实例化一个预约文件管理对象
	OrderFile orderFileManager;

	// 如果orderFileManager里面的m_Size为零，说明里面只有零条数据（即：无数据）
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n无预约记录\n" << endl;
		return;
	}

	// 如果有数据，展示出来
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：星期" << orderFileManager.m_orderData[i]["date"];
		cout << "   时段：" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "   学号：" << orderFileManager.m_orderData[i]["stuId"];
		cout << "   姓名：" << orderFileManager.m_orderData[i]["stuName"];
		cout << "   机房：" << orderFileManager.m_orderData[i]["roomId"];

		// 这里的status变量不能放到循环外面，每一次重新定义，起到了初始化清理的作用！
		string status = "  状态：";	// 0 取消预约		1 审核中		2 已预约		-1 预约失败

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


// 取消预约
void Student::cancelOrder()
{
	// 实例化一个预约文件管理对象
	OrderFile orderFileManager;

	// 如果orderFileManager里面的m_Size为零，说明里面只有零条数据（即：无数据）
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n无预约记录\n" << endl;
		return;
	}

	cout << "\n温馨提示：处于审核中、预约成功的记录都可以取消！\n" << endl;

	// 用于临时装下数据的真实编号
	vector<int> v;
	v.clear();

	int index = 1;		// index 是展示给用户看的数据中最前面的编号

	// 显示预约记录
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		if (atoi(orderFileManager.m_orderData[i]["stuId"].c_str()) != this->m_Id) { continue; }
		if (orderFileManager.m_orderData[i]["status"] == "1" || orderFileManager.m_orderData[i]["status"] == "2")
		{
			v.push_back(i);		// 文件中实际上的编号
			cout << index++ << "、";
			cout << "预约日期：星期" << orderFileManager.m_orderData[i]["date"];
			cout << "   时段：" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "   机房：" << orderFileManager.m_orderData[i]["roomId"];

			// 这里的status变量不能放到循环外面，每一次重新定义，起到了初始化清理的作用！
			string status = "  状态：";		// 0 取消预约		1 审核中		2 已预约		-1 预约失败

			if (orderFileManager.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (orderFileManager.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			cout << status << endl;
		}
	}


	// 如果文件里面有数据，但是有关与"我的记录"是空
	if (v.size() == 0)
	{
		cout << "\n----< 暂时没有你的预约记录 >----\n" << endl;
		return;
	}

	// 根据用户选择，取消对应记录
	cout << "\n请输入你要取消的记录：(输入0则返回)" << endl;
	int select = 0;
	while (true)
	{
		cout << ">>> ";
		cin >> select;

		if (select < 0 || select > v.size())
		{
			cout << "输入有误，请重新输入" << endl;
			continue;
		}

		if (select == 0) {
			break;
		}
		else
		{
			orderFileManager.m_orderData[v[select - 1]]["status"] = "0";
			orderFileManager.updateOrder();
			cout << "已取消预约" << endl;
			break;
		}
	}
}