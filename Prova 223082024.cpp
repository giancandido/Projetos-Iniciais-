#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
int dia;
int mes;
int ano;
} Data;

typedef struct {
char nome[30];
char cpf[12]; //armazena apenas números (sem . e -)
char sexo[2]; //utilizar M para masculino e F para Feminino
Data nascimento;
} Pessoa;

Pessoa dados[100];
int posicao =0;
void inserir_dados() {
  if (posicao >= 100) {
    printf("Banco de dados cheio.\n");
    return;
  }
  printf("Digite o nome: ");
  scanf("%s", dados[posicao].nome);
  printf("Digite o cpf : ");
  scanf("%s", dados[posicao].cpf);
  printf("Digite o sexo: ");
  scanf("%1s", dados[posicao].sexo);
  printf("Digite a data de nascimento (dd/mm/aaaa): ");
  scanf("%d/%d/%d", &dados[posicao].nascimento.dia, &dados[posicao].nascimento.mes, &dados[posicao].nascimento.ano);
posicao++;
return;
}
void contar_Sexo() {
    int numFeminino = 0;
    int numMasculino = 0;

    for (int i = 0; i < posicao; i++) {
        if (strcmp(dados[i].sexo,"F" )) {
            (numFeminino)++;
        } else if (strcmp(dados[i].sexo,"M" )) {
            (numMasculino)++;
        }
    }
    printf("Numeros de homens: %d", numMasculino);
    printf("Numeros de mulheres: %d", numFeminino);

}

void buscar_dados() {
    char busca_cpf[12];
    
     printf("Digite o CPF desejado:\n");
     scanf("%12s", busca_cpf);
  for (int i = 0; i < posicao; i++) {
   
    if (strcmp(dados[i].cpf, busca_cpf) == 0) {
      printf("Nome: %s\n", dados[i].nome);
      printf("CPF: %s\n", dados[i].cpf);
      printf("Sexo: R$ %s\n", dados[i].sexo);
      printf("Data de nascimento: %d/%d/%d\n", dados[i].nascimento.dia,
             dados[i].nascimento.mes, dados[i].nascimento.ano);
      return;
    }
  }
  printf("CPF não encontrado\n");
}
Data data_busca;
void buscar_data(Data data_busca) {
printf("Digita a data desejada:(dd/mm/aa)\n");
scanf("%d/%d/%d", &data_busca.dia, &data_busca.mes, &data_busca.ano);
bool verific = false;
for (int i = 0; i < posicao; i++){
      if (dados[i].nascimento.ano* 365 + dados[i].nascimento.mes * 30 + dados[i].nascimento.dia ==
      data_busca.ano * 365 + data_busca.mes * 30 + data_busca.dia)
       {
       printf("Nome: %s\n", dados[i].nome);
       verific = true; 
   }
  }
  if (verific == false){
    printf("data não encontrada");
  } 
}

void intervalo_data(Data data_antiga, Data data_recente) { 
int qtdd = 0;
for (int i = 0; i < posicao; i++){
      if ((data_antiga.ano* 365 + data_antiga.mes * 30 + data_antiga.dia)<=(dados[i].nascimento.ano* 365 + dados[i].nascimento.mes * 30 + dados[i].nascimento.dia) && (dados[i].nascimento.ano* 365 + dados[i].nascimento.mes * 30 + dados[i].nascimento.dia)<= (data_recente.ano* 365 + data_recente.mes * 30 + data_recente.dia))
       {
       qtdd++;
       
   }
  }

     printf("Quantidade de nascimentos entre as datas: %d\n", qtdd);


 
}
int menu() {
  int opc;
  printf("\n\n======= MENU =======\n");
  printf("1 - Inserir dados\n");
  printf("2 - Distribuicao do sexo\n");
  printf("3 - Buscar dados\n");
  printf("4 - Verificar intervalo de data\n");
  printf("0 - Sair\n");
  printf("\nDigite a opção: ");
  scanf ("%d", &opc);
  return opc;
}
int main(){
 int opc = -1;
 Data data_antiga, data_recente;
while (opc != 0) {
    opc = menu();
    switch (opc) {
      case 1:
        inserir_dados();
        break;

      case 2:
      contar_Sexo();

        break;

      case 3:
        buscar_dados();
        break;

      case 4:
        printf("Digite a prinmeira data (mais antiga): ");
  scanf("%d/%d/%d", &data_antiga.dia, &data_antiga.mes, &data_antiga.ano);
  printf("Digite a prinmeira data (mais recente): ");
  scanf("%d/%d/%d", &data_recente.dia, &data_recente.mes, &data_recente.ano);
  intervalo_data(data_antiga, data_recente);
        break;

      case 0:
        printf("Até mais!!\n");
        break;

      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}
