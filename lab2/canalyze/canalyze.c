#include <stdlib.h>
#include <stdio.h>
#include "fgetname.h"
#include "namelist.h"

int main(int argc, char **argv) {
  
  int i;
  char *kwords[] ={"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "unsigned", "void", "volatile" ,"while"};
  namelist nl = make_namelist();
  
  for(i=0; i<31; i++){
    add_name(nl, kwords[i]);
  }

  
  for(i=1; i<argc; i++){
	FILE *stream = fopen(argv[i],"r");
	char name[64];
	if(!stream) {
		fprintf(stderr, "run the test in the source directory\n");
		return 1;
	}
	
	while(fgetname(name, sizeof(name), stream)){
	//	printf("%s ", name);
	
	  int j;
	  for(j=0; j<31; j++){
	      if(!strcmp(kwords[j], name)){
		add_name(nl ,name);
		//printf("%s\n", name);
	      }
	  }	
//	printf("\n");
	}
	fclose(stream);
  }
	for(i = 0; i!=nl->size; ++i) {
	  if(nl->names[i].count==2){
	  printf("%s ", nl->names[i].name);
	  }
	}
	printf("\n");
	return 0;
}

	

 
