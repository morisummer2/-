#pragma once
#include "NODE.h"
#include "DATA.h"



/*
설명 : 
	

*/


class DATA_MANAGER
{
private:
	NODE* header;	//노드의 헤더(dummy)
	int count;		//노드의 갯수
protected:

public:

	DATA_MANAGER();

	virtual ~DATA_MANAGER();

	//노드를 추가한다.
	void Add_Node(NODE* data);

	//노드 안에 있는 데이터 출력
	void Print_Data();

	//노드할당해제
	void Release();

};

DATA_MANAGER::DATA_MANAGER()
	: header(nullptr),
	count(0)
{
	header = new DATA("dummy", "dummy");//첫 헤드 생성
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
설명 : 
	노드를 추가한다. ITERATOR의 READ_DATA함수에서 값을 받아옴

매개변수 : 
	NODE* data : 문제, 정답에 해당하는 문자열을 할당한다.

*/

void DATA_MANAGER::Add_Node(NODE* data)			//노드 추가 
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
설명 : 
	중복 없는 난수를 배열에 넣은 후 그 난수만큼의 노드이동 후 
	데이터를 출력


*/
void DATA_MANAGER::Print_Data()
{
	//난수생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, count - 1);

	//배열생성
	shared_ptr<NODE* []>node_arr(new NODE * [count], default_delete<NODE* []>());
	shared_ptr<int[]>num_arr(new int[count], default_delete<int[]>());

	char answer[256];

	//문제 출력
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

		cout << "문제 : " << node->Get_Question() << endl;
		cin >> answer;				//정답쓰는건데 정답인지 아닌지 체크는안함

		cout << "정답 : " << node->Get_Answer() << endl << endl;
	}

}

//노드할당해제
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

