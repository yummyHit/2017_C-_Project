#include <iostream>
#include <string.h>
#include "personInfo.h"
#define MAX_SIZE 100
using namespace std;

int personInfo::login(personInfo *person, int user_count) { //�α��� �Լ�
	string checkName, checkPw;
	int tmp = 0;

	if (person[99].pw.empty()) person[99].pw = "admin"; //99��° ������� ��й�ȣ�� ���ٸ� 99° ������� ��й�ȣ�� admin���� ����

	cout << "��   ���̵� �Է� >> ";
	cin >> checkName;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (person[i].name.compare(checkName) == 0) {	//����� ���̵� ��ġ�ϸ� if�� ����
			cout << "��   ��й�ȣ �Է� >> ";
			cin >> checkPw;
			if (person[i].pw.compare(checkPw) != 0)	//����� ��й�ȣ�� Ʋ���� if�� ����
				cout << error_name(4) << endl; //��й�ȣ�� ��ġ���� �ʽ��ϴ�.
			else {									//����� ��й�ȣ�� ������ else�� ����
				cout << "��      ## ȯ���մϴ� " << checkName << " ���� !!##\n";
				return i;								//����ڰ� �ִ� index�� ���� ���� ��ȯ�� tmp�� i�� ����
			}
		}
		else
			tmp = i - 1;									//���̵� ��ġ���� ������ tmp�� i ����
	}
	if (tmp == (MAX_SIZE - 2)) {//����� ���̵� ��ġ���� ���� ��, �� for���� admin(99)���� �ݺ��ǹǷ� ������ i���� tmp�� ���� ��
								//����� ���̵� �����Ƿ� ������ ���
		cout << error_name(5) << endl; //����ڰ� �����ϴ� �����޽���
		tmp = 0;
	}
	return tmp;	//����ڰ� ����ִ� �迭�� index�� ��ȯ
};


int personInfo::insertInfo(personInfo *person, int user_count) { //ȸ������ �Լ�
	int count = 0;
	cout << "��      ## ����� ����� �����ϼ̽��ϴ�. ##" << endl;
	cout << "��   �̸� �Է� >> ";
	cin >> name; 
	for (int i = 0; i < MAX_SIZE; i++)				//������� �̸��� �ߺ��Ǵ��� �˻��ϴ� �ݺ���
		if (person[i].name.compare(name) == 0) {
			count++;								//��� �Է¹��� name(=person[user_count].name)�� person[i].name���� 1���� �����Ƿ�
			if (count == 2) {						//2��°�� �����̸��� �ִٴ� ���� �ߺ��ȴٴ� ��
				cout << error_name(6) << endl;    //���� �̸��� �����մϴ�.
				name.clear();						//���� index�� name�� �ʱ�ȭ ��Ų ��
				return user_count = 0;						//index�� 0���� ��ȯ
			}
		}

	cout << "��   ��й�ȣ �Է� >> ";
	cin >> pw;
	cout << "��   �ܾ� �Է� >> ";
	cin >> account;
	cout << "��      ### ����� ��� ���� !! ###" << endl;
	return user_count;
};

int personInfo::checkID() {			//����� ������ ��ϵ��� ���� �ε����� �������� �Լ�
	int count;
	if (name.empty())
		return count = 0;			//�����Լ����� �� �Լ��� 0�̸� �ε����� ����
	return count = 1;				//�� �Լ��� 1�̸� �ε����� ������Ű�� ������ ��
};

void personInfo::confirm() {//�����ε�
	return;
};

void personInfo::confirm(personInfo *person) { //�����ڷ� �α����ҽ�,�������̵�
	int select = 0;
	cout << "��   ## �޴��� �������ּ��� ##" << endl;
	cout << "��      1. ��ϵ� ��� ����� Ȯ��" << endl;
	cout << "��      2. ��� ���� Ȯ��" << endl;
	cout << "��      ���� >> ";
	cin >> select;
	switch (select) {
	case 1: //��ϵ� ����� Ȯ��
		for (int i = 1; i < MAX_SIZE - 1; i++) { //��ü ��ü �ݺ�
			if (person[i].name.empty()) break; //���� ��ü�� name�� null�̶�� break
			else if (person[i].info_dog.empty()) continue;  //���� ��ü�� info_dog�� ���ٸ� continue(��ü�� info_dog���� reg_dog�� ������찡 �ֱ⶧��)
			else cout << "��   ������� >> ȸ�� �� : " << person[i].name << ", ����� ���� : " << person[i].info_dog << ", ����� : " << person[i].money << " �Դϴ�." << endl;
		}
		break;
	case 2: //��� ���� Ȯ��
		for (int i = 1; i < MAX_SIZE - 1; i++) { //��ü ��ü �ݺ�
			if (person[i].name.empty()) break; //���� ��ü�� name�� null�̶�� break
			else if (person[i].reg_dog.empty()) continue;//���� ��ü�� reg_dog�� ���ٸ� continue(��ü�� reg_dog���� info_dog�� ������찡 �ֱ⶧��)
			else {
				cout << "��   �������� >> ȸ�� �� : " << person[i].name << ", ����� ���� : " << person[i].reg_dog << ", �߰� ��ġ : " << person[i].reg_location << endl; //���
				cout << "��               �������� : " << person[i].reg_detail << " �Դϴ�." << endl;
			}
		}
		break;
	default:
		cout << error_name(11);
		break;
	}
};

void personInfo::inquire() { //����� ���� ��ȸ
	if (name.empty()) {	//�α����� �ȵǾ�������
		cout << error_name(7) << endl; // �α����� �ȵǾ��ֽ��ϴ� �����޽���
	}
	else {
		cout << "��   ## ȸ�� ���� ##" << endl;
		cout << "��   �̸� : " << name << endl;
		cout << "��   �ܾ� : " << account << endl;
	}
}

void personInfo::datas(personInfo *person, char *sel) {
	int i = 1, cnt = 0, cur = 0;
	char *tmp = (char*)malloc(sizeof(int));
	memset(tmp, 0, sizeof(int));
	FILE *fp = fopen("C:\\user_data.txt", "a+");
	if(!strncmp(sel, "load", 4)) {
		sel = (char*)malloc(MAX_SIZE);
		fp = fopen("C:\\user_data.txt", "r");
		while(1) {
			memset(sel, 0, sizeof(sel));
			fseek(fp, cur, SEEK_CUR);
			fgets(sel, MAX_SIZE, fp);
			if(strlen(sel) == 0) break;
			cur += strlen(sel)+1;
			person[i].name.append(strtok(sel, ","));
			person[i].pw.append(strtok(NULL, ","));
			strcpy(tmp, strtok(NULL, ","));
			while(1) {
				if(isdigit(tmp[cnt])) {
					person[i].account *= 10;
					person[i].account += tmp[cnt++] - '0';
				}
				else {
					cnt = 0;
					break;
				}
			}
			i++;
			rewind(fp);
		}
	}
	else if(!strncmp(sel, "save", 4)) {
		sel = (char*)malloc(MAX_SIZE);
		fp = fopen("C:\\user_data.txt", "w+");
		while(1) {
			if(i == MAX_SIZE || person[i].name.empty()) break;
			memset(sel, 0, sizeof(sel));
			fprintf(fp, "%s,%s,%d\n", person[i].name.c_str(), person[i].pw.c_str(), person[i].account);
			i++;
		}
	}
	fclose(fp);
}