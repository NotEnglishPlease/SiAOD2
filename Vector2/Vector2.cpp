#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> inputArr(int n, int M, int N); // Заполнение матрицы значениями с клавиатуры
void outArr(vector<vector<int>>x, int M, int N); // Вывод маасива 
vector<int> mCord(vector<vector<int>>x, int M, int N); // Перезапись координат m в одномерный вектор
vector<int> nCord(vector<vector<int>>x, int M, int N); // Перезапись координат n в одномерный вектор
bool exam(vector<int>x, vector<int>y); // Проверка, лежат ли какие-либо 2 точки на одной прямой
float task(vector<int>x); // Поиск уравнения медианы


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
		cout << "Практическая работа №2 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" << "\n\n"
			"Задание 3\n"
			"Меню\n"
			"1) Заполнить поле плоскости.\n"
			"2) Вывести поле плоскости.\n"
			"3) Дано множество из n точек на плоскости.\nНайти вертикальную медиану этого множества точек на плоскости в предположении, что никакие две точки не лежат на одной прямой.\n"
			"4) Выход из программы.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "\nВведите количество точек в плоскости (кратное 2): ";
			cin >> n;
			if ((n <= 0 || n > 100) || (n%2==1)) // проверка ввода n
			{
				cout << "\nНеверный ввод";
				return 1;
			}
			cout << "Введите размер поля(mxn), в пределах которого расположены точки\n ";
			cout << "M = ";
			cin >> p_m;
			if (p_m <= 0 || p_m > 100) // проверка ввода n
			{
				cout << "\nНеверный ввод, введите N в диапазоне от 1 до 100";
				return 1;
			}
			cout << "N = ";
			cin >> p_n;
			if (p_n <= 0 || p_n > 100) // проверка ввода n
			{
				cout << "\nНеверный ввод, введите M в диапазоне от 1 до 100";
				return 1;
			}
			vec = inputArr(n, p_m, p_n);
			system("pause");
			break;
		case 2:
			if ((p_m != 0) && (p_n!=0)) {
				cout << "Вывод поля плоскости \n";
				outArr(vec, p_m,p_n);
			}
			else {
				cout << "Массив пуст.\n";
			}
			system("pause");
			break;
		case 3:
			vecm = mCord(vec, p_m, p_n);
			vecn = nCord(vec, p_m, p_n);
			if (exam(vecn, vecm) == 0) {
				cout << "Вертикальная медиана имеет уравнение x = " << task(vecm)<<endl;
			}
			else {
				cout << "Какие либо 2 точки лежат на одной горизонтальной или вертикальной прямой"<<endl;
			}
			system("pause");
			break;
		case 4:
			cout << "Спасибо, до свидания!" << stop;
			flag = 0;
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
			system("pause");
		}
	}
	return 0;
}

vector<vector<int>> inputArr(int n, int M, int N){
	int y, x;
	vector<vector<int>> v(M, vector<int>(N,0));
	for (int i = 0; i < n; i++) // заполнение поля точек
	{
		cout << "Введите координаты " << i + 1 << " точки\n ";
		cout << "Координата по х:";
		cin >> x;
		cout << "Координата по y:";
		cin >> y;
		vector <int> temp; 
		v[x][y] = 1; // призваивание еденицы значению переменной на координате точки
	}
	return v; // возврат вектора
}

void outArr(vector<vector<int>>x, int M, int N) {
	for (int i = 0; i < M; i++) { // цикл, идущий по строкам
		for (int j = 0; j < N; j++) { // цикл, идущий по строкам
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
	for (int i=0;i<M;i++) // цикл, идущий по строкам
		for (int j = 0; j < N; j++) // цикл, идущий по столбцам
			if (x[i][j] == 1) { // если текущий элемент = 1 (наличие точки на координате)
				y.push_back(i); // добавляем координату m в новый одномерный вектор
			}
	return y; // возврат нового одномерного вектора
}

vector<int> nCord(vector<vector<int>>x, int M, int N) {
	vector<int>y;
	for (int i = 0; i < M; i++) // цикл, идущий по строкам
		for (int j = 0; j < N; j++) // цикл, идущий по столбцам
			if (x[i][j] == 1) { // если текущий элемент = 1 (наличие точки на координате)
				y.push_back(j); // добавляем координату n в новый одномерный вектор
			}
	return y; // возврат нового одномерного вектора
}

bool exam(vector<int>x, vector<int>y) {
	bool flag = 0;
	for (int i = 0; i < (x.size()-1); i++) // проверка, лежат ли 2 точки на одной прямой по вертикали
		for (int j = i + 1; j < x.size(); j++) {
			if (x[i] == x[j]) {
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
	}
	for (int i = 0; i < (y.size() - 1); i++) // проверка, лежат ли 2 точки на одной прямой по вертикали
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
	int l = x.size() / 2; // координаты точки посередине
	if ((x.size()) % 2 == 0) // если количество точек четное
		return (x[l]+x[l+1]) / 2.0; // возвращаем половину от суммы двух средних координат 
	else
		return x[l]; // иначе возвращаем среднюю координату
}