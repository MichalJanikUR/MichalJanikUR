#include <stdio.h>

int main()
{
    int A[5][5] = { {5, 2, 8, 2, 7}, {9, 3, 5, 1, 4}, {6, 0, 3, 9, 2}, {1, 8, 3, 6, 9}, {2, 9, 4, 3, 6} };
    int B[5][5] = { {1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {6, 7, 8, 9, 10}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} };

    int rozmXA = sizeof(A) / sizeof(A[0]); //wiersz A
    int rozmYA = sizeof(A[0]) / sizeof(A[0][0]); //kolumna A
    int rozmXB = sizeof(B) / sizeof(B[0]); //wiersz B
    int rozmYB = sizeof(B[0]) / sizeof(B[0][0]); //kolumna B

    int C[5][5];

    if((rozmXA == rozmXB) && (rozmYA == rozmYB) && (rozmXA == rozmYA) && (rozmXB == rozmYB))
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }
    else printf("Rozmiary macierzy nie sa takie same!");



    return 0;
}
