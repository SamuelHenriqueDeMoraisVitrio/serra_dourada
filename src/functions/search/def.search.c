
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end





int private_compare_ignore_case(const char *str1, const char *str2) {
  while (*str1 && *str2) {
    if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
      return 0;
    }
    str1++;
    str2++;
  }
  return *str2 == '\0';
}

ResponseSearchArray search_string(const char *texto, const char *palavra, bool diferenciar_maiusculo_minusculo) {
    int tamanho_texto = strlen(texto);
    int tamanho_palavra = strlen(palavra);

    ResponseSearchArray lista_resultados;
    lista_resultados.size = 0;
    lista_resultados.searchs = NULL;

    if (tamanho_palavra == 0) {
        return lista_resultados;
    }

    int linha_atual = 1;
    for (int i = 0; i <= tamanho_texto - tamanho_palavra; i++) {
        if (texto[i] == '\n') {
            linha_atual++;
        }

        bool encontrado = false;
        if (diferenciar_maiusculo_minusculo) {
            encontrado = (strncmp(&texto[i], palavra, tamanho_palavra) == 0);
        } else {
            encontrado = private_compare_ignore_case(&texto[i], palavra);
        }

        if (encontrado) {
            lista_resultados.size++;

            lista_resultados.searchs = realloc(lista_resultados.searchs, lista_resultados.size * sizeof(ResponseSearch));
            if (lista_resultados.searchs == NULL) {
                printf("Interno Error;");
                exit(EXIT_FAILURE);
            }

            ResponseSearch *resultado_atual = &lista_resultados.searchs[lista_resultados.size - 1];
            resultado_atual->position = i;
            resultado_atual->line = linha_atual;

            int margin = flag_call_int_by_macro(__MARGIN_FLAG, 0);
                
            if(margin < 1){
                margin = 8;
            }
            

            int inicio = (i - margin < 0) ? 0 : i - margin;
            int fim = (i + tamanho_palavra + margin > tamanho_texto) ? tamanho_texto : i + tamanho_palavra + margin;

            int tamanho_contexto = fim - inicio + 1;
            resultado_atual->context = (char *)malloc(tamanho_contexto * sizeof(char));
            if (resultado_atual->context != NULL) {
                strncpy(resultado_atual->context, &texto[inicio], fim - inicio);
                resultado_atual->context[fim - inicio] = '\0';
            }

            resultado_atual->path = (char *)malloc(256 * sizeof(char));
            if (resultado_atual->path != NULL) {
                strcpy(resultado_atual->path, "caminho/arquivo.txt");
            }

            i += tamanho_palavra - 1;
        }
    }

    if(lista_resultados.size > 0){
        lista_resultados.exist = true;
    }

    return lista_resultados;
}

bool ResponseSearchArray_exist(ResponseSearchArray *struct_value, int position){
    if(!struct_value){
        return false;
    }
    if(!struct_value->searchs){
        return false;
    }
    if(!struct_value->searchs[position].context || strcmp(struct_value->searchs[position].context, "") == 0){
        return false;
    }
    return true;
}

