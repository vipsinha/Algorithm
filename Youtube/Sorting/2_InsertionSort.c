/*
https://en.wikipedia.org/wiki/Insertion_sort
*/
#include<stdio.h>
#include<stdlib.h>

void EnterAnArray(int* array, int size);
void PrintAnArray(int* array, int size);
void InsertionSort(int* array,int size);
void swap(int* element1, int* element2);

int main(){

    int size =0;
    int *arr;

    printf("Enter array size = ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));

    EnterAnArray(arr, size);
    InsertionSort(arr,size);
    PrintAnArray(arr, size);

    return 0;
}

void EnterAnArray(int* array, int size){
    printf("Enter %d elements\n", size);
    for(int i=0; i<size; i++){
        scanf("%d", &array[i]);
    }
}

void PrintAnArray(int* array, int size){
    printf("Array elements are = ");
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }  
}

void InsertionSort(int* array,int size){
    for(int i=1; i<size; i++){
        int j = i;
        while((j>0) && (array[j-1]>array[j])){
            swap(&array[j-1], &array[j]);
            j--;
        }
    }
}

void swap(int* element1, int* element2){
    int temp = 0;
    temp = *element2;
    *element2 = *element1;
    *element1 = temp;
}