#include <stdio.h>
 
/* count number of words in sentence */
int main(int argc, char **argv) {
  int i;
 
  for(i=argc-1; i!=1; --i) {
    printf("%s", argv[i]);
 
    if(i!=1)
    printf(" ");
  }
 
  return 0;
}