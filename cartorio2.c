#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registrar(){      //função responsavel por cadastrar os usuários no sistema
    //inicio da criação da variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação da variaveis/string
	
	printf("\tCadastro\n\n"); //coletando informação do usuário
	
	printf("CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: %s", cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("NOME: ");
	scanf(" %[^\n]", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "NOME: %s", nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("SOBRENOME: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "SOBRENOME: %s", sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("CARGO: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "CARGO: %s", cargo);
	fclose(file);
	
	system("pause");
}

int consultar(){
	setlocale(LC_ALL, "portuguese_brazil"); //definindo linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Insira o CPF para a busca: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Não localizado!\n");
		system("pause");
	}
	
	system("cls");
	
	printf("Informações do usuário: \n\n");
	while(fgets(conteudo,200,file) !=NULL){
		printf("%s", conteudo);
	}
	system("pause");
	printf("\n\n");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Usuário não se encontra no momento!\n");
		system("pause");
	}
}

int main(){
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1; laco==1;){
	  system("cls");
	
	  setlocale(LC_ALL, "portuguese");
	
	  printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	  printf("Escolha a opção desejada no menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("Opção: "); //fim do menu
	
	  scanf("%d", &opcao); //armazenando informações e escolha do usuário
	
	  system("cls");  //responsavel por limpar a tela
	  
	  switch(opcao){  //inicio da seleção do menu
	  
	  	  case 1:
	  	  registrar();  //chamada de funções
	      break;
	    
	      case 2:
	      consultar();
		  break;
		
		  case 3:
		  deletar();
		  break;
	    
	      default:
	      printf("Essa opção não está disponivel!\n");
		  system("pause");
		  break;
		  //fim da seleção
       }   
	}	
}

