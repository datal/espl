#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int argc, char **argv) {
 /* int i;
  for ( i = 1; i < argc; i++ ){
    if (!strcmp(argv[i], "-h")){ 
      printf("OPTIONS\n");
      printf("             -h  print a summary of options and exit\n");
      printf("             -n NUMBER  print first NUMBER differences and exit\n");
      printf("             -q do not print out the differences, exist with code 0\n");
      printf("                  if the files are identical, 1 otherwise\n");
      return 0;
    }
    else (!strcmp(argv[i], "-n")){
    }
    else (!strcmp(argv[i], "-q")){
    }  
*/     
    unsigned char ch1, ch2;
    
    FILE *file1 = fopen( "file1", "r"); 
    FILE *file2 = fopen( "file2", "r");
    int place; 
    
    if(file1 && file2){
      place=0;
    while(fread(&ch1, 1, 1, file1) && fread(&ch2, 1, 1, file2)) {
      place++;
      if(&ch1 && &ch2){
	if(ch1!=ch2){
	  printf("byte %d -%d +%d\n", place, ch1, ch2);
	  //$bcmp foo bar > diff
	}
      }
    }
  }
  fclose(file1);
  fclose(file2);
  return 0;
}