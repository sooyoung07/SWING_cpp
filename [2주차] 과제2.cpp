#include <iostream>
using namespace std;

int main(void) {

    int seat[10][6] = { };  // 10�� 6���� �迭 ����
    int a, width, length, new_length, new_width;  // width = ����, length = ����

    do {
        // �޴� ���
        cout << " ** ����� �¼� ���� �ý��� ** " << endl << endl;
        cout << "1. �ű� ����" << endl;
        cout << "2. ���� ����" << endl;
        cout << "3. ���α׷� ����" << endl << endl;
        cout << "��ȣ�� �Է��ϼ���: ";
        cin >> a;

        if (a == 1) {  // 1�� �Է��� ���
            // ���� ���� ��Ȳ�� ���
            cout << endl;
            cout << "1 2 3" << "\t" << "4 5 6" << endl;
            cout << "-------------" << endl;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 3) {
                        cout << "\t";
                    }
                    cout << seat[i][j] << " ";  // �¼� �迭�� ���� ���
                }
                cout << endl;
            }

            cout << endl << "�, ���° �¼��� �����Ͻðڽ��ϱ�? ";
            cin >> length >> width;

            if (seat[length - 1][width - 1] == 0) {
                seat[length - 1][width - 1] = 1;
                cout << "����Ǿ����ϴ�." << endl;
            }  
            else {
                cout << "�̹� ����� �ڸ��Դϴ�." << endl;
            }
        }

        else if (a == 2) {  // 2�� �Է��� ���
            // ���� ���� ��Ȳ�� ���
            cout << endl;
            cout << "1 2 3" << "\t" << "4 5 6" << endl;
            cout << "-------------" << endl;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 3) {
                        cout << "\t";
                    }
                    cout << seat[i][j] << " ";  // �¼� �迭�� ���� ���
                }
                cout << endl;
            }

            cout << endl << "���� �¼��� �����ϰ��� �ϴ� �¼��� ���� ��, ��ȣ ������ �Է��� �ּ���: ";
            cin >> length >> width >> new_length >> new_width;

            if (seat[length - 1][width - 1] == 0) {
                cout << "�¼��� ��Ȯ�� �Է��� �ּ���." << endl;
            }
            else if (seat[new_length - 1][new_width - 1] == 1) {
                cout << "�̹� ����� �¼��Դϴ�. �ٸ� �¼��� ������ �ּ���." << endl;
            }
            else {
                seat[new_length - 1][new_width - 1] = 1;
                seat[length - 1][width - 1] = 0;
                cout << "�¼��� ����Ǿ����ϴ�." << endl;
            }
        }

        else if (a == 3) {  // 3�� �Է��� ���
            cout << "���α׷��� �����մϴ�." << endl;
        }

        else {  // 1,2,3 �̿��� ���� �Է��� ���
            cout << "�ùٸ� ���ڸ� �Է��� �ּ���." << endl;
        }

    } while (a != 3);

}