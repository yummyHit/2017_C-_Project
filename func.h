#ifndef FUNC_H
#define FUNC_H


class func {
public:
	virtual int login() { return 0; }; //로그인 함수
	virtual int insertInfo() { return 0; };//회원가입 함수
	virtual int checkID() = 0; //중복아이디 확인 함수

	virtual void reg() = 0; //유기견 등록함수
	virtual void report() = 0; //유기견 제보함수
	virtual void confirm() = 0; //제보 확인 함수
	virtual void inquire() = 0; //사용자 정보 조회 함수
};

#endif