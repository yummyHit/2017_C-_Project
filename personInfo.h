#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "func.h"
#include "exception.h"
#include <string>

class personInfo :public func, public Exception {
protected:
	string pw;	// pw : ��й�ȣ
	int money;			// money : �����
	
public:
	string  name, info_dog, reg_dog, reg_location, reg_detail;
	// name : ����� �̸� // info_dog : ���� ������ ��Ͻ� ���� // reg_dog : ������ ������ ���� // reg_location : ��Ͻ� �߰��� ��ġ // reg_detail : ������ ������
	int account;		// account : �ʱ� �� 
	personInfo() {
		account = 0;
		money = 0;
	};	//������, personinfo��ü�� ���� �� ��� �ʱ�ȭ

	~personInfo() {};
	int login(personInfo *person, int user_count);//����� �α��� �Լ�
	int insertInfo(personInfo *person, int user_count);//����� ��� �Լ�
	int checkID();							//����ڰ� ����ִ� �ε��� �˻��� �Լ�
	void confirm();							//�����ڿ� confirm
	void confirm(personInfo *person);		//�����ε�
	void inquire(); //����� ���� ��ȸ �Լ�
	void datas(personInfo *person, char *sel);
};

#endif
