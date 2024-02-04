// Arquivo Lista_os Sequencial.h
#define MAX 100

struct ordemdeservico {
   int codord; //Código da ordem de serviço -> código a ser considerado é o da ordenação da lista_os
   int codequi; //Código do equipamento
   int codcli; // Código do cliente
   int codser; // Código do serviço a ser realizado
   int codfun; // Código do funcionário que realizará
   int status; // 0 indica não realizado, 1 indica realizado
   char prioridade; // prioridade de realização do serviço podendo ser A=3, B=2 ou C=1
};

struct equipamento {
   int codequi; // código do equipamento
   char equipamento[30]; // identificação do equipamento
};

struct cliente {
   int codcli; // código do cliente
   char cliente[30]; // razão social ou nome fantasia do cliente;
};

struct servico {
   int codser; // código do serviço
   char servico[30]; // ex.: troca de filtro, limpeza, etc
};

struct funcionario {
   int codfun; // código do funcionário
   char funcionario[30]; // nome do funcionário
};



typedef struct lista_os Lista_os;
typedef struct lista_eq Lista_eq;
typedef struct lista_cli Lista_cli;
typedef struct lista_ser Lista_ser;
typedef struct lista_fun Lista_fun;



Lista_os* cria_lista_os();
Lista_eq* cria_lista_eq();
Lista_cli* cria_lista_cli();
Lista_ser* cria_lista_ser();
Lista_fun* cria_lista_fun();



void libera_lista_os(Lista_os* li);
void libera_lista_eq(Lista_eq* li);
void libera_lista_cli(Lista_cli* li);
void libera_lista_ser(Lista_ser* li);
void libera_lista_fun(Lista_fun* li);



int consulta_lista_pos(Lista_os* li, int pos, struct ordemdeservico *os);
int consulta_lista_codequi(Lista_os* li, int codequi, struct ordemdeservico *os);
int consulta_lista_codcli(Lista_os* li, int codcli, struct ordemdeservico *os);
int consulta_lista_codser(Lista_os* li, int codser, struct ordemdeservico *os);
int consulta_lista_codfun(Lista_os* li, int codfun, struct ordemdeservico *os);



int insere_lista_ordenada_os(Lista_os* li, struct ordemdeservico os);
int remove_lista_os(Lista_os* li, int codord);
int tamanho_lista_os(Lista_os* li);
int lista_cheia_os(Lista_os* li);
int lista_vazia_os(Lista_os* li);



int insere_lista_ordenada_eq(Lista_eq* li, struct equipamento eq);
int remove_lista_eq(Lista_eq* li, int codequi);
int tamanho_lista_eq(Lista_eq* li);
int lista_cheia_eq(Lista_eq* li);
int lista_vazia_eq(Lista_eq* li);



int insere_lista_ordenada_cli(Lista_cli* li, struct cliente cli);
int remove_lista_cli(Lista_cli* li, int codcli);
int tamanho_lista_cli(Lista_cli* li);
int lista_cheia_cli(Lista_cli* li);
int lista_vazia_cli(Lista_cli* li);



int insere_lista_ordenada_ser(Lista_ser* li, struct servico ser);
int remove_lista_ser(Lista_ser* li, int codser);
int tamanho_lista_ser(Lista_ser* li);
int lista_cheia_ser(Lista_ser* li);
int lista_vazia_ser(Lista_ser* li);



int insere_lista_ordenada_fun(Lista_fun* li, struct funcionario fun);
int remove_lista_fun(Lista_fun* li, int codfun);
int tamanho_lista_fun(Lista_fun* li);
int lista_cheia_fun(Lista_fun* li);
int lista_vazia_fun(Lista_fun* li);



void imprime_lista_os(Lista_os* li);
void imprime_todas_os(Lista_os* li);
void imprime_lista_eq(Lista_eq* li);
void imprime_lista_cli(Lista_cli* li);
void imprime_lista_ser(Lista_ser* li);
void imprime_lista_fun(Lista_fun* li);