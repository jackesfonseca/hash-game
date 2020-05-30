/**HASH GAME
* Versão simplificado do hash game
* Por Jackes Tiago Ferreira da Fonseca
* Versão 05.09.20
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 3

typedef struct Posicao
{
	char c[TAM][TAM];	
}Posicao;

Posicao posicao;

int validaPosicao(int res, Posicao posicao);//Verifica se a casa já está preenchida
int verificaVitoriaUm(Posicao posicao);//verifica a vitória do jogador um
int verificaVitoriaDois(Posicao posicao);//verifica a vitória do jogador dois

int main()
{
	setlocale(LC_ALL, "Portuguese, Brazil");
	system("color F0");
	
	//tela inicial
	printf("\n");
	printf("==================================================================\n");
	printf("|                  **********HASH GAME**********                 |\n");
	printf("|                                                                |\n");
	printf("|INSTRUÇÕES:                                                     |\n");
	printf("|                                                                |\n");
	printf("|* Para dois jogadores (X/O)                                     |\n");
	printf("|* O jogador um (X) sempre inicia a partida                      |\n");
	printf("|* Informe um número de 1 à 9 para posicionar a figura na casa   |\n");
	printf("|                                                                |\n");
	printf("|              pressione <enter> para iniciar o jogo             |\n");
	printf("|                                                                |\n");
	printf("==================================================================\n");
	printf("\n");
	getchar();
		
	int res, i, j;
	char again;
	
	for(i=0; i<sizeof(res)/sizeof(char); i++)
	{
		for(j=0; j<sizeof(res)/sizeof(char); j++)
		{
			posicao.c[i][j] = '\0';
		}
	}
	
	//jogada 1
	system("cls");
	printf("\n");
	
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}		
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'X';break;
		case 2: posicao.c[0][1] = 'X';break;
		case 3: posicao.c[0][2] = 'X';break;
		case 4: posicao.c[1][0] = 'X';break;
		case 5: posicao.c[1][1] = 'X';break;
		case 6: posicao.c[1][2] = 'X';break;
		case 7: posicao.c[2][0] = 'X';break;
		case 8: posicao.c[2][1] = 'X';break;
		case 9: posicao.c[2][2] = 'X';break;
	}
	
	//jogada 2
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaUm(posicao) == 1)
	{
		printf("\nJogador um vence!\n\n");
		system("pause");
		return 0;
	}
	
	printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}		
	}	
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'O';break;
		case 2: posicao.c[0][1] = 'O';break;
		case 3: posicao.c[0][2] = 'O';break;
		case 4: posicao.c[1][0] = 'O';break;
		case 5: posicao.c[1][1] = 'O';break;
		case 6: posicao.c[1][2] = 'O';break;
		case 7: posicao.c[2][0] = 'O';break;
		case 8: posicao.c[2][1] = 'O';break;
		case 9: posicao.c[2][2] = 'O';break;
	}
	
	//jogada 3
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaDois(posicao) == 1)
	{
		printf("\nJogador dois vence!\n\n");
		system("pause");
		return 0;
	}
	
	printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);		
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}
		
	}

	switch(res)
	{
		case 1: posicao.c[0][0] = 'X';break;
		case 2: posicao.c[0][1] = 'X';break;
		case 3: posicao.c[0][2] = 'X';break;
		case 4: posicao.c[1][0] = 'X';break;
		case 5: posicao.c[1][1] = 'X';break;
		case 6: posicao.c[1][2] = 'X';break;
		case 7: posicao.c[2][0] = 'X';break;
		case 8: posicao.c[2][1] = 'X';break;
		case 9: posicao.c[2][2] = 'X';break;
	}
	
	//jogada 4
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaUm(posicao) == 1)
	{
		printf("\nJogador um vence!\n\n");
		system("pause");
		return 0;
	}
	
	printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}			
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'O';break;
		case 2: posicao.c[0][1] = 'O';break;
		case 3: posicao.c[0][2] = 'O';break;
		case 4: posicao.c[1][0] = 'O';break;
		case 5: posicao.c[1][1] = 'O';break;
		case 6: posicao.c[1][2] = 'O';break;
		case 7: posicao.c[2][0] = 'O';break;
		case 8: posicao.c[2][1] = 'O';break;
		case 9: posicao.c[2][2] = 'O';break;
	}
	
	//jogada 5
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaDois(posicao) == 1)
	{
		printf("\nJogador dois vence!\n\n");
		system("pause");
		return 0;
	}
	
	printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}		
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'X';break;
		case 2: posicao.c[0][1] = 'X';break;
		case 3: posicao.c[0][2] = 'X';break;
		case 4: posicao.c[1][0] = 'X';break;
		case 5: posicao.c[1][1] = 'X';break;
		case 6: posicao.c[1][2] = 'X';break;
		case 7: posicao.c[2][0] = 'X';break;
		case 8: posicao.c[2][1] = 'X';break;
		case 9: posicao.c[2][2] = 'X';break;
	}
	
	//jogada 6
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaUm(posicao) == 1)
	{
		printf("\nJogador um vence!\n\n");
		getchar();//limpar o buffer do \n
		printf("Deseja continuar S/N: ");
		scanf("%c", &again);
		
		again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
		if(again == 'S')
		{
			system("cls");
			getchar();//limpar o buffer do \n
			main();
		}
		return 0;
	}
	
	printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);		
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}	
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'O';break;
		case 2: posicao.c[0][1] = 'O';break;
		case 3: posicao.c[0][2] = 'O';break;
		case 4: posicao.c[1][0] = 'O';break;
		case 5: posicao.c[1][1] = 'O';break;
		case 6: posicao.c[1][2] = 'O';break;
		case 7: posicao.c[2][0] = 'O';break;
		case 8: posicao.c[2][1] = 'O';break;
		case 9: posicao.c[2][2] = 'O';break;
	}
	
	//jogada 7
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaDois(posicao) == 1)
	{
		printf("\nJogador dois vence!\n\n");
		getchar();//limpar o buffer do \n
		printf("Deseja continuar S/N: ");
		scanf("%c", &again);
		
		again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
		if(again == 'S')
		{
			system("cls");
			getchar();//limpar o buffer do \n
			main();
		}
		return 0;
	}
	
	printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}		
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'X';break;
		case 2: posicao.c[0][1] = 'X';break;
		case 3: posicao.c[0][2] = 'X';break;
		case 4: posicao.c[1][0] = 'X';break;
		case 5: posicao.c[1][1] = 'X';break;
		case 6: posicao.c[1][2] = 'X';break;
		case 7: posicao.c[2][0] = 'X';break;
		case 8: posicao.c[2][1] = 'X';break;
		case 9: posicao.c[2][2] = 'X';break;
	}
	
	//jogada 8
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaUm(posicao) == 1)
	{
		printf("\nJogador um vence!\n\n");
		getchar();//limpar o buffer do \n
		printf("Deseja continuar S/N: ");
		scanf("%c", &again);
		
		again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
		if(again == 'S')
		{
			system("cls");
			getchar();//limpar o buffer do \n
			main();
		}
		return 0;
	}
	
	printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador dois (O) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}		
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'O';break;
		case 2: posicao.c[0][1] = 'O';break;
		case 3: posicao.c[0][2] = 'O';break;
		case 4: posicao.c[1][0] = 'O';break;
		case 5: posicao.c[1][1] = 'O';break;
		case 6: posicao.c[1][2] = 'O';break;
		case 7: posicao.c[2][0] = 'O';break;
		case 8: posicao.c[2][1] = 'O';break;
		case 9: posicao.c[2][2] = 'O';break;
	}

	//jogada 9
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaDois(posicao) == 1)
	{
		printf("\nJogador dois vence!\n\n");
		getchar();//limpar o buffer do \n
		printf("Deseja continuar S/N: ");
		scanf("%c", &again);
		
		again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
		if(again == 'S')
		{
			system("cls");
			getchar();//limpar o buffer do \n
			main();
		}
		return 0;
	}	
	
	printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
	scanf("%d", &res);
	
	if(validaPosicao(res, posicao) == 0)
	{
		printf("\nJogada inválida!\n");
		printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
		scanf("%d", &res);
		
		while(validaPosicao(res, posicao) == 0)
		{
			printf("\nJogada inválida!\n");
			printf("\nJogador um (X) escolha uma posição de 1 à 9: ");
			scanf("%d", &res);	
		}			
	}
	
	switch(res)
	{
		case 1: posicao.c[0][0] = 'X';break;
		case 2: posicao.c[0][1] = 'X';break;
		case 3: posicao.c[0][2] = 'X';break;
		case 4: posicao.c[1][0] = 'X';break;
		case 5: posicao.c[1][1] = 'X';break;
		case 6: posicao.c[1][2] = 'X';break;
		case 7: posicao.c[2][0] = 'X';break;
		case 8: posicao.c[2][1] = 'X';break;
		case 9: posicao.c[2][2] = 'X';break;
	}
	
	system("cls");
	
	printf("\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[0][0], posicao.c[0][1], posicao.c[0][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[1][0], posicao.c[1][1], posicao.c[1][2]);
	printf("\t\t\t__________________\n");
	printf("\t\t\t  %c  |  %c  |  %c  \n", posicao.c[2][0], posicao.c[2][1], posicao.c[2][2]);
	
	if(verificaVitoriaUm(posicao) == 1)
	{
		printf("\nJogador um vence!\n\n");
		getchar();//limpar o buffer do \n
		printf("Deseja continuar S/N: ");
		scanf("%c", &again);
		
		again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
		if(again == 'S')
		{
			system("cls");
			getchar();//limpar o buffer do \n
			main();
		}
		return 0;
	}

	printf("\nDeu velha!\n\n");
	
	getchar();//limpar o buffer do \n
	printf("Deseja continuar S/N: ");
	scanf("%c", &again);
		
	again = toupper(again);//transformar carcatere em maiúsculo utilizando a biblioteca ctype
		
	if(again == 'S')
	{
		system("cls");
		getchar();//limpar o buffer do \n
		main();
	}
	return 0;
}

//validar posicao
int validaPosicao(int res, Posicao posicao)
{
	switch(res)
	{
		case 1: 
			if(posicao.c[0][0] != '\0')
				return 0; //false
			else
				return 1; //true
		case 2: 
			if(posicao.c[0][1] != '\0')
				return 0; //false
			else
				return 1; //true
		case 3:
			if(posicao.c[0][2] != '\0')
				return 0; //false
			else
				return 1; //true
		case 4:
			if(posicao.c[1][0] != '\0')
				return 0; //false
			else
				return 1; //true
		case 5:
			if(posicao.c[1][1] != '\0')
				return 0; //false
			else
				return 1; //true
		case 6:
			if(posicao.c[1][2] != '\0')
				return 0; //false
			else
				return 1; //true
		case 7:
			if(posicao.c[2][0] != '\0')
				return 0; //false
			else
				return 1; //true
		case 8:
			if(posicao.c[2][1] != '\0')
				return 0; //false
			else
				return 1; //true
		case 9:
			if(posicao.c[2][2] != '\0')
				return 0; //false
			else
				return 1; //true
		default:
			return 0;//false
	}	
}

int verificaVitoriaUm(Posicao posicao)
{
	if((posicao.c[0][0] == 'X' && posicao.c[1][1] == 'X' && posicao.c[2][2] == 'X') || 
	(posicao.c[0][0] == 'X' && posicao.c[0][1] == 'X' && posicao.c[0][2] == 'X') ||
	(posicao.c[1][0] == 'X' && posicao.c[1][1] == 'X' && posicao.c[1][2] == 'X') ||
	(posicao.c[2][0] == 'X' && posicao.c[2][1] == 'X' && posicao.c[2][2] == 'X') ||
	(posicao.c[0][0] == 'X' && posicao.c[1][0] == 'X' && posicao.c[2][0] == 'X') ||
	(posicao.c[0][1] == 'X' && posicao.c[1][1] == 'X' && posicao.c[2][1] == 'X') ||
	(posicao.c[0][2] == 'X' && posicao.c[1][2] == 'X' && posicao.c[2][2] == 'X') ||
	(posicao.c[2][0] == 'X' && posicao.c[1][1] == 'X' && posicao.c[0][2] == 'X'))
	{
		return 1;//true	
	}
	
	return 0;//false
}

int verificaVitoriaDois(Posicao posicao)
{
	if((posicao.c[0][0] == 'O' && posicao.c[1][1] == 'O' && posicao.c[2][2] == 'O') || 
	(posicao.c[0][0] == 'O' && posicao.c[0][1] == 'O' && posicao.c[0][2] == 'O') ||
	(posicao.c[1][0] == 'O' && posicao.c[1][1] == 'O' && posicao.c[1][2] == 'O') ||
	(posicao.c[2][0] == 'O' && posicao.c[2][1] == 'O' && posicao.c[2][2] == 'O') ||
	(posicao.c[0][0] == 'O' && posicao.c[1][0] == 'O' && posicao.c[2][0] == 'O') ||
	(posicao.c[0][1] == 'O' && posicao.c[1][1] == 'O' && posicao.c[2][1] == 'O') ||
	(posicao.c[0][2] == 'O' && posicao.c[1][2] == 'O' && posicao.c[2][2] == 'O') ||
	(posicao.c[2][0] == 'O' && posicao.c[1][1] == 'O' && posicao.c[0][2] == 'O'))
	{
		return 1;//true	
	}
	
	return 0;//false
}
