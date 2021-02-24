#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<tchar.h>
#include<fstream>
#include<random>

using namespace std;

/*
���� : 
	��带 �����ϴ� Ŭ�����̴�
*/

class NODE
{
	friend class DATA_MANAGER;
private:
	NODE* p_next;	//����� ���� ��Ÿ���� ����
protected:
public:

	NODE();

	virtual ~NODE() {}

	NODE(const NODE&) = delete;
	NODE& operator= (const NODE&) = delete;

	virtual const char* const Get_Question() const { return nullptr; }
	virtual const char* const Get_Answer() const { return nullptr; }

};

NODE::NODE()
	: p_next(nullptr)
{}