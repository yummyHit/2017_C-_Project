#include <iostream>
#include <string.h>
#include "dogInfo.h"
#define MAX_SIZE 100
using namespace std;


void dogInfo::reg() { //����� ���� ���
	char selector; //Y�Ǵ�N�� ���� ����
	if (name.empty()) {	//�α����� �ȵǾ������� ������ ���
		cout << error_name(7) << endl;
	}
	else {
		cout << "��   ## ����� ����� �����ϼ̽��ϴ� ##" << endl;
		while (1) {
				cout << "��   �Ҿ���� �������� ������ �Է��ϼ��� >> ";
				cin >> info_dog;
				cout << "��   ������� �Է��ϼ��� >> ";
				cin >> money;
				if (money > account) { // �ܾ��� ����ݺ��� ������
					cout << error_name(8) << endl; //�ܾ��� �����մϴ� �����޽���
					info_dog.clear();
					break;
				}
				else if (money < 0 || money > account) {
					cout << error_name(9) << endl; //�߸��� �Է°��Դϴ�.
					
					break;
				cout << "��   ������� >> �������� : " << info_dog << ", ����� : " << money << " �Դϴ�." << endl;
			}
			cout << "��   ����Ͻ� ������ �½��ϱ�? (Y/N) : ";
			cin >> selector;
			switch (selector) {
			case 'n':
			case 'N':
				info_dog.clear();
				money = 0;
				break;
			case 'y':
			case 'Y':
				account -= money;
				cout << "��   ����� �Ϸ�Ǿ����ϴ�!" << endl;
				break;
			default:
				cout << error_name(10) << endl;
				break;
			}
			if (money != 0)	break; //������� 0�� �ƴҽ� while�� ���������� ����
			
		}
	}
}

void dogInfo::report() { // ����� ����
	char selector;
	if (name.empty()) {	//����ڰ� ���� �� ������ ���
		cout << error_name(7) << endl;
	}
	else {
		cout << "��   ## ����� ������ �����ϼ̽��ϴ� ##" << endl;
		while (1) {
			cout << "��   ������ �������� ������ �Է��ϼ��� >> ";
			cin >> reg_dog;
			cout << "��   ��𿡼� �߰��ϼ̽��ϱ�? >> ";
			cin >> reg_location;
			fflush(stdin);
			cout << "��   ���λ����� �Է����ּ��� >> ";
			getline(cin, reg_detail);
			
			cout << "��   ������� >> ������ ���� : " << reg_dog << ", �߰� ��ġ : " << reg_location << " �Դϴ�." << endl;
			cout << "��   ������ ������ �½��ϱ�? (Y/N) : ";
			cin >> selector;
			if (selector == 'n' || selector == 'N') {
				reg_dog.clear();
				reg_location.clear();
				continue;
			}
			else if (selector == 'y' || selector == 'Y') {
				cout << "��   ������ ���������� �Ǿ����ϴ�!" << endl;
				break;
			}
		}
	}
}

void dogInfo::confirm(personInfo *person) { //����Ȯ��
	int select = 0, select2 = 0; //�޴��� ������ ����

	if (name.empty()) {	//����ڰ� ���� �� ������ ���
		cout << error_name(7) << endl;
	}
	else {
		cout << "��   ## �޴��� �������ּ��� ##" << endl;
		cout << "��      1. ���� ���� ����� ����� Ȯ��" << endl;
		cout << "��      2. ���� ������ ����� Ȯ��" << endl;
		cout << "��      ���� >> ";
		cin >> select;
		switch (select) {
		case 1:
			if (info_dog.empty()) {
				cout << "��   ����� ������� �����ϴ�" << endl;
				break;
			}
			system("cls");
			showMenu();
			cout << "��   ������� >> �������� : " << info_dog << ", ����� : " << money << " �Դϴ�." << endl;
			cout << "��      1. ������ ���� ���� Ȯ��" << endl;
			cout << "��      2. ���� ����� ����� ����" << endl;
			cout << "��      ���� >> ";
			cin >> select2;
			break;

		case 2:
			if (reg_dog.empty()) {
				cout << "��   ������ ������ �����ϴ�" << endl;
				break;
			}
			system("cls");
			showMenu();
			cout << "��      1. ���� ����� ���� Ȯ��" << endl;
			cout << "��      2. ���� ����� ���� ����" << endl;
			cout << "��      ���� >> ";
			cin >> select2;
			break;
		}
		selectmenu(select, select2, person); // select�� select2������, person�� �Ű������� �̿��� �ش� ��� �����ϴ� �Լ� ȣ��
	}
}

