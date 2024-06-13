#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio criação de variáveis/sring
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a salvar uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os arquivos das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre um arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //
	
	file = fopen(arquivo, "a");//abre um arquivo
	fprintf(file,nome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre um arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abre um arquivo
	fprintf(file,sobrenome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre um arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//abre um arquivo
	fprintf(file,cargo);
	fclose(file);//fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //definindo variáveis
	int laco=1;
			
	for(laco=1;laco=1;)
	{
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		system("cls");
		
		printf("### cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
	
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
