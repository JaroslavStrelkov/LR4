#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer() {
    while (getchar() != '\n'); // Очищаем входной поток
}

int main() {
    int row, col;
    int **p;
    char input[100];
    int choice;

    while (1) {
        printf("Игра сапёр.\n");
        printf("Выполнил Стрелков Ярослав Михайлович, студент группы 453505.\n");
        printf("Для ввода контрольных значений нажмите 1\n");
        printf("Для выхода из программы нажмите 2\n");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода.\n");
            clear_input_buffer();
            continue;
        }

        clear_input_buffer(); // Очищаем входной поток после выбора

        switch (choice) {
        case 1:
            printf("Введите количество строк.\n");
            while (1) {
                if (scanf("%d", &row) == 1 && row > 0) {
                    clear_input_buffer(); // Убираем лишние символы
                    break;
                } else {
                    printf("Ошибка ввода: введите положительное число.\n");
                    clear_input_buffer();
                }
            }

            printf("Введите количество столбцов.\n");
            while (1) {
                if (scanf("%d", &col) == 1 && col > 0) {
                    clear_input_buffer(); // Убираем лишние символы
                    break;
                } else {
                    printf("Ошибка ввода: введите положительное число.\n");
                    clear_input_buffer();
                }
            }

            // Выделяем память под массив
            p = malloc(row * sizeof(int *));
            for (int i = 0; i < row; i++) {
                p[i] = malloc(col * sizeof(int));
            }

            printf("Введите ´*´ и ´.´, где ´*´ является бомбой, а ´.´ является пустой клеткой:\n");
            for (int i = 0; i < row * col; i++) {
                int j = 0;
                while (j < col) {
                    if (fgets(input, sizeof(input), stdin)) {
                        int valid = 1;
                        for (int k = 0; input[k] != '\0' && j < col; k++) {
                            if (input[k] == '.') {
                                p[i][j++] = 0;
                            } else if (input[k] == '*') {
                                p[i][j++] = -1;
                            } else if (input[k] != ' ' && input[k] != '\n') {
                                valid = 0;
                                break;
                            }
                        }
                        if (!valid) {
                            printf("Ошибка ввода: используйте только '*' и '.'. Повторите ввод строки %d.\n", i + 1);
                            j = 0; // Сбрасываем ввод строки
                        }
                    }
                }
            }

            // Вывод результата
            printf("Результат:\n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    printf("%d ", p[i][j]);
                }
                printf("\n");
            }

            // Очистка памяти
            for (int i = 0; i < row; i++) {
                free(p[i]);
            }
            free(p);

            break;

        case 2:
            return 0;

        default:
            printf("Ошибка ввода.\n");
            break;
        }
    }
    return 0;
}