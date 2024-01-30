#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"  



// definição das estruturas de listas aplicadas no projeto
struct lista_os{
   int codord;
   struct ordemdeservico OrdemDeServico[MAX];
};
struct lista_eq{
   int codequi;
   struct equipamento Equipamento[MAX];
};
struct lista_cli{
   int codcli;
   struct cliente Cliente[MAX];
};
struct lista_ser{
   int codser;
   struct servico Servico[MAX];
};
struct lista_fun{
   int codfun;
   struct funcionario Funcionario[MAX];
};



// Declaração dos diferentes tipos de lista
Lista_os* cria_lista_os(){
   Lista_os *li;
   li = (Lista_os*) malloc(sizeof(struct lista_os));
   if(li != NULL){
      li->codord = 0;
   }
   return li;
}
Lista_eq* cria_lista_eq(){
   Lista_eq *li;
   li = (Lista_eq*) malloc(sizeof(struct lista_eq));
   if(li != NULL){
      li->codequi = 0;
   }
   return li;
}
Lista_cli* cria_lista_cli(){
   Lista_cli *li;
   li = (Lista_cli*) malloc(sizeof(struct lista_cli));
   if(li != NULL){
      li->codcli = 0;
   }
   return li;
}
Lista_ser* cria_lista_ser(){
   Lista_ser *li;
   li = (Lista_ser*) malloc(sizeof(struct lista_ser));
   if(li != NULL){
      li->codser = 0;
   }
   return li;
}
Lista_fun* cria_lista_fun(){
   Lista_fun *li;
   li = (Lista_fun*) malloc(sizeof(struct lista_fun));
   if(li != NULL){
      li->codfun = 0;
   }
   return li;
}



// Funções para limpar os diferentes tipos de listas implmentados
void libera_lista_os(Lista_os* li){
   free(li);
}
void libera_lista_eq(Lista_eq* li){
   free(li);
}
void libera_lista_cli(Lista_cli* li){
   free(li);
}
void libera_lista_ser(Lista_ser* li){
   free(li);
}
void libera_lista_fun(Lista_fun* li){
   free(li);
}



// Consultar a lista de OS's segundo cada campo.
// não foi implementado para as outras listas, de clientes, equipamentos, etc...
// pois o objetivo final é o processamento das ordens de serviço e não dos seus campos
// apesar de ser necessária a inserção destes por listas para maior controle
int consulta_lista_pos(Lista_os* li, int pos, struct ordemdeservico *os){
   if(li == NULL || pos <= 0 ||  pos > li->codord)
       return 0;
   *os = li->OrdemDeServico[pos-1];
   return 1;
}
int consulta_lista_codequi(Lista_os* li, int codequi, struct ordemdeservico *os){
   if(li == NULL)
       return 0;
   int i = 0;
   while(i<li->codord && li->OrdemDeServico[i].codequi != codequi)
       i++;
   if(i == li->codord)//elemento nao encontrado
       return 0;
   *os = li->OrdemDeServico[i];
   return 1;
}
int consulta_lista_codcli(Lista_os* li, int codcli, struct ordemdeservico *os){
   if(li == NULL)
       return 0;
   int i = 0;
   while(i<li->codord && li->OrdemDeServico[i].codcli != codcli)
       i++;
   if(i == li->codord)//elemento nao encontrado
       return 0;
   *os = li->OrdemDeServico[i];
   return 1;
}
int consulta_lista_codser(Lista_os* li, int codser, struct ordemdeservico *os){
   if(li == NULL)
       return 0;
   int i = 0;
   while(i<li->codord && li->OrdemDeServico[i].codser != codser)
       i++;
   if(i == li->codord)//elemento nao encontrado
       return 0;
   *os = li->OrdemDeServico[i];
   return 1;
}
int consulta_lista_codfun(Lista_os* li, int codfun, struct ordemdeservico *os){
   if(li == NULL)
       return 0;
   int i = 0;
   while(i<li->codord && li->OrdemDeServico[i].codfun != codfun)
       i++;
   if(i == li->codord)//elemento nao encontrado
       return 0;
   *os = li->OrdemDeServico[i];
   return 1;
}



