
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../../imports/imports.dec.h"
//silver_chain_scope_end



const char *flag_call_str_by_macro(const char *flag_name, int position){
  CliFlag *flag = flag_call(flag_name);
  return flag_call_str(flag, position);
}

int flag_call_int_by_macro(const char* flag_name, int position){
  CliFlag *flag = flag_call(flag_name);
  return flag_call_int(flag, position);
}

bool flag_call_bool_by_macro(const char* flag_name, int position){
  CliFlag *flag = flag_call(flag_name);
  return flag_call_bool(flag, position);
}


