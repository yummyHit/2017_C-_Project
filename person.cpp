#include <iostream>
#include <string.h>
#include "personInfo.h"
#define MAX_SIZE 100
using namespace std;

int personInfo::login(personInfo *person, int user_count) { //로그인 함수
	string checkName, checkPw;
	int tmp = 0;

	if (person[99].pw.empty()) person[99].pw = "admin"; //99번째 사용자의 비밀번호가 없다면 99째 사용자의 비밀번호는 admin으로 설정

	cout << "│   아이디 입력 >> ";
	cin >> checkName;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (person[i].name.compare(checkName) == 0) {	//사용자 아이디가 일치하면 if문 실행
			cout << "│   비밀번호 입력 >> ";
			cin >> checkPw;
			if (person[i].pw.compare(checkPw) != 0)	//사용자 비밀번호가 틀리면 if문 실행
				cout << error_name(4) << endl; //비밀번호가 일치하지 않습니다.
			else {									//사용자 비밀번호가 맞으면 else문 실행
				cout << "│      ## 환영합니다 " << checkName << " 고객님 !!##\n";
				return i;								//사용자가 있는 index로 가기 위한 반환값 tmp에 i값 대입
			}
		}
		else
			tmp = i - 1;									//아이디가 일치하지 않을시 tmp에 i 대입
	}
	if (tmp == (MAX_SIZE - 2)) {//사용자 아이디가 일치하지 않을 때, 위 for문이 admin(99)까지 반복되므로 마지막 i값을 tmp에 대입 후
								//사용자 아이디가 없으므로 에러문 출력
		cout << error_name(5) << endl; //사용자가 없습니다 에러메시지
		tmp = 0;
	}
	return tmp;	//사용자가 들어있는 배열의 index값 반환
};


int personInfo::insertInfo(personInfo *person, int user_count) { //회원가입 함수
	int count = 0;
	cout << "│      ## 사용자 등록을 선택하셨습니다. ##" << endl;
	cout << "│   이름 입력 >> ";
	cin >> name; 
	for (int i = 0; i < MAX_SIZE; i++)				//사용자의 이름이 중복되는지 검사하는 반복문
		if (person[i].name.compare(name) == 0) {
			count++;								//방금 입력받은 name(=person[user_count].name)이 person[i].name에도 1개가 있으므로
			if (count == 2) {						//2번째로 같은이름이 있다는 것은 중복된다는 것
				cout << error_name(6) << endl;    //같은 이름이 존재합니다.
				name.clear();						//현재 index의 name을 초기화 시킨 후
				return user_count = 0;						//index값 0으로 반환
			}
		}

	cout << "│   비밀번호 입력 >> ";
	cin >> pw;
	cout << "│   잔액 입력 >> ";
	cin >> account;
	cout << "│      ### 사용자 등록 성공 !! ###" << endl;
	return user_count;
};

int personInfo::checkID() {			//사용자 정보가 등록되지 않은 인덱스로 가기위한 함수
	int count;
	if (name.empty())
		return count = 0;			//메인함수에서 이 함수가 0이면 인덱스로 가고
	return count = 1;				//이 함수가 1이면 인덱스를 증가시키는 역할을 함
};

void personInfo::confirm() {//오버로딩
	return;
};

void personInfo::confirm(personInfo *person) { //관리자로 로그인할시,오버라이딩
	int select = 0;
	cout << "│   ## 메뉴를 선택해주세요 ##" << endl;
	cout << "│      1. 등록된 모든 유기견 확인" << endl;
	cout << "│      2. 모든 제보 확인" << endl;
	cout << "│      선택 >> ";
	cin >> select;
	switch (select) {
	case 1: //등록된 유기견 확인
		for (int i = 1; i < MAX_SIZE - 1; i++) { //전체 객체 반복
			if (person[i].name.empty()) break; //만약 객체의 name이 null이라면 break
			else if (person[i].info_dog.empty()) continue;  //만약 객체의 info_dog가 없다면 continue(객체에 info_dog없이 reg_dog만 있을경우가 있기때문)
			else cout << "│   등록정보 >> 회원 명 : " << person[i].name << ", 유기견 종류 : " << person[i].info_dog << ", 포상금 : " << person[i].money << " 입니다." << endl;
		}
		break;
	case 2: //모든 제보 확인
		for (int i = 1; i < MAX_SIZE - 1; i++) { //전체 객체 반복
			if (person[i].name.empty()) break; //만약 객체의 name이 null이라면 break
			else if (person[i].reg_dog.empty()) continue;//만약 객체의 reg_dog가 없다면 continue(객체에 reg_dog없이 info_dog만 있을경우가 있기때문)
			else {
				cout << "│   제보정보 >> 회원 명 : " << person[i].name << ", 유기견 종류 : " << person[i].reg_dog << ", 발견 위치 : " << person[i].reg_location << endl; //출력
				cout << "│               세부정보 : " << person[i].reg_detail << " 입니다." << endl;
			}
		}
		break;
	default:
		cout << error_name(11);
		break;
	}
};

void personInfo::inquire() { //사용자 정보 조회
	if (name.empty()) {	//로그인이 안되어있을시
		cout << error_name(7) << endl; // 로그인이 안되어있습니다 에러메시지
	}
	else {
		cout << "│   ## 회원 정보 ##" << endl;
		cout << "│   이름 : " << name << endl;
		cout << "│   잔액 : " << account << endl;
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