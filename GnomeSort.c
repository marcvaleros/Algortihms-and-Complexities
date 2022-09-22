
/*************
Program to sort the array using Gnome Sort, which was known as stupid sort.
This sorting algorithm can be best described as the child of insertion(the way it compares values to adjacent values) and bubble sort(constant swapping).
It is similar to bubble sort but gnome sort discards the nested loops. Best used for small data structures.
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

      retval = gnomeSort(unsorted,MAX_SIZE);

      for(x = 0; x < MAX_SIZE;x++){
        printf("%d ",retval[x]);
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

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}