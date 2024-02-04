// Aluno: Gabriel Brito Ribeiro - 202305530

// Projeto de TAD para representação de Ordens de Serviços para clientes de uma empresa de manutenção.
// Os equipamentos, clientes, serviços e funcionários, bem como as próprias ordens de serviço são inseridas
// em listas sequenciais. Durante o cadastro de uma ordem de serviço é possível fazer o cadastro de novos elementos
// em cada uma das outras listas;

#include <stdio.h>
#include "ListaSequencial.h"

void ordensdeservico(Lista_os* li){
   int op;
   do{
      printf("\n----------------MENU ORDENS DE SERVICO----------------\n");
      printf("\nSelecione uma das opções a seguir:\n");
      printf("1. Exibir ordens de serviço em aberto\n");
      printf("2. Inserir ordem de serviço\n");
      printf("3. Remover ordem de serviço\n");
      printf("4. Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &op);
      switch (op) {
         case 1:
            imprime_todas_os(&li);
            break;
         case 2:
            struct ordemdeservico os;
            // printf's para coletar as informações do usuário e cadastrar a os;
            insere_lista_ordenada_os(&li, os);
            break;
         case 3:
            int codord;
            printf("Informe o código da ordem de serviço: ");
            scanf("%d", &codord);
            remove_lista_os(&li, codord);
            break;
         default:
            break;
      } 
         
   } while (op != 4);
}

void equipamentos(Lista_eq* li){
   int op;
      do{
         printf("\n----------------MENU EQUIPAMENTOS----------------\n");
         printf("\nSelecione uma das opções a seguir:\n");
         printf("1. Exibir todos os equipamentos\n");
         printf("2. Inserir equipamento\n");
         printf("3. Remover equipamento\n");
         printf("4. Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d", &op);
         switch (op) {
            case 1:
               imprime_lista_eq(&li);
               break;
            case 2:
               struct equipamento eq;
               // printf's para coletar as informações do usuário e cadastrar a os;
               insere_lista_ordenada_eq(&li, eq);
               break;
            case 3:
               int codequi;
               printf("Informe o código do equipamento: ");
               scanf("%d", &codequi);
               remove_lista_eq(&eq, codequi);
               break;
            default:
               break;
         } 
            
      } while (op != 4);
}

void clientes(Lista_cli* li){
   int op;
      do{
         printf("\n----------------MENU CLIENTES----------------\n");
         printf("\nSelecione uma das opções a seguir:\n");
         printf("1. Exibir todos os clientes\n");
         printf("2. Inserir cliente\n");
         printf("3. Remover cliente\n");
         printf("4. Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d", &op);
         switch (op) {
            case 1:
               imprime_lista_cli(&li);
               break;
            case 2:
               struct cliente cli;
               // printf's para coletar as informações do usuário e cadastrar a os;
               insere_lista_ordenada_cli(&li, cli);
               break;
            case 3:
               int codcli;
               printf("Informe o código do cliente: ");
               scanf("%d", &codcli);
               remove_lista_eq(&li, codcli);
               break;
            default:
               break;
         } 
            
      } while (op != 4);  
}

void servicos(Lista_ser* li){
   int op;
      do{
         printf("\n----------------MENU SERVICOS----------------\n");
         printf("\nSelecione uma das opções a seguir:\n");
         printf("1. Exibir todos os serviços\n");
         printf("2. Inserir serviço\n");
         printf("3. Remover serviço\n");
         printf("4. Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d", &op);
         switch (op) {
            case 1:
               imprime_lista_cli(&li);
               break;
            case 2:
               struct servico ser;
               // printf's para coletar as informações do usuário e cadastrar a os;
               insere_lista_ordenada_ser(&li, ser);
               break;
            case 3:
               int codser;
               printf("Informe o código do serviço: ");
               scanf("%d", &codser);
               remove_lista_eq(&li, codser);
               break;
            default:
               break;
         } 
            
      } while (op != 4);
}

void funcionarios(Lista_fun* li){
   int op;
      do{
         printf("\n----------------MENU FUNCIONÁRIOS----------------\n");
         printf("\nSelecione uma das opções a seguir:\n");
         printf("1. Exibir todos os funcionários\n");
         printf("2. Inserir funcionário\n");
         printf("3. Remover funcionário\n");
         printf("4. Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d", &op);
         switch (op) {
            case 1:
               imprime_lista_cli(&li);
               break;
            case 2:
               struct funcionario fun;
               // printf's para coletar as informações do usuário e cadastrar a os;
               insere_lista_ordenada_fun(&li, fun);
               break;
            case 3:
               int codfun;
               printf("Informe o código do funcionário: ");
               scanf("%d", &codfun);
               remove_lista_eq(&li, codfun);
               break;
            default:
               break;
         } 
            
      } while (op != 4);
}

int main(){
   printf("\nSISTEMA DE GESTÃO DE ORDENS DE SERVIÇO\n");
   // Inicialização das Listas:
   Lista_os* os = cria_lista_os(); // ordens de serviço
   Lista_eq* eq = cria_lista_eq(); // equipamentos
   Lista_cli* cli = cria_lista_cliente(); //clientes
   Lista_ser* ser = cria_lista_ser(); // serviços
   Lista_fun* fun = cria_lista_fun(); // funcionários
   int op;
   do{
      printf("\nSelecione uma das opções a seguir:\n");
      printf("1. Ordens de Serviço\n");
      printf("2. Equipamentos\n");
      printf("3. Clientes\n");
      printf("4. Serviços\n");
      printf("5. Funcionários\n");
      printf("6. Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &op);
      switch (op) {
            case 1:
               ordensdeservico(&os);
               break;
            case 2:
               equipamentos(&eq);
               break;
            case 3:
               clientes(&cli);
               break;
            case 4:
               clientes(&cli);
               break;
            case 5:
               printf("Encerrando o programa.\n");
               funcionarios(&fun);
               break;
            case 6:
               printf("Encerrando o programa.\n");
               break;
            default:
               printf("Opção inválida. Tente novamente.\n");
        }
   } while (op != 5);

   return 0;
}
