#include"orderFile.h"
using namespace std;


// 数据初始化，将文件中的数据，读入到map容器中
void OrderFile::initData()
{
	// 创建文件输入流对象，并打开文件
	ifstream file(ORDER_FILE, ios::in);

	string date;		// 日期
	string interval;	// 时间段
	string stuId;		// 学生编号
	string stuName;		// 学生姓名
	string roomId;		// 机房编号
	string status;		// 预约状态

	// 大map容器中的数据个数
	this->m_Size = 0;

	// 为下面的循环准备
	int pos;
	string key;
	string value;
	map<string, string> m;

	// 将文件的每一行数据，拆解成一个个键值对的格式，存入到map中
	// 数据格式：date:2 interval:2 stuId:1001 stuName:张三 roomId:3 status:1
	while (file >> date && file >> interval && file >> stuId && file >> stuName && file >> roomId && file >> status)
	{
		// 每次读取前，先清空(重置)小map容器 m
		m.clear();

		// date 数据处理
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// interval 数据处理
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// stuId 数据处理
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// stuName 数据处理
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// roomId 数据处理
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// status 数据处理
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));	// 键值对 放入到小map容器中
		}

		// 每循环一次，代表小map容器中，装下了一行的"键值对"数据，我们将小map容器放入到大map容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));

		// 记录大map容器中的内容个数
		this->m_Size++;
	}

	// 循环结束，读取文件数据完毕，关闭文件
	file.close();
}


// 构造函数
OrderFile::OrderFile()
{
	// 将文件中的数据，读入到map容器中
	initData();
}


// 更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)	return;

	// 创建文件输出流对象，并打开文件
	ofstream file(ORDER_FILE, ios::out | ios::trunc);

	// 向文件输入数据：来自内存中最新的数据
	for (int i = 0; i < m_Size; i++)
	{
		file << "date:" << this->m_orderData[i]["date"] << " ";
		file << "interval:" << this->m_orderData[i]["interval"] << " ";
		file << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		file << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		file << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		file << "status:" << this->m_orderData[i]["status"] << endl;
	}

	// 关闭文件
	file.close();
}