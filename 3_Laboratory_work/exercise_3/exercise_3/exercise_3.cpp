#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;
class Soft
{
private:
	// Закрытые поля класса 
	string SName;
	string DName;
	string SSize;
	int Day;
	int Month;
	int Year;
public:
	// Инициализируем поля класса нулями(конструктор по умолчанию
	Soft() :SName(""), DName(""), SSize(""), Month(0), Day(0), Year(0) {}
	// Деструктор
	~Soft()
	{
		cout << endl << "Успешно выполнено" << endl;
	}
	// Функция ввода
	void input()
	{
		cout << "Введите название программы: ";
		cin >> SName;
		cout << "Введите наименование разработчика: ";
		cin >> DName;
		cout << "Введите занимаемый объем: ";
		cin >> SSize;
	f:cout << "Введите дату завершения лицензии *День, Месяц, Год*: ";
		// Ввод даты 
		cin >> Day >> Month >> Year;
		// Проверка правильность введенных данных 
		if (Day > 31 || Month > 12)
		{
			// Если не правильно, то выводим сообщение 
			cout << "Введите день, не больше 31, месяц не больше 12!" << endl;
			goto f;
		}
	}
	// Функция для вычисления дня 
	void ColDay()
	{
		// для ввода даты 
		int DY, MN, YR;
		system("CLS");
		// Вводим дату
	f2:	cout << "Введите сегодняшнюю дату (День, Месяц, Год): ";
		cin >> DY >> MN >> YR;
		// Проверка введенных данных 
		if (DY > 31 || MN > 12)
		{
			cout << "Ошибка! Введите день, не больше 31 и месяц не больше 12!!" << endl;
			goto f2;
		}
		else
		{
			// date_1 - это сегодняшняя дата в секундах 
			time_t date_1 = dateSoft(DY, MN, YR);
			// date_2 - это дата окончания лицензии ПО в секундах 
			time_t date_2 = dateSoft(Day, Month, Year);
			// Проверяем даты. Если дата окончания лицензии меньше сегод.даты, то выводим сообщение 
			if (date_1 > date_2)
			{
				cout << "Срок действия лицензии уже истек!" << endl;
			}
			else
			{
				// Если иначе, то вычисляем разницу между двумя датами 
				// Возвращает разность в секундах  между date_2 и date_1
				double sec = difftime(date_2, date_1);
				// Получаем количество дней. Переменная длинного целого числа 
				long days = (sec / ((3600 * 24)));
				cout << "Число дней между ";
				if (Day < 10)
				{
					cout << "0" << Day << ".";
				}
				else
				{
					cout << Day << ".";
				}
				if (Month < 10)
				{
					cout << "0" << Month << ".";
				}
				else
				{
					cout << Month << ".";
				}
				cout << Year << " и ";
				if (DY < 10)
				{
					cout << "0" << DY << ".";
				}
				else
				{
					cout << DY << ".";
				}
				if (MN < 10)
				{
					cout << "0" << MN << ".";
				}
				else
				{
					cout << MN << ".";
				}
				cout << YR << " составляет: " << days << endl;
			}
		}
		cout << endl << endl;
	}
	// Функция для получения даты из введенной даты
	time_t dateSoft(int day, int month, int year)
	{
		// Временная структура 
		tm tmp = tm();
		// Поле структуры 
		tmp.tm_mday = day;
		// из месяца отнимаем 1, так как диапазон месяца от 0 до 11
		tmp.tm_mon = month - 1;
		// Количество лет с 1900 года
		tmp.tm_year = year - 1900;
		// Функция восстанавливает полную дату и время. Возвращает количество секунд из даты
		return mktime(&tmp);
	}
	// Вывод данных
	void Show()
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
		cout << "| Название программы | Имя разработчика | Занимаемый объем | Дата лицензии |" << endl;
		cout << "*--------------------|------------------|------------------|---------------*" << endl;
		cout << "| " << SName << setw(17) << "| " << DName << setw(10) << "| " << SSize << setw(16) << "| ";
		// Условия для более кооректного вывода даты 
		if (Day < 10)
		{
			cout << "0" << Day << ".";
		}
		else
		{
			cout << Day << ".";
		}
		if (Month < 10)
		{
			cout << "0" << Month << ".";
		}
		else
		{
			cout << Month << ".";
		}
		cout << Year << setw(5) << "|";
		cout << endl << endl;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// Создаем объект
	Soft prog;
	int value = 0;
	// Пока пользователь не введет 4
	while (value != 4)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("CLS");
		cout << "\tМеню" << endl;
		cout << "1) Ввод ПО" << "\n2) Вывод ПО" << "\n3) Вычислить количество дней" << endl;
		cout << endl << "Введите номер операции: ";
		cin >> value;
		if (value == 1)
		{
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			system("CLS");
			prog.input();
			cout << "Данные записаны!" << endl;
			system("pause");
			system("CLS");
		}
		else if (value == 2)
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			system("CLS");

			cout << "*--------------------------------------------------------------------------*" << endl;
			cout << "|                   Сведения о программном обеспечении                     |" << endl;
			prog.Show();
			system("pause");
			system("CLS");
		}
		else if (value == 3)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			prog.ColDay();
			system("pause");
			system("CLS");
		}
	}

	system("CLS");
	cout << "До свидания!" << endl;
	system("pause");
}
