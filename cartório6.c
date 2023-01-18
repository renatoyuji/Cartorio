#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa write
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF não registrado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int excluir()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser excluído: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF não encontrado!\n");
		system("pause");
	}
}

int main()
{
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório ###\n\n"); //início do menu
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 - Registro\n");
		printf("\t2 - Consulta\n");
		printf("\t3 - Excluir\n\n");
		printf("Opção: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpa a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			default:
			printf("Essa opção não existe!\n");
			system("pause");
			break;
		} //fim da seleção
	
	
	}
}
