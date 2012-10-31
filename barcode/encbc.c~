#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv) {
	int barcode[BC_WIDTH][BC_NBITS] = {0};
	int i, j, k;
	k=0;
			
	/* ecode */	
	for(i=1; i!=argc; ++i) {
	  for(j=0; argv[i][j]; j++){
	    bc_char2bits(argv[i][j], barcode[k]);  
	    k++;
	  } 
	  if(i!=argc-1){
	  bc_char2bits(' ', barcode[k]); 
	  k++;
	  }
	}
	
	for(j=0; j!=BC_NBITS; ++j) {
	  for(i=0; i!=k; i++){
	    if(barcode[i][j])
	      printf("#");
	    else
	      printf(" ");
	  }
	  printf("\n");
	}

    return 0;
}