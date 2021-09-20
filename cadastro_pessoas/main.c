#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[30];
  char nascimento[10];
  int gastos;
} pessoa;

pessoa cadastro[10];

unsigned int TAMANHO_CADASTRO = 10;
unsigned int PESSOAS_CADASTRADAS = 0;

int menu()
{
  int opcao = 0;
  while (opcao == 0)
  {
    printf("\n ***SISTEMA DE CADASTRO DE CLIENTES DA ORYANGE***");
    printf("\n |----------------------------------------------|");
    printf("\n |             ***MENU DE OPÇÕES***             |");
    printf("\n |----------------------------------------------|");
    printf("\n | 1 - Incluir novo cliente                     |");
    printf("\n | 2 - Remover cliente                          |");
    printf("\n | 3 - Zerar montantes - virada de mês          |");
    printf("\n | 4 - Listar o melhor cliente comprador        |");
    printf("\n | 5 - Exibir cliente específico                |");
    printf("\n | 6 - Sair                                     |");
    printf("\n \n | INFORME A SUA OPÇÃO: ");
    scanf("%d", &opcao);
  }
  if (opcao > 6 || opcao < 0)
  {
    printf("Opção %d, inválida!", opcao);
    opcao = 0;
  }
  return opcao;
}

void salvarCadastro()
{
  FILE *arquivo;
  arquivo = fopen("CADASTRO.txt", "w+");

  for (int i = 0; i < PESSOAS_CADASTRADAS; i++)
  {
    fprintf(arquivo, "\n Nome completo: %s", cadastro[i].nome);
    fprintf(arquivo, "\n Nascimento: %s", cadastro[i].nascimento);
    fprintf(arquivo, "\n Gastos mês: %d", cadastro[i].gastos);
  }
  fclose(arquivo);
}

void aumentaCadastro()
{
  printf("\n Tamanho máximo de cadastro atingido!");
  printf("\n | Digite  1 para aumentar o limite  |");
  printf("\n | Digite  0 para retornar ao menu   | \n");
  int number;
  scanf("%d", &number);
  if(number == 1)
  {
    int limit;
    printf("\n O limite pode ser aumentado de 10 em 10. \n Digite quantas vezes de 10 você deseja ampliar o cadastro: ");
    scanf("%d", &limit);
    TAMANHO_CADASTRO = limit * 10;
    printf("Cadastro aumentado com sucesso, o novo tamanho é: %d", TAMANHO_CADASTRO);

  } else {
    menu();
  }
}

void cadastrarPessoa()
{
  if (TAMANHO_CADASTRO > PESSOAS_CADASTRADAS)
  {
    puts("\n Informe o nome completo: ");
    scanf("%30s", cadastro[PESSOAS_CADASTRADAS].nome);
    printf("\n Nome completo: %s", cadastro[PESSOAS_CADASTRADAS].nome);

    puts("\n Informe a Data de Nascimento: ");
    scanf("%10s", cadastro[PESSOAS_CADASTRADAS].nascimento);
    printf("\n Nascimento: %s", cadastro[PESSOAS_CADASTRADAS].nascimento);

    puts("\n Informe o montante gasto no mês: ");
    scanf("%d", &cadastro[PESSOAS_CADASTRADAS].gastos);
    printf("\n Gastos do mês: %d", cadastro[PESSOAS_CADASTRADAS].gastos);

    PESSOAS_CADASTRADAS++;
    salvarCadastro();
    printf("\n Cadastro realizado com sucesso!");
  }
  else
  {
    aumentaCadastro();
  }
}

void removeCadastro()
{
  printf("\n Insira o nome do cliente que deseja remover: ");
  int opcao;
  char nomeCadastrado[30];
  scanf("%19s", nomeCadastrado);
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (strcmp(cadastro[i].nome, nomeCadastrado) == 0)
    {
      printf("\n O cadastro a ser removido é de: %s", cadastro[i].nome);
      printf("\n Digite 1 para continuar e 0 para retornar ao menu");
      scanf("%d", &opcao);
      if (opcao == 1)
      {
        memset(cadastro[i].nome, ' ', 30);
        memset(cadastro[i].nascimento, ' ', 10);
        cadastro[i].gastos = 0;
        PESSOAS_CADASTRADAS = PESSOAS_CADASTRADAS - 1;
      }
      else
      {
        menu();
      }
    }
  }
}

void zerarMontantes()
{
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    cadastro[i].gastos = 0;
  }
}

void melhorCliente()
{
  int montante = 0;
  char *cliente[30]; 
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (cadastro[i].gastos > montante)
    {
      montante = cadastro[i].gastos;
      *cliente = cadastro[i].nome;
    }
  }
  printf("\n Melhor cliente: %s que gastou: %d", *cliente, montante);  
}


void pesquisarCliente()
{
  printf("\n Insira o nome do cliente que deseja pesquisar: ");
  char nomeCadastrado[30];
  scanf("%19s", nomeCadastrado);
  for (int i = 0; i < TAMANHO_CADASTRO; i++)
  {
    if (strcmp(cadastro[i].nome, nomeCadastrado) == 0)
    {
      printf("***Informações do Cliente Pesquisado***");
      printf("\n Nome completo: %s", cadastro[i].nome);
      printf("\n Nascimento: %s", cadastro[i].nascimento);
      printf("\n Gastos mês: %d", cadastro[i].gastos);      
    }
    else
    {
      printf("\n Cliente não encontrado! :( \n Escolha uma nova opção no menu: ");
    }
  }
}

int main(int argc, char **argv)
{
  int opcao = 0;
  do
  {
    opcao = menu();
    switch (opcao)
    {
    case 1:
      cadastrarPessoa();
      break;
    case 2:
      removeCadastro();
      break;
    case 3:
      zerarMontantes();
      break;
    case 4:
      melhorCliente();
      break;
    case 5:
      pesquisarCliente();
      break;
    default:
      break;
    }
  } while (opcao != 6);
  printf("\n Agradecemos por utilizar nosso sistema!\n Aperte 0 para encerrar o programa. :)");
  
  return 0;
}
