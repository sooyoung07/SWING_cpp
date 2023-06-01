#include <iostream>
#include <string>
using namespace std;

string todo_list[100];  // 할 일 목록 저장하는 배열
int todo_count = 0;  // 할 일 개수 저장하는 변수 선언과 초기화
string complete_list[100];  // 완료한 일 목록 저장하는 배열
int complete_count = 0;  // 완료한 일 개수 저장하는 변수 선언과 초기화


//할일을 입력받을 때 사용되는 함수
void todoinput() {
    cout << "[ 할 일 추가 ]" << endl << endl;
    cout << "할 일을 입력하세요(완료 후 'end' 입력)" << endl << endl;

    string input;
    cin >> input;

    while (input != "end") {  // 'end'가 입력되지 않으면 반복
        todo_list[todo_count] = input;  // 입력된 할 일을 'todo_list' 배열에 저장
        todo_count++;  // 할 일 개수 증가
        cin >> input;  // 다음 할 일 입력 받음
    }
    cout << endl << "============== TO DO ===============" << endl << endl;
    for (int i = 0; i < todo_count; i++) {
        cout << i + 1 << ". " << todo_list[i] << endl;  // 현재까지의 할 일 목록을 순서대로 출력
    }
}

//완료한 일을 입력받을 때 사용되는 함수
void completeinput()
{
    cout << "[ 완료한 일 추가 ]" << endl << endl;
    cout << "완료한 일의 번호를 입력하세요 : ";

    int index; //할일 목록에 있는 번호를 입력하여 항목을 선택해 완료시킬 수 있도록 함
    cin >> index; //입력받은 번호를 index에 저장

    if (index >= 1 && index <= todo_count) { //index가 유효한 숫자일 때만 실행될 수 있도록 1부터 저장된 수인 todo_count까지의 숫자일때만 실행되도록 제한해줌
        string completed_item = todo_list[index - 1]; //완료된 항목에 선택한 숫자에 해당하는 항목을 가져옴(index에 +1을 하여 배열이 출력될 수 있도록 지정했기 때문에 -1을 해줌)
        complete_list[complete_count] = completed_item; //완료된 항목을 complete_list에 저장
        complete_count++; //완료된 항목의 수를 증가시켜 항목별로 번호를 가지고 저장되도록 함

        // 완료한 일 적용하여 할 일과 완료한 일 목록 업데이트
        for (int i = index - 1; i < todo_count - 1; i++) {
            todo_list[i] = todo_list[i + 1];
        } //선택한 항목을 todolist에서 삭제해주고 번호를 하나씩 앞당겨줄 수 있도록 설정

        todo_count--; //할 일을 하나 완료하였으므로 할일의 수를 하나 줄여줌

        cout << endl << "============= COMPLETE =============" << endl << endl; //구분선 아래로 완료된 항목을 출력
        for (int i = 0; i < complete_count; i++) {
            cout << i + 1 << ". " << complete_list[i] << endl;
        } //저장되어있는 완료된 항목을 출력함(0이 아닌 1부터 번호를 부여하기 위해서 +1하여 출력)

        cout << endl << "============== TO DO ===============" << endl << endl; // 구분선 아래로 업데이트 된 할일 목록 출력
        for (int i = 0; i < todo_count; i++) {
            cout << i + 1 << ". " << todo_list[i] << endl;
        } //완료된 항목을 제외하고 저장되어있는 할 일을 출력함((0이 아닌 1부터 번호를 부여하기 위해서 +1하여 출력)
    }
    else {
        cout << "유효하지 않은 번호입니다." << endl;
    } //todo_count 안에 속해있지 않은 번호 입력 시 유효하지 않은 번호임을 안내
}

