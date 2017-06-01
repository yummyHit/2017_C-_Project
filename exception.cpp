#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

string Exception::error_name(int errnum) {
	switch (errnum) {
	case 1:
		return "��   �����Ͱ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.\n";
		break;
	case 2:
		return "��   �̹� �α����� �Ǿ��ֽ��ϴ�.";
		break;
	case 3:
		return "��   ȸ�������� �Ͻ÷��� �α׾ƿ��� ���ּ���.";
		break;
	case 4:
		return "��      ### ��й�ȣ�� ��ġ���� �ʽ��ϴ� !! ###";
		break;
	case 5:
		return "��   ����ڰ� �������� �ʽ��ϴ�.\n��   ���� ����� ����� �ϼ���.";
		break;
	case 6:
		return "��   �̹� ���� �̸��� �����մϴ�.\n��   �ٽ� ������ �ּ���.";
		break;
	case 7:
		return "��   �α����� �ȵǾ� �ֽ��ϴ�.";
		break;
	case 8:
		return  "��   �ܾ��� �����մϴ�, �ܾ��� Ȯ���� �ٽ� ������ּ���.";
		break;
	case 9:
		return "��   �߸��� �Է°� �Դϴ�. �ٽ� �Է��� �ּ���.";
		break;
	case 10:
		return "��   �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.";
		break;
	case 11:
		return "��       ## �߸� �Է��ϼ̽��ϴ� ##\n��    �޴��� �ִ� ��ȣ�� �Է����ּ���";
		break;
	default:
		return "�� �� ���� ���� �߻�!";
		break;
	}
}