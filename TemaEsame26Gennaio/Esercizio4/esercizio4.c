#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILENAME "risultati.txt"

FILE* openFile(){
  FILE *fp = fopen(FILENAME, "w");

  return fp;
}

int nDivisori(int numero){
  int divisore = 2;
  int delta = 1;
  int n = 0;

  if( numero%2 != 0 ){
    delta = 2;
    divisore = 3;
  }
  while( divisore <= (int)sqrt(numero) ){

    if( numero%divisore == 0 ){
      n++;
      if( divisore != (numero/divisore) ){
        n++;
      }
    }

    divisore += delta;
  }

  return n;
}

int main(){
  int *numbers;
  int i = 0;
  int currentNumber = 1;
  FILE *fp;

  numbers = (int*) malloc(sizeof(int*));

  while( currentNumber > 0 ){
    printf("\nInserisci un numero ( < 0 per terminare ): ");
    scanf("%d", &currentNumber);
    if( currentNumber > 0 ){
      if( i > 0 )
        numbers = (int*) realloc(numbers, (i + 1)*sizeof(int));
      numbers[i] = currentNumber;
      i++;
    }
  }
  fp = openFile();

  for(int j = 0; j < i; j++ ){
    fprintf(fp, "%d\t%d\n", numbers[j], nDivisori(numbers[j]));
  }

  fclose(fp);
}
