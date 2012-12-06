#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void compare(FILE *file1, FILE *file2);

void compare(FILE *file1, FILE *file2){
  int counter=0;
  unsigned char ch1, ch2;
  while(fread(&ch1, 1, 1, file1) && fread(&ch2, 1, 1, file2)) {
      if(ch1!=ch2 ){
	  printf("byte %d -%d +%d\n", counter+1, ch1, ch2);
      }
      counter++;
    }//end while
}