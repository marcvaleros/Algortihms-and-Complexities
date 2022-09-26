/*************
Program to sort the array using Counting Sort, its functions accepts as parameters the main array to be sorted, the range and the size of the array.
This sorting algorithm have a time complexity of  O(n+k) where k is the range of non negative values and n is the number of elements in that array.
**************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

int* countingSort(int A[], int k, int n);
int* gnomeSort(int A[], int n);

void swap(int *a, int *b);

void main(){
  int unsorted[MAX_SIZE];
  int *retval;
  int x,y,max = 0;

  for(x = 0; x < MAX_SIZE;x++){
    scanf("%d",&unsorted[x]);
    max = (unsorted[x] > max) ? unsorted[x] : max;
  }


  /******** COUNTING SORT *********/
      retval = countingSort(unsorted,max,MAX_SIZE);

      for(x = 0; x < MAX_SIZE;x++){
        printf("%d ",retval[x]);
      }

}


int* countingSort(int A[], int k, int n){
  int x,y;

  int *countArr = (int* ) calloc(k+1,sizeof(int));     //automatically initialize the array to 0
  int *outArr = (int *) calloc(n,sizeof(int));      

  for(x = 0; x < n ; x++){                             //count array
    countArr[A[x]] =  countArr[A[x]] + 1;
  }

  for(x = 1; x < k+1; x++){                            //get the prefix sum to identify its location on the output array
    countArr[x] = countArr[x] + countArr[x-1];
  }
  
  for(x = n - 1 ; x >= 0; x--){                         //put values to the output array in sorted order
    outArr[--countArr[A[x]]] = A[x];
  }

  return outArr;
}