// Funções de manipulação de listas voltadas para a lista de OS's
int insere_lista_ordenada_os(Lista_os* li, struct ordemdeservico os){
   if(li == NULL)
       return 0;
   
   if(li->codord == MAX)//lista cheia
       return 0;
   
   int k,i = 0;
   
   while(i<li->codord && li->OrdemDeServico[i].codord < os.codord)
       i++;

   for(k=li->codord-1; k >= i; k--)
       li->OrdemDeServico[k+1] = li->OrdemDeServico[k];

   li->OrdemDeServico[i] = os;
   li->codord++;
   return 1;
}
int remove_lista_os(Lista_os* li, int codord){
   if(li == NULL)
       return 0;
   if(li->codord == 0)
       return 0;
   int i = 0;
   while(i<li->codord && li->OrdemDeServico[i].codord != codord)
       i++;
   if(i == li->codord)//elemento nao encontrado
       return 0;
   
   li->codord--;
   li->OrdemDeServico[i] = li->OrdemDeServico[li->codord];
   return 1;
}
int tamanho_lista_os(Lista_os* li){
   if(li == NULL)
       return -1;
   else
       return li->codord;
}
int lista_cheia_os(Lista_os* li){
   if(li == NULL)
       return -1;
   return (li->codord == MAX);
}
int lista_vazia_os(Lista_os* li){
   if(li == NULL)
       return -1;
   return (li->codord == 0);
}



// Funções de manipulação de listas para a Lista de equipamentos
int insere_lista_ordenada_eq(Lista_eq* li, struct equipamento eq){
   if(li == NULL)
       return 0;
   
   if(li->codequi == MAX)//lista cheia
       return 0;
   
   int k,i = 0;
   
   while(i<li->codequi && li->Equipamento[i].codequi < eq.codequi)
       i++;

   for(k=li->codequi-1; k >= i; k--)
       li->Equipamento[k+1] = li->Equipamento[k];

   li->Equipamento[i] = eq;
   li->codequi++;
   return 1;
}
int remove_lista_eq(Lista_eq* li, int codequi){
   if(li == NULL)
       return 0;
   if(li->codequi == 0)
       return 0;
   int i = 0;
   while(i<li->codequi && li->Equipamento[i].codequi != codequi)
       i++;
   if(i == li->codequi)//elemento nao encontrado
       return 0;
   
   li->codequi--;
   li->Equipamento[i] = li->Equipamento[li->codequi];
   return 1;
}
int tamanho_lista_eq(Lista_eq* li){
   if(li == NULL)
       return -1;
   else
       return li->codequi;
}
int lista_cheia_eq(Lista_eq* li){
   if(li == NULL)
       return -1;
   return (li->codequi == MAX);
}
int lista_vazia_eq(Lista_eq* li){
   if(li == NULL)
       return -1;
   return (li->codequi == 0);
}



// Funções de manipulação de listas para a lista de clientes
int insere_lista_ordenada_cli(Lista_cli* li, struct cliente cli){
   if(li == NULL)
       return 0;
   
   if(li->codcli == MAX)//lista cheia
       return 0;
   
   int k,i = 0;
   
   while(i<li->codcli && li->Cliente[i].codcli < cli.codcli)
       i++;

   for(k=li->codcli-1; k >= i; k--)
       li->Cliente[k+1] = li->Cliente[k];

   li->Cliente[i] = cli;
   li->codcli++;
   return 1;
}
int remove_lista_cli(Lista_cli* li, int codcli){
   if(li == NULL)
       return 0;
   if(li->codcli == 0)
       return 0;
   int i = 0;
   while(i<li->codcli && li->Cliente[i].codcli != codcli)
       i++;
   if(i == li->codcli)//elemento nao encontrado
       return 0;
   
   li->codcli--;
   li->Cliente[i] = li->Cliente[li->codcli];
   return 1;
}
int tamanho_lista_cli(Lista_cli* li){
   if(li == NULL)
       return -1;
   else
       return li->codcli;
}
int lista_cheia_cli(Lista_cli* li){
   if(li == NULL)
       return -1;
   return (li->codcli == MAX);
}
int lista_vazia_cli(Lista_cli* li){
   if(li == NULL)
       return -1;
   return (li->codcli == 0);
}