void dogInfo::selectmenu(int select, int select2, personInfo *person) {  //����Ȯ���Լ�(confirm)���� ȣ���ϴ� �Լ�
	int user_idx[10] = { 0, }, i = 1, j = 0;
	string tmp;
	if (select == 1 && select2 == 1) { //������ ���� ���� Ȯ�ν�
		while (1) {
			if (person[i].reg_dog.compare(info_dog) == 0) { //����ڵ��� reg_dog�� ���� info_dog�� ���ؼ� ���ٸ�
				cout << "��   [" << ++j << "]" << person[i].name << "���� ���� // ����� ���� : " << person[i].reg_dog << ", �߰� ��ġ : " << person[i].reg_location << endl; //���
				user_idx[j] = i; //�����ڵ��� index�� user_index�� ����
			}
			i++;
			if (person[i].name.empty()) break; //����ڰ� ���̻� ������ break
		}
		if (user_idx[1] == NULL) { //user_index�� ù��° �ּҿ� ���� ������ ;������ 1���� ����
			cout << "��   ���� ������ ���� �����ϴ�." << endl;
			return;
		}
		cout << "��   � �����ڸ� �����Ͻðڽ��ϱ�?(���ý� ���������� Ȯ���Ͻ� �� ������ ������� �����ڿ��� ���޵˴ϴ�.)" << endl;
		cout << "��   (�����Ͻ��� �������� 0�� / ���߼��ý� 1,3 �� ���� �޸�(,)�� ����)" << endl;
		cout << "��   ���� >> ";
		cin >> tmp;
		if (tmp.data() == "0") { //0���� ���ý� while���� ���� ����
			cout << "��   0���� �����ϼ̽��ϴ�. �ٽ� ������ �ּ���." << endl;
			return;
		}
		for (i = 0; i < tmp.length(); i+=2) { //���° �����ڸ� �����ߴ��� ����ϱ� ����
			if (i == (tmp.length() - 1)) cout << tmp.at(i); // - '0' : ĳ����(char)���� int������ ��ȯ
			else if (i == 0) cout << "��   " << tmp.at(i) << ", "; 
			else cout << tmp.at(i) << ", ";
		}
		cout << "��° �����ڸ� �����ϼ̽��ϴ�." << endl;
		for (i = 0; i < tmp.length(); i+=2) {
			person[user_idx[tmp.at(i) - '0']].account += (int)(money / (tmp.length() / 2 + 1)); //������ ����鿡�� ����� �й�
			cout << "��   " << person[user_idx[tmp.at(i) - '0']].name << "���� ���� �������� " << person[user_idx[tmp.at(i) - '0']].reg_detail << " �Դϴ�." << endl;//���� ���
		}
		cout << "��   ������ ������(��)���� ������� ���޵Ǿ����ϴ�!!" << endl;
		
	}
	else if (select == 1 && select2 == 2) {//�ڽ��� ����� ����� ��ҽ�
		account += money; //���� ����� ����������� ����� ��ȯ
		info_dog.clear(); //�迭 �ʱ�ȭ
		cout << "��    ��ϻ����Ǿ����ϴ�!" << endl;
	}
	else if (select == 2 && select2 == 1) {//�ڽ��� ������ ���� ���ý�
		cout << "��   " << name << "���� �������� : �������� : " << reg_dog << ", �߰� ��ġ : " << reg_location << " �Դϴ�." << endl;
	}
	
	else if (select == 2 && select2 == 2) {//�ڽ��� ������ ����� ��ҽ� �迭 �ʱ�ȭ
		reg_dog.clear();
		reg_location.clear();
		reg_detail.clear();
		cout << "��    ��ϻ����Ǿ����ϴ�!" << endl;
	}
}

void dogInfo::showMenu() {
	cout << "���Ѥ�  C++ 2�� ����� ã�� ���α׷�  �ѤѦ�" << endl;
	cout << "��	                                  ��" << endl;
	cout << "���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�" << endl;
}