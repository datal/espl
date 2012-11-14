#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int argc, char **argv) {
  
 int print=1;
 int numDiff=0;
 int i;
  
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
	printf ("-n NUMBER  print first NUMBER differences and exit\n");
	printf ("-q do not print out the differences, exits with code 0\n if the files are identical, 1 otherwise\n");
	break;
      
      case 'n':
	for(i=0; i<argc; i++){
	  if(!strcmp(argv[i], "-n")){
	    numDiff=atoi(argv[i+1]);
	  }
	}
	break;
      
      case 'q':
	print=0;
	break;
      
      default:
	printf("default\n");
    }
  }//end while
    
    unsigned char ch1, ch2;
    char *firstFileName=argv[argc-2];
    char *secondFileName=argv[argc-1];
    FILE *file1 = fopen( firstFileName, "r"); 
    FILE *file2 = fopen( secondFileName, "r");
    int place; 
    int counter=0;
    
    if(file1 && file2){
      place=0;
      while(fread(&ch1, 1, 1, file1) && fread(&ch2, 1, 1, file2)) {
	place++;
	if(&ch1 && &ch2){
	  if(ch1!=ch2 && ((numDiff==0) || (numDiff>0 && counter<numDiff))){
	    if(print){
	      printf("byte %d -%d +%d\n", place, ch1, ch2);
	      counter++;
	    //$bcmp foo bar > diff
	    }
	  }
	}
      }//end while
    }//end if
  if(counter>0){
    return 1;
  }
  
  fclose(file1);
  fclose(file2);
  return 0;
}