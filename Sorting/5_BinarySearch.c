/*
https://www.geeksforgeeks.org/binary-search/
*/
#include<stdio.h>
#include<stdlib.h>

void EnterAnArray(int* array, int size);
void PrintAnArray(int* array, int size);
void InsertionSort(int* array,int size);
int BinarySearch(int* array,int start, int end, int searchElement);
void swap(int* element1, int* element2);

int main(){

    int size =0;
    int searchElement = 0;
    int *arr;

    printf("Enter array size = ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));

    EnterAnArray(arr, size);
    InsertionSort(arr,size);
    PrintAnArray(arr, size);

    printf("Enter the element to search\n");
    scanf("%d", &searchElement);
    printf("Searched index = %d\n", BinarySearch(arr, 0, size, searchElement));

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
    printf("\n");
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

int BinarySearch(int* arr, int start, int end, int searchElement){
    int mid = (start+end)/2;

    if(arr[mid]==searchElement)
        return mid;
    else if(arr[mid]>searchElement)
        return BinarySearch(arr, 0, mid, searchElement);
    else if(arr[mid]<searchElement)
        return(BinarySearch(arr, mid, end, searchElement));
    else
        return -1;
}