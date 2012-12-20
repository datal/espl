#include <stdlib.h>
#include <stdio.h>
#include "diff.h" 
#include <getopt.h>
#include <assert.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


void fix(FILE *file1, char *line, int print);

int main(int argc, char **argv) {
  
  int numPrint=0;
  pid_t childId;
  
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
	printf ("-p NPROC maximum number of child processes\n");
	break;
      
      case 'r':
	break;
      
      case 'm':
	numPrint=1;
	break;
	
      case 'p':
	
	break;
      
      default:
	printf("default\n");
    }
  }//end while
  
  
  char *fdiff=argv[argc-1];
  char *toFix=argv[argc-2];
  FILE *fix1 = fopen(fdiff, "r");
  FILE *file1 = fopen(toFix, "r+"); 
  char line[128];
  int counter = 0;
    
  if(fix1 && file1){
    while(fgets(line,sizeof(line),fix1) !=NULL){
	childId = fork();
	if(childId == -1) {
	  perror("fork");    exit(EXIT_FAILURE); 
	} 
	
	if(childId == 0){
	  counter++;
	  printf("new child PID is %ld\n", (long) getpid());
	  fix(file1, line, numPrint);
	  exit(0);
	}
    }//end while2
  }//end if
  
  int i;
  for(i=0; i<counter; i++){
    wait(0);
  }
  
  fclose(fix1);
  fclose(file1);
  return 0; 
}

void fix(FILE *file1, char *line, int print){
  struct diff diff;
  parsediff(line, &diff);
  fseek(file1, diff.offset-1, SEEK_SET);
  fwrite(&diff.new , 1, 1, file1);
  if(print) {
    printf("A change has been applied\n");
  }
}  
