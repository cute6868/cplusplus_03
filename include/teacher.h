#pragma once
#include"identity.h"


// ��ʦ��
class Teacher :public Identity
{
public:
	// ��ʦ���
	int m_EmpId;

	// Ĭ�Ϲ���
	Teacher();

	// ���ι��죨ְ����š����������룩
	Teacher(int empId, std::string name, std::string pwd);

	// �˵�����
	void operMenu();

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void validOrder();
};