/*
https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
*/
#include<stdio.h>
#include<stdlib.h>

void EnterAnArray(int* array, int size);
void PrintAnArray(int* array, int size);
void BubbleSort(int* array,int size);
void swap(int* element1, int* element2);

int main(){

    int size =0;
    int *arr;

    printf("Enter array size = ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));

    EnterAnArray(arr, size);
    BubbleSort(arr,size);
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

void BubbleSort(int* array,int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(array[j]<array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void swap(int* element1, int* element2){
    int temp = 0;
    temp = *element2;
    *element2 = *element1;
    *element1 = temp;
}