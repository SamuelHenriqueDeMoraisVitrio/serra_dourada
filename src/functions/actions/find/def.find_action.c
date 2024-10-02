
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end


void private_find_action(CTextArray *paths){
  
  CTextArray *filtered_paths = ctext.array.filter(paths, private_filter_paths_with_text);

  if(filtered_paths->size < 1){
    perror(RED "\n\tNo key found in source\n" RESET);
    return;
  }

  ctext.array.foreach(filtered_paths, private_represent_string_array_filtered);

  printf("\tend\n");
}


