


#include <stdio.h>
#define MAX 10


//Function to perform matrix addition
void matrix_addition(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


//Function to perform matrix subtraction
void matrix_subtraction(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}


//Function to perform matrix multiplication
void matrix_multiplication(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


//Function to perform matrix transpose
void matrix_transpose(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}
void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){

    printf("ADITYA AWASTHI\n");
    printf("Roll No: 2504231530007\n");
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    printf("\nMatrix A + Matrix B:\n");
    matrix_addition(A, B, result, rows, cols);
    print_matrix(result, rows, cols);

    printf("\nMatrix A - Matrix B:\n");
    matrix_subtraction(A, B, result, rows, cols);
    print_matrix(result, rows, cols);

    if(cols==rows){
    printf("\nMatrix A * Matrix B:\n");
    matrix_multiplication(A, B, result, rows, cols, rows, cols);
    print_matrix(result, rows, cols);
    } else {
        printf("\nMatrix multiplication not possible due to incompatible dimensions.\n");
    }

    printf("\nTranspose of Matrix A:\n");
    matrix_transpose(A, result, rows, cols);
    print_matrix(result, cols, rows);

    printf("\nTranspose of Matrix B:\n");
    matrix_transpose(B, result, rows, cols);
    print_matrix(result, cols, rows);
    return 0;
}

