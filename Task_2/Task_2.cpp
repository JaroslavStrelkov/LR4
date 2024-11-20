#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Найти количество отрицательных чисел выше главной диагонали.\n";
    std::cout << "Выполнил Стрелков Ярослав Михайлович, студент группы 453505, вариант 2.\n";
    int a;

    while (true) {
        std::cout << "Для ввода контрольных значений нажмите 1\n";
        std::cout << "Для выхода из программы нажмите 2\n";
        std::cin >> a;
        if (std::cin.fail()) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

        switch (a) {
        case 1: {
            const int maxstr = 1000;
            const int maxstl = 1000;
            long long str,stl, n = 0;
            long long arr[maxstr][maxstl];
            std::cout << "Введите количчество строк\n";
            std::cin >> str;
            if (std::cin.fail() || str <= 0 || str > maxstr) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Введите количество столбцов\n";
            std::cin >> stl;
            if (std::cin.fail() || stl <= 0 || stl > maxstr) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Заполните матрицу.\n";
            for (int i = 0; i < str; i++) {
                for (int j = 0; j < stl; j++) {
                    std::cin >> arr[i][j];
                    
                }
            }

            for (int i = 0; i < str; i++) {
                for (int j = 0; j < stl; j++) {
                    if ((j > i) && (arr[i][j]< 0)) {
                    n++;
                     
                    }
                   
                }
                 
            }
            std::cout << "Количество отрицательных элементов.\n";
            std::cout << n << "\n"; 
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
