#include <iostream>
#include <string>
using namespace std;

void myaccount(int* p, int* q, int* r, int* s)  // 계좌 정보 출력 함수
{
	cout << "------------------- swing 계좌 정보 -------------------" << endl;
	cout << "l   " << "예금" << "   l   " << "적금" << "   ㅣ   " << "주택청약" << "   ㅣ   " << "주식계좌" << "   ㅣ" << endl;
	cout << "l   " << *p << "   l   " << *q << "   l       " << *r << "        l       " << *s << "     l" << endl;
	cout << "-------------------------------------------------------" << endl;
}

int total(int* p, int* q, int* r, int* s)  // 총 자산 출력 함수
{
	int total_money = *p + *q + *r + *s;
	return total_money;
}

int main(void)
{
	int number, number_;  // 첫 번째 반복문 숫자와 두 번째 반복문 숫자 변수 선언
	string name, id, password, id_, password_;  // 회원가입 이름, 회원가입 아이디, 회원가입 비밀번호, 로그인 아이디, 로그인 비밀번호 변수 선언 

	int a = 5000;  // 예금 변수 선언과 값 저장
	int b = 4000;  // 적금 변수 선언과 값 저장
	int c = 0;  // 주택청약 변수 선언과 값 저장
	int d = 10;  // 주식계좌 변수 선언과 값 저장

	while (true)
	{
		cout << " ********** swing 은행 ********** " << endl;
		cout << "1. 회원가입" << endl;
		cout << "2. 로그인" << endl << endl;
		cout << "번호를 입력하세요 >> ";
		cin >> number;  // 첫 번째 반복문 번호 입력받기

		if (number == 1)  // 1을 입력한 경우
		{
			cout << endl;
			cout << "이름: ";
			cin >> name;  // 회원가입 이름 입력받기
			cout << "아이디: ";
			cin >> id;  // 회원가입 아이디 입력받기
			cout << "비밀번호: ";
			cin >> password;  // 회원가입 비밀번호 입력받기
			cout << endl << "===== 회원가입 성공 =====" << endl << endl;
		}
		else if (number == 2)  // 2를 입력한 경우
		{
			cout << endl;
			cout << "아이디: ";
			cin >> id_;  // 로그인 아이디 입력받기
			cout << "비밀번호: ";
			cin >> password_;  // 로그인 비밀번호 입력받기

			if (id == id_ && password == password_)  // 회원가입 시 입력한 아이디 & 비밀번호가 로그인 시 입력한 아이디 & 비밀번호와 같은 경우
			{
				cout << endl << "===== 로그인 성공 =====" << endl << endl;
				cout << name << "님 환영합니다." << endl << endl;  // 회원가입 시 입력한 이름 포함한 문장 출력
				break;  // 반복문 탈출 후 "swing 자산 관리 서비스" 반복문 실행
			}
			else
			{
				cout << endl << "아이디 혹은 비밀번호가 틀렸습니다." << endl << endl;  // 같지 않은 경우 반복문 실행
			}
		}
	} 
	while (true)
	{
		cout << "********** swing 자산 관리 서비스 **********" << endl;
		cout << "1. 계좌 정보 출력" << endl;
		cout << "2. 총 자산 출력" << endl;
		cout << "3. 로그아웃" << endl << endl;
		cout << "번호를 입력하세요 >> ";
		cin >> number_;  // 두 번째 반복문 번호 입력받기
		cout << endl;

		if (number_ == 1)  // 1을 입력한 경우
		{
			myaccount(&a, &b, &c, &d);  // myaccount() 함수 호출
			cout << endl;
		}
		else if (number_ == 2)  // 2를 입력한 경우
		{
			cout << "현재 " << id << " 자산관리 서비스에 등록된 회원님의 총 자산은 " << total(&a, &b, &c, &d) << "원 입니다." << endl << endl;  // total() 함수 호출
		}
		else  // 3을 입력한 경우
		{
			cout << "===== 로그아웃 =====" << endl << endl;
			cout << "로그아웃 되었습니다. 안녕히 가세요." << endl;
			break;  // 프로그램 실행 종료
		}
	}
}