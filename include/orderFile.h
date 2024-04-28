#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include"globalFile.h"

class OrderFile
{
public:
	// ��¼������ key --- ��¼������	value --- �����¼�ļ�ֵ����Ϣ
	std::map<int, std::map<std::string, std::string>> m_orderData;

	// ԤԼ��¼����
	int m_Size;

	// ���캯��
	OrderFile();

	// ���ݳ�ʼ�������ļ��е����ݣ����뵽map������
	void initData();

	// ����ԤԼ��¼
	void updateOrder();
};