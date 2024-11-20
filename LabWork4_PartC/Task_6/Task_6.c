#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
//#include <gtest/gtest.h>
//int TEST_OUT = 1;
void increasingSquare(int n, int** magicSquare);
void decreasingSquare(int n, int** magicSquare);
void nodiagonalsZero(int n, int** magicSquare, int startRow, int startCol);
void diagonalsZero(int n, int** magicSquare, int startRow, int startCol);
void sumMagicSquare(int n, int** magicSquare1, int** magicSquare2, int** resultMagicSquare);
int printfMagicSquare(int n, int** magicSquare);
void algorithmKratn4(int n);
void algorithmKratnNechetn(int n); 
void algorithmkratn2(int n);
//char testMagicSquare(int n, int* l);

// TEST(testMagicScuare, MagicSquare)
//     {
//         EXPECT_EQ(0, TEST_OUT);
//     }

int main() {
    //::testing::InitGoogleTest();
    printf("Магический квадрат.\n");
    printf("Выполнил Стрелков Ярослав Михайлович, студент группы 453505, вариант 2.\n");
    int a;

    while (true) {
        printf("Для ввода контрольных значений нажмите 1\n");
        printf("Для выхода из программы нажмите 2\n");
        scanf(" %d", &a);
        

        switch (a) {
        case 1: 
        {
            int n;
            char ch;
            // int *l = (int*)malloc(n * n * sizeof(int));

//проверка на ввод


while (1) {
        printf("Введите значение для стороны магического квадрата. ");
        
        if (scanf("%d", &n) == 1) {
            
            ch = getchar();
            if (ch == '\n') {
                
                if (n > 0) {       
                        break;            
                    } 
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

            if(n%4 == 0) 
            {
                algorithmKratn4(n);
            }
            else if(n%2 == 0) 
            {
               algorithmkratn2(n);  
            }
            else
            {
                algorithmKratnNechetn(n);
            }

            // TEST_OUT = testMagicSquare(n, l);
            // RUN_ALL_TESTS();
            // free(l);

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

void algorithmKratnNechetn(int n) {
    int **magicSquare = (int**)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++) {
                magicSquare[i] = (int *)malloc(n * sizeof(int));
            } 

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;                               

        int new_i = (i - 1 + n) % n;  
        int new_j = (j + 1) % n;      
        if (magicSquare[new_i][new_j] != 0) {

            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }



    for (i = 0; i < n; i++) {
                free(magicSquare[i]);
                magicSquare[i] = NULL;
            }
            free(magicSquare);
            magicSquare = NULL;
}
    void algorithmkratn2(int n) {
    
    int **magic_square = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        magic_square[i] = (int *)calloc(n, sizeof(int));
    }

    int k = (n - 2) / 4;
    int size = n / 2;

    int **sub_squares[4];
    for (int s = 0; s < 4; s++) {
        sub_squares[s] = (int **)calloc(size, sizeof(int *));
        for (int i = 0; i < size; i++) {
            sub_squares[s][i] = (int *)calloc(size, sizeof(int));
        }
    }

    int start_nums[4] = {1, size * size + 1, 2 * size * size + 1, 3 * size * size + 1};
    for (int s = 0; s < 4; s++) {
        int start_num = start_nums[s];
        int i = 0, j = size / 2;
        for (int num = start_num; num < start_num + size * size; num++) {
            sub_squares[s][i][j] = num;
            int new_i = (i - 1 + size) % size;
            int new_j = (j + 1) % size;
            if (sub_squares[s][new_i][new_j] != 0) {
                i = (i + 1) % size;
            } else {
                i = new_i;
                j = new_j;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            magic_square[i][j] = sub_squares[0][i][j];
            magic_square[i][j + size] = sub_squares[2][i][j];
            magic_square[i + size][j] = sub_squares[3][i][j];
            magic_square[i + size][j + size] = sub_squares[1][i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < k; j++) {
            int temp = magic_square[i][j];
            magic_square[i][j] = magic_square[i + size][j];
            magic_square[i + size][j] = temp;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = n - k + 1; j < n; j++) {
            int temp = magic_square[i][j];
            magic_square[i][j] = magic_square[i + size][j];
            magic_square[i + size][j] = temp;
        }
    }

    int temp = magic_square[k][0];
    magic_square[k][0] = magic_square[k + size][0];
    magic_square[k + size][0] = temp;

    temp = magic_square[k][k];
    magic_square[k][k] = magic_square[k + size][k];
    magic_square[k + size][k] = temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", magic_square[i][j]);
        }
        printf("\n");
    }

    for (int s = 0; s < 4; s++) {
        for (int i = 0; i < size; i++) {
            free(sub_squares[s][i]);
        }
        free(sub_squares[s]);
    }
    for (int i = 0; i < n; i++) {
        free(magic_square[i]);
    }
    free(magic_square);
}

    void increasingSquare(int n, int** magicSquare) 
    {
        int number  = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                magicSquare[i][j] = number++;
            }
        }
    }

    void decreasingSquare(int n, int** magicSquare)
    {
        int number = n * n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                magicSquare[i][j] = number--;
            }
        }
    }

    void nodiagonalsZero(int n, int** magicSquare, int startRow, int startCol)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ( (i != j && (i + j) != (n - 1))) 
                {
                    magicSquare[startRow + i][startCol + j] = 0;
                } 
            }
        }
    }

    void diagonalsZero(int n, int** magicSquare, int startRow, int startCol)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ( i == j || (i + j) == (n - 1))
                {
                    magicSquare[startRow + i][startCol + j] = 0;
                } 
            }
        }
    }

    void sumMagicSquare(int n, int** magicSquare1, int** magicSquare2, int** resultMagicSquare)
    {
       for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                resultMagicSquare[i][j] = magicSquare1[i][j] + magicSquare2[i][j];
            }
        } 
    }

    int  printfMagicSquare(int n, int** magicSquare) 
    {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    }
    
    void algorithmKratn4(int n)
    {
    int **magicSquare1 = (int**)malloc(n * sizeof(int *));
    int **magicSquare2 = (int**)malloc(n * sizeof(int *));
    int **resultMagicSquare = (int**)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        magicSquare1[i] = (int *)malloc(n * sizeof(int));
        magicSquare2[i] = (int *)malloc(n * sizeof(int));
        resultMagicSquare[i] = (int *)malloc(n * sizeof(int));
    }

    increasingSquare(n, magicSquare1);
    decreasingSquare(n, magicSquare2);
    for(int i = 0; i < n; i += 4)
    {
        for(int j = 0; j < n; j += 4)
        {
            diagonalsZero(4, magicSquare1, i, j);
            nodiagonalsZero(4, magicSquare2, i, j);

        }
    }
    sumMagicSquare(n, magicSquare1, magicSquare2, resultMagicSquare);
    printfMagicSquare(n, resultMagicSquare);
    for (int i = 0; i < n; i++) {
        free(magicSquare1[i]);
        free(magicSquare2[i]);
        free(resultMagicSquare[i]);
        magicSquare1[i] = NULL;
        magicSquare2[i] = NULL;
        resultMagicSquare[i] = NULL;
    }
    free(magicSquare1);
    free(magicSquare2);
    free(resultMagicSquare);
    magicSquare1 = NULL;
    magicSquare2 = NULL;
    resultMagicSquare = NULL;
    }
    //  char testMagicSquare(int n, int* l) 
    // {
    //     int sumrows = 0, sumcol = 0, sumdiagonalnorm = 0, sumdiagonalpobochn = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             sumrows = sumrows + l[i * n + j];
    //             sumcol = sumcol + l[j * n + i];
    //         }
    //         sumdiagonalnorm = sumdiagonalnorm + l[i * n + i];
    //         sumdiagonalpobochn = sumdiagonalpobochn + l[i * n + (n - i - 1)];
    //         if(sumrows != sumcol) return 1;

    //     }
    //     if(sumdiagonalnorm != sumdiagonalpobochn) return 1;
    //     return 0;
    // }