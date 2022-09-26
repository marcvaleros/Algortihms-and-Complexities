/***** 

Program to sort an array using Quicksort
Three variations of Quicksort depends on the placement of the pivot (first,middle,last)
Note: Pivot used in this program is the last element

Coded by Marc Valeros - 08/21/2022

*****/
#include  <stdio.h>
#define SIZE 10

void QSort(int A[] ,int low, int high);
int partition(int A[], int low,int high);
void swap(int* A, int* B);


void main(){

  int x;
  int arr[] = {10,50,22,70,25,20,36,15,47,80};
  // int *newArr = malloc(sizeof(int)*SIZE);

  // quicksort pivot:last element
  QSort(arr,0,SIZE-1);

  // display sorted array
  for(x=0; x < SIZE; x++){
    printf("%d ",arr[x]);
  }

}

/**** Utility functions ****/

void QSort(int A[] ,int low, int high){
  int pivot;

  if( low < high){
    pivot = partition(A,low,high);
    QSort(A, low, pivot-1);  
    QSort(A, pivot + 1, high);  
  }
}

int partition(int A[], int low,int high){
  //last element as pivot
  int pivot = A[high];
  int x, y = low - 1; 

  for(x = low; x < high; x++){
    if(A[x] <= pivot){
      swap(&A[++y], &A[x]);
    }
  }
  //swap the pivot to its proper pos 
  swap(&A[++y],&A[high]);

  //return the new pivot position
  return y;
}


void swap(int* A, int* B){
  int temp; 
  temp = *A;
  *A = *B;
  *B = temp;
}


