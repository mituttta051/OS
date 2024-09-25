#include <stdio.h>
//Create a static array of 5 characters to store the value “inno”.
//Can we increase the size of the string to hold the value “innopolis”
//without creating a new string? Repeat the previous steps using a
//dynamic array.

//Create a fixed size array m for storing 4 floats with the values
//{0.25, 0.5, 0.75, 1}. Declare a pointer p to a float and make it
//refers to the previous array m. What is the size of the array m
//and the pointer p? Can we consider the pointer to a <datatype>
//as an array? Check the size of the pointer to char? Is it the same
//as size of the pointer to float?

//Create 2-dimensional fixed size array n of (3x3) and fill the values
//with numbers from 0 to 10. Create a pointer q to the array m and
//replicate the values of the array m to make an array of size (2x4).

int main() {
    char str[5] = "inno";
    printf("%s\n", str);
    //str[5] = "polis";

    char* str2 = "inno";
    printf("%s\n", str2);
    str2 = "innopolis";
    printf("%s\n", str2);


    float m[4] = {0.25, 0.5, 0.75, 1};
    float* p = m;
    printf("Size of m: %lu\n", sizeof(m));
    printf("Size of p: %lu\n", sizeof(p));
    printf("Size of char*: %lu\n", sizeof(char*));

    int n[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int (*q)[3] = n;
    int m2[2][4];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            m2[i][j] = *(*(q + i) + j);
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    return 0;

}

