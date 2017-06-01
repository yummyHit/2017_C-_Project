#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

string Exception::error_name(int errnum) {
	switch (errnum) {
	case 1:
		return "│   데이터가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.\n";
		break;
	case 2:
		return "│   이미 로그인이 되어있습니다.";
		break;
	case 3:
		return "│   회원가입을 하시려면 로그아웃을 해주세요.";
		break;
	case 4:
		return "│      ### 비밀번호가 일치하지 않습니다 !! ###";
		break;
	case 5:
		return "│   사용자가 존재하지 않습니다.\n│   먼저 사용자 등록을 하세요.";
		break;
	case 6:
		return "│   이미 같은 이름이 존재합니다.\n│   다시 실행해 주세요.";
		break;
	case 7:
		return "│   로그인이 안되어 있습니다.";
		break;
	case 8:
		return  "│   잔액이 부족합니다, 잔액을 확인후 다시 등록해주세요.";
		break;
	case 9:
		return "│   잘못된 입력값 입니다. 다시 입력해 주세요.";
		break;
	case 10:
		return "│   잘못 입력하셨습니다. 다시 입력해주세요.";
		break;
	case 11:
		return "│       ## 잘못 입력하셨습니다 ##\n│    메뉴에 있는 번호만 입력해주세요";
		break;
	default:
		return "알 수 없는 에러 발생!";
		break;
	}
}