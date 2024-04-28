#include"manager.h"
using namespace std;

// ����
void showComputerRoom();	// չʾ������Ϣ


// Ĭ�Ϲ���
Manager::Manager()
{

}


// �вι��죨����Ա���������룩
Manager::Manager(std::string name, std::string pwd)
{
	// ��ʼ����������
	this->m_Name = name;
	this->m_Password = pwd;

	// ��ʼ������
	this->initVector();
}


// ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << endl;
	cout << "\t--------------------------\n";
	cout << "\t|                        |\n";
	cout << "\t|        1.����˺�      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        2.�鿴�˺�      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        3.�鿴����      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        4.���ԤԼ      |\n";
	cout << "\t|                        |\n";
	cout << "\t|        0.�˳���¼      |\n";
	cout << "\t--------------------------\n";
	cout << "\n����������ѡ��";
}


// ����û�
void Manager::addUser()
{
	int select = 0;
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	cout << ">>> ";
	cin >> select;

	ofstream file;		// ����һ��������ļ�����
	string fileName;	// �ļ���������ѧ���ļ�����ʦ�ļ���Ҫ��
	string tip;			// ѧ������ʦ����ʾ��Ϣ
	int id;				// ѧ�� �� ְ�����
	string name;		// �û���
	string pwd;			// ְ�����
	string errorTip;	// ������ʾ

	// �����û���ѡ��ȷ����ͬ���ļ�������ʾ��Ϣ
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ������ظ�������������";
	}

	// ��ȡ�û�����Ϣ
	while (true)
	{
		cout << endl << endl << tip;
		cin >> id;
		bool ret = this->isExist(id, select);
		if (ret) { cout << errorTip << endl; }
		else { break; }
	}
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;

	// ���ļ�
	file.open(fileName, ios::out | ios::app);

	// ���������뵽�ļ���
	file << id << " " << name << " " << pwd << endl;

	// �����ʾ��Ϣ
	cout << "��ӳɹ�" << endl;

	// ������������
	this->initVector();

	// �ر��ļ�
	file.close();
}


// ��ʾ�˺� (��ͨ����)
void printStudent(Student& s)
{
	cout << "|   ѧ�ţ�" << s.m_Id << "   ������" << s.m_Name << "   ���룺" << s.m_Password << endl;
}
void printTeacher(Teacher& t)
{
	cout << "|   ְ����ţ�" << t.m_EmpId << "   ������" << t.m_Name << "   ���룺" << t.m_Password << endl;
}


// �鿴�û�
void Manager::showUser()
{
	int select = 0;
	cout << "��ѡ��鿴������" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	cout << ">>> ";
	cin >> select;

	if (select == 1)
	{
		cout << "\n����ѧ����Ϣ���£�\n" << endl;
		cout << "-------------------------------------------" << endl;
		for_each(vStudent.begin(), vStudent.end(), printStudent);
		cout << "-------------------------------------------" << endl;
		cout << endl;
	}
	else
	{
		cout << "\n������ʦ��Ϣ���£�\n" << endl;
		cout << "-------------------------------------------" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
		cout << "-------------------------------------------" << endl;
		cout << endl;
	}
}


// �鿴����
void Manager::showComputer()
{
	// ����ȫ�ֺ�������չʾ����
	showComputerRoom();
}


// ���ԤԼ��¼
void Manager::cleanFile()
{
	// �����ļ���������󣬲���trunc��ʽ��(�ص㣺ÿ�δ򿪶�������ļ�)
	ofstream file(ORDER_FILE, ios::trunc);		// ����������ԣ����ﵽ����ļ���Ŀ��
	file.close();	// �ر��ļ�

	cout << "��ռ�¼�ɹ�!" << endl << endl;
}


// ��ʼ������
void Manager::initVector()
{
	// �����ļ�����������
	ifstream file;

	// ---------------- ��ȡѧ���ļ��е���Ϣ ----------------
	file.open(STUDENT_FILE, ios::in);
	// ������ܶ�ȡ
	if (!file.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	// ������Զ�ȡ
	vStudent.clear();	// �������
	Student s;
	while (file >> s.m_Id && file >> s.m_Name && file >> s.m_Password)
	{
		vStudent.push_back(s);
	}
	file.close();

	// ---------------- ��ȡ��ʦ�ļ��е���Ϣ ----------------
	file.open(TEACHER_FILE, ios::in);
	// ������ܶ�ȡ
	if (!file.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	// ������Զ�ȡ
	vTeacher.clear();	// �������
	Teacher t;
	while (file >> t.m_EmpId && file >> t.m_Name && file >> t.m_Password)
	{
		vTeacher.push_back(t);
	}
	file.close();
}


// �û��Ƿ����
bool Manager::isExist(int id, int type)
{
	if (type == 1)
	{
		// �ж�ѧ���Ƿ��Ѿ�����
		for (vector<Student>::iterator iterator = vStudent.begin(); iterator != vStudent.end(); iterator++)
		{
			if (id == iterator->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		// �ж���ʦ�Ƿ��Ѿ�����
		for (vector<Teacher>::iterator iterator = vTeacher.begin(); iterator != vTeacher.end(); iterator++)
		{
			if (id == iterator->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
