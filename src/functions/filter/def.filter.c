
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
#include <stdio.h>
//silver_chain_scope_end



bool private_filter_paths_with_text(CTextStack *self){
  
  CTextArray *elements = ctext.array.newArray();
  CTextArray *elements_ignore_path = ctext.array.newArray();
  

  CliFlag *flag_not_filter = flag_call(__IGNORE_EXTENSION_DEPTH_FLAG);

  bool flag_bool = true;

  if(!flag_not_filter->exist){

    CliFlag *flag_filter = flag_call(__EXTENSION_DEPTH_FLAG);

    elements = flag_filter->elements;

    flag_bool = elements->size < 1;
  }else{
    elements = flag_not_filter->elements;
  }

  CliFlag *flag_ignore_path = flag_call(__IGNORE_FIND_FLAG);

  elements_ignore_path = flag_ignore_path->elements;

  DtwPath *file = dtw.path.newPath(self->rendered_text);

  const char *path = dtw.path.get_path(file);
  const char *extension = dtw.path.get_extension(file);


  for (int i = 0; i < elements->size; i++) {
    const char *current_extension = elements->stacks[i]->rendered_text;

    if (strcmp(extension, current_extension) == 0) {
      flag_bool = !flag_bool;
      break;
    }
  }

  for (int i = 0; i < elements_ignore_path->size; i++) {
    const char *current_path = elements_ignore_path->stacks[i]->rendered_text;

    if (strcmp(path, current_path) == 0) {
      flag_bool = false;
      break;
    }
  }

  if(!flag_bool){
    return flag_bool;
  }

  const char *text = dtw.load_string_file_content(path);

  CliFlag *key = flag_call(__KEY_FLAG);

  if(!text || !key->exist || !flag_call_str(key, 0)){
    return false;
  }

  printf("\ntext:\n%s\n", text);

  ResponseSearchArray search = search_string(text, flag_call_str(key, 0), !flag_call(__UPPER_CASE_SENSITIVE_FLAG)->exist);

  if(!search.exist){
    return false;
  }

  return true;

}






