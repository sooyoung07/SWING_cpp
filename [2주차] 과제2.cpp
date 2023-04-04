#include <iostream>
using namespace std;

int main(void) {

    int seat[10][6] = { };  // 10행 6열의 배열 선언
    int a, width, length, new_length, new_width;  // width = 가로, length = 세로

    do {
        // 메뉴 출력
        cout << " ** 비행기 좌석 예약 시스템 ** " << endl << endl;
        cout << "1. 신규 예약" << endl;
        cout << "2. 예약 변경" << endl;
        cout << "3. 프로그램 종료" << endl << endl;
        cout << "번호를 입력하세요: ";
        cin >> a;

        if (a == 1) {  // 1을 입력한 경우
            // 현재 예약 상황을 출력
            cout << endl;
            cout << "1 2 3" << "\t" << "4 5 6" << endl;
            cout << "-------------" << endl;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 3) {
                        cout << "\t";
                    }
                    cout << seat[i][j] << " ";  // 좌석 배열의 값을 출력
                }
                cout << endl;
            }

            cout << endl << "몇열, 몇번째 좌석을 예약하시겠습니까? ";
            cin >> length >> width;

            if (seat[length - 1][width - 1] == 0) {
                seat[length - 1][width - 1] = 1;
                cout << "예약되었습니다." << endl;
            }  
            else {
                cout << "이미 예약된 자리입니다." << endl;
            }
        }

        else if (a == 2) {  // 2를 입력한 경우
            // 현재 예약 상황을 출력
            cout << endl;
            cout << "1 2 3" << "\t" << "4 5 6" << endl;
            cout << "-------------" << endl;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 3) {
                        cout << "\t";
                    }
                    cout << seat[i][j] << " ";  // 좌석 배열의 값을 출력
                }
                cout << endl;
            }

            cout << endl << "현재 좌석과 변경하고자 하는 좌석을 각각 열, 번호 순서로 입력해 주세요: ";
            cin >> length >> width >> new_length >> new_width;

            if (seat[length - 1][width - 1] == 0) {
                cout << "좌석을 정확히 입력해 주세요." << endl;
            }
            else if (seat[new_length - 1][new_width - 1] == 1) {
                cout << "이미 예약된 좌석입니다. 다른 좌석을 선택해 주세요." << endl;
            }
            else {
                seat[new_length - 1][new_width - 1] = 1;
                seat[length - 1][width - 1] = 0;
                cout << "좌석이 변경되었습니다." << endl;
            }
        }

        else if (a == 3) {  // 3을 입력한 경우
            cout << "프로그램을 종료합니다." << endl;
        }

        else {  // 1,2,3 이외의 수를 입력한 경우
            cout << "올바른 숫자를 입력해 주세요." << endl;
        }

    } while (a != 3);

}