#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tam 300 
char nome[tam][50];
char email[tam][50];
int cpf[tam];
int op;

void cadastro();
void pesquisa();

 int main(void){
    cadastro();
    pesquisa();
}
void cadastro(){
static int linha;
do{
printf("\nDigite o nome: ");
scanf("%[^\n]s", &nome[linha]);
printf("\nDigite o email: ");
scanf("%s", &email[linha]);
printf("\nDigite o CPF sem ponto: ");
scanf("%d", &cpf[linha]);
printf("\nDigite 1 para continuar ou outro valor para sair: ");
scanf("%d", &op);
linha++;
}while(op ==1);
} // fim da função de cadastro

void pesquisa(){
    int cpfpesq;
    char emailpesq[50];
    int i;
    do{
       printf("\nDigite 1 para buscar pelo CPF ou 2 para buscar por email: ");
       scanf("%d", &op);
       switch (op){
        case 1:
         printf("\nDigite o CPF: ");
         scanf("%d", &cpfpesq);
         for(i = 0; i < tam; i++){
            if (cpf[i] == cpfpesq){
                printf("\nNome: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
            }
         }
         break;
        case 2:
        printf("\nDigite o email: ");
            scanf("%s", &emailpesq);
            for(i = 0; i < tam; i++){
            if (strcmp(email[i], emailpesq)==0){
                printf("\nNome: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
            }
         }
         break;
         default:
         printf("\nOpcao Invalida");
          break;
       }
       printf("\nDigite 1 para continuar pesquisando ou outro numero para sair: ");
        scanf("%d", &op); 

    }while(op == 1);
}