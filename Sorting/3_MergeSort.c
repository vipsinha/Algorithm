/*
https://en.wikipedia.org/wiki/Insertion_sort
*/
#include<stdio.h>
#include<stdlib.h>

void EnterAnArray(int* array, int size);
void PrintAnArray(int* array, int size);
void MergeSort(int* array,int size);
void MergeSort_Split(int* TargetArray, int* SourceArray, int Start, int End);
void MergeSort_Join(int* SrcArray, int* TargetArray, int Start, int Middle, int End);
void CopyArray(int A[], int Start, int End, int B[]);

int main(){

    int size =0;
    int *arr;

    printf("Enter array size = ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));

    EnterAnArray(arr, size);
    MergeSort(arr,size);
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

void MergeSort(int* array,int size){

    int *TargetArray = (int*)malloc(size * sizeof(int));
    int Start = 0;
    int End = size;

    CopyArray(array, 0, size, TargetArray);
    MergeSort_Split(TargetArray, array, 0, size);
}

void MergeSort_Split(int* TargetArray, int* SourceArray, int Start, int End)
{
    if(End - Start <= 1)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int Middle = (End + Start) / 2;              // Middle = mid point
    // recursively sort both runs from array A[] into B[]
    MergeSort_Split(SourceArray, TargetArray, Start, Middle);  // sort the left  run
    MergeSort_Split(SourceArray, TargetArray, Middle, End);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    MergeSort_Join(TargetArray, SourceArray, Start, Middle, End);
}

void MergeSort_Join(int* TargetArray, int* SourceArray, int Start, int Middle, int End){
    int i = Start;
    int j = Middle;
    int k;

    for(k=Start; k<End; k++){
        if((i<Middle) && ((j>=End) || (TargetArray[i]<=TargetArray[j]))){
            SourceArray[k] = TargetArray[i];
            i++;
        }else{
            SourceArray[k] = TargetArray[j];
            j++;
        }
    }
}

void CopyArray(int A[], int Start, int End, int B[])
{
    for(int k = Start; k < End; k++)
        B[k] = A[k];
}