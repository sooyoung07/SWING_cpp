#include <iostream>
#include <string>
using namespace std;

void myaccount(int* p, int* q, int* r, int* s)  // ���� ���� ��� �Լ�
{
	cout << "------------------- swing ���� ���� -------------------" << endl;
	cout << "l   " << "����" << "   l   " << "����" << "   ��   " << "����û��" << "   ��   " << "�ֽİ���" << "   ��" << endl;
	cout << "l   " << *p << "   l   " << *q << "   l       " << *r << "        l       " << *s << "     l" << endl;
	cout << "-------------------------------------------------------" << endl;
}

int total(int* p, int* q, int* r, int* s)  // �� �ڻ� ��� �Լ�
{
	int total_money = *p + *q + *r + *s;
	return total_money;
}

int main(void)
{
	int number, number_;  // ù ��° �ݺ��� ���ڿ� �� ��° �ݺ��� ���� ���� ����
	string name, id, password, id_, password_;  // ȸ������ �̸�, ȸ������ ���̵�, ȸ������ ��й�ȣ, �α��� ���̵�, �α��� ��й�ȣ ���� ���� 

	int a = 5000;  // ���� ���� ����� �� ����
	int b = 4000;  // ���� ���� ����� �� ����
	int c = 0;  // ����û�� ���� ����� �� ����
	int d = 10;  // �ֽİ��� ���� ����� �� ����

	while (true)
	{
		cout << " ********** swing ���� ********** " << endl;
		cout << "1. ȸ������" << endl;
		cout << "2. �α���" << endl << endl;
		cout << "��ȣ�� �Է��ϼ��� >> ";
		cin >> number;  // ù ��° �ݺ��� ��ȣ �Է¹ޱ�

		if (number == 1)  // 1�� �Է��� ���
		{
			cout << endl;
			cout << "�̸�: ";
			cin >> name;  // ȸ������ �̸� �Է¹ޱ�
			cout << "���̵�: ";
			cin >> id;  // ȸ������ ���̵� �Է¹ޱ�
			cout << "��й�ȣ: ";
			cin >> password;  // ȸ������ ��й�ȣ �Է¹ޱ�
			cout << endl << "===== ȸ������ ���� =====" << endl << endl;
		}
		else if (number == 2)  // 2�� �Է��� ���
		{
			cout << endl;
			cout << "���̵�: ";
			cin >> id_;  // �α��� ���̵� �Է¹ޱ�
			cout << "��й�ȣ: ";
			cin >> password_;  // �α��� ��й�ȣ �Է¹ޱ�

			if (id == id_ && password == password_)  // ȸ������ �� �Է��� ���̵� & ��й�ȣ�� �α��� �� �Է��� ���̵� & ��й�ȣ�� ���� ���
			{
				cout << endl << "===== �α��� ���� =====" << endl << endl;
				cout << name << "�� ȯ���մϴ�." << endl << endl;  // ȸ������ �� �Է��� �̸� ������ ���� ���
				break;  // �ݺ��� Ż�� �� "swing �ڻ� ���� ����" �ݺ��� ����
			}
			else
			{
				cout << endl << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << endl;  // ���� ���� ��� �ݺ��� ����
			}
		}
	} 
	while (true)
	{
		cout << "********** swing �ڻ� ���� ���� **********" << endl;
		cout << "1. ���� ���� ���" << endl;
		cout << "2. �� �ڻ� ���" << endl;
		cout << "3. �α׾ƿ�" << endl << endl;
		cout << "��ȣ�� �Է��ϼ��� >> ";
		cin >> number_;  // �� ��° �ݺ��� ��ȣ �Է¹ޱ�
		cout << endl;

		if (number_ == 1)  // 1�� �Է��� ���
		{
			myaccount(&a, &b, &c, &d);  // myaccount() �Լ� ȣ��
			cout << endl;
		}
		else if (number_ == 2)  // 2�� �Է��� ���
		{
			cout << "���� " << id << " �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� " << total(&a, &b, &c, &d) << "�� �Դϴ�." << endl << endl;  // total() �Լ� ȣ��
		}
		else  // 3�� �Է��� ���
		{
			cout << "===== �α׾ƿ� =====" << endl << endl;
			cout << "�α׾ƿ� �Ǿ����ϴ�. �ȳ��� ������." << endl;
			break;  // ���α׷� ���� ����
		}
	}
}