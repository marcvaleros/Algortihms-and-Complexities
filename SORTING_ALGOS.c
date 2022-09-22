//This program is for all the sorting algorithms that utilize the array data structure
//10 8 9 7 5 6 4 2 3 1
//16 21 32 51 32 12 43 63 45 11

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

void bubbleSort(int A[], int n);
void insertionSort(int A[], int n);
void selectionSort(int A[], int n);
void shellSort(int A[], int size);

int* countingSort(int A[], int k, int n);
int* gnomeSort(int A[], int n);


void displaySorted(int A[]);
void swap(int *a, int *b);

void main(){
  int unsorted[] = {161, 212, 323, 514, 325, 126, 437, 638, 459, 119};
  int *retval;
  int x,y,max = 0;

 /******** BUBBLE SORT *********/
      // bubbleSort(unsorted,MAX_SIZE);

 /******** INSERTION SORT *********/
      // insertionSort(unsorted,MAX_SIZE);

 /******** SELECTION SORT *********/
      // selectionSort(unsorted,MAX_SIZE);
      
  /******** COUNTING SORT *********/
      // retval = countingSort(unsorted,max,MAX_SIZE);
      // displaySorted(retval);

  /******** GNOME SORT *********/
      // retval = gnomeSort(unsorted,MAX_SIZE);
      // displaySorted(retval);

   /******** SHELL SORT *********/
      // shellSort(unsorted,MAX_SIZE);

   /******** RADIX SORT *********/
      // radix(unsorted,MAX_SIZE);

}

void insertionSort(int A[], int n){
  int x,y, key;

  for(x = 1 ; x < n; x++){
    key = A[x];
    for( y = x - 1; key < A[y] && y >= 0; y--){
      A[y + 1] = A[y]; 
    }
    A[y + 1] = key;
  }
     printf("Sorted Array \n");
      for(x=0; x < n; x++){
        printf("%d ",A[x]);
    }
}

void bubbleSort(int A[], int n){
  int x,y;

  for(x = 0; x < n - 1; x++){
    for(y = 0; y < n - x - 1; y++){
      if(A[y] > A[y+1]){
        swap(&A[y],&A[y+1]);
      }
    }
  }
 
  //display sorted
    printf("Sorted Array \n");
      for(x=0; x < n; x++){
        printf("%d ",A[x]);
      }
  }

void selectionSort(int A[], int n){
  int x,y,min_index;
  
  for(x = 0; x < n - 1; x++){
    min_index = x;
    for(y = x + 1; y < n; y++){
      if(A[y] < A[min_index]){
        min_index = y;
      }
    }
    swap(&A[x], &A[min_index]);
  }

    //display sorted
    printf("Sorted Array \n");
      for(x = 0; x < n; x++){
        printf("%d ",A[x]);
      }

}


  int* gnomeSort(int A[], int n){
      int x;
      int *retval = (int*) malloc(n*sizeof(int));
      memcpy(retval,A,sizeof(int)*n);

      for(x = 0; x < n;){
        if(x == 0 || retval[x] >= retval[x-1]){
          x++;
        }else{
          swap(&retval[x],&retval[x-1]);
          x--;
        }
      }
      return retval;
  }


int* countingSort(int A[], int k, int n){
  int x,y;

  //automatically initialize the array to 0
  int *countArr = (int* ) calloc(k+1,sizeof(int));     
  int *outArr = (int *) calloc(n,sizeof(int));      

    //count array
  for(x = 0; x < n ; x++){                           
    countArr[A[x]]++;
  }

  //get the prefix sum/cumulative sum to identify its location on the output array
  for(x = 1; x < k+1; x++){                          
    countArr[x] += countArr[x-1];
  }
  
  //put values to the output array in sorted order
  for(x = n - 1 ; x >= 0; x--){                         
    outArr[--countArr[A[x]]] = A[x];
  }

  return outArr;
}


void shellSort(int A[], int size){
  int x,y,z,gap,temp;
  for(gap = size/2; gap > 0; gap /=2){
    for(x = gap; x < size; x++){
      temp = A[x];
      for(y = x; y >= gap && A[y - gap] > temp; y -= gap){
        A[y] = A[y - gap];
      }
      A[y] = temp;
    }
  }

  printf("\n");
    for(z = 0; z < MAX_SIZE;z++){
      printf("%d ", A[z]);
    }
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

