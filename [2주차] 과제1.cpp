#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    int i;
    int num;
    srand(time(NULL));  // ������ �� ������ ���� srand() �Լ� ���
    int random_num = rand() % 101;  // rand() �Լ� ����Ͽ� 0���� 100������ �� ����

    cout << "������ ��: " << random_num << endl;
    cout << "Ư�� ��� ����: ";
    cin >> num;
    cout << endl << endl;

    int* multiples = new int[num];  // �Է¹��� Ư�� ����� �����ϱ� ���� ���� ����

    for (i = 0; i < num; i++) {
        cout << i + 1 << " ��° Ư�� ���: ";
        cin >> multiples[i];

        cout << "<Ư�� ����� ����ϴ� ���α׷�>" << endl;
        for (int j = 1; j <= random_num; j++) {  // 1���� ������ ������ �ݺ��� ����
            if (j % multiples[i] != 0) {  // j�� i��° Ư�� ����� ������ �������� ������ continue ����
                continue;
            }
            cout << j << ", ";  // j�� i��° Ư�� ����� ������ �������� ���
        }
        cout << endl;

        cout << "<Ư�� ��� ���� ����ϴ� ���α׷�>" << endl;
        for (int j = 1; j <= random_num; j++) {  // 1���� ������ ������ �ݺ��� ����
            if (j % multiples[i] == 0) {  // j�� i��° Ư�� ����� ������ �������� ������ continue ����
                continue;
            }
            cout << j << ", ";  // j�� i��° Ư�� ����� ������ �������� ���
        }
        cout << endl << endl;
    }

}