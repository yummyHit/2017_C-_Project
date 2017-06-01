#include <iostream>
#include <string.h>
#include "dogInfo.h"
#define MAX_SIZE 100
using namespace std;


void dogInfo::reg() { //유기견 실종 등록
	char selector; //Y또는N를 담을 변수
	if (name.empty()) {	//로그인이 안되어있을때 에러문 출력
		cout << error_name(7) << endl;
	}
	else {
		cout << "│   ## 유기견 등록을 선택하셨습니다 ##" << endl;
		while (1) {
				cout << "│   잃어버린 강아지의 종류를 입력하세요 >> ";
				cin >> info_dog;
				cout << "│   포상금을 입력하세요 >> ";
				cin >> money;
				if (money > account) { // 잔액이 포상금보다 적을시
					cout << error_name(8) << endl; //잔액이 부족합니다 에러메시지
					info_dog.clear();
					break;
				}
				else if (money < 0 || money > account) {
					cout << error_name(9) << endl; //잘못된 입력값입니다.
					
					break;
				cout << "│   등록정보 >> 강아지명 : " << info_dog << ", 포상금 : " << money << " 입니다." << endl;
			}
			cout << "│   등록하신 정보가 맞습니까? (Y/N) : ";
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
				cout << "│   등록이 완료되었습니다!" << endl;
				break;
			default:
				cout << error_name(10) << endl;
				break;
			}
			if (money != 0)	break; //포상금이 0이 아닐시 while문 빠져나가기 위함
			
		}
	}
}

void dogInfo::report() { // 유기견 제보
	char selector;
	if (name.empty()) {	//사용자가 없을 때 에러문 출력
		cout << error_name(7) << endl;
	}
	else {
		cout << "│   ## 유기견 제보를 선택하셨습니다 ##" << endl;
		while (1) {
			cout << "│   제보할 강아지의 종류를 입력하세요 >> ";
			cin >> reg_dog;
			cout << "│   어디에서 발견하셨습니까? >> ";
			cin >> reg_location;
			fflush(stdin);
			cout << "│   세부사항을 입력해주세요 >> ";
			getline(cin, reg_detail);
			
			cout << "│   등록정보 >> 강아지 종류 : " << reg_dog << ", 발견 위치 : " << reg_location << " 입니다." << endl;
			cout << "│   제보할 정보가 맞습니까? (Y/N) : ";
			cin >> selector;
			if (selector == 'n' || selector == 'N') {
				reg_dog.clear();
				reg_location.clear();
				continue;
			}
			else if (selector == 'y' || selector == 'Y') {
				cout << "│   제보가 성공적으로 되었습니다!" << endl;
				break;
			}
		}
	}
}

void dogInfo::confirm(personInfo *person) { //제보확인
	int select = 0, select2 = 0; //메뉴를 선택할 변수

	if (name.empty()) {	//사용자가 없을 때 에러문 출력
		cout << error_name(7) << endl;
	}
	else {
		cout << "│   ## 메뉴를 선택해주세요 ##" << endl;
		cout << "│      1. 내가 실종 등록한 유기견 확인" << endl;
		cout << "│      2. 내가 제보한 유기견 확인" << endl;
		cout << "│      선택 >> ";
		cin >> select;
		switch (select) {
		case 1:
			if (info_dog.empty()) {
				cout << "│   등록한 유기견이 없습니다" << endl;
				break;
			}
			system("cls");
			showMenu();
			cout << "│   등록정보 >> 강아지명 : " << info_dog << ", 포상금 : " << money << " 입니다." << endl;
			cout << "│      1. 나에게 들어온 제보 확인" << endl;
			cout << "│      2. 내가 등록한 유기견 삭제" << endl;
			cout << "│      선택 >> ";
			cin >> select2;
			break;

		case 2:
			if (reg_dog.empty()) {
				cout << "│   제보한 정보가 없습니다" << endl;
				break;
			}
			system("cls");
			showMenu();
			cout << "│      1. 내가 등록한 제보 확인" << endl;
			cout << "│      2. 내가 등록한 제보 삭제" << endl;
			cout << "│      선택 >> ";
			cin >> select2;
			break;
		}
		selectmenu(select, select2, person); // select와 select2변수값, person을 매개변수로 이용해 해당 기능 수행하는 함수 호출
	}
}

