#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  struct Node *prec;
  int value;
  struct Node *next;
} node_t;

typedef struct List{
  node_t *head;
  node_t *tail;
} list_t;

list_t* newList(){
  list_t *list = (list_t*)malloc(sizeof(list_t));

  node_t *headTail = (node_t*)malloc(sizeof(node_t));

  headTail->prec = NULL;
  headTail->next = NULL;

  list->head = headTail;
  list->tail = headTail;

  return list;
}

node_t* newNode(int value){
  node_t *node = (node_t*)malloc(sizeof(node_t));

  node->value = value;

  return node;
}

list_t* arrayToList(int array[], int length){
  int i = 0;
  list_t *list = newList();
  node_t *temp;
  node_t *temp2;

  temp = newNode(array[i]);
  list->head = temp;

  for(i = 1; i < length; i++ ){
    temp2 = newNode(array[i]);
    temp->next = temp2;
    temp2->prec = temp;
    temp = temp2;
  }

  return list;
}

void printList(list_t *list){
  node_t *curr = list->head;

  while( curr != NULL ){
    printf("%d\t", curr->value);
    curr = curr->next;
  }

  return;
}

int main(){

  int array[] = {1, 2, 3, 4, 5, 6, 7};
  int length = 7;

  list_t *list = arrayToList(array, length);
  printList(list);

  return 0;
}
