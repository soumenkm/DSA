#include <stdio.h>
#include <stdlib.h>

struct Book {
    char name;
    float price;
    int pages;
};

void printBook(struct Book* book) {
    printf("name: %c\n", book -> name);
    printf("price: %.2f\n", book -> price);
    printf("pages: %d\n", book -> pages);
}

int main() {
    struct Book b1 = {'a', 10.5, 100};
    struct Book b2 = {'b', 20.5, 200};
    struct Book b3 = {'c', 30.5, 300};

    printBook(&b1);
    printBook(&b2);
    printBook(&b3);

    struct Book* b[3] = {&b1, &b2, &b3};
    printf("%p\n", b[0]); // prints the first element of the array
    b[0] -> name = 'd';
    printBook(b[0]);

    return 0;
}