#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  if(!strcmp()){
    
  }
  
  
  
  
  FILE *fp = fopen("text.txt", "r");
  unsigned int word;
  unsigned int sum;
  
  while(fread(&word, sizeof(word), 1, fp)){
    sum=sum^word;
  }

  printf("sum %d\n", sum);
  fclose(fp);
  return 0;
} 
