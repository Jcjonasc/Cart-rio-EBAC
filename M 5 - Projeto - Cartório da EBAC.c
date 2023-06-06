#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados 
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar arquivo no banco de dados
	fprintf(file," - "); //colocar - para dar espaço
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazenar conteúdo dentro variável nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salvando conteudo dentro da variável nome
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar - para dar espaço
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //armazenar conteúdo dentro variável sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvando conteudo dentro da variável sobrenome
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar - para dar espaço
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //armazenar conteúdo dentro variável cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvando conteudo dentro da variável cargo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - "); //colocar , para dar espaço
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
		printf("Não foi Possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	if (file == NULL)  //Validação caso não encontre o arquivo
	{
		printf("usuário não encontrado no sistema! \n");
		system("pause");
	}
	else
		printf("Usuário deletado com sucesso! \n\n");
		
	system("pause");
	
			
}



int main()
	{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//definindo linguagem
	
		printf("### Cartótio da EBAC ###\n\n");//início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("opção:");//Fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
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
			printf("esta opção não está disponível!\n");
			system ("pause");
			break;
		} //fim da seleção
	
	}
}
