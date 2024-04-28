#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

#include"globalFile.h"
#include"orderFile.h"


// 抽象出一个身份类
class Identity
{
public:
	// 操作菜单（纯虚函数）
	virtual void operMenu() = 0;

	std::string m_Name;		// 用户名
	std::string m_Password;	// 密码
};