#include <stdlib.h>
#include <stdio.h>
#include "diff.h" 
#include <getopt.h>
#include <assert.h>
#include <string.h>

int main(int argc, char **argv) {
  
  int numPrint=0;
  
  while(1){
    char ch;
    ch = getopt(argc, argv, "hrm\n");
    if(ch == -1){
      break;
    }
    
    switch(ch){
      case 'h':
	printf ("OPTIONS\n");	  
	printf ("-h  print a summary of options and exit\n");
	printf ("-r  reverse the differences\n");
	printf ("-m  print a message each time a change is applied\n");
	break;
      
      case 'r':
	break;
      
      case 'm':
	numPrint=1;
	break;
      
      default:
	printf("default\n");
    }
  }//end while
  
  struct diff diff;
  char *fdiff=argv[argc-1];
  char *toFix=argv[argc-2];
  FILE *fix = fopen(fdiff, "r");
  FILE *file1 = fopen(toFix, "r+"); 
  char line[128];
   
  if(fix && file1){
    while(fgets(line,sizeof(line),fix) !=NULL){
	parsediff(line, &diff);
	fseek(file1, diff.offset-1, SEEK_SET);
	fwrite(&diff.new , 1, 1, file1);
    }//end while2
  }//end if
  fclose(fix);
  fclose(file1);
  return 0; 
}
