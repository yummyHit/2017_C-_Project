#ifndef DOGINFO_H
#define DOGINFO_H

#include "personInfo.h"

class dogInfo :public personInfo {
public:
	void reg();							//����� ��� �Լ�
	void report() ;	//����� ���� �Լ�
	void confirm(personInfo *person);				//���� Ȯ�� �Լ�, �������̵��ϱ����� �״�� ������
	
	void showMenu();
	void selectmenu(int select, int select2, personInfo *person);//���� Ȯ�ο��� �� �޴����� �Լ�
};

#endif