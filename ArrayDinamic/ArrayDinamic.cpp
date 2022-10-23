#include <iostream>
#include <time.h>
#include <string>

using namespace std;

long** inputArr(int n); // ���������� ������� ���������� � ����������
long** inputRandArr(int n); // ���������� ������� ���������� ����������
void outArr(long** x, int n); // ����� ������� 
void arrClean(long** x, int n); // ������� �������
int multMain(long** x, int n); // ������������ ��������� ��� ������� ����������
int multSide(long** x, int n); // ������������ ��������� ��� �������� ����������

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	bool f = 0;
	long n = 0;
	long** arr = {0};

	while (flag)
	{
		system("cls");
		cout << "������������ ������ �2 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"������� 2\n"
			"����\n"
			"1) ��������� �������.\n"
			"2) ������� �������.\n"
			"3) ������� �������.\n"
			"4) ���� ���������� �������. ���������, ��� � ������ ������� ������������ ���������,\n������� ��� �������� ����������, ����� ������������ ���������, ������� ��� ������� ����������.\n"
			"5) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "\n������� ���������� �����(��������) � �������: ";
			cin >> n;
			if (n <= 0 || n > 100) // �������� ����� n
			{
				cout << "\n�������� ����, ������� n � ��������� �� 1 �� 100";
				return 1;
			}
			cout << "������� ������ ���������� ������� (0 - � ����������, 1 - ��������): ";
			cin >> f;
			if (f == 0) {
				arr = inputArr(n);
			}
			else {
				inputRandArr(n);
			}
			system("pause");
			break;
		case 2:
			if (n != 0) {
				cout << "����� ������� \n";
				outArr(arr, n);
			}
			else {
				cout << "������ ����.\n";
			}
			system("pause");
			break;
		case 3:
			if (n != 0) {
				n = 0;
				arrClean(arr, n);
			}
			else {
				cout << "������ ����.\n";
			}
			system("pause");
			break;
		case 4:
			if (multMain(arr, n) == multSide(arr, n)) { // ��������, ����� �� ������������ ��������� ��� �������� ���������� � ��� �������
				cout << "� ������ ������� ������������ ���������, ������� ��� �������� ����������,\n����� ������������ ���������, ������� ��� ������� ����������" << endl;
			}
			else {
				cout << "� ������ ������� ������������ ���������, ������� ��� �������� ����������,\n�� ����� ������������ ���������, ������� ��� ������� ����������" << endl;
			}
			system("pause");
			break;
		case 5:
			cout << "�������, �� ��������!" << stop;
			flag = 0;
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

long** inputArr(int n)
{
	long** x = (long**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) // ����, ������ �� �������
	{
		x[i] = (long*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) // ����, ������ �� ��������
		{
			cout << "������� ������� ������� � ������� ������ " << i + 1 << ", � ������� ������� " << j + 1 << ":";
			cin >> x[i][j];
		}
	}

	return x;
}


long** inputRandArr(int n)
{
	long** x = (long**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) // ����, ������ �� �������
	{
		x[i] = (long*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) // ����, ������ �� ��������
		{
			x[i][j] = rand() % 1000; // ��������� ����� �� n<=3 ����
		}
	}

	return x;
}

void arrClean(long** x, int n) {
	for (int i = 0; i < n; i++) // �������� �����
		delete[] x[i];
	delete[] x; // �������� ������� ����������
}

void outArr(long** x, int n) {
	for (int i = 0; i < n; i++) { // ����, ������ �� �������
		for (int j = 0; j < n; j++) { // ����, ������ �� �������
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

int multMain(long** x, int n) {
	int m = 1;
	for (int i = 0; i < (n - 1); i++) { // ����, ��������� ������������ ��������� ��� ������� ����������
		m = x[i][i + 1] * m;
	}
	return m;
}

int multSide(long** x, int n) {
	int m = 1;
	for (int i = 0; i < (n - 1); i++) { // ����, ��������� ������������ ��������� ��� �������� ����������
		m = x[i][n - 2 - i] * m;
	}
	return m;
}