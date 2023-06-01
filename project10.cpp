#include <iostream>
#include <string>
using namespace std;

string todo_list[100];  // �� �� ��� �����ϴ� �迭
int todo_count = 0;  // �� �� ���� �����ϴ� ���� ����� �ʱ�ȭ
string complete_list[100];  // �Ϸ��� �� ��� �����ϴ� �迭
int complete_count = 0;  // �Ϸ��� �� ���� �����ϴ� ���� ����� �ʱ�ȭ


//������ �Է¹��� �� ���Ǵ� �Լ�
void todoinput() {
    cout << "[ �� �� �߰� ]" << endl << endl;
    cout << "�� ���� �Է��ϼ���(�Ϸ� �� 'end' �Է�)" << endl << endl;

    string input;
    cin >> input;

    while (input != "end") {  // 'end'�� �Էµ��� ������ �ݺ�
        todo_list[todo_count] = input;  // �Էµ� �� ���� 'todo_list' �迭�� ����
        todo_count++;  // �� �� ���� ����
        cin >> input;  // ���� �� �� �Է� ����
    }
    cout << endl << "============== TO DO ===============" << endl << endl;
    for (int i = 0; i < todo_count; i++) {
        cout << i + 1 << ". " << todo_list[i] << endl;  // ��������� �� �� ����� ������� ���
    }
}

//�Ϸ��� ���� �Է¹��� �� ���Ǵ� �Լ�
void completeinput()
{
    cout << "[ �Ϸ��� �� �߰� ]" << endl << endl;
    cout << "�Ϸ��� ���� ��ȣ�� �Է��ϼ��� : ";

    int index; //���� ��Ͽ� �ִ� ��ȣ�� �Է��Ͽ� �׸��� ������ �Ϸ��ų �� �ֵ��� ��
    cin >> index; //�Է¹��� ��ȣ�� index�� ����

    if (index >= 1 && index <= todo_count) { //index�� ��ȿ�� ������ ���� ����� �� �ֵ��� 1���� ����� ���� todo_count������ �����϶��� ����ǵ��� ��������
        string completed_item = todo_list[index - 1]; //�Ϸ�� �׸� ������ ���ڿ� �ش��ϴ� �׸��� ������(index�� +1�� �Ͽ� �迭�� ��µ� �� �ֵ��� �����߱� ������ -1�� ����)
        complete_list[complete_count] = completed_item; //�Ϸ�� �׸��� complete_list�� ����
        complete_count++; //�Ϸ�� �׸��� ���� �������� �׸񺰷� ��ȣ�� ������ ����ǵ��� ��

        // �Ϸ��� �� �����Ͽ� �� �ϰ� �Ϸ��� �� ��� ������Ʈ
        for (int i = index - 1; i < todo_count - 1; i++) {
            todo_list[i] = todo_list[i + 1];
        } //������ �׸��� todolist���� �������ְ� ��ȣ�� �ϳ��� �մ���� �� �ֵ��� ����

        todo_count--; //�� ���� �ϳ� �Ϸ��Ͽ����Ƿ� ������ ���� �ϳ� �ٿ���

        cout << endl << "============= COMPLETE =============" << endl << endl; //���м� �Ʒ��� �Ϸ�� �׸��� ���
        for (int i = 0; i < complete_count; i++) {
            cout << i + 1 << ". " << complete_list[i] << endl;
        } //����Ǿ��ִ� �Ϸ�� �׸��� �����(0�� �ƴ� 1���� ��ȣ�� �ο��ϱ� ���ؼ� +1�Ͽ� ���)

        cout << endl << "============== TO DO ===============" << endl << endl; // ���м� �Ʒ��� ������Ʈ �� ���� ��� ���
        for (int i = 0; i < todo_count; i++) {
            cout << i + 1 << ". " << todo_list[i] << endl;
        } //�Ϸ�� �׸��� �����ϰ� ����Ǿ��ִ� �� ���� �����((0�� �ƴ� 1���� ��ȣ�� �ο��ϱ� ���ؼ� +1�Ͽ� ���)
    }
    else {
        cout << "��ȿ���� ���� ��ȣ�Դϴ�." << endl;
    } //todo_count �ȿ� �������� ���� ��ȣ �Է� �� ��ȿ���� ���� ��ȣ���� �ȳ�
}

