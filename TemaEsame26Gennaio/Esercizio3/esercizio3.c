#include <stdio.h>

int kminimo(int array[], int length, int k){
  int kIndex = -1;
  int i;
  int j;
  int foundMoreThan = 0;

  if( length > (2 * k) ){
    for( i = k; i < (length - k); i++ ){
      for(j = i - k; (j < (i + k)) && !foundMoreThan; j++){
        if( array[i] >= array[j] && i != j )
          foundMoreThan = 1;
      }
      if( !foundMoreThan ){
        kIndex = i;
        break;
      } else {
        foundMoreThan = 0;
      }
    }
  }
  return kIndex;
}

int main(){
  int array[] = {10, 8, 5, 6, 7};

  printf("\n%d\n", kminimo(array, 5, 2));

  return 0;
}
