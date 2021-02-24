#pragma once
#include "DATA_MANAGER.h"


/*
설명 : 
	UI_MANAGER 가 직접 DATA와 맞닫지않게 하기 위한 클래스

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

	//파일읽는 함수
	void Read_Data();

	//문제 출제
	void Print_Question();

	//프로그램 사용법
	void exp() const;
};

/*
설명 : 
	파일로 부터 문제 및 정답을 받아옴
	문제당 개행 하나로 분류함

*/
void ITERATOR::Read_Data()
{
	ifstream file;
	char buf1[buf_size] = { 0, };
	char buf2[buf_size] = { 0, };
	cout << "파일 이름을 입력해주세요(ex : file.txt) : ";
	cin >> buf1;
	file.open(buf1);


	try
	{
		system("cls");
		if (file.is_open())								//파일이 열렸는가?
		{
			while (!file.eof()) {						//eof검사
				memset(buf1, 0, buf_size);
				memset(buf2, 0, buf_size);
				file.getline(buf1, buf_size);
				file.getline(buf2, buf_size);

				data_manager.Add_Node(new DATA(buf1, buf2));

				if (!file.eof())
					file.getline(buf1, buf_size);		//개행 제거
			}
			file.close();
		}
		else
		{
			cout << "입력하신 파일이 해당 경로에 없거나 여는데 실패하였습니다" << endl;
			return;
		}


	}
	catch (...)
	{
		cout << "Read_Data Error" << endl;
		abort();
	}
}

//랜덤된 데이터를 출력한다.
void ITERATOR::Print_Question()
{
	data_manager.Print_Data();
}


void ITERATOR::exp() const
{
	cout << "문제 랜덤 출력             -> 제작자 : morisummer2" << endl;

	cout << "=======================사용법=============================" << endl;
	cout << "txt파일에 문제와 정답을 각각 한줄에 써 넣은 후 한칸 띄고 또다른 문제 정답 입력 한다(각 문제당 개행으로 구분함)" << endl;
	cout << "예시: " << endl;

	cout << "문제1" << endl;
	cout << "문제1에 대한 정답   " << endl;
	cout << "                         <-개행" << endl;
	cout << "문제2" << endl;
	cout << "문제2에 대한 정답" << endl;
	cout << "                         <-개행" << endl;

}
