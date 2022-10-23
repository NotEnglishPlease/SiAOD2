#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> inputArr(int n, int M, int N); // ���������� ������� ���������� � ����������
void outArr(vector<vector<int>>x, int M, int N); // ����� ������� 
vector<int> mCord(vector<vector<int>>x, int M, int N); // ���������� ��������� m � ���������� ������
vector<int> nCord(vector<vector<int>>x, int M, int N); // ���������� ��������� n � ���������� ������
bool exam(vector<int>x, vector<int>y); // ��������, ����� �� �����-���� 2 ����� �� ����� ������
float task(vector<int>x); // ����� ��������� �������


int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, p_n,p_m;
	long n = 0;
	vector<vector<int>> vec;
	vector<int>vecm;
	vector<int>vecn;

	while (flag)
	{
		system("cls");
		cout << "������������ ������ �2 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"������� 3\n"
			"����\n"
			"1) ��������� ���� ���������.\n"
			"2) ������� ���� ���������.\n"
			"3) ���� ��������� �� n ����� �� ���������.\n����� ������������ ������� ����� ��������� ����� �� ��������� � �������������, ��� ������� ��� ����� �� ����� �� ����� ������.\n"
			"4) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "\n������� ���������� ����� � ��������� (������� 2): ";
			cin >> n;
			if ((n <= 0 || n > 100) || (n%2==1)) // �������� ����� n
			{
				cout << "\n�������� ����";
				return 1;
			}
			cout << "������� ������ ����(mxn), � �������� �������� ����������� �����\n ";
			cout << "M = ";
			cin >> p_m;
			if (p_m <= 0 || p_m > 100) // �������� ����� n
			{
				cout << "\n�������� ����, ������� N � ��������� �� 1 �� 100";
				return 1;
			}
			cout << "N = ";
			cin >> p_n;
			if (p_n <= 0 || p_n > 100) // �������� ����� n
			{
				cout << "\n�������� ����, ������� M � ��������� �� 1 �� 100";
				return 1;
			}
			vec = inputArr(n, p_m, p_n);
			system("pause");
			break;
		case 2:
			if ((p_m != 0) && (p_n!=0)) {
				cout << "����� ���� ��������� \n";
				outArr(vec, p_m,p_n);
			}
			else {
				cout << "������ ����.\n";
			}
			system("pause");
			break;
		case 3:
			vecm = mCord(vec, p_m, p_n);
			vecn = nCord(vec, p_m, p_n);
			if (exam(vecn, vecm) == 0) {
				cout << "������������ ������� ����� ��������� x = " << task(vecm)<<endl;
			}
			else {
				cout << "����� ���� 2 ����� ����� �� ����� �������������� ��� ������������ ������"<<endl;
			}
			system("pause");
			break;
		case 4:
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

vector<vector<int>> inputArr(int n, int M, int N){
	int y, x;
	vector<vector<int>> v(M, vector<int>(N,0));
	for (int i = 0; i < n; i++) // ���������� ���� �����
	{
		cout << "������� ���������� " << i + 1 << " �����\n ";
		cout << "���������� �� �:";
		cin >> x;
		cout << "���������� �� y:";
		cin >> y;
		vector <int> temp; 
		v[x][y] = 1; // ������������ ������� �������� ���������� �� ���������� �����
	}
	return v; // ������� �������
}

void outArr(vector<vector<int>>x, int M, int N) {
	for (int i = 0; i < M; i++) { // ����, ������ �� �������
		for (int j = 0; j < N; j++) { // ����, ������ �� �������
			if (x[i][j] == 0) {
				cout << " ";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
}

vector<int> mCord(vector<vector<int>>x ,int M, int N) {
	vector<int>y;
	for (int i=0;i<M;i++) // ����, ������ �� �������
		for (int j = 0; j < N; j++) // ����, ������ �� ��������
			if (x[i][j] == 1) { // ���� ������� ������� = 1 (������� ����� �� ����������)
				y.push_back(i); // ��������� ���������� m � ����� ���������� ������
			}
	return y; // ������� ������ ����������� �������
}

vector<int> nCord(vector<vector<int>>x, int M, int N) {
	vector<int>y;
	for (int i = 0; i < M; i++) // ����, ������ �� �������
		for (int j = 0; j < N; j++) // ����, ������ �� ��������
			if (x[i][j] == 1) { // ���� ������� ������� = 1 (������� ����� �� ����������)
				y.push_back(j); // ��������� ���������� n � ����� ���������� ������
			}
	return y; // ������� ������ ����������� �������
}

bool exam(vector<int>x, vector<int>y) {
	bool flag = 0;
	for (int i = 0; i < (x.size()-1); i++) // ��������, ����� �� 2 ����� �� ����� ������ �� ���������
		for (int j = i + 1; j < x.size(); j++) {
			if (x[i] == x[j]) {
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
	}
	for (int i = 0; i < (y.size() - 1); i++) // ��������, ����� �� 2 ����� �� ����� ������ �� ���������
		for (int j = i + 1; j < y.size(); j++) {
			if (y[i] == y[j]) {
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
		}
	return flag;
}

float task(vector<int>x) {
	int l = x.size() / 2; // ���������� ����� ����������
	if ((x.size()) % 2 == 0) // ���� ���������� ����� ������
		return (x[l]+x[l+1]) / 2.0; // ���������� �������� �� ����� ���� ������� ��������� 
	else
		return x[l]; // ����� ���������� ������� ����������
}