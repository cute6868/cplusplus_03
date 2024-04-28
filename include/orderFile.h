#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"globalFile.h"

class OrderFile
{
public:
	// 记录的容器 key --- 记录的条数	value --- 具体记录的键值对信息
	std::map<int, std::map<std::string, std::string>> m_orderData;

	// 预约记录条数
	int m_Size;

	// 构造函数
	OrderFile();

	// 数据初始化，将文件中的数据，读入到map容器中
	void initData();

	// 更新预约记录
	void updateOrder();
};