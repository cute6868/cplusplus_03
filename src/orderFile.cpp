#include"orderFile.h"
using namespace std;


// ���ݳ�ʼ�������ļ��е����ݣ����뵽map������
void OrderFile::initData()
{
	// �����ļ����������󣬲����ļ�
	ifstream file(ORDER_FILE, ios::in);

	string date;		// ����
	string interval;	// ʱ���
	string stuId;		// ѧ�����
	string stuName;		// ѧ������
	string roomId;		// �������
	string status;		// ԤԼ״̬

	// ��map�����е����ݸ���
	this->m_Size = 0;

	// Ϊ�����ѭ��׼��
	int pos;
	string key;
	string value;
	map<string, string> m;

	// ���ļ���ÿһ�����ݣ�����һ������ֵ�Եĸ�ʽ�����뵽map��
	// ���ݸ�ʽ��date:2 interval:2 stuId:1001 stuName:���� roomId:3 status:1
	while (file >> date && file >> interval && file >> stuId && file >> stuName && file >> roomId && file >> status)
	{
		// ÿ�ζ�ȡǰ�������(����)Сmap���� m
		m.clear();

		// date ���ݴ���
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// interval ���ݴ���
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// stuId ���ݴ���
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// stuName ���ݴ���
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// roomId ���ݴ���
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// status ���ݴ���
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));	// ��ֵ�� ���뵽Сmap������
		}

		// ÿѭ��һ�Σ�����Сmap�����У�װ����һ�е�"��ֵ��"���ݣ����ǽ�Сmap�������뵽��map������
		this->m_orderData.insert(make_pair(this->m_Size, m));

		// ��¼��map�����е����ݸ���
		this->m_Size++;
	}

	// ѭ����������ȡ�ļ�������ϣ��ر��ļ�
	file.close();
}


// ���캯��
OrderFile::OrderFile()
{
	// ���ļ��е����ݣ����뵽map������
	initData();
}


// ����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)	return;

	// �����ļ���������󣬲����ļ�
	ofstream file(ORDER_FILE, ios::out | ios::trunc);

	// ���ļ��������ݣ������ڴ������µ�����
	for (int i = 0; i < m_Size; i++)
	{
		file << "date:" << this->m_orderData[i]["date"] << " ";
		file << "interval:" << this->m_orderData[i]["interval"] << " ";
		file << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		file << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		file << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		file << "status:" << this->m_orderData[i]["status"] << endl;
	}

	// �ر��ļ�
	file.close();
}