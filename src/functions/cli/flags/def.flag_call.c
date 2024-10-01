
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end



CliFlag *flag_call(const char *name_flag){
  return cli.entry.get_flag(cliEntry, name_flag, CLI_NOT_CASE_SENSITIVE);
}



