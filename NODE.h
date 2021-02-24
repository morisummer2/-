#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<tchar.h>
#include<fstream>
#include<random>

using namespace std;

/*
설명 : 
	노드를 관리하는 클래스이다
*/

class NODE
{
	friend class DATA_MANAGER;
private:
	NODE* p_next;	//노드의 끝을 나타내는 변수
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