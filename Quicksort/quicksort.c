#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j){
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void quicksort(int v[], int left, int right){
  int i, last;

  if( left >= right ){
    return;
  }

  swap(v, left, (left+right)/2);
  last = left;

  for( i = left + 1; i <= right; i++ ){
    if( v[i] < v[left] ){
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  quicksort(v, left, last - 1);
  quicksort(v, last + 1, right);
}

int main(){

  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  quicksort(array, 0, 9);

  for(int i = 0; i < 10; i++ ){
    printf("%d\t", array[i]);
  }

  exit(0);
}
