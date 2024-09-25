#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
//Write a function aggregate that applies an aggregation operation
//on the elements of an array of double and integer types. The
//supported aggregation operations are addition, multiplication and
//the max of the elements. The function accepts base as a pointer
//to any type, size as the size of array datatype in bytes, int n as
//the number of items of the array, initial value as pointer to the
//inital value of the aggregation operation and opr as function
//pointer of two paramaters and used to apply the corresponding
//operation on the parameters . It has the following header:
//void* aggregate(void* base, size t size, int n, void* initial value,
//void* (*opr)(const void*, const void*))

void* aggregate(void* base, //pointer to any type
                size_t size, // size of array datatype
                int n, //number of items of the array
                void* initial_value, //pointer to the inital value of the aggregation operation
                void* (*opr)(const void*, const void*)) //function used to apply the corresponding operation on the parameters
                {
    void* result = initial_value;
    for (int i = 0; i < n; i++) {
        result = opr(result, base + i * size);
    }
    return result;
    }

void* addi(const void* a, const void* b) {
    int* result = malloc(sizeof(int));
    *result = *(const int*) a + *(const int*) b;
    return result;

}

void* multd(const void* a, const void* b) {
    double* result = malloc(sizeof(double));
    *result = *(const double*) a * *(const double*) b;
    return result;
}

void* maxi(const void* a, const void* b) {
    int* result = malloc(sizeof(int));
    if (*(const int*) a > *(const int*) b) {
        *result = *(const int*)a;
    } else {
        *result = *(const int*)b;
    }
    return result;
}



int main() {
    int arr1[5] = {0, 1, 2, 3, 4};
    double arr2[5] = {0.2, 1.1, 2.2, 3.3, 4.4};

    int initial_value1 = 0;
    int* result1 = aggregate(arr1, sizeof(int), 5, &initial_value1, addi);

    double initial_value2 = 1.0;
    double* result2 = aggregate(arr2, sizeof(double), 5, &initial_value2, multd);

    int initial_value3 = 0;
    int* result3 = aggregate(arr1, sizeof(int), 5, &initial_value3, maxi);

    // Remember to free the results if they are dynamically allocated
    free(result1);
    free(result2);
    free(result3);

    return 0;
}