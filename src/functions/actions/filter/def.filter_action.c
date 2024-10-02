
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
#include <stdio.h>
//silver_chain_scope_end





void filter_paths(CTextArray *paths){

  CTextArray *filtered_paths = ctext.array.filter(paths, private_filter_paths_with_text);

  if(filtered_paths->size < 1){
    perror(RED "\n\tNo key found in source\n" RESET);
    return;
  }

  printf("\n\tKeyword found in the following files.\n\n");

  ctext.array.foreach(filtered_paths, private_represent_paths);

  printf("\n\tend\n");

}