int main(void)
{
    int month, day, num;
    int lastday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // �� ���� �ϼ��� �����ϴ� �迭
    int firstDay[12] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };  // �� ���� ù° ���� ������ �����ϴ� �迭 > 0���� 6���� ���ʴ�� �Ͽ���, ������ ,,, �����

    cout << "============ 2023 TO DO ============" << endl << endl;
    cout << "���ϴ� ��(��)�� �Է��ϼ��� > ";
    cin >> month;

    int calendar[5][7] = { 0 };  // �޷� �迭 �ʱ�ȭ

    int totalDays = lastday[month - 1];  // �Է¹��� ���� �� �ϼ�
    int start = firstDay[month - 1];  // �Է¹��� ���� ù° ���� ����
    int day_ = 1;  // ��¥ �ʱⰪ

    // 1�� 1�� ������ ��¥�� �������� ó��
    for (int i = 0; i < start; i++) {
        calendar[i / 7][i % 7] = 0;
    }
    // �޷� �迭�� ��¥ ä��
    for (int row = start / 7; row < 5; row++) {  // �޷� �迭�� ���� ���� �ε����� �̿��� �ݺ�
        for (int col = start % 7; col < 7; col++) {  // �޷� �迭�� ���� ���� �ε����� �̿��� �ݺ�
            if (day_ > totalDays)  // �� �ϼ����� ū ��� �ݺ��� ����
                break;

            calendar[row][col] = day_++;  // ���� ��¥�� �޷� �迭�� �ش� ��ġ�� �Ҵ��ϰ� ��¥ ����
        }
        start = 0;  // ���� ���� ù° ���Ϸ� ����
    }

    cout << endl << "============================\n";
    cout << "  ��  ��  ȭ  ��  ��  ��  ��\n";
    cout << "============================\n";

    // �޷� ���
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 7; col++) {
            if (calendar[row][col] != 0)
                printf("%4d", calendar[row][col]);  // �迭 ��� �� ��ҿ� ���ڸ��� �Ҵ�Ǿ� ������ ���ԵǾ� ��� > ��� ��Ұ� ������ ���� ����
            else
                cout << "    ";
        }
        cout << "\n";
    }

    cout << "============================\n";
    cout << endl << "���ϴ� ��(��)�� �Է��ϼ��� > ";
    cin >> day;

    while (1)
    {
        cout << endl << "====================================" << endl << endl;

        cout << "1. �� �� �߰�" << endl;
        cout << "2. �Ϸ��� �� �߰�" << endl;
        cout << "3. ��¥ ����" << endl;
        cout << "4. ����" << endl << endl;
        cout << "��ȣ�� �Է��ϼ��� >> ";
        cin >> num;
        cout << endl;

        //swich���� ����Ͽ� �Է¹��� num�� ���� ���ϴ� ����� ����ǵ��� ��
        switch (num)
        {
        case 1: //1�Է� �� �� ���� �߰��ϴ� ����� �����ϱ� ���� todoinput�Լ��� �̵��Ͽ� ����
            todoinput();
            continue;//�ݺ������� ���ڸ� �Է¹��� �� �ֵ��� continue�� �����

        case 2: //2�Է� �� �Ϸ�� �׸��� �߰��ϴ� ����� �����ϱ� ���� completeinput()�Լ��� �̵��Ͽ� ����
            completeinput();
            continue;

        case 3: //3�� �Է��� ��� ��¥�� �����ϴ� �׸����� ���ư����� ��
            // �߰������� �޷��� �Լ��� ���� ������ �� �����ϰ��� ������ �޷� ������ �ʾ��� �ڵ带 �ݺ��ؼ� ���� �Ǿ����ϴ�.
            cout << "���ϴ� ��(��)�� �Է��ϼ��� > ";
            cin >> month;
            cout << endl << "============================\n";
            cout << "  ��  ��  ȭ  ��  ��  ��  ��\n";
            cout << "============================\n";

            for (int row = 0; row < 5; row++) { //5���� ��(5��)�� ���鵵�� �ݺ�
                for (int col = 0; col < 7; col++) { //7���� ��(7��)�� ���鵵�� �ݺ�
                    if (calendar[row][col] != 0)
                        printf("%4d", calendar[row][col]);  // �迭 ��� �� ��ҿ� ���ڸ��� �Ҵ�Ǿ� ������ ���ԵǾ� ��� > ��� ��Ұ� ������ ���� ����
                    else
                        cout << "    ";
                }
                cout << "\n";
            }
            cout << "============================\n";
            cout << endl << "���ϴ� ��(��)�� �Է��ϼ��� > ";
            cin >> day;

            cout << endl << "============== TO DO ===============" << endl << endl;
            cout << "��¥: " << month << "�� " << day << "��" << endl << endl;

            for (int i = 0; i < todo_count; i++) {
                cout << i + 1 << ". " << todo_list[i] << endl;
            } //������ ��¥�� �� �� ����� ���

            cout << endl << "============= COMPLETE =============" << endl << endl;
            cout << "��¥: " << month << "�� " << day << "��" << endl << endl;

            for (int i = 0; i < complete_count; i++) {
                cout << i + 1 << ". " << complete_list[i] << endl;
            } //������ ��¥�� �Ϸ��� �� ����� ���
            continue;

        case 4: //4���� �� ���α׷� ����
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;

        default: //������ ��� �� �ٸ� ��ȣ�� ���� �� ������� �ʰ� �ٽ� ��ȣ�� �Է¹��� �� �ֵ��� ��
            cout << "��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
            continue;
        }
    }
}