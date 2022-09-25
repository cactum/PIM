#include<stdio.h> // declaração da biblioteca padrão
#include<string.h> // declaração da biblioteca para manipulação de strings
#include<stdlib.h> 
#define tam 300 // definida a constante de tamanho da matriz
char nome[tam][50]; // matriz que vai armazenar nome
char email[tam][50]; // matriz que vai armazenar email
int cpf[tam]; // matriz que vai armazenar cpf
int op; // variavel global utilizada para armazenar as opções de escolha no programa

void cadastro(); // função de cadstro
void pesquisa(); // função de pesquisa
void lista();    // função de lista

 int main(void){ // aqui é criada a função principal do programa 
     do{
       system("cls");
       printf("\n----Menu----\n1 - Cadastrar\n2 - Pesquisar\n3 - Lista\n9 - Sair\n");
       scanf("%d", &op);
       switch (op){
        case 1:
           cadastro();
        break;
        case 2:
           pesquisa();
        break;
        case 3:
           lista();
        break;
        case 9:
           system("exit");
        break;
        default:
           printf("\nOpcao Invalida");
        break;   
        }
    }while(op !=9);
}
void cadastro(){ // execução da função cadastro
static int linha;// declaração de uma variavel static para manter o valor das variaveis linha 
do{ // inicio do loop 
printf("\nDigite o nome: "); // Imprime na tela a solicitação de cadastro do nome
scanf("%[^\n]s", &nome[linha]); // aloca os dados digitados no endereço nome
printf("\nDigite o email: "); // Imprime na tela a solicitação de cadastro do email
scanf("%s", &email[linha]); // aloca os dados digitados no endereço email
printf("\nDigite o CPF sem ponto: "); // Imprime na tela a solicitação de cadastro do cpf
scanf("%d", &cpf[linha]); //aloca os dados digitados no endereço cpf
printf("\nDigite 1 para continuar ou outro valor para sair: "); // da condição para escolher finalizar o loop ou cadastrar mais dados
scanf("%d", &op);// lê a opção digitada
linha++; // da continuidade a chamada para ser armazenada na proxima linha
}while(op ==1); // fim do loop
} // fim da declaração da função cadastro
void pesquisa(){ // desenvolvimento da função pesquisa
    int cpfpesq; // declaração de variavel de pesquisa por cpf
    char emailpesq[50]; // declara variavel de pesquisa de email
    int i; // variavel auxiliar
    do{ // inicio do loop
       printf("\nDigite 1 para buscar pelo CPF ou 2 para buscar por email: ");// imprime as opções de pesquisa
       scanf("%d", &op);// lê a opção digitada
       switch (op){ // função de condição de escolha
        case 1: 
         printf("\nDigite o CPF: ");
         scanf("%d", &cpfpesq); // lê os dados que deseja pesquisar
         for(i = 0; i < tam; i++){ // condição para variavel percorrer o codigo
            if (cpf[i] == cpfpesq){ // condição se o que estiver no vetor cpf linha i é igual  variavel cpfpesq 
                printf("\nNome: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]); // imprime os dados se compativeis com a pesquisa
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
void lista(){
    int i;
    for(i = 0; i<tam; i++){
        if(cpf[i]>0){
            printf("\nNome %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
        }else{
            break;
        }
    }
    getchar();
    getchar();
}
