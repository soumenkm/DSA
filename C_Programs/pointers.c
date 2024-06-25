#include<stdio.h>

void printArray(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr+i)); // *(arr+i) is same as arr[i]
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%p ", (arr+i)); // arr+i is same as &arr[i]
    }
    printf("\n");
}

void print2DStaticArray(int (*arr)[5], int row) {
    /* arr = &array[0][0] is not same as &array[0] or &array because array is always a 
    pointer to the first element of array and since it is 2D array so the first element
    of 2D array is 1D array so array[0] is nothing but a pointer pointing to the first
    element of 1D array which is array[0][0]

    arr: pointer to an array of 5 integers = &arr[0] (by default first element address which is address of whole 1D array)
    arr[0]: pointer to an int = &arr[0][0] (by default first element address which is address of int)
    arr + i: pointer to move in the row i, *(arr+i) = arr[i] = address of whole i-th row or whole i-th 1D array
    *(arr+i) + j = arr[i] + j: pointer to the i,j th element of array meaning it points to i,j th element
    *(arr[i]+j) = arr[i][j] = actual value
    */

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]); // *(*(arr+i)+j)
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    // printArray(arr, sizeof(arr)/sizeof(int));

    char* pc; // pointer to character or 1B memory
    int* pi; // pointer to integer or 4B memory
    double* pd; // pointer to double or 8B memory
    int** ppi; // pointer to pointer to int or 8B memory
    int (*rp)[5]; // pointer to an array of 5 integers or 20B memory

    // difference between array and pointer
    int* pa = arr; // pointer to integer which is first element of array still points to 4B
    pa = pa + 1; // Okay
    // arr = arr + 1; // Error as arr is not normal variable
    // printf("%d\n", sizeof(arr)); // 20B
    // printf("%d\n", sizeof(pa)); // 8B 

    // difference between character array and string
    char* str = "string"; // by default '\0' is added at end (string literal, read only)
    char pc1[] = "string"; // also '\0' is added at end as there is space
    // str[1] = 'e'; // bus error as read only memory
    pc1[1] = 'e'; // Okay as user defined array
    char pc2[6] = "string"; // '\0' is not added as there is no space
    char pc3[10] = {'s','t','r','i','n','g'}; // rest all are padded with '\0'

    // 2D static array
    int arr2[][5] = {{1,2,3,4,5},{6,7,8,9,10}}; // 2nd dim must not be empty
    int (*p2darr)[5] = arr2; // pointer to an array of 5 integers, arr2 = &arr2[0] (address of first element)

    // print2DStaticArray(arr2, 2);
    // print2DStaticArray(p2darr, 2);

    // array of pointers vs pointer to an array
    int arr3[5] = {1,2,3,4,5};
    int (*p4)[5] = &arr3; // this is address of whole array so it is pointer to an array of 5 int
    int* p5 = arr3; // same as &arr3[0] so it is a pointer to an integer. &arr3 != &arr3[0] but arr3 = &arr3[0]

    /* p4 is pointer to an array of 5 integers so it points to 5 integers as a whole
    Now *p4 means it will dereference to the entire 5 integers and then it takes the address
    of only the first integer so *p4 = &arr3[0] = &(*(arr3 + 0)) = arr3 which is by default the address of 1st element
    (*p4)[0] = content of arr3[0] so p4[0][0], p4[0][1], ... to access the values
    *p4 + i: pointer to the i-th element of the array
    *(*p4 + i) = *(p4[0] + i) = p4[0][i] = (*p4)[i]
    */

    int* arr4[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]}; // array of pointers to int

    // *arr4[2] = *(arr4[2]) so the preference is given to [] over *
    // *arr4[2] != (*arr4)[2] 

}