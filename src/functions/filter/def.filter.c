
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end



bool filter_paths_with_text(CTextArray *self){
  
  const char *path_src = flag_call_str_by_macro(__SRC_FLAG, 0);

  if(!path_src){
    path_src = "src";
  }


  return true;

}






