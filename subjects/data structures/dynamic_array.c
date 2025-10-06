#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

dynamicArray* createdynamicArray(int initialCapacity){
    dynamicArray* arr = malloc(sizeof(dynamicArray));
    arr->capacity = initialCapacity;
    arr->size = 0;
    arr->data = malloc(initialCapacity*sizeof(int));

    return arr;
}//O(1)

void destroydynamicArray(dynamicArray* arr){
    free(arr->data);
    free(arr);
}//O(1)

void addElement(dynamicArray* arr, int value){
    if(arr->size >= arr->capacity){
        arr->capacity *=2;
        arr->data = (int*) realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}//O(n)

void getElement(dynamicArray* arr, int index){
    if(index < 0 || index >= arr->size) printf("Index out of bounds\n");
    else printf("Elemento na posicao (%d):%d\n",index, arr->data[index]);
}//O(1)

int getdynamicArraySize(dynamicArray* arr){
    return arr->size;
}

int getdynamicArrayCapacity(dynamicArray* arr){
    return arr->capacity;
}

void printdynamicArray(dynamicArray* arr){
    printf("Array: [");
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d,", arr->data[i]);
    }
    printf("]\n");
    
}

int main(){
    dynamicArray* arr = createdynamicArray(5);
    for (size_t i = 0; i < 15; i++)
    {
        addElement(arr, i);
    }
    printf("Tamanho final: %d\n", getdynamicArraySize(arr));
    printf("Capacidade final: %d\n", getdynamicArrayCapacity(arr));

    getElement(arr, 10);
    getElement(arr, 100);

    printdynamicArray(arr);
    destroydynamicArray(arr);

    return 0;
}