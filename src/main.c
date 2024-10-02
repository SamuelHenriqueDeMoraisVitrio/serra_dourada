
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.def.h"
//silver_chain_scope_end





int main(int arg, char **argv){
  
  dtw = newDtwNamespace();
  ctext = newCTextNamespace();
  cli = newCliNamespace();
  cliEntry = newCLI_entry(arg, argv);

  CTextStack *self = ctext.stack.newStack_string("sla/sui/nsei.txt");

  printf("\n\t%s\n\n", filter_paths_with_text(self)?"true":"false");

  return EXIT_SUCCESS;
}