void dogInfo::selectmenu(int select, int select2, personInfo *person) {  //제보확인함수(confirm)에서 호출하는 함수
	int user_idx[10] = { 0, }, i = 1, j = 0;
	string tmp;
	if (select == 1 && select2 == 1) { //나에게 들어온 제보 확인시
		while (1) {
			if (person[i].reg_dog.compare(info_dog) == 0) { //사용자들의 reg_dog와 나의 info_dog를 비교해서 같다면
				cout << "│   [" << ++j << "]" << person[i].name << "님의 제보 // 유기견 종류 : " << person[i].reg_dog << ", 발견 위치 : " << person[i].reg_location << endl; //출력
				user_idx[j] = i; //제보자들의 index를 user_index에 저장
			}
			i++;
			if (person[i].name.empty()) break; //사용자가 더이상 없을시 break
		}
		if (user_idx[1] == NULL) { //user_index의 첫번째 주소에 값이 없을시 ;제보는 1부터 들어옴
			cout << "│   들어온 제보가 아직 없습니다." << endl;
			return;
		}
		cout << "│   어떤 제보자를 선택하시겠습니까?(선택시 세부정보를 확인하실 수 있으며 포상금이 제보자에게 지급됩니다.)" << endl;
		cout << "│   (선택하시지 않으려면 0번 / 다중선택시 1,3 과 같이 콤마(,)로 구분)" << endl;
		cout << "│   선택 >> ";
		cin >> tmp;
		if (tmp.data() == "0") { //0번을 선택시 while문을 빠져 나감
			cout << "│   0번을 선택하셨습니다. 다시 시작해 주세요." << endl;
			return;
		}
		for (i = 0; i < tmp.length(); i+=2) { //몇번째 제보자를 선택했는지 출력하기 위해
			if (i == (tmp.length() - 1)) cout << tmp.at(i); // - '0' : 캐릭터(char)에서 int형으로 변환
			else if (i == 0) cout << "│   " << tmp.at(i) << ", "; 
			else cout << tmp.at(i) << ", ";
		}
		cout << "번째 제보자를 선택하셨습니다." << endl;
		for (i = 0; i < tmp.length(); i+=2) {
			person[user_idx[tmp.at(i) - '0']].account += (int)(money / (tmp.length() / 2 + 1)); //선택한 사람들에게 포상금 분배
			cout << "│   " << person[user_idx[tmp.at(i) - '0']].name << "님의 제보 상세정보는 " << person[user_idx[tmp.at(i) - '0']].reg_detail << " 입니다." << endl;//정보 출력
		}
		cout << "│   선택한 제보자(들)에게 포상금이 지급되었습니다!!" << endl;
		
	}
	else if (select == 1 && select2 == 2) {//자신이 등록한 유기견 취소시
		account += money; //실종 등록을 취소했음으로 포상금 반환
		info_dog.clear(); //배열 초기화
		cout << "│    등록삭제되었습니다!" << endl;
	}
	else if (select == 2 && select2 == 1) {//자신이 제보한 정보 선택시
		cout << "│   " << name << "님의 제보정보 : 강아지명 : " << reg_dog << ", 발견 위치 : " << reg_location << " 입니다." << endl;
	}
	
	else if (select == 2 && select2 == 2) {//자신이 제보한 유기견 취소시 배열 초기화
		reg_dog.clear();
		reg_location.clear();
		reg_detail.clear();
		cout << "│    등록삭제되었습니다!" << endl;
	}
}

void dogInfo::showMenu() {
	cout << "┌ㅡㅡ  C++ 2조 유기견 찾기 프로그램  ㅡㅡ┐" << endl;
	cout << "│	                                  │" << endl;
	cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘" << endl;
}