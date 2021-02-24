#pragma once
#include"ITERATOR.h"

/*
���� : 
	����ڰ� �� �� �ִ� UI�� �����ϴ� Ŭ����

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

//���� �Լ�
void UI_MANAGER::Start() const
{
	iterator->exp();

	iterator->Read_Data();

	iterator->Print_Question();
}
