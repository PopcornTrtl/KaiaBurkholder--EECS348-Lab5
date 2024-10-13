#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//since all matrix are SIZE by SIZE, all are equal sizes and thus all operations will function
#define SIZE 5
//adds two matricies together
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int column = 0; column < SIZE; column++)
        {
            sum[row][column] = m1[row][column] + m2[row][column];
        }
    }
}
//multiplies matrix m1 by matrix m2
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE])
{
    int m1_column_size = SIZE;
    int m2_row_size = SIZE;
    if(m2_row_size == m1_column_size)
    {
        for(int m1_row = 0; m1_row < SIZE; m1_row++)
        {
            for(int m2_column = 0; m2_column < SIZE; m2_column++)
            {
                product[m1_row][m2_column] = 0;
                for(int m1_column = 0; m1_column < SIZE; m1_column++)
                {
                    product[m1_row][m2_column] += ((m1[m1_row][m1_column])*(m2[m1_column][m2_column]));
                }
            }
        }   
    }
    else
    {
        printf("The two matricies cannot be multiplied together\n");
    }
}
//transposes given matrix, swapping the rows and columns
int transposeMatrix(int m1[SIZE][SIZE], int transpose[SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int column = 0; column < SIZE; column++)
        {
            transpose[column][row] = m1[row][column];
        }
    }
}
//prints a given matrix for the user
int printMatrix(int m1[SIZE][SIZE])
{
    printf("===========================\n");
    for(int row = 0; row < SIZE; row++)
    {
        for(int column = 0; column < SIZE; column++)
        {
            printf("%d ", m1[row][column]);
        }
        printf("\n");
    }
    printf("===========================\n");
}

int main() {
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int matrix_sum[SIZE][SIZE];
    int matrix_product[SIZE][SIZE];
    int transpose_product[SIZE][SIZE];

    //adds, multiplies, and transposes given matricies
    addMatrices(m1,m2, matrix_sum);
    multiplyMatrices(m1,m2, matrix_product);
    transposeMatrix(m1, transpose_product);
    //prints out each new matrix
    printf("Matrix Sum:\n");
    printMatrix(matrix_sum);
    printf("\nMatrix Product:\n");
    printMatrix(matrix_product);
    printf("\nTranspose of Matrix m1:\n");
    printMatrix(transpose_product);
}