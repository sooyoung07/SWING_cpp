#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    int i;
    int num;
    srand(time(NULL));  // 랜던함 수 생성을 위해 srand() 함수 사용
    int random_num = rand() % 101;  // rand() 함수 사용하여 0부터 100까지의 수 생성

    cout << "랜덤한 수: " << random_num << endl;
    cout << "특정 배수 개수: ";
    cin >> num;
    cout << endl << endl;

    int* multiples = new int[num];  // 입력받은 특정 배수를 저장하기 위한 변수 선언

    for (i = 0; i < num; i++) {
        cout << i + 1 << " 번째 특정 배수: ";
        cin >> multiples[i];

        cout << "<특정 배수만 출력하는 프로그램>" << endl;
        for (int j = 1; j <= random_num; j++) {  // 1부터 랜덤한 수까지 반복문 실행
            if (j % multiples[i] != 0) {  // j가 i번째 특정 배수로 나누어 떨어지지 않으면 continue 실행
                continue;
            }
            cout << j << ", ";  // j가 i번째 특정 배수로 나누어 떨어지면 출력
        }
        cout << endl;

        cout << "<특정 배수 제외 출력하는 프로그램>" << endl;
        for (int j = 1; j <= random_num; j++) {  // 1부터 랜덤한 수까지 반복문 실행
            if (j % multiples[i] == 0) {  // j가 i번째 특정 배수로 나누어 떨어지지 않으면 continue 실행
                continue;
            }
            cout << j << ", ";  // j가 i번째 특정 배수로 나누어 떨어지면 출력
        }
        cout << endl << endl;
    }

}