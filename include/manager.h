#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"


// ��������
class Manager :public Identity
{
public:
	// ѧ�������������洢��ѧ���ļ��ж�ȡ��ѧ������
	std::vector<Student> vStudent;

	// ��ʦ�����������洢����ʦ�ļ��ж�ȡ����ʦ����
	std::vector<Teacher> vTeacher;

	// Ĭ�Ϲ���
	Manager();

	// �вι��죨����Ա���������룩
	Manager(std::string, std::string);

	// ѡ��˵�
	void operMenu();

	// ����û�
	void addUser();

	// �鿴�û�
	void showUser();

	// �鿴����
	void showComputer();

	// ���ԤԼ��¼
	void cleanFile();

	// ��ʼ������
	void initVector();

	// �û��Ƿ����
	bool isExist(int, int);
};