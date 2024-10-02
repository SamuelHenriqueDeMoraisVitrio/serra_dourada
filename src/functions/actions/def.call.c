
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
#include <stdio.h>
//silver_chain_scope_end



void call_actions(){
  CliFlag *src_flag = flag_call(__SRC_FLAG);

  if(!src_flag->exist || src_flag->size < 1){
    perror(RED "flag source not informed correctly." RESET);
    exit(EXIT_FAILURE);
  }

  const char *value_src_flag = flag_call_str(src_flag, 0);

  if(!value_src_flag){
    perror(RED "Value provided for font is incorrect." RESET);
    exit(EXIT_FAILURE);
  }

  DtwStringArray *dtw_list_paths = dtw.list_files_recursively(value_src_flag, DTW_CONCAT_PATH);
  CTextArray *string_array = ctext.array.newArray();

  if(dtw_list_paths->size < 1){
    perror(RED "Value provied for font is incorrect." RESET);
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < dtw_list_paths->size; i++){
    ctext.array.append_string(string_array, dtw_list_paths->strings[i]);
  }

  CliFlag *tipe_action_flag = flag_call(__TIPE_ACTION_FLAG);

  const char *tipe_action = flag_call_str(tipe_action_flag, 0);

  if(tipe_action_flag->exist && tipe_action_flag->size < 1){
    if(strcmp(tipe_action, "filter") == 0){
      private_filter_paths(string_array);
      return;
    }
  }
  printf("\n\tsize %d\n", dtw_list_paths->size);

  private_find_action(string_array);

}


