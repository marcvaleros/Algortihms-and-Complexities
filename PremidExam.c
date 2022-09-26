//This program is my answer for the Premid Test C Exam for Algorithms and Complexities
#include<stdio.h>
#include<stdlib.h>
#define ARR_SIZE 10
#define BUCKET_SIZE 10

typedef struct node{
    int elem;
    struct node* link;
}*List;

typedef List Bucket[BUCKET_SIZE];

void radixSort(List *L);
void bucketSort(List* L, int placevalue);

int findMaxElem(List *L);
void insertFirst(List *L, int elem);
void displayLL(List L);

void main(){ 
    //make a linked list
    List LL = NULL;
    int x;
    int A[] = {315,143,123,412,532,641,234,351,643,754};
    
    for(x = 0; x < ARR_SIZE;x++){
      insertFirst(&LL, A[x]);
    }

    displayLL(LL);
    printf("\n");
    radixSort(&LL);
    displayLL(LL);

}

void bucketSort(List *L, int pvalue){
  List *trav, *trav2, ptr,temp;
  int num,x;
  Bucket bucketlist;

  //initialize bucketlist
  for(x = 0;x < BUCKET_SIZE;x++){
    bucketlist[x] = NULL;
  }

  //traverse the LL and put all the values with the same place value 
  for(trav = L; *trav != NULL;){
            temp = *trav;
            *trav = temp->link;

            trav2 = &bucketlist[temp->elem/pvalue % 10];

            if(*trav2 != NULL){
               temp->link = *trav2;
            }else{
               temp->link = NULL;
            }

            *trav2 = temp; 
  }
  //gather the elements back into the LL

  *L = NULL;
  trav2 = NULL;
  for(x = BUCKET_SIZE - 1; x >= 0; x--){
        for(trav2 = &bucketlist[x]; *trav2 != NULL;){

          //remove first elem until empty
          temp = *trav2;
          *trav2 = temp->link;

          //add to LL using insertfirst
          if(*L != NULL){
            temp->link = *L;
          }else{
            temp->link = NULL;
          }
          *L = temp;
        }
  }

  // printf("\nThis is the partially sorted LL:\n");
  // displayLL(*L);
}

void radixSort(List *L){

  int max = findMaxElem(L);
  int placevalue;

  for(placevalue = 1; max/placevalue > 0; placevalue *= 10){
      bucketSort(L,placevalue);
  }
}

void insertFirst(List *L, int elem){
  List *trav, temp;

  for(trav = L; *trav != NULL; trav = &(*trav)->link){}
    temp = (List) calloc(1,sizeof(struct node));
    temp->elem = elem;
    temp->link = *trav;
    *trav = temp;
}

void displayLL(List L){
  List trav;

  for(trav = L;trav != NULL; trav = trav->link){
    printf("%d ",trav->elem);
  }
}

int findMaxElem(List *L){
  int max = 0;
  List trav;
  for(trav = *L; trav != NULL; trav = trav->link){
    if(trav->elem > max){
      max = trav->elem;
    }
  }

  return max;
}
