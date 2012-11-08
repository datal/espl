#include <stdlib.h>
#include <stdio.h>
#include "diff.h" 
#include <getopt.h>
#include <assert.h>
#include <string.h>

int main(int argc, char **argv) {
    
  struct diff diff;
  FILE *fix = fopen( "fix", "r");
  FILE *file1 = fopen( "file1", "r+"); 
  char line[128];
  
  
  if(fix && file1){
    while(fgets(line,sizeof(line),fix) !=NULL){
	parsediff(line, &diff);
	fseek(file1, diff.offset-1, SEEK_SET);
	fwrite(&diff.new , 1, 1, file1);
    }
  }
  fclose(fix);
  fclose(file1);
  return 0; 
}
