
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

  ctext.array.append_string(self, "test/b.txt");

  private_filter_paths(self);

  return EXIT_SUCCESS;
}







