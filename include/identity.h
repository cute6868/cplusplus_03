#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

#include"globalFile.h"
#include"orderFile.h"


// �����һ�������
class Identity
{
public:
	// �����˵������麯����
	virtual void operMenu() = 0;

	std::string m_Name;		// �û���
	std::string m_Password;	// ����
};