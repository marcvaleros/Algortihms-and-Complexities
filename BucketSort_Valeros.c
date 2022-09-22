#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


typedef struct node{
  int data;
  struct node* link;
}*nodePtr;

void bucketSort(int A[], int size, int numbuckets);
void insertSorted(nodePtr * head, float num);

void main(){
  int x;
  int ARR[] = {161, 212, 323, 514, 325, 126, 437, 638, 459, 119};

   bucketSort(ARR, SIZE, 4);

   for(x = 0; x < SIZE;x++){
    printf("%d ",ARR[x]);
   }
}


void bucketSort(int A[], int size, int numbuckets){
  int x,y,min,max,range;


  //find the range by getting the min and max  of the array

  max = min = A[0];
  for(x = 0; x < size;x++){
    min = (A[x] < min) ? A[x] : min;
    max = (A[x] > max) ? A[x] : max;
  }

  range = (max - min) / numbuckets;

  //create a array of pointers
  nodePtr *buckets = (nodePtr*) calloc(numbuckets,sizeof(struct node));

  //traverse through the linked list and add to their respective buckets base on the range
  for(x= 0; x < size; x++){
    int bucketndx = (A[x] - min) / range;
    insertSorted(&buckets[bucketndx],A[x]);
  }

  //transfer from LL to array
  int ctr = 0;
  for(x = 0; x < sizeof(buckets); x++){
    nodePtr trav;
    for(trav = buckets[x]; trav != NULL; trav = trav->link){
      A[ctr++] = trav->data;
    }
  }
}


void insertSorted(nodePtr * head, float num){
  nodePtr * trav, temp;

  for(trav = head; *trav != NULL && (*trav)->data < num; trav = &(*trav)->link){}
    temp = (nodePtr) calloc(1,sizeof(struct node));
    temp->data = num;
    temp->link = *trav;
    *trav = temp;
}

