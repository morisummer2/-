#pragma once
#include"NODE.h"

/*
설명 : 
	노드 안에 들어가는 데이터클래스이다.

*/

class DATA : public NODE
{
private:
protected:
	char* question;		//문제
	char* answer;		//정답
public:

	DATA();

	virtual ~DATA();

	DATA(const char* p_question, const char* p_answer);			//문제 및 정답 할당

	virtual const char* const Get_Question() const { return question; }	//문제 주소값 리턴
	virtual const char* const Get_Answer() const { return answer; }		//정답 주소값 리턴

	//생성자 삭제 
	DATA(const DATA&) = delete;
	DATA& operator=(const DATA&) = delete;

	//할당해제함수 
	void Release();

};

/*
	DATA 기본생성자
*/
DATA::DATA()
	: question(nullptr), answer(nullptr)
{}

/*
	DATA 소멸자
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
설명 : 
	노드의 문제, 정답에 해당하는 문자열을 할당한다.

매개변수 : 
	const char* p_question	: 문제 문자열
	const char* p_answer	: 정답 문자열	 
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
설명 : 
	DATA클래스의 메모리를 해제하는 역할을 한다.

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