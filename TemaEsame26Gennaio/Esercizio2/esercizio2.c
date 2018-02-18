#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 1000;

typedef struct string{
  char* content;
  int length;
} string_t;

void stringCopy(string_t dest, string_t src, int nTimes){

  int i = 0, k = 0;

  while( nTimes > 0 ){
    dest.content[k] = src.content[i];
    i++;
    if( i == src.length ){
      i = 0;
      nTimes--;
    }
    k++;
  }

  return;
}

string_t replica(string_t original, int n){
  string_t returnString;

  returnString.content = (char*)malloc(((sizeof(char) * (original.length - 1) * n)) + 1);
  returnString.length = original.length * n;

  stringCopy(returnString, original, n);

  return returnString;
}

int main(){
  string_t stringa, stringaNuova;
  int i = 0;
  char c;
  stringa.content = (char*) malloc(sizeof(char)*10);
  stringa.length = 4;

  while( i < 4  && ((c = getchar()) != '\n') ){
    stringa.content[i] = c;
    i++;
  }

  stringa.content[i] = '\0';
  stringaNuova = replica(stringa, 8);

  printf("%s\n", stringaNuova.content);
}
