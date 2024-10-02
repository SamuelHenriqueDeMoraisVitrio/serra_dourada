
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../../imports/imports.dec.h"
//silver_chain_scope_end




const char *flag_call_str(CliFlag *flag, int position){
  return cli.flag.get_str(flag, position, CLI_NOT_CASE_SENSITIVE);
}

int flag_call_int(CliFlag *flag, int position){
  return (int)cli.flag.get_long(flag, position);
}


bool flag_call_bool(CliFlag *flag, int position){
  return cli.flag.get_bool(flag, position);
}

