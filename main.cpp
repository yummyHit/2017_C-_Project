#include <iostream>
#include <Windows.h>
#include "dogInfo.h"
using namespace std;
#define MAX_SIZE 100

void showMenu();
void showMenu(int index);

int main() {
	dogInfo *person = new dogInfo[MAX_SIZE];				//�ִ� ����� 100��(�������� ��ü����)
	personInfo *admin = NULL; // admin ��ü�� personInfoŬ�����κ��� ����
	int select, user_count = 0, i = 0;
	char selector;
	admin->datas(person, "load");
	person[99].name = "admin"; //99��° �迭�� name�� admin���� ����, pw�� protect�� ������ ���ٺҰ�
	
	while (1) {
		
		if(i != 99) showMenu(); // i�� 99�� �ƴ϶��(�Ϲݻ���ڶ��) showmenu�Լ� ���
		else showMenu(i); //i�� 99���(�����ڶ��) showmenu(int index)�Լ� ���
		cout << "��   ������ �޴� ��ȣ�Է� >> ";
		cin >> select;	//1��~8�� �޴� �Է¹޴� select ����
		if (i == 99 && select == 2) select = 7; //�����ڸ鼭 2���� ������ �Ϲݻ������ 7������ ����(�α׾ƿ�)
		else if (i == 99 && select == 3) select = 8; //�����ڸ鼭 3���� ������ �Ϲݻ������ 8������ ����(����)
		
		switch (select) {
		case 1: //�α���
			if (i > 0 && i != 99) { //�α����� �Ǿ��ִٸ�
				cout << person[i].error_name(2) << endl; //�̹� �α��� �Ǿ� �ֽ��ϴ� �����޽���
				break;
			}
			else if(i != 99) i = person[i].login(person, user_count);	//�Ϲݻ����,���� i���� ����ڿ� �ش��ϴ� index�� ����(�α��� ���)
			else admin->confirm(person); //i�� 99(������)��� personInfo�� �ִ� confirm�Լ� ����
			break;
			
		case 2://ȸ������
			if (i > 0) {//�α��� �Ǿ����� �� ȸ�������� �Ҷ� �����޽���
				cout << person[i].error_name(3) << endl; //ȸ�������� �Ͻ÷��� �α׾ƿ��� �������ּ���
				break;
			}
			else if (i != 99) {
				for (int j = 1; j < MAX_SIZE; j++)
					if (person[j].checkID() == 0) {		//����ڰ� ��ϵǾ����� ���� index�� �̵��ϱ����� �ݺ���
						user_count = j;
						break;
					}
				person[user_count].insertInfo(person, user_count);	//����� ���(ȸ������ ���)
			}
			//else ��� ���� Ȯ�� �Լ�
			break;

		case 3:
			person[i].reg();	//����� ���
			break;

		case 4:
			person[i].report(); //����� ����
			break;

		case 5:
			person[i].confirm(person); // ���� Ȯ��
			break;


		case 6:
			person[i].inquire(); // �ڱ� ���� Ȯ��
			
			break;

		case 7: // �α׾ƿ�
			if (i == 0) {
				cout << person[i].error_name(7) << endl;
				break;
			}
			cout << "��   �α׾ƿ� �Ͻðڽ��ϱ�?(Y/N)" ;
			cin >> selector;
			switch (selector) {
			case 'n':
			case 'N':
				break;
			case 'y':
			case 'Y':
				i = 0;
				cout << "��   �α׾ƿ� �Ǿ����ϴ�!" << endl;
				break;
			default:
				cout << person[i].error_name(10) << endl;
				cin.ignore(); //���ۿ� �����ִ� �����Ⱚ�� �ʱ�ȭ��Ŵ
				break;
			}
			break;

		case 8:
			admin->datas(person, "save");
			delete[] person; //�����Ҵ� ��ü ����
			exit(1);	//����

		default:
			cout << person[i].error_name(11) << endl;
		}
		cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		system("pause"); system("cls");
		//pause(�Ͻ�����), cls(���������) ��ɾ� ����
	}
}

void showMenu() {
		cout << "���Ѥ�  C++ 2�� ����� ã�� ���α׷�  �ѤѦ�" << endl;
		cout << "��	                                  ��" << endl;
		cout << "��          1. �α���                     ��" << endl;
		cout << "��          2. ȸ������                   ��" << endl;
		cout << "��          3. ����� ���� ���           ��" << endl;
		cout << "��          4. ����� ����                ��" << endl;
		cout << "��          5. ���� Ȯ��                  ��" << endl;
		cout << "��          6. �� ���� Ȯ��               ��" << endl;
		cout << "��          7. �α׾ƿ�                   ��" << endl;
		cout << "��          8. ����                       ��" << endl;
		cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�" << endl;
};						//���ø޴� ����Լ�

void showMenu(int index) { //�����ε�
	cout << "���Ѥ�  C++ 2�� ����� ã�� ���α׷�  �ѤѦ�" << endl;
	cout << "��	  ������ ���� �����ϼ̽��ϴ�.   ��" << endl;
	cout << "��          1. ��� ���/���� Ȯ��        ��" << endl;
	cout << "��          2. �α׾ƿ�                   ��" << endl;
	cout << "��          3. ����                       ��" << endl;
	cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�" << endl;
}