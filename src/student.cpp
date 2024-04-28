#include"student.h"
using namespace std;


// Ĭ�Ϻ���
Student::Student()
{

}


// �вι���
Student::Student(int id, std::string name, std::string pwd)
{
	// ��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = pwd;
}


// �˵�����
void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_Name << endl;
	cout << "\t----------------------------\n";
	cout << "\t|                          |\n";
	cout << "\t|        1.����ԤԼ        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        2.�鿴�ҵ�ԤԼ    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        3.�鿴����ԤԼ    |\n";
	cout << "\t|                          |\n";
	cout << "\t|        4.ȡ��ԤԼ        |\n";
	cout << "\t|                          |\n";
	cout << "\t|        0.�˳���¼        |\n";
	cout << "\t----------------------------\n";
	cout << "����������ѡ��";
}


// ����ԤԼ
void Student::applyOrder()
{
	// ��ȡ����
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "\n����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;		// ʱ��
	int interval = 0;	// ���
	int room = 0;		// ������

	while (true)
	{
		cout << ">>> ";
		cin >> date;
		if (date >= 1 && date <= 5) { break; }
		cout << "������������������" << endl << endl;
	}

	cout << "\n������ѡ��ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		cout << ">>> ";
		cin >> interval;
		if (interval >= 1 && interval <= 2) { break; }
		cout << "������������������" << endl << endl;
	}

	cout << "\n��ѡ�������" << endl;
	cout << "1.һ�Ż���" << endl;
	cout << "2.���Ż���" << endl;
	cout << "3.���Ż���" << endl;

	while (true)
	{
		cout << ">>> ";
		cin >> room;
		if (room >= 1 && room <= 3) { break; }
		cout << "������������������" << endl << endl;
	}

	cout << "\n�ɹ��ύԤԼ���룡�����ĵȴ����\n" << endl;

	// ������д���ļ�
	ofstream file(ORDER_FILE, ios::app);
	file << "date:" << date << " ";
	file << "interval:" << interval << " ";
	file << "stuId:" << this->m_Id << " ";
	file << "stuName:" << this->m_Name << " ";
	file << "roomId:" << room << " ";
	file << "status:" << 1 << endl;
	file.close();
}


// �鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	// ʵ����һ��ԤԼ�ļ��������
	OrderFile orderFileManager;

	// ���orderFileManager�����m_SizeΪ�㣬˵������ֻ���������ݣ����������ݣ�
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n��ԤԼ��¼\n" << endl;
		return;
	}

	// ��������ݣ�չʾ����
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		// ���idƥ����ϣ�˵�����Լ������ݣ��������
		if (atoi(orderFileManager.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ�����" << orderFileManager.m_orderData[i]["date"];
			cout << "   ʱ�Σ�" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "   ������" << orderFileManager.m_orderData[i]["roomId"];

			// �����status�������ܷŵ�ѭ�����棬ÿһ�����¶��壬���˳�ʼ����������ã�
			string status = "  ״̬��";		// 0 ȡ��ԤԼ		1 �����		2 ��ԤԼ		-1 ԤԼʧ��
			
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
}


// �鿴����ԤԼ
void Student::showAllOrder()
{
	// ʵ����һ��ԤԼ�ļ��������
	OrderFile orderFileManager;

	// ���orderFileManager�����m_SizeΪ�㣬˵������ֻ���������ݣ����������ݣ�
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n��ԤԼ��¼\n" << endl;
		return;
	}

	// ��������ݣ�չʾ����
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ�����" << orderFileManager.m_orderData[i]["date"];
		cout << "   ʱ�Σ�" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "   ѧ�ţ�" << orderFileManager.m_orderData[i]["stuId"];
		cout << "   ������" << orderFileManager.m_orderData[i]["stuName"];
		cout << "   ������" << orderFileManager.m_orderData[i]["roomId"];

		// �����status�������ܷŵ�ѭ�����棬ÿһ�����¶��壬���˳�ʼ����������ã�
		string status = "  ״̬��";	// 0 ȡ��ԤԼ		1 �����		2 ��ԤԼ		-1 ԤԼʧ��

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


// ȡ��ԤԼ
void Student::cancelOrder()
{
	// ʵ����һ��ԤԼ�ļ��������
	OrderFile orderFileManager;

	// ���orderFileManager�����m_SizeΪ�㣬˵������ֻ���������ݣ����������ݣ�
	if (orderFileManager.m_Size == 0)
	{
		cout << "\n��ԤԼ��¼\n" << endl;
		return;
	}

	cout << "\n��ܰ��ʾ����������С�ԤԼ�ɹ��ļ�¼������ȡ����\n" << endl;

	// ������ʱװ�����ݵ���ʵ���
	vector<int> v;
	v.clear();

	int index = 1;		// index ��չʾ���û�������������ǰ��ı��

	// ��ʾԤԼ��¼
	for (int i = 0; i < orderFileManager.m_Size; i++)
	{
		if (atoi(orderFileManager.m_orderData[i]["stuId"].c_str()) != this->m_Id) { continue; }
		if (orderFileManager.m_orderData[i]["status"] == "1" || orderFileManager.m_orderData[i]["status"] == "2")
		{
			v.push_back(i);		// �ļ���ʵ���ϵı��
			cout << index++ << "��";
			cout << "ԤԼ���ڣ�����" << orderFileManager.m_orderData[i]["date"];
			cout << "   ʱ�Σ�" << (orderFileManager.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "   ������" << orderFileManager.m_orderData[i]["roomId"];

			// �����status�������ܷŵ�ѭ�����棬ÿһ�����¶��壬���˳�ʼ����������ã�
			string status = "  ״̬��";		// 0 ȡ��ԤԼ		1 �����		2 ��ԤԼ		-1 ԤԼʧ��

			if (orderFileManager.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (orderFileManager.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			cout << status << endl;
		}
	}


	// ����ļ����������ݣ������й���"�ҵļ�¼"�ǿ�
	if (v.size() == 0)
	{
		cout << "\n----< ��ʱû�����ԤԼ��¼ >----\n" << endl;
		return;
	}

	// �����û�ѡ��ȡ����Ӧ��¼
	cout << "\n��������Ҫȡ���ļ�¼��(����0�򷵻�)" << endl;
	int select = 0;
	while (true)
	{
		cout << ">>> ";
		cin >> select;

		if (select < 0 || select > v.size())
		{
			cout << "������������������" << endl;
			continue;
		}

		if (select == 0) {
			break;
		}
		else
		{
			orderFileManager.m_orderData[v[select - 1]]["status"] = "0";
			orderFileManager.updateOrder();
			cout << "��ȡ��ԤԼ" << endl;
			break;
		}
	}
}