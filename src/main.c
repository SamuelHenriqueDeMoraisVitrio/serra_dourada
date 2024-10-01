
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.def.h"
//silver_chain_scope_end





int main(int arg, char **argv){
  
  dtw = newDtwNamespace();
  ctext = newCTextNamespace();
  cli = newCliNamespace();
  cliEntry = newCLI_entry(arg, argv);

  const char *text = "Meu nome é Samuel Henrique\nMeu nome é Samuel Henrique\nMeu nome é Samuel Henrique\nMeu nome é Samuel Henrique\n";
  const char *text_find = "Samuel";

  ResponseSearchArray find = search_string(text, text_find, NOT_UPPER_CASE_SENSITIVI);

  if(!ResponseSearchArray_exist(&find, 0)){
    return 0;
  }

  printf("\n\tAchado: %s\n\tLine: %d\n\tPosition: %d\n\tsize: %d\n\n", find.searchs[0].context, find.searchs[0].line, find.searchs[0].position, find.size);

  return EXIT_SUCCESS;
}







