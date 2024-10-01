
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.def.h"
//silver_chain_scope_end



int main(int arg, char **argv){
  
  dtw = newDtwNamespace();
  ctext = newCTextNamespace();
  cli = newCliNamespace();
  cliEntry = newCLI_entry(arg, argv);

  const char *text = "Meu nome é Samuel Henrique";
  const char *text_find = "Samuel";

  ResponseSearchArray find = search_string(text, text_find, true);

  printf("\n\tAchado: %s\n", find.searchs[0].context);

  return EXIT_SUCCESS;
}







