#include <iostream>
#include <limits>
#include <ctime>

void multiply(long double** A, long double** B, long double** result, long long N){
    for (long long i = 0; i < N; i++)
    {
        
        for (long long j = 0; j < N; j++)
        {
            result[i][j] = 0;
            for(long long k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }        
                   
        }
            
    }
}
void power(long double** A, long double** result, long long N, long long K) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }
    long double** temp = new long double*[N];
    for (long long i = 0; i < N; i++) {
        temp[i] = new long double[N];
    }

    for(long long g = 0; g < K; g++) {
        multiply(result, A, temp, N);
    
        for (long long i = 0; i < N; i++) {
                for (long long j = 0; j < N; j++) 
                {
                    result[i][j] = temp[i][j];
                }
        }
    }
    
    for (long long i = 0; i < N; i++) {
        delete[] temp[i];
    }
    delete[] temp;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    std::cout << "Возведение матрицы в степень.\n";
    std::cout << "Выполнил Стрелков Ярослав Михайлович, студент группы 453505, вариант 2.\n";
    long long a;

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
            long long N, K, i = 0;
            std::cout << "Введите размер матрицы\n";
            std::cin >> N;
            if (std::cin.fail()) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Введите степень в которую хотите возвести матрицу\n";
            std::cin >> K;
            if (std::cin.fail()) {
                std::cout << "Ошибка ввода\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            long double** arr = new long double*[N];
            long double** result = new long double*[N];
            for (int i = 0; i < N; i++) {
                arr[i] = new long double[N];
                result[i] = new long double[N];
            }
            std::cout << "Заполнение матрицы\n";
            for (long long i = 0; i < N; i++)
            {
       
                for (long long j = 0; j < N; j++)
                {
                    arr[i][j] = rand() % 53;
                }
            }
            power (arr, result, N, K);
            //Вывод
            std::cout << "Наша матрица:\n";
            for (long long i = 0; i < N; i++)
            {
        
                for (long long j = 0; j < N; j++)
                {
                    
                    std::cout << result[i][j] << " ";
                }
            std::cout << std::endl;
            }
     
    for (long long i = 0; i < N; i++)
    {
        delete[] arr[i];
        delete[] result[i];
    }
    delete[] arr;
    delete[] result;
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
