#pragma once
#include"identity.h"


// ѧ����
class Student :public Identity
{
public:
	// ѧ��ѧ��
	int m_Id;

	// Ĭ�Ϻ���
	Student();

	// �вι��죨ѧ�š����������룩
	Student(int id, std::string name, std::string pwd);

	// �˵�����
	void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴�ҵ�ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();
};