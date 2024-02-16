#include <iostream>
#include<Windows.h>
#include <iomanip>

using namespace std;
class Nomenclature
{
private:
	// Закрытые поля класса 
	string Nproduct;
	int Wprice;
	int Rmargin;
	int Cproduct = 0;
	int col = 0;
public:
	Nomenclature() :Nproduct(""), Wprice(0), Rmargin(0), Cproduct(0) {} // Инициализируем поля класса нулями
	void input() { // Функция ввода данных 
		cout << "Название товара: ";
		cin >> Nproduct;
		cout << "Оптовая цена (сом): ";
		cin >> Wprice;
		cout << "Розничная наценка (сом): ";
		cin >> Rmargin;
		cout << "Количество товара: " << endl;
		cin >> Cproduct;
		col++;
	}
	~Nomenclature() { cout << endl << "Успешно выполнен!" << endl; } // Деструктор  

	void Searchprice(int n, int* Sum) { // Функция для нахождения чистого дохода от каждого товара
		float  Ch_D = 0, Val_D = 0;
		Val_D = Wprice * Cproduct; // Умножаем оптовую цену и количество товара 
		Ch_D = Val_D - n; // от полученного результата отнимаем налоговый платеж. Таким образом находим чистый доход от товара
		cout << "Чистый доход от товара: " << "' " << Nproduct << " '" << ", составляет : " << Ch_D << endl; // Выводим доход 
		*Sum = Ch_D; // Записываем доход в переменную 
	}

	void Show() { // Вывод данных 
		cout << setw(5) << Nproduct;
		cout << setw(25) << Wprice;
		cout << setw(15) << Rmargin;
		cout << setw(15) << Cproduct;
		cout << endl;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	int val = 0, col = 0;
	int Sum = 0;
	float Sum2 = 0;
	Nomenclature Obj[10]; // количество элементов
	while (val != 4) {
		system("CLS");
		cout << "\tМеню" << endl << endl;
		cout << "1) Ввод данных" << "\n2) Вывод данных" << "\n3) Вывод дохода" << "\n4) Выход" << endl << endl;
		cout << "Выберите из меню: ";
		cin >> val;
		if (val == 1) {
			Obj[col].input(); // Добавляем данные 
			col++; // Увеличиваем количество 
			cout << "Данные записаны!" << endl;
			system("pause");
		}
		else if (val == 2) {
			system("CLS");
			cout << "\t\tВсе товары" << endl << endl;
			cout << setw(5) << "Название товара" << setw(20) << "Оптовая цена" << setw(20) << "Розничная наценка" << setw(20) << "Количество товара" << endl;
			for (int i = 0; i < col; i++) {
				Obj[i].Show();  // Вывод данных 
			}
			system("pause");
		}
		else if (val == 3) {
			int n = 0;
			system("CLS");
			cout << "Введите сумму  налогового платежа: ";
			cin >> n;
			for (int i = 0; i < col; i++) {
				Obj[i].Searchprice(n, &Sum); // Вызываем функция с двумя параметрами.
				Sum2 += Sum; // Суммируем доходы для вычисления общего дохода от товаров 
			}
			cout << endl << "Общий доход: ";
			cout << Sum2 << endl; // Вывод дохода
			Sum2 = 0; // Обнуляем переменную
			system("pause");
		}
	}
	system("CLS");
	cout << "До свидания!" << endl;
	system("pause");
}