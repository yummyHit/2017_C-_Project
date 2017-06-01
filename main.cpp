#include <iostream>
#include <Windows.h>
#include "dogInfo.h"
using namespace std;
#define MAX_SIZE 100

void showMenu();
void showMenu(int index);

int main() {
	dogInfo *person = new dogInfo[MAX_SIZE];				//최대 사용자 100명(동적으로 객체생성)
	personInfo *admin = NULL; // admin 객체를 personInfo클래스로부터 생성
	int select, user_count = 0, i = 0;
	char selector;
	admin->datas(person, "load");
	person[99].name = "admin"; //99번째 배열의 name은 admin으로 지정, pw는 protect기 때문에 접근불가
	
	while (1) {
		
		if(i != 99) showMenu(); // i가 99가 아니라면(일반사용자라면) showmenu함수 출력
		else showMenu(i); //i가 99라면(관리자라면) showmenu(int index)함수 출력
		cout << "│   선택할 메뉴 번호입력 >> ";
		cin >> select;	//1번~8번 메뉴 입력받는 select 변수
		if (i == 99 && select == 2) select = 7; //관리자면서 2번을 누르면 일반사용자의 7번동작 수행(로그아웃)
		else if (i == 99 && select == 3) select = 8; //관리자면서 3번을 누르면 일반사용자의 8번동작 수행(종료)
		
		switch (select) {
		case 1: //로그인
			if (i > 0 && i != 99) { //로그인이 되어있다면
				cout << person[i].error_name(2) << endl; //이미 로그인 되어 있습니다 에러메시지
				break;
			}
			else if(i != 99) i = person[i].login(person, user_count);	//일반사용자,변수 i값에 사용자에 해당하는 index값 저장(로그인 기능)
			else admin->confirm(person); //i가 99(관리자)라면 personInfo에 있는 confirm함수 실행
			break;
			
		case 2://회원가입
			if (i > 0) {//로그인 되어있을 시 회원가입을 할때 에러메시지
				cout << person[i].error_name(3) << endl; //회원가입을 하시려면 로그아웃을 먼저해주세요
				break;
			}
			else if (i != 99) {
				for (int j = 1; j < MAX_SIZE; j++)
					if (person[j].checkID() == 0) {		//사용자가 등록되어있지 않은 index로 이동하기위한 반복문
						user_count = j;
						break;
					}
				person[user_count].insertInfo(person, user_count);	//사용자 등록(회원가입 기능)
			}
			//else 모든 제보 확인 함수
			break;

		case 3:
			person[i].reg();	//유기견 등록
			break;

		case 4:
			person[i].report(); //유기견 제보
			break;

		case 5:
			person[i].confirm(person); // 제보 확인
			break;


		case 6:
			person[i].inquire(); // 자기 정보 확인
			
			break;

		case 7: // 로그아웃
			if (i == 0) {
				cout << person[i].error_name(7) << endl;
				break;
			}
			cout << "│   로그아웃 하시겠습니까?(Y/N)" ;
			cin >> selector;
			switch (selector) {
			case 'n':
			case 'N':
				break;
			case 'y':
			case 'Y':
				i = 0;
				cout << "│   로그아웃 되었습니다!" << endl;
				break;
			default:
				cout << person[i].error_name(10) << endl;
				cin.ignore(); //버퍼에 남아있는 쓰레기값을 초기화시킴
				break;
			}
			break;

		case 8:
			admin->datas(person, "save");
			delete[] person; //동적할당 객체 제거
			exit(1);	//종료

		default:
			cout << person[i].error_name(11) << endl;
		}
		cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		system("pause"); system("cls");
		//pause(일시정지), cls(버퍼지우기) 명령어 실행
	}
}

void showMenu() {
		cout << "┌ㅡㅡ  C++ 2조 유기견 찾기 프로그램  ㅡㅡ┐" << endl;
		cout << "│	                                  │" << endl;
		cout << "│          1. 로그인                     │" << endl;
		cout << "│          2. 회원가입                   │" << endl;
		cout << "│          3. 유기견 실종 등록           │" << endl;
		cout << "│          4. 유기견 제보                │" << endl;
		cout << "│          5. 제보 확인                  │" << endl;
		cout << "│          6. 내 정보 확인               │" << endl;
		cout << "│          7. 로그아웃                   │" << endl;
		cout << "│          8. 종료                       │" << endl;
		cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘" << endl;
};						//선택메뉴 출력함수

void showMenu(int index) { //오버로딩
	cout << "┌ㅡㅡ  C++ 2조 유기견 찾기 프로그램  ㅡㅡ┐" << endl;
	cout << "│	  관리자 모드로 접근하셨습니다.   │" << endl;
	cout << "│          1. 모든 등록/제보 확인        │" << endl;
	cout << "│          2. 로그아웃                   │" << endl;
	cout << "│          3. 종료                       │" << endl;
	cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘" << endl;
}