int main(void)
{
    int month, day, num;
    int lastday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // 각 달의 일수를 저장하는 배열
    int firstDay[12] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };  // 각 달의 첫째 날의 요일을 저장하는 배열 > 0부터 6까지 차례대로 일요일, 월요일 ,,, 토요일

    cout << "============ 2023 TO DO ============" << endl << endl;
    cout << "원하는 달(월)을 입력하세요 > ";
    cin >> month;

    int calendar[5][7] = { 0 };  // 달력 배열 초기화

    int totalDays = lastday[month - 1];  // 입력받은 달의 총 일수
    int start = firstDay[month - 1];  // 입력받은 달의 첫째 날의 요일
    int day_ = 1;  // 날짜 초기값

    // 1월 1일 이전의 날짜를 공백으로 처리
    for (int i = 0; i < start; i++) {
        calendar[i / 7][i % 7] = 0;
    }
    // 달력 배열에 날짜 채움
    for (int row = start / 7; row < 5; row++) {  // 달력 배열의 행을 시작 인덱스를 이용해 반복
        for (int col = start % 7; col < 7; col++) {  // 달력 배열의 열을 시작 인덱스를 이용해 반복
            if (day_ > totalDays)  // 총 일수보다 큰 경우 반복문 종료
                break;

            calendar[row][col] = day_++;  // 현재 날짜를 달력 배열의 해당 위치에 할당하고 날짜 증가
        }
        start = 0;  // 다음 주의 첫째 요일로 설정
    }

    cout << endl << "============================\n";
    cout << "  일  월  화  수  목  금  토\n";
    cout << "============================\n";

    // 달력 출력
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 7; col++) {
            if (calendar[row][col] != 0)
                printf("%4d", calendar[row][col]);  // 배열 출력 시 요소에 네자리가 할당되어 공백이 포함되어 출력 > 모든 요소가 일정한 열로 정렬
            else
                cout << "    ";
        }
        cout << "\n";
    }

    cout << "============================\n";
    cout << endl << "원하는 날(일)을 입력하세요 > ";
    cin >> day;

    while (1)
    {
        cout << endl << "====================================" << endl << endl;

        cout << "1. 할 일 추가" << endl;
        cout << "2. 완료한 일 추가" << endl;
        cout << "3. 날짜 선택" << endl;
        cout << "4. 종료" << endl << endl;
        cout << "번호를 입력하세요 >> ";
        cin >> num;
        cout << endl;

        //swich문을 사용하여 입력받은 num에 따라 원하는 기능이 실행되도록 함
        switch (num)
        {
        case 1: //1입력 시 할 일을 추가하는 기능을 구현하기 위해 todoinput함수로 이동하여 실행
            todoinput();
            continue;//반복적으로 숫자를 입력받을 수 있도록 continue를 사용함

        case 2: //2입력 시 완료된 항목을 추가하는 기능을 구현하기 위해 completeinput()함수로 이동하여 실행
            completeinput();
            continue;

        case 3: //3을 입력할 경우 날짜를 선택하는 항목으로 돌아가도록 함
            // 추가적으로 달력을 함수로 따로 구현한 후 실행하고자 했지만 달력 구현이 늦어져 코드를 반복해서 적게 되었습니다.
            cout << "원하는 달(월)을 입력하세요 > ";
            cin >> month;
            cout << endl << "============================\n";
            cout << "  일  월  화  수  목  금  토\n";
            cout << "============================\n";

            for (int row = 0; row < 5; row++) { //5개의 행(5주)을 만들도록 반복
                for (int col = 0; col < 7; col++) { //7개의 열(7일)을 만들도록 반복
                    if (calendar[row][col] != 0)
                        printf("%4d", calendar[row][col]);  // 배열 출력 시 요소에 네자리가 할당되어 공백이 포함되어 출력 > 모든 요소가 일정한 열로 정렬
                    else
                        cout << "    ";
                }
                cout << "\n";
            }
            cout << "============================\n";
            cout << endl << "원하는 날(일)을 입력하세요 > ";
            cin >> day;

            cout << endl << "============== TO DO ===============" << endl << endl;
            cout << "날짜: " << month << "월 " << day << "일" << endl << endl;

            for (int i = 0; i < todo_count; i++) {
                cout << i + 1 << ". " << todo_list[i] << endl;
            } //선택한 날짜의 할 일 목록을 출력

            cout << endl << "============= COMPLETE =============" << endl << endl;
            cout << "날짜: " << month << "월 " << day << "일" << endl << endl;

            for (int i = 0; i < complete_count; i++) {
                cout << i + 1 << ". " << complete_list[i] << endl;
            } //선택한 날짜의 완료한 일 목록을 출력
            continue;

        case 4: //4선택 시 프로그램 종료
            cout << "프로그램을 종료합니다." << endl;
            return 0;

        default: //구현된 기능 외 다른 번호를 선택 시 실행되지 않고 다시 번호를 입력받을 수 있도록 함
            cout << "유효하지 않은 번호입니다. 다시 입력하세요." << endl;
            continue;
        }
    }
}
