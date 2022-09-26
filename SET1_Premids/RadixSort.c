//This program is for sorting using RadixSort
//10 8 9 7 5 6 4 2 3 1
//16 21 32 51 32 12 43 63 45 11

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

int getMax(int A[], int size);
void radixSort(int A[], int size);
void radiXcountSort(int A[], int digit);


void displaySorted(int A[]);
void swap(int *a, int *b);

void main(){
  int unsorted[] = {161, 212, 323, 514, 325, 126, 437, 638, 459, 119};
  int *retval;
  int x,y,max = 0;

   /******** RADIX SORT *********/
      radixSort(unsorted,MAX_SIZE);

}

int getMax(int A[], int size){
  int x,y,max = A[0];
  for(x = 1; x < size;x++){
    if(A[x] > max ){
      max = A[x];
    }
  }
  return max;
}

void radiXcountSort(int A[], int digit){
    int x,max;
    int *output = (int*) malloc(sizeof(int) * MAX_SIZE);

    //get max digit
    max = A[x]/digit % 10;
    for(x = 0; x < MAX_SIZE; x++){
        if(A[x]/digit % 10 > max){
          max = A[x]/digit % 10;
        }
    }

    int *count = (int*) calloc(max + 1,sizeof(int));
    //counter
    for(x = 0; x < MAX_SIZE;x++){
      count[(A[x]/digit) % 10]++; 
    }

    //fibo   
    for(x = 1; x <= max; x++){
      count[x] += count[x-1];
    }

    //output - start from the last elem
    for(x = MAX_SIZE - 1; x >= 0; x--){
      output[--count[(A[x]/digit) % 10]] = A[x]; 
    }

    for(x = 0; x<MAX_SIZE; x++){
        A[x] = output[x];
    }

}


void radixSort(int A[], int size){
  int digit,x,y,max;
  
  //get the max number 
  max = getMax(A,size);

  for(digit = 1; max/digit > 0; digit *= 10){
    //call counting sort here
    radiXcountSort(A,digit);
  }

   displaySorted(A);
}

void displaySorted(int A[]){
  int x;
  for(x = 0; x < MAX_SIZE; x++){
    printf("%d ",A[x]);
  }
}

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

