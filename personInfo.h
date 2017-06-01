#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "func.h"
#include "exception.h"
#include <string>

class personInfo :public func, public Exception {
protected:
	string pw;	// pw : 비밀번호
	int money;			// money : 포상금
	
public:
	string  name, info_dog, reg_dog, reg_location, reg_detail;
	// name : 사용자 이름 // info_dog : 실종 강아지 등록시 종류 // reg_dog : 강아지 제보시 종류 // reg_location : 등록시 발견한 위치 // reg_detail : 제보시 상세정보
	int account;		// account : 초기 돈 
	personInfo() {
		account = 0;
		money = 0;
	};	//생성자, personinfo객체를 만들 시 모두 초기화

	~personInfo() {};
	int login(personInfo *person, int user_count);//사용자 로그인 함수
	int insertInfo(personInfo *person, int user_count);//사용자 등록 함수
	int checkID();							//사용자가 비어있는 인덱스 검색용 함수
	void confirm();							//관리자용 confirm
	void confirm(personInfo *person);		//오버로딩
	void inquire(); //사용자 정보 조회 함수
	void datas(personInfo *person, char *sel);
};

#endif
