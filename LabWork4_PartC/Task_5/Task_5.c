#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <gtest/gtest.h>
// int TestSaper(int row, int col, int **arr);
// int TEST_OUT = 1;
// TEST(TestSaper, Saper)
//     {
//         EXPECT_EQ(0, TEST_OUT);
//     }



int main() {
    //::testing::InitGoogleTest();
    printf("Игра сапёр.\n");
    printf("Выполнил Стрелков Ярослав Михайлович, студент группы 453505.\n");
    int a;

    while (true) {
        printf("Для ввода контрольных значений нажмите 1\n");
        printf("Для выхода из программы нажмите 2\n");
        scanf(" %d", &a);

        switch (a) {
        case 1: {
            char num;
            int i, j, row, col;

            printf("Введите количество строк.\n");
            while (1) {
            if (scanf("%d", &row) == 1) {
                char ch = getchar();      
                if (ch == '\n') {        
                    if (row > 0) {       
                        break;            
                    } else {
                        printf("Ошибка ввода.\n");
                    }
                } 
                else {
                
                    while (ch != '\n' && ch != EOF) ch = getchar();
                    printf("Ошибка ввода.\n");
                }
            } else 
            {
                while ((getchar()) != '\n');
                printf("Ошибка ввода.\n");
            }
            }

            printf("Введите количество столбцов.\n");
            while (1) {
            if (scanf("%d", &col) == 1) {
                char ch = getchar();      
                if (ch == '\n') {        
                    if (col > 0) {       
                        break;            
                    } else {
                        printf("Ошибка ввода.\n");
                    }
                } 
                else {
                
                    while (ch != '\n' && ch != EOF) ch = getchar();
                    printf("Ошибка ввода.\n");
                }
            } else 
            {
                while ((getchar()) != '\n');
                printf("Ошибка ввода.\n");
            }
            }

            int **p = (int **)malloc(row * sizeof(int *));
            for (i = 0; i < row; i++) {
                p[i] = (int *)malloc(col * sizeof(int));
            }

            // Ввод массива
            printf("Введите ´*´ и ´.´ где ´*´ является бомбой, а ´.´ является пустой клеткой.\n");
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    scanf(" %c", &num);
                    if (num == '.') {
                        p[i][j] = 0;
                        
                    } else if (num == '*') {
                        p[i][j] = -1;
                        
                    } else {
                        printf("Ошибка ввода.\n");
                        j--;
                    }
                }
            }

            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    if (p[i][j] == -1) {
                        for (int k = -1; k <= 1; k++) {
                            for (int v = -1; v <= 1; v++) {
                                int num1 = i + k;
                                int num2 = j + v;
                                if (num1 >= 0 && num2 >= 0 && num1 < row && num2 < col && p[num1][num2] != -1) {
                                    p[num1][num2]++;
                                }
                            }
                        }
                    }
                }
            }

           //TEST_OUT = TestSaper(row, col, p);
            

            // Вывод массива
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    if (p[i][j] == 0) {
                        printf(" .");
                    } else if (p[i][j] == -1) {
                        printf(" *");
                    } else {
                        printf(" %d", p[i][j]);
                    }
                }
                printf("\n");
            }

            
            



            // Очистка
            for (i = 0; i < row; i++) {
                free(p[i]);
            }
            free(p);
            
        } 
      /// RUN_ALL_TESTS();
        break;

        case 2:
            return 0;

        default:
            printf("Ошибка ввода\n");
            return 0;
        }
    }
    return 0;
}

// int TestSaper(int row, int col, int **arr) {
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if (arr[i][j] == 0) {
//                 for (int k = -1; k <= 1; k++) {
//                     for (int v = -1; v <= 1; v++) {
//                         int num1 = i + k;
//                         int num2 = j + v;
//                         if (num1 >= 0 && num2 >= 0 && num1 < row && num2 < col) 
//                         {
//                             if (arr[num1][num2] == -1) 
//                             {
//                                 return 1;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }