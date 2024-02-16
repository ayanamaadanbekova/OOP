#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class timer
{
    int seconds;
public:
    // Секунды задаются строкой в конструкторе - перегрузка
    timer(char* t)
    {
        seconds = atoi(t);
    }
    // Секунды задаются целым числом в конструкторе- перегрузка
    timer(int t)
    {
        seconds = t;
    }
    // Время задается в минутах и секундах - перегрузка
    timer(int min, int sec)
    {
        seconds = min * 60 + sec;
    }
    void run()
    {
        clock_t t1, t2;
        t1 = t2 = clock() / CLK_TCK;
        while (seconds) {
            if (t1 / CLK_TCK + 1 <= (t2 = clock()) / CLK_TCK) {
                seconds--;
                t1 = t2;
                cout << seconds << " ";
            }
        }
        cout << "\n\a"; // звонок}
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int secInput;
    cout << "Введите количество секунд: ";
    cin >> secInput;
    timer a(secInput);
    cout << "Обратный отсчет на " << secInput << " секунд :" << endl;
    a.run();

    int minInput, secInput2;
    cout << "Введите количество минут: ";
    cin >> minInput;
    cout << "Введите количество секунд: ";
    cin >> secInput2;
    timer b(minInput, secInput2);
    cout << "Обратный отсчет на " << minInput << " минут " << secInput2 << " секунд :" << endl;
    b.run();

    return 0;
}
