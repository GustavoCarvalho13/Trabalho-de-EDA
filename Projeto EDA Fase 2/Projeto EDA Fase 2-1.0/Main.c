#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int menu()
{
	int op;
	printf("========== MENU ==========\n");
	printf("1-Entrar como utilizador\n");
	printf("2-Entrar como gestor\n");
	printf("3-Ler meios\n");
	printf("4-Listar meios\n");
	printf("0-Sair\n");
	printf("Opcao:\n");
	scanf("%d", &op);
	return(op);
}

int menuUsers() {
	int opU;
	printf("========== MENU ==========\n");
	printf("1-Log in\n");
	printf("2-Alugar um meio de mobilidade\n");
	printf("0-Retroceder\n");
	printf("Opcao:\n");
	scanf("%d", &opU);
	return(opU);
}

int menuGestor() {
	int opG;
	int pass;
	printf("========== MENU ==========\n");
	printf("1-Adicionar utilizador\n");
	printf("2-Remover utilizador\n");
	printf("3-Alterar utilizador\n");
	printf("4-Adicionar meio de mobilidade\n");
	printf("5-Remover meio de mobilidade\n");
	printf("6-Alterar um meio de mobilidade\n");
	printf("7-Guardar Meios\n");
	printf("8-Ler Meios\n");
	printf("9-Listar meios\n");
	printf("10-Listar utilizadores\n");
	printf("11-Inserir gestor\n");
	printf("12-Listar gestores\n");
	printf("13-Remover gestor\n");
	printf("14-Alterar Gestor\n");
	printf("15-Listar meios por ordem de autunomia\n");
	printf("16-Encontrar os meios de mobilidade mais proximos\n");
	printf("17-Encontrtar o caminho mais rapido\n");
	printf("0-Retroceder");
	printf("Opcao:\n");
	scanf("%d", &opG);
	return(opG);
}

