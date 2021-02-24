#pragma once
#include "DATA_MANAGER.h"


/*
���� : 
	UI_MANAGER �� ���� DATA�� �´����ʰ� �ϱ� ���� Ŭ����

*/
class ITERATOR
{
private:
	DATA_MANAGER data_manager;
	enum { buf_size = 1024 };
protected:
public:
	ITERATOR() {};
	~ITERATOR() {};
	ITERATOR(const ITERATOR&) = delete;
	ITERATOR& operator=(const ITERATOR&) = delete;

	//�����д� �Լ�
	void Read_Data();

	//���� ����
	void Print_Question();

	//���α׷� ����
	void exp() const;
};

/*
���� : 
	���Ϸ� ���� ���� �� ������ �޾ƿ�
	������ ���� �ϳ��� �з���

*/
void ITERATOR::Read_Data()
{
	ifstream file;
	char buf1[buf_size] = { 0, };
	char buf2[buf_size] = { 0, };
	cout << "���� �̸��� �Է����ּ���(ex : file.txt) : ";
	cin >> buf1;
	file.open(buf1);


	try
	{
		system("cls");
		if (file.is_open())								//������ ���ȴ°�?
		{
			while (!file.eof()) {						//eof�˻�
				memset(buf1, 0, buf_size);
				memset(buf2, 0, buf_size);
				file.getline(buf1, buf_size);
				file.getline(buf2, buf_size);

				data_manager.Add_Node(new DATA(buf1, buf2));

				if (!file.eof())
					file.getline(buf1, buf_size);		//���� ����
			}
			file.close();
		}
		else
		{
			cout << "�Է��Ͻ� ������ �ش� ��ο� ���ų� ���µ� �����Ͽ����ϴ�" << endl;
			return;
		}


	}
	catch (...)
	{
		cout << "Read_Data Error" << endl;
		abort();
	}
}

//������ �����͸� ����Ѵ�.
void ITERATOR::Print_Question()
{
	data_manager.Print_Data();
}


void ITERATOR::exp() const
{
	cout << "���� ���� ���             -> ������ : morisummer2" << endl;

	cout << "=======================����=============================" << endl;
	cout << "txt���Ͽ� ������ ������ ���� ���ٿ� �� ���� �� ��ĭ ��� �Ǵٸ� ���� ���� �Է� �Ѵ�(�� ������ �������� ������)" << endl;
	cout << "����: " << endl;

	cout << "����1" << endl;
	cout << "����1�� ���� ����   " << endl;
	cout << "                         <-����" << endl;
	cout << "����2" << endl;
	cout << "����2�� ���� ����" << endl;
	cout << "                         <-����" << endl;

}
