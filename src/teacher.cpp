#include"teacher.h"
using namespace std;


// Ĭ�Ϲ���
Teacher::Teacher()
{

}


// ���ι��죨ְ����š����������룩
Teacher::Teacher(int empId, std::string name, std::string pwd)
{
	// ��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}


// �˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << endl;
	cout << "\t----------------------------\n";
	cout << "\t|                          |\n";
	cout << "\t|        1.�鿴����ԤԼ    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        2.���ԤԼ        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        0.�˳���¼        |\n";
	cout << "\t----------------------------\n";
	cout << "����������ѡ��";
}


// �鿴����ԤԼ
void Teacher::showAllOrder()
{
	// ����һ��"ԤԼ�ļ�������"����
	OrderFile orderFileManager;

	// ������¼
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n��ԤԼ��¼\n" << endl;
		return;
	}

	// ����������¼
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ�����" << orderFileManager.m_orderData[i]["date"];
		cout << "   ʱ�Σ�" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "   ѧ�ţ�" << orderFileManager.m_orderData[i]["stuId"];
		cout << "   ������" << orderFileManager.m_orderData[i]["stuName"];
		cout << "   ������" << orderFileManager.m_orderData[i]["roomId"];

		string status = "   ״̬��";		// ���в��ܷŵ����棬ÿ��ѭ�������õ�����

		if (orderFileManager.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (orderFileManager.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (orderFileManager.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl << endl;
	}
}


// ���ԤԼ
void Teacher::validOrder()
{
	// ����һ��"ԤԼ�ļ�"�������
	OrderFile orderFileManager;

	// ������¼
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n��ԤԼ��¼\n" << endl;
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl << endl;

	vector<int> v;		// ��ʱװ��ÿһ�����ݵ���ʵ���

	int index = 1;

	// ��ʾ����˵�ԤԼ��Ϣ
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		if (orderFileManager.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);		// ��¼��ʵ���
			cout << index++ << "��";
			cout << "ԤԼ���ڣ�����" << orderFileManager.m_orderData[i]["date"];
			cout << "   ʱ�Σ�" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "   ������" << orderFileManager.m_orderData[i]["roomId"];

			string status = "   ״̬��";		// ���в��ܷŵ����棬ÿ��ѭ�������õ�����

			if (orderFileManager.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl << endl;
		}
	}

	// �����û�ѡ������ݣ�ִ�ж�Ӧ�Ĺ���
	int select = 0;
	int res = 0;
	cout << "��������˵�ԤԼ��¼����0�����أ�" << endl;
	while (true)
	{
		cout << ">>> ";
		cin >> select;
		if (select < 0 || select > v.size())
		{
			cout << "\n������������������\n" << endl;
			continue;
		}
		if (select == 0)	break;
		else
		{
			cout << "��������˽��" << endl;
			cout << "1.ͨ��" << endl;
			cout << "2.��ͨ��" << endl;
			cout << ">>> ";
			cin >> res;
		}

		// ִ�����
		if (res == 1) { orderFileManager.m_orderData[v[select - 1]]["status"] = "2"; }
		else { orderFileManager.m_orderData[v[select - 1]]["status"] = "-1"; }

		// �������ݣ�ͬ�����ݵ��ļ�
		orderFileManager.updateOrder();

		// �����ʾ��Ϣ
		cout << "������" << endl << endl;
		break;
	}





}