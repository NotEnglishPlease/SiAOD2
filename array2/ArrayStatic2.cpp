#include <iostream>
#include <time.h>
#include <string>

using namespace std;

const int k = 100;

void inputArr(long(*x)[k], int n); // Заполнение матрицы значениями с клавиатуры
void inputRandArr(long(*x)[k], int n); // Заполнение матрицы рандомными значениями
void outArr(long(*x)[k], int n); // Вывод маасива 
void arrClean(long(*x)[k], int n); // Очистка массива
int multMain(long(*x)[k], int n); // Произведение элементов над главной диагональю
int multSide(long(*x)[k], int n); // Произведение элементов над побочной диагональю

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	bool f = 0;
	long n = 0;
	long arr[k][k] = { {0} };

	while (flag)
	{
		system("cls");
		cout << "Практическая работа №2 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" << "\n\n"
			"Задание 1\n"
			"Меню\n"
			"1) Заполнить матрицу.\n"
			"2) Вывести матрицу.\n"
			"3) Очистить матрицу (обнулить).\n"
			"4) Дана квадратная матрица. Проверить, что в данной матрице произведение элементов,\nстоящих над побочной диагональю, равно произведению элементов, стоящих над главной диагональю.\n"
			"5) Выход из программы.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "\nВведите количество строк(столбцов) в матрице: ";
			cin >> n;
			if (n <= 0 || n > 100) // проверка ввода n
			{
				cout << "\nНеверный ввод, введите n в диапазоне от 1 до 100";
				return 1;
			}
			cout << "Введите способ заполнения массива (0 - с клавиатуры, 1 - рандомно): ";
			cin >> f;
			if (f == 0) { 
				inputArr(arr, n);
			}
			else {
				inputRandArr(arr, n);
			}
			system("pause");
			break;
		case 2:
			if (n != 0) {
				cout << "Вывод массива \n";
				outArr(arr, n);
			}
			else {
				cout << "Массив пуст.\n";
			}
			system("pause");
			break;
		case 3:
			if (n != 0) {
				n = 0;
				arrClean(arr, n);
			}
			else {
				cout << "Массив пуст.\n";
			}
			system("pause");
			break;
		case 4:
			if (multMain(arr, n) == multSide(arr, n)) { // проверка, равны ли произведение элементов над побочной диагональю и над главной
				cout << "В данной матрице произведение элементов, стоящих над побочной диагональю,\nравно произведению элементов, стоящих над главной диагональю" << endl;
			}
			else {
				cout << "В данной матрице произведение элементов, стоящих над побочной диагональю,\nне равно произведению элементов, стоящих над главной диагональю" << endl;
			}
			system("pause");
			break;
		case 5:
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

void inputArr(long(*x)[k], int n) {
	for (int i = 0; i < n; i++) { // цикл, идущий по строкам
		for (int j = 0; j < n; j++) { // цикл, идущий по столбцам
			cout << "Введите элемент матрицы с номером строки " << i + 1 << ", и номером столбца " << j + 1 <<":";
			cin >> x[i][j];
		}
	}
}

void inputRandArr(long(*x)[k], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) { // цикл, идущий по строкам
		for (int j = 0; j < n; j++) { // цикл, идущий по столбцам
			x[i][j]=rand()%1000; // рандомное число из n<=3 цифр
		}
	}
}

void outArr(long(*x)[k], int n) {
	for (int i = 0; i < n; i++) { // цикл, идущий по строкам
		for (int j = 0; j < n; j++) { // цикл, идущий по строкам
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void arrClean(long(*x)[k], int n) {
	for (int i = 0; i < n; i++) { // цикл, идущий по строкам
		for (int j = 0; j < n; j++) { // цикл, идущий по столбцам
			x[i][j] = 0; // обнуление элементов
		}
	}
}

int multMain(long(*x)[k], int n) {
	int m = 1;
	for (int i = 0; i < (n - 1); i++) { // цикл, считающий произведение элементов над главной диагональю
		m = x[i][i+1] * m;
	}
	return m;
}

int multSide(long(*x)[k], int n) {
	int m = 1;
	for (int i = 0; i < (n - 1); i++) { // цикл, считающий произведение элементов над побочной диагональю
		m = x[i][n-2-i] * m;
	}
	return m;
}