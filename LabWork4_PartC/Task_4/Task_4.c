#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>




int main() {
    printf("Нфйти максимальную диагональ куба.\n");
    printf("Выполнил Стрелков Ярослав Михайлович, студент группы 453505, вариант 2.\n");
    int a;

    while (true) {
        printf("Для ввода контрольных значений нажмите 1\n");
        printf("Для выхода из программы нажмите 2\n");
        scanf("%d", &a);

        switch (a) {
        case 1: {
            int ***p = NULL;
            int N, i, j, g, dsum1 = 0, dsum2 = 0, dsum3 = 0, dsum4 = 0;
            printf("Введите размер матрицы\n");


            char ch;
    while (1) {
        
        if (scanf("%d", &N) == 1) {
            
            ch = getchar();
            if (ch == '\n') {
                break;
            } else {
                
                while (ch != '\n' && ch != EOF) {
                    ch = getchar();
                }
            }
        } else {
            
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        
        printf("Ошибка ввода.\n");
    }

            p = (int***)malloc(N * sizeof(int**));
            for (i = 0; i < N; i++) 
            {
                p[i] = (int**) malloc(N * sizeof(int*));
            
                for (j = 0; j < N; j++) 
                {
                    p[i][j] = (int*) malloc(N * sizeof(int));
                }
            }
            //Ввод массива
            for (i = 0; i < N; i++) 
            {
                for (j = 0; j < N; j++) {
                    for (g = 0; g < N; g++) 
                    {
                        
                        p[i][j][g] = rand() % 100;
                    }
                }
            }

            //Сумма элементов на диагоналях
            printf("Диагональ 1\n");
            for (i = 0; i < N; i++ ) {
                dsum1 += p[N - i - 1][0 + i][0 + i];
               
            }
            printf("%d\n", dsum1);

            printf("Диагональ 2\n");
            for (i = 0; i < N; i++ ) {
                dsum2 += p[0 + i][0 + i][0 + i];
                
            }
            printf("%d\n", dsum2);
            printf("Диагональ 3\n");
            for (i = 0; i < N; i++ ) {
                dsum3 += p[N - i - 1][N - i - 1][0 + i];
                
            }
            printf("%d\n", dsum3);
            printf("Диагональ 4\n");
            for (i = 0; i < N; i++ ) {
                dsum4 += p[N - i - 1][0 + i][N - i - 1];
                
            }
            printf("%d\n", dsum4);




            //Максимальная сумма 
            printf("Максимальная сумма диагонали: ");
            int maxsum = dsum1;
            if (dsum2 > maxsum) 
            {
                maxsum = dsum2;
            }
            if (dsum3 > maxsum) 
            {
                maxsum = dsum3;
            }
            if (dsum4 > maxsum) 
            {
                maxsum = dsum4;
            }
            printf("%d\n", maxsum);
            
            

            //Очистка
            for (i = 0; i < N; i++) 
            {
                for (j = 0; j < N; j++) 
                {
                free(p[i][j]);
                p[i][j] = NULL;
                }
                free(p[i]);
            }
            free(p);
            p = NULL;
}
        break;
        case 2:
            return 0;
        default:
            printf("Ошибка ввода\n");
            break;
        }
    }
    return 0;
}
