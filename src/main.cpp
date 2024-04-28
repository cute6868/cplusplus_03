#include<iostream>
#include<fstream>

#include"globalFile.h"

#include"manager.h"
#include"teacher.h"
#include"student.h"

using namespace std;



// ȫ�ֺ���-����
void showMainMenu();
void exitSystem();
void showComputerRoom();	// չʾ������Ϣ
void login(string, int);
void managerMenu(Identity*&);
void studentMenu(Identity*&);
void teacherMenu(Identity*&);


// �������
int main()
{
	// ��ȡ�û�ѡ��
	int select = 0;

	while (true)
	{
		// ��ʾ���˵�
		showMainMenu();

		// ��ȡ�û�ѡ��
		cin >> select;

		// ִ�ж�Ӧ����
		switch (select)
		{
		case 1:		// ѧ�����
			login(STUDENT_FILE, 1);
			break;
		case 2:		// ��ʦ���
			login(TEACHER_FILE, 2);
			break;
		case 3:		// ����Ա���
			login(ADMIN_FILE, 3);
			break;
		case 0:		// �˳�ϵͳ
			exitSystem();
			break;
		default:
			cout << "\nѡ�����������ѡ��\n" << endl;
			break;
		}

		// ��ͣ���û��ۿ�ִ�н�����ۿ���Ϻ�����Ļ
		cout << endl << endl;
		system("pause");
		system("cls");
	}
}



// ȫ�ֺ���-ʵ��
// ��ʾ���˵�
void showMainMenu()
{
	cout << "==================== ��ӭʹ�û���ԤԼϵͳ ====================" << endl;
	cout << endl << "��������ǣ�" << endl;
	cout << "\t ----------------------------------------\n";
	cout << "\t |					|\n";
	cout << "\t |		1. ѧ������		|\n";
	cout << "\t |					|\n";
	cout << "\t |		2. ��ʦ	 		|\n";
	cout << "\t |					|\n";
	cout << "\t |		3. ����Ա		|\n";
	cout << "\t |					|\n";
	cout << "\t |		0. �˳�			|\n";
	cout << "\t |					|\n";
	cout << "\t ----------------------------------------\n";
	cout << "����������ѡ��";
}


// �˳�ϵͳ
void exitSystem()
{
	cout << "\n��ӭ�´�ʹ��\n\n";
	system("pause");
	exit(0);
}


// չʾ������Ϣ
void showComputerRoom()
{
	// �����ļ����������󣬲�����
	ifstream file(COMPUTERROOM, ios::in);

	// ������ܶ�ȡ����
	if (!file.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	// ������Զ�ȡ����
	int id;
	int capacity;
	cout << "\n������Ϣ���£�\n" << endl;
	cout << "-------------------------------------------" << endl;
	while (file >> id && file >> capacity)
	{
		cout << "|   ������ţ�" << id << "   �������������" << capacity << endl;
	}
	cout << "-------------------------------------------" << endl;
	cout << endl;

	// �ر��ļ�
	file.close();
}


// ��¼����
void login(string fileName, int type)
{
	// ��׼����һ��ͨ�õ����ָ�룬����װ�¹���Ա����ʦ��ѧ��
	Identity* person = NULL;


	// �����ļ�����������������ķ�ʽ���ļ�
	ifstream file;
	file.open(fileName, ios::in);


	// �ļ������ڣ�ֱ�ӽ���
	if (!file.is_open())
	{
		cout << "�ļ�������" << endl;
		file.close();
		return;
	}


	// �ļ����ڣ�ִ�и������
	// 1. ��ȡ��¼��Ϣ
	int id = 0;
	string name;
	string pwd;

	// --- ѧ������ʦ����id������Աû��id
	if (type == 1)	// ѧ����¼
	{
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)	// ��ʦ��¼
	{
		cout << "���������ְ���ţ�";
		cin >> id;
	}

	// --- ѧ������ʦ������Ա�����û���������
	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;


	// 2. ���е�¼��֤
	int fId;			// ���ļ��ж�ȡ�����id
	string fName;		// ���ļ��ж�ȡ������û���
	string fPwd;		// ���ļ��ж�ȡ���������
	if (type == 1)
	{
		// ѧ����¼��֤
		while (file >> fId && file >> fName && file >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// ��ʾ��Ϣ
				cout << "��¼�ɹ���" << endl << endl;

				// ʵ����һ��ѧ��
				person = new Student(id, name, pwd);

				// ����ѧ�����Ӳ˵�
				system("pause");	// ���û������¼����ʾ��Ϣ
				system("cls");		// ������˵���ʾ������
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		// ��ʦ��¼��֤
		while (file >> fId && file >> fName && file >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// ��ʾ��Ϣ
				cout << "��¼�ɹ���" << endl << endl;

				// ʵ����һ����ʦ
				person = new Teacher(id, name, pwd);

				// ������ʦ���Ӳ˵�
				system("pause");	// ���û������¼����ʾ��Ϣ
				system("cls");		// ������˵���ʾ������
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		// ����Ա��¼��֤
		while (file >> fName && file >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				// ��ʾ��Ϣ
				cout << "��¼�ɹ���" << endl << endl;

				// ʵ����һ������Ա
				person = new Manager(name, pwd);

				// �������Ա���Ӳ˵�
				system("pause");	// ���û������¼����ʾ��Ϣ
				system("cls");		// ������˵���ʾ������
				managerMenu(person);

				return;
			}
		}
	}

	file.close();
	cout << "��¼��֤ʧ�ܣ�" << endl;
}


// ����Ա�˵�
void managerMenu(Identity*& manager)
{
	// �������ָ��ǿ��ת��Ϊ�����ָ��
	// ԭ�򣺲�ǿ��ת���Ļ���ֻ�ܵ�������͸��඼�еĹ����ӿڣ�������ʹ���Լ����еĹ���
	Manager* man = (Manager*)manager;

	while (true)
	{
		// 1. ��ʾ����Ա�˵�
		manager->operMenu();

		// 2. ��ȡ�û�ѡ��Ȼ������û���ѡ��ִ�о���Ĺ���

		// ��ȡ�û�ѡ��
		int select = 0;
		cin >> select;

		// ִ�о��幦��
		if (select == 1)
		{
			system("cls");
			cout << "\t\t<<< ����˺� >>>\n" << endl;
			man->addUser();
		}
		else if (select == 2)
		{
			system("cls");
			cout << "\t\t<<< �鿴�˺� >>>\n" << endl;
			man->showUser();
		}
		else if (select == 3)
		{
			system("cls");
			cout << "\t\t<<< �鿴���� >>>\n" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			system("cls");
			cout << "\t\t<<< ���ԤԼ >>>\n" << endl;
			man->cleanFile();
		}
		else
		{
			system("cls");
			delete manager;
			cout << "\n\t\t���ѳɹ��˳���¼!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}


// ѧ���˵�
void studentMenu(Identity*& student)
{
	// �������ָ��ǿ��ת��Ϊ�����ָ��
	// ԭ�򣺲�ǿ��ת���Ļ���ֻ�ܵ�������͸��඼�еĹ����ӿڣ�������ʹ���Լ����еĹ���
	Student* stu = (Student*)student;

	while (true)
	{
		// 1. ��ʾѧ���˵�
		stu->operMenu();

		// 2. ��ȡ�û�ѡ��Ȼ������û���ѡ��ִ�о���Ĺ���

		// ��ȡ�û�ѡ��
		int select = 0;
		cin >> select;

		// ִ�о��幦��
		if (select == 1)
		{
			system("cls");
			cout << "\t\t<<< ����ԤԼ >>>\n" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			system("cls");
			cout << "\t\t<<< �ҵ�ԤԼ >>>\n" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			system("cls");
			cout << "\t\t<<< ����ԤԼ >>>\n" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			system("cls");
			cout << "\t\t<<< ȡ��ԤԼ >>>\n" << endl;
			stu->cancelOrder();
		}
		else
		{
			system("cls");
			delete stu;
			cout << "\n\t\t���ѳɹ��˳���¼!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}


// ��ʦ�˵�
void teacherMenu(Identity*& teacher)
{
	// �������ָ��ǿ��ת��Ϊ�����ָ��
	// ԭ�򣺲�ǿ��ת���Ļ���ֻ�ܵ�������͸��඼�еĹ����ӿڣ�������ʹ���Լ����еĹ���
	Teacher* tea = (Teacher*)teacher;

	while (true)
	{
		// չʾ�˵�����
		tea->operMenu();

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// �鿴����ԤԼ
			system("cls");
			cout << "\t\t<<< ����ԤԼ >>>\n" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			// ���ԤԼ
			system("cls");
			cout << "\t\t<<< ���ԤԼ >>>\n" << endl;
			tea->validOrder();
		}
		else
		{
			system("cls");
			delete tea;
			cout << "\n\t\t���ѳɹ��˳���¼!\n" << endl;
			return;
		}
		system("pause");
		system("cls");
	}
}