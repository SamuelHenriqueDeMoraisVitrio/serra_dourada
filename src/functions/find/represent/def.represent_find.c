
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end





void private_represent_string_array_filtered(CTextStack *self){

  const char *text = dtw.load_string_file_content(self->rendered_text);

  CliFlag *key = flag_call(__KEY_FLAG);

  if(!text || !key->exist || !flag_call_str(key, 0)){
    perror(RED "\n\tinvalid key or file is not readable.\n" RESET);
    exit(EXIT_FAILURE);
  }

  ResponseSearchArray search = search_string(text, flag_call_str(key, 0), !flag_call(__UPPER_CASE_SENSITIVE_FLAG)->exist);

  if(!search.exist){
    perror(RED "\n\tNo key found in source\n" RESET);
    exit(EXIT_FAILURE);
  }


  printf("\n\tpath: %s\n\n" BLUE, self->rendered_text);

  for(int i = 0; i < search.size; i++){
    CTextStack *text_no_formated = ctext.stack.newStack_string(search.searchs[i].context);
    CTextStack *context_replaced = ctext.stack.replace(text_no_formated, "\n", "");
    printf("context:\t... \"%s\" ...\n", context_replaced->rendered_text);
    printf("line:\t%ld\n", search.searchs[i].line);
    printf("position:\t%ld\n\n", search.searchs[i].position);
  }

  return;

}
