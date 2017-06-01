#ifndef DOGINFO_H
#define DOGINFO_H

#include "personInfo.h"

class dogInfo :public personInfo {
public:
	void reg();							//유기견 등록 함수
	void report() ;	//유기견 제보 함수
	void confirm(personInfo *person);				//제보 확인 함수, 오버라이딩하기위해 그대로 가져옴
	
	void showMenu();
	void selectmenu(int select, int select2, personInfo *person);//제보 확인에서 상세 메뉴선택 함수
};

#endif