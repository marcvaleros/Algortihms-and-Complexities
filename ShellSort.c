//This program is used for Shell Sort Sorting Algorithm
//10 8 9 7 5 6 4 2 3 1
//16 21 32 51 32 12 43 63 45 11

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

void shellSort(int A[], int size);

void main(){
  int unsorted[] = {161, 212, 323, 514, 325, 126, 437, 638, 459, 119};
  //161 212 323 514 325 126 437 638 459 119
  int *retval;
  int x,y,max = 0;

 /******** SHELL SORT *********/
      shellSort(unsorted,MAX_SIZE);

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
  printf("\n");
    for(z = 0; z < MAX_SIZE;z++){
      printf("%d ", A[z]);
    }
  }
}
