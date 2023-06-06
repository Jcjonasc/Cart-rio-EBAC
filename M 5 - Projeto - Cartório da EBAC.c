#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados 
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar arquivo no banco de dados
	fprintf(file," - "); //colocar - para dar espa�o
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazenar conte�do dentro vari�vel nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salvando conteudo dentro da vari�vel nome
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar - para dar espa�o
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //armazenar conte�do dentro vari�vel sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvando conteudo dentro da vari�vel sobrenome
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar - para dar espa�o
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //armazenar conte�do dentro vari�vel cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvando conteudo dentro da vari�vel cargo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar , para dar espa�o
	fclose(file);
	
	system("pause"); //Dizer ao sistema operacional para pausar o programa
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi Poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf [400];
	
	printf("Digite o CPF que queira cancelar\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)  //Valida��o caso n�o encontre o arquivo
	{
		printf("usu�rio n�o encontrado no sistema! \n");
		system("pause");
	}
	else
		printf("Usu�rio deletado com sucesso! \n\n");
		
	system("pause");
	
			
}



int main()
	{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//definindo linguagem
	
		printf("### Cart�tio da EBAC ###\n\n");//in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("op��o:");//Fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");//limpar tela
		
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
			
			default:
			printf("esta op��o n�o est� dispon�vel!\n");
			system ("pause");
			break;
		} //fim da sele��o
	
	}
}
