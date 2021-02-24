#pragma once
#include"ITERATOR.h"

/*
설명 : 
	사용자가 볼 수 있는 UI를 설정하는 클래스

*/
class UI_MANAGER
{

private:
	ITERATOR* iterator;
protected:
public:

	UI_MANAGER(ITERATOR& p_iterator);
	~UI_MANAGER() {}
	UI_MANAGER(const UI_MANAGER&) = delete;
	UI_MANAGER& operator=(const UI_MANAGER&) = delete;



	void Start() const;
};

UI_MANAGER::UI_MANAGER(ITERATOR& p_iterator)
{
	iterator = &p_iterator;
}

//시작 함수
void UI_MANAGER::Start() const
{
	iterator->exp();

	iterator->Read_Data();

	iterator->Print_Question();
}
