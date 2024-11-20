#include <iostream>
#include <limits>
#include <ctime>

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    std::cout << "Необходимо вывести массив в обратном порядке.\n";
    std::cout << "Выполнил Стрелков Ярослав Михайлович, студент группы 453505, вариант 2.\n";
    int a;

    while (true) {
        std::cout << "Для ввода контрольных значений нажмите 1\n";
        std::cout << "Для выхода из программы нажмите 2\n";
        std::cin >> a;

        switch (a) {
        case 1: {
            const int max = 1000000;
            long long k;
            long long arr[max];
            std::cout << "Введите длинну массива\n";
            std::cin >> k;
            if (std::cin.fail() || k <= 0 || k > max) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Введите числа в массив состоящий из" << " " << k << " " << "элементов\n";
            for (int i = 0; i < k; i++) {
                arr[i] = rand() % 53;
            }

            for (int i = 0; i < k / 2; i++) {
                long long temp = arr[i];
                arr[i] = arr[k - 1 - i];
                arr[k - 1 - i] = temp;
            }

            std::cout << "Массив в обратном порядке: ";
            for (int i = 0; i < k; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;  
        }
        break;
        case 2:
            return 0;
        default:
            std::cout << "Ошибка ввода\n";
            break;
        }
    }
    return 0;
}