int main()
{
	Meio* meios = NULL; // Lista ligada vazia 
	int op, opU, opG, cod, i, pos;
	float bat, aut, cust;
	char tipo[50], loc[50];

	Meio* listaMeios = NULL; // Poe a lista de meios do ficheiro como null
	User* listaUsers = NULL;
	int opcao;

	User* users = NULL; //Criar a lista ligada e apontar para null
	int id, nif, opcaoU;
	float saldo;
	char nome[50], morada[50];

	Gestor* gestor = NULL; // criar a lista ligada e apontar para null
	int idG;
	char nomeG[50], moradaG[50];

	Grafo g = NULL;

	criarVertice(&g, "BUS");
	criarVertice(&g, "EST");
	criarVertice(&g, "ESD");
	criarVertice(&g, "ESG");
	criarVertice(&g, "Estacionamento.EST");
	criarVertice(&g, "Estacionamento.ESG");
	criarVertice(&g, "Estacionamento.ESD");
	criarVertice(&g, "Cantina");

	criarAresta(g, "BUS", "Estacionamento.EST", 150);
	criarAresta(g, "BUS", "EST", 75);
	criarAresta(g, "BUS", "ESD", 100);
	criarAresta(g, "Estacionamento.EST", "EST", 100);
	criarAresta(g, "EST", "ESD", 50);
	criarAresta(g, "ESD", "Estacionamento.ESD", 50);
	criarAresta(g, "EST", "ESG", 50);
	criarAresta(g, "ESG", "Estacionamento.ESG", 100);
	criarAresta(g, "ESG", "Cantina", 100);
	criarAresta(g, "Cantina", "Estacionamento.ESG", 150);

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
					users = inserirUtilizadores(users, id, nif, saldo, nome, morada); //passa a lista e o utilizador novo e retorna a lista com o utilizador adicionado
					break;
				case 2:
					listarMeios(meios); // lista os meios disponiveis
					printf("Qaul o meio que quer alugar\n");
					scanf("%d", &cod);
					if (saldo < cust) {
						printf("Saldo insuficiente!");
					}
					else
					{
						meios = removerMeio(meios, cod);
					}
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
					printf("\nInsira o ID do utilizador que deseja alterar: ");
					scanf("%d", &id);

					printf("\nInsira o novo NIF do utilizador: ");
					scanf("%d", &nif);

					printf("\nInsira o novo saldo do utilizador: ");
					scanf("%f", &saldo);

					printf("\nInsira o novo nome do utilizador: ");
					scanf("%s", nome);

					printf("\nInsira a nova morada do utilizador: ");
					scanf("%s", morada);

					users = alterarUtilizador(users, id, nif, saldo, nome, morada);
					break;
				case 4:
					printf("Codigo?\n");
					scanf("%d", &cod);
					scanf("%*c");
					printf("Tipo\n");
					scanf("%[^\n]s", tipo);
					printf("Nivel da bateria?\n");
					scanf("%f", &bat);
					printf("Autonomia\n");
					scanf("%f", &aut);
					printf("Custo do meio?\n");
					scanf("%f", &cust);
					printf("Localizacao do meio:");
					scanf("%s", &loc);

					meios = inserirMeio(meios, cod, tipo, bat, aut, cust, loc);
					break;
				case 5:
					printf("Codigo do meio de mobilidade a remover?\n");
					scanf("%d", &cod);
					meios = removerMeio(meios, cod);
					break;
				case 6:
					printf("\nPosicao do meio de transporte a ser alterado: ");
					scanf("%d", &pos);
					printf("Novo codigo do meio de transporte: ");
					scanf("%d", &cod);
					printf("Novo tipo de meio de transporte: ");
					scanf("%s", tipo);
					printf("Nova bateria: ");
					scanf("%f", &bat);
					printf("Nova autonomia: ");
					scanf("%f", &aut);
					printf("Novo custo do meio?\n");
					scanf("%f", &cust);		
					printf("Nova localizacao");
					scanf("%s", &loc);
					
					meios = alterarMeio(meios, pos, cod, tipo, bat, aut, cust, g);
					break;
					break;
				case 7: guardarMeios(meios); break; // guardar meios no ficheiro
				case 8: meios = lerMeios(); break; // ler meios do ficheiro 
				case 9:listarMeios(meios); break;
				case 10:listarUtilizadores(users); break;
				case 11:
					printf("Id?\n");
					scanf("%d", &idG);
					printf("Nome\n");
					scanf(" %[^\n]s", nomeG);
					printf("Morada\n");
					scanf(" %[^\n]s", moradaG);
					gestor = inserirGestor(gestor, idG, nomeG, moradaG);
					break;
				case 12:listarGestores(gestor, idG, nomeG, moradaG); break;
				case 13:
					printf("Id do gestor que quer remover\n");
					scanf("%d", &idG);
					gestor = removerGestor(gestor, idG);
					break;
				case 14:
					printf("Digite o ID do gestor que deseja alterar: ");
					scanf("%d", &idG);
					printf("Digite o novo nome do gestor: ");
					scanf(" %[^\n]", nomeG);
					printf("Digite a nova morada do gestor: ");
					scanf(" %[^\n]", moradaG);

					gestor = alterarGestor(gestor, idG, nomeG, moradaG);
					printf("Dados do gestor alterados com sucesso!\n");
					break;
					break;
				case 15:
					printf("\nLista dos Meios de Mobilidade Electrica - Ordenada por Autonomia (decrescente):\n");
					meios = ordenarMeios(meios);
					if (meios == NULL) {
						printf("A lista está vazia.\n");
					}
					else {
						listarMeios(meios);
					}	
					break;
				case 16:
					printf("Em qual localizacao se encontra?\n");
					scanf("%s", &loc);
					listarAdjacentes(g, loc);
					
					break;
				case 17:
					printf("Em qual ponto quer comecar?\n");

					break;
				}
			} while (opG != 0);
		case 3:meios = lerMeios(); break;
		case 4:listarMeios(meios); break;
		}
	} while (op != 0);
}
