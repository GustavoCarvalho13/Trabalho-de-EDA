#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "meio.h"

int menu()
{
	int op;
	printf("M E N U\n");
	printf("1 Entrar como utilizador\n");
	printf("2 Entrar como gestor\n");
	printf("3 Ler meios\n");
	printf("4 Listar meios\n");
	printf("0 Sair\n");
	printf("Opcao:\n");
	scanf("%d", &op);
	return(op);
}

int menuUsers() {
	int opU;
	printf("M E N U\n");
	printf("1 Log in\n");
	printf("2 Alugar um meio de mobilidade\n");
	printf("0 Sair\n");
	printf("Opcao:\n");
	scanf("%d", &opU);
	return(opU);
}

int menuGestor() {
	int opG;
	int pass;
	printf("M E N U\n");
	printf("1 Adicionar utilizador\n");
	printf("2 Remover utilizador\n");
	printf("3 Adicionar meio de mobilidade\n");
	printf("4 Remover meio de mobilidade\n");
	printf("5 Guardar Meios\n");
	printf("6 Ler Meios\n");
	printf("7 Listar meios\n");
	printf("8 Listar utilizadores\n");
	printf("9 Inserir gestor\n");
	printf("10 Listar gestores\n");
	printf("11 Remover gestor\n");
	printf("Opcao:\n");
	scanf("%d", &opG);
	return(opG);
	}

int main()
{
	Meio* meios = NULL; // Lista ligada vazia 
	int op, opU, opG, cod;
	float bat, aut;
	char tipo[50];

	Meio* listaMeios = NULL;
	User* listaUsers = NULL;
	int opcao;

	User* users = NULL;
	int id, nif;
	float saldo;
	char nome[50], morada[50];

	Gestor* gestor = NULL;
	int idG;
	char nomeG[50], moradaG[50];

	listaMeios = lerMeios(); // Lê a lista de meios de um ficheiro
	listaUsers = lerUsers(); // Lê a lista de utilizadores de um ficheiro
	do
	{
		op = menu();
		switch (op)
		{
			case 1:
				do
				{
					opU = menuUsers();
					switch (opU)
					{
					case 1:
						printf("Id?\n");
						scanf("%d", &id);
						printf("Nome\n");
						scanf(" %[^\n]s", nome);
						printf("Morada\n");
						scanf(" %[^\n]s", morada);
						printf("NIF?\n");
						scanf("%d", &nif);
						printf("Saldo?\n");
						scanf("%f", &saldo);
						users = inserirUtilizadores(users, id, nif, saldo, nome, morada);
						break;
					case 2:
						listarMeios(meios);
						printf("Qaul o meio que quer alugar\n");
						scanf("%d", &cod);
						meios = removerMeio(meios, cod);
						break;

					} 
				} while (opU != 0);
				break;
			case 2:
				do
				{
					opG = menuGestor();
					switch (opG)
					{
					case 1:
						printf("Id?\n");
						scanf("%d", &id);
						printf("Nome\n");
						scanf(" %[^\n]s", nome);
						printf("Morada\n");
						scanf(" %[^\n]s", morada);
						printf("NIF?\n");
						scanf("%d", &nif);
						printf("Saldo?\n");
						scanf("%f", &saldo);
						users = inserirUtilizadores(users, id, nif, saldo, nome, morada);
						break;
					case 2:
						printf("Id do utilizador que quer remover\n");
						scanf("%d", &id);
						users = removerUtilizador(users, id);
						break;
					case 3:
						printf("Codigo?\n");
						scanf("%d", &cod);
						scanf("%*c");
						printf("Tipo\n");
						scanf("%[^\n]s", tipo);
						printf("Nivel da bateria?\n");
						scanf("%f", &bat);
						printf("Autonomia\n");
						scanf("%f", &aut);
						meios = inserirMeio(meios, cod, tipo, bat, aut);
						break;
					case 4:
						printf("Codigo do meio de mobilidade a remover?\n");
						scanf("%d", &cod);
						meios = removerMeio(meios, cod);
						break;
					case 5: guardarMeios(meios); break;
					case 6: meios = lerMeios(); break;
					case 7:listarMeios(meios); break;
					case 8:listarUtilizadores(users); break;
					case 9:
						printf("Id?\n");
						scanf("%d", &idG);
						printf("Nome\n");
						scanf(" %[^\n]s", nomeG);
						printf("Morada\n");
						scanf(" %[^\n]s", moradaG);
						gestor = inserirGestor(gestor, idG, nomeG, moradaG);
						break;
					case 10:listarGestores(gestor, idG, nomeG, moradaG); break;
					case 11:
						printf("Id do gestor que quer remover\n");
						scanf("%d", &idG);
						gestor = removerGestor(gestor, idG);
						break;
					}
				} while (opG != 0);
			case 3:meios = lerMeios(); break;
			case 4:listarMeios(meios); break;
		}
	} while (op != 0);
}
