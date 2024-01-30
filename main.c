// Aluno: Gabriel Brito Ribeiro - 202305530

// Projeto de TAD para representação de Ordens de Serviços para clientes de uma empresa de manutenção.
// Os equipamentos, clientes, serviços e funcionários, bem como as próprias ordens de serviço são inseridas
// em listas sequenciais. Durante o cadastro de uma ordem de serviço é possível fazer o cadastro de novos elementos
// em cada uma das outras listas;

#include <stdio.h>
#include "ListaSequencial.h"

void ordensdeservico(Lista_os* os){

}

void equipamentos(Lista_eq* eq){

}

void clientes(Lista_cli* cli){
   
}

void servicos(Lista_ser* ser){

}

void funcionarios(Lista_fun* fun){

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