// Funções de manipulação de listas para a lista de serviços
int insere_lista_ordenada_ser(Lista_ser* li, struct servico ser){
   if(li == NULL)
       return 0;
   
   if(li->codser == MAX)//lista cheia
       return 0;
   
   int k,i = 0;
   
   while(i<li->codser && li->Servico[i].codser < ser.codser)
       i++;

   for(k=li->codser-1; k >= i; k--)
       li->Servico[k+1] = li->Servico[k];

   li->Servico[i] = ser;
   li->codser++;
   return 1;
}
int remove_lista_ser(Lista_ser* li, int codser){
   if(li == NULL)
       return 0;
   if(li->codser == 0)
       return 0;
   int i = 0;
   while(i<li->codser && li->Servico[i].codser != codser)
       i++;
   if(i == li->codser)//elemento nao encontrado
       return 0;
   
   li->codser--;
   li->Servico[i] = li->Servico[li->codser];
   return 1;
}
int tamanho_lista_ser(Lista_ser* li){
   if(li == NULL)
       return -1;
   else
       return li->codser;
}
int lista_cheia_ser(Lista_ser* li){
   if(li == NULL)
       return -1;
   return (li->codser == MAX);
}
int lista_vazia_ser(Lista_ser* li){
   if(li == NULL)
       return -1;
   return (li->codser == 0);
}



// Funções de manipulação de listas para a lista de funcionários
int insere_lista_ordenada_fun(Lista_fun* li, struct funcionario fun){
   if(li == NULL)
       return 0;
   
   if(li->codfun == MAX)//lista cheia
       return 0;
   
   int k,i = 0;
   
   while(i<li->codfun && li->Funcionario[i].codfun < fun.codfun)
       i++;

   for(k=li->codfun-1; k >= i; k--)
       li->Funcionario[k+1] = li->Funcionario[k];

   li->Funcionario[i] = fun;
   li->codfun++;
   return 1;
}
int remove_lista_fun(Lista_fun* li, int codfun){
   if(li == NULL)
       return 0;
   if(li->codfun == 0)
       return 0;
   int i = 0;
   while(i<li->codfun && li->Funcionario[i].codfun != codfun)
       i++;
   if(i == li->codfun)//elemento nao encontrado
       return 0;
   
   li->codfun--;
   li->Funcionario[i] = li->Funcionario[li->codfun];
   return 1;
}
int tamanho_lista_fun(Lista_fun* li){
   if(li == NULL)
       return -1;
   else
       return li->codfun;
}
int lista_cheia_fun(Lista_fun* li){
   if(li == NULL)
       return -1;
   return (li->codfun == MAX);
}
int lista_vazia_fun(Lista_fun* li){
   if(li == NULL)
       return -1;
   return (li->codfun == 0);
}



void imprime_lista(Lista_os* li){
   if(li == NULL)
       return;
   int i;
   for(i=0; i< li->codord; i++){
      printf("Codigo da Ordem de Serviço: %d\n",li->OrdemDeServico[i].codord);
      printf("Codigo do Equipamento: %d\n",li->OrdemDeServico[i].codequi);
      printf("Cliente: %s\n",li->OrdemDeServico[i].codcli);
      printf("-------------------------------\n");
   }
}