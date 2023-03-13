#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Header.h"

// Inserção de um novo registo
// inserção realizada no início da lista ligada
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut)
{
	if (!existeMeio(inicio, cod))
	{
		Meio* novo = malloc(sizeof(struct registo));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio* inicio)
{
	while (inicio != NULL)
	{
		printf("id:%d | %s | Bateria:%.2f | Autonomia:%.2f Km\n", inicio->codigo, inicio->tipo,
			inicio->bateria, inicio->autonomia);
		inicio = inicio->seguinte;
	}
}


// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}

/*
Meio* removerMeio(Meio* inicio, int cod) // Remover um meio a partir do seu código
{while (inicio!=NULL)
 {if (inicio->codigo==cod)
	 {aux = inicio->seguinte;
		  free(inicio);
	  return(aux);
	 }
  else {inicio = removerMeio(inicio->seguinte,cod);
	return(inicio);
	   }
 }
}
*/

// Remover um meio a partir do seu código{
Meio* removerMeio(Meio* inicio, int cod)
{
	Meio* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL); // lista ligada vazia
	else if (atual->codigo == cod) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}



int existeUtilizador(User* inicio, int id) {
	while (inicio != NULL) {
		if (inicio->id == id) {
			return 1; // user with given ID exists
		}
		inicio = inicio->seguinte;
	}
	return 0; // user with given ID does not exist
}


User* adicionarUtilizador(User* inicio, int id, int nif, float saldo, char nome[], char morada[])
{
	// Verificar se o ID do utilizador já existe na lista
	if (existeUtilizador(inicio, id))
	{
		printf("O utilizador com ID %d ja existe na lista.\n", id);
		return inicio;
	}

	// Criar um novo utilizador
	User* novo = malloc(sizeof(User));
	if (novo != NULL)
	{
		novo->id = id;
		novo->NIF = nif;
		novo->saldo = saldo;
		strcpy(novo->nome, nome);
		strcpy(novo->morada, morada);
		novo->seguinte = inicio;
		printf("Utilizador adicionado com sucesso!\n");
		return novo;
	}
	else
	{
		printf("Erro ao alocar memoria para um novo utilizador.\n");
		return inicio;
	}

}

void listarUtilizadores(User* inicio) {
	if (inicio == NULL) {
		printf("Nao existem utilizadores registados.\n");
	}
	else {
		printf("Lista de Utilizadores:\n");
		while (inicio != NULL) {
			printf("ID:%d | NIF:%d | Saldo:%.2f | Nome:%s | Morada:%s\n", inicio->id, inicio->NIF, inicio->saldo, inicio->nome, inicio->morada);
			inicio = inicio->seguinte;
		}
	}
}