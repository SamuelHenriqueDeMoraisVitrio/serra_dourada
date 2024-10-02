
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.def.h"
//silver_chain_scope_end





int main(int arg, char **argv){
  
  dtw = newDtwNamespace();
  ctext = newCTextNamespace();
  cli = newCliNamespace();
  cliEntry = newCLI_entry(arg, argv);

  CTextArray *self = ctext.array.newArray();

  filter_paths_with_text(self);

  return EXIT_SUCCESS;
}







