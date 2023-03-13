#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "meio.h"


int guardarMeios(Meio* inicio)
{
	FILE* fp;
	fp = fopen("meios.txt", "w");
	if (fp != NULL)
	{
		Meio* aux = inicio;
		while (aux != NULL)
		{
			fprintf(fp, "%d;%f;%f;%s\n", aux->codigo, aux->bateria,
				aux->autonomia, aux->tipo);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

Meio* lerMeios()
{
	FILE* fp;
	int cod;
	float bat, aut;
	char tipo[50];
	Meio* aux = NULL;
	fp = fopen("meios.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%f;%f;%[^\n]s\n", &cod, &bat, &aut, tipo);
			aux = inserirMeio(aux, cod, tipo, bat, aut);
		}
		fclose(fp);
	}
	return(aux);
}

// Inserção de um novo registo
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
		printf("%d %s %.2f %.2f\n", inicio->codigo, inicio->tipo,
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

	if (atual == NULL) return(NULL);
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

int guardarUtilizador(User* inicio)
{
	FILE* fp;
	fp = fopen("users.txt", "w");
	if (fp != NULL)
	{
		User* aux = inicio;
		while (aux != NULL)
		{
			fprintf(fp, "%d;%d;%f;%s;%s\n", aux->id, aux->nif,
				aux->saldo, aux->nome, aux->morada);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

User* lerUsers()
{
	FILE* fp;
	int id, nif;
	float saldo;
	char nome[50], morada[50];
	User* aux = NULL;
	fp = fopen("users.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%d;%f;%[^\n]s;%[^\n]s\n", &id, &nif, &saldo, nome, morada);
			aux = inserirUtilizadores(aux, id, nif, saldo, nome, morada);
		}
		fclose(fp);
	}
	return(aux);
}

// Inserção de um novo User
User* inserirUtilizadores(User* inicio, int id, int nif, float saldo, char nome[], char morada[]) 
{
	if (!existeUtilizador(inicio, id))
	{
		User* novo = malloc(sizeof(struct utilizador));
		if (novo != NULL)
		{
			novo->id = id;
			novo->nif = nif;
			novo->saldo = saldo;
			strcpy(novo->nome, nome);
			strcpy(novo->morada, morada);
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}

void listarUtilizadores(User* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %d %.2f %s %s\n", inicio->id, inicio->nif,
			inicio->saldo, inicio->nome, inicio->morada);
		inicio = inicio->seguinte;
	}
}
int existeUtilizador(User* inicio, int id)
{
	while (inicio != NULL)
	{
		if (inicio->id == id) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}

User* removerUtilizador(User* inicio, int id)
{
	User* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->id == id) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->id != id))
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