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
	
	printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("Sobrenome: ");
    scanf("%s", sobrenome);

    printf("Cargo: ");
    scanf("%s", cargo);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //abre o arquivo
	
	fprintf(file, "CPF: %s\n", cpf); //salva o valor da variavel
	fprintf(file, "Nome: %s\n", nome); //salva o valor da variavel
	fprintf(file, "Sobrenome: %s\n", sobrenome); //salva o valor da variavel
	fprintf(file, "Cargo: %s\n", cargo); //salva o valor da variavel
	
	fclose(file); //fecha o arquivo
	
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
		return 1;
	}
	
	system("cls");
	
	printf("Informações do usuário: \n\n");
	while(fgets(conteudo,200,file) !=NULL){
		printf("%s", conteudo);
	}
	fclose(file);
	
	system("pause");
	printf("\n\n");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	if (remove(cpf) == 0){
		printf("Usuário deletado com sucesso!\n");
	}
	
	else {
		printf("Usuário não encontrado!\n");
	}
	
	system("pause");
}

int main(){
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	char login[20]="a";
	char senha[20]="a";
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador\n\n");
	
	printf("Login: ");
	scanf("%s", login);
	
	printf("Senha: ");
	scanf("%s", senha);
	
	if(strcmp(login, "suki") == 0 && strcmp(senha, "admin") == 0){
		
		printf("Acesso liberado\n");
	
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
	
	else 
		printf("Login ou senha incorretos!");
}

