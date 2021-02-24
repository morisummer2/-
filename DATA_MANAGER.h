#pragma once
#include "NODE.h"
#include "DATA.h"



/*
���� : 
	

*/


class DATA_MANAGER
{
private:
	NODE* header;	//����� ���(dummy)
	int count;		//����� ����
protected:

public:

	DATA_MANAGER();

	virtual ~DATA_MANAGER();

	//��带 �߰��Ѵ�.
	void Add_Node(NODE* data);

	//��� �ȿ� �ִ� ������ ���
	void Print_Data();

	//����Ҵ�����
	void Release();

};

DATA_MANAGER::DATA_MANAGER()
	: header(nullptr),
	count(0)
{
	header = new DATA("dummy", "dummy");//ù ��� ����
}


DATA_MANAGER::~DATA_MANAGER()
{
	try
	{
		Release();
	}
	catch (...)
	{
		cout << "Release Error" << endl;
		abort();

	}
}

/*
���� : 
	��带 �߰��Ѵ�. ITERATOR�� READ_DATA�Լ����� ���� �޾ƿ�

�Ű����� : 
	NODE* data : ����, ���信 �ش��ϴ� ���ڿ��� �Ҵ��Ѵ�.

*/

void DATA_MANAGER::Add_Node(NODE* data)			//��� �߰� 
{
	try
	{
		count++;
		data->p_next = header->p_next;
		header->p_next = data;

	}
	catch (...)
	{
		count--;
		delete data;
		abort();
	}
}

/*
���� : 
	�ߺ� ���� ������ �迭�� ���� �� �� ������ŭ�� ����̵� �� 
	�����͸� ���


*/
void DATA_MANAGER::Print_Data()
{
	//��������
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, count - 1);

	//�迭����
	shared_ptr<NODE* []>node_arr(new NODE * [count], default_delete<NODE* []>());
	shared_ptr<int[]>num_arr(new int[count], default_delete<int[]>());

	char answer[256];

	//���� ���
	for (int i = 0; i < count; i++)
	{
		int t1;
		t1 = num_arr[i] = dis(gen);
		for (int j = 0; j < i; j++)
		{
			if (num_arr[j] == num_arr[i])
				i--;
		}
	}

	for (int i = 0; i < count; i++)
	{
		NODE* node = header->p_next;
		for (int j = 0; j < num_arr[i]; j++)
		{
			node = node->p_next;
		}

		cout << "���� : " << node->Get_Question() << endl;
		cin >> answer;				//���侲�°ǵ� �������� �ƴ��� üũ�¾���

		cout << "���� : " << node->Get_Answer() << endl << endl;
	}

}

//����Ҵ�����
void DATA_MANAGER::Release()
{
	NODE* node = header->p_next;
	NODE* delete_node = nullptr;

	while (node)
	{
		delete_node = node;
		node = node->p_next;
		delete delete_node;
	}
	header->p_next = nullptr;
	delete header;
}

