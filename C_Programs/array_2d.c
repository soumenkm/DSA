#include<stdio.h>
#include<stdlib.h>

int** create2DArray(int row, int col) {
    // first create the array of pointer to int and the first element address is casted to
    // store the address of int* so arr becomes int** type
    int** arr = (int**) malloc(sizeof(int*) * row); 
    for (int i = 0; i < row; i++) {
        arr[i] = (int*) malloc(sizeof(int) * col); 
    }
    return arr;
}

void delete2DArray(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}

void print2DArray(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fill2DArrayFromFile(char* file_name, int** arr, int row, int col) {
    FILE* fptr = fopen(file_name, "r");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(fptr, "%d", &arr[i][j]);
        }
    }
    fclose(fptr);
}

int main() {
    int row = 4;
    int col = 5;
    int** arr = create2DArray(row, col);
    char* file_name = "/Users/soumen/DSA_prep/DSA/C_Programs/array.txt";
    fill2DArrayFromFile(file_name, arr, row, col);
    print2DArray(arr, row, col);
    delete2DArray(arr, row);
    return 0;
}