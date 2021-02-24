#pragma once
#include"NODE.h"

/*
���� : 
	��� �ȿ� ���� ������Ŭ�����̴�.

*/

class DATA : public NODE
{
private:
protected:
	char* question;		//����
	char* answer;		//����
public:

	DATA();

	virtual ~DATA();

	DATA(const char* p_question, const char* p_answer);			//���� �� ���� �Ҵ�

	virtual const char* const Get_Question() const { return question; }	//���� �ּҰ� ����
	virtual const char* const Get_Answer() const { return answer; }		//���� �ּҰ� ����

	//������ ���� 
	DATA(const DATA&) = delete;
	DATA& operator=(const DATA&) = delete;

	//�Ҵ������Լ� 
	void Release();

};

/*
	DATA �⺻������
*/
DATA::DATA()
	: question(nullptr), answer(nullptr)
{}

/*
	DATA �Ҹ���
*/
DATA::~DATA() {

	try
	{
		Release();
	}
	catch (...)
	{
		cout << "~DATA ERROR" << endl;
		abort();
	}

}

/*
���� : 
	����� ����, ���信 �ش��ϴ� ���ڿ��� �Ҵ��Ѵ�.

�Ű����� : 
	const char* p_question	: ���� ���ڿ�
	const char* p_answer	: ���� ���ڿ�	 
*/
DATA::DATA(const char* p_question, const char* p_answer)
	: DATA()
{
	int question_size = strlen(p_question) + 1;
	int answer_size = strlen(p_answer) + 1;
	try {

		question = new char[question_size];
		answer = new char[answer_size];

		memset(question, 0, question_size);
		memset(answer, 0, answer_size);

		strcpy(question, p_question);
		strcpy(answer, p_answer);
	}
	catch (...)
	{
		cout << "DATA(cosnt char*,const char*)ERROR" << endl;
		abort();
	}
}

/*
���� : 
	DATAŬ������ �޸𸮸� �����ϴ� ������ �Ѵ�.

*/

void DATA::Release()
{
	if (question != nullptr)
	{
		delete question;
		question = nullptr;
	}
	if (answer != nullptr)
	{
		delete answer;
		question = nullptr;
	}
}