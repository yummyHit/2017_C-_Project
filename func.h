#ifndef FUNC_H
#define FUNC_H


class func {
public:
	virtual int login() { return 0; }; //�α��� �Լ�
	virtual int insertInfo() { return 0; };//ȸ������ �Լ�
	virtual int checkID() = 0; //�ߺ����̵� Ȯ�� �Լ�

	virtual void reg() = 0; //����� ����Լ�
	virtual void report() = 0; //����� �����Լ�
	virtual void confirm() = 0; //���� Ȯ�� �Լ�
	virtual void inquire() = 0; //����� ���� ��ȸ �Լ�
};

#endif