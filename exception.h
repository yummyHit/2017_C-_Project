#pragma once
#include <string>
using namespace std;


class Exception {
	int errnum;
public:
	string error_name(int errnum);
};