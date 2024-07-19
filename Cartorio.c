#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF: \n");
	scanf("%s", cpf); //"%s" ler uma string 
	
	strcpy(arquivo, cpf);//copiar valor das strings
	
	FILE *file;
	file = fopen(arquivo, "w"); //"w" escrever no arquivo
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" atualizar no arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome: \n");
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome: \n");
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: \n");
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char resultado[200];
	
	printf("Digite o CPF a ser consultado \n");
	scanf("%s", cpf); 
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" ler o arquivo
	
	if(file==NULL)
	{
		printf("CPF não localiado! \n");
		system("pause");
	}
	while(fgets(resultado, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", resultado);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Insira o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf); 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("CPF não localiado! \n");
		system("pause");
	}
}

int main()
{
	int opcao = 0;
	int x = 1;
	
	for(x = 1; x=1; )
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório EBAC \n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1- Registrar Nomes\n");
		printf("\t2- Consultar Nomes\n");
		printf("\t3- Deletar Nomes\n\n");
		printf("\t4- Sair do sistema\n\n");
		printf("\tOpção: ");
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário //"%d" ler um int
		system("cls"); //Limpando a tela
		
		switch(opcao)
		{
			case 1: 
			registro();
			break;
			case 2: 
			consulta();
			break;
			case 3: 
			deletar();
			break;
			case 4: 
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			default:
			printf("Selecione uma opção válida \n");
			system("pause");
			break;
		}
	}
	
	
}

