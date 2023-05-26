#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"


int guardarMeios(Meio* inicio)
{
	FILE* fp;
	fp = fopen("meios.txt", "w"); // cria o txt caso ele ainda nao exista
	if (fp != NULL)
	{
		Meio* aux = inicio;
		while (aux != NULL) // se a lista estiver vazia ele adiciona os respetivos meios
		{
			fprintf(fp, "%d|Bateria:%f|Autunomia:%f|Tipo:%s|Custo:%f|Localizacao:%s\n", aux->codigo, aux->bateria,
				aux->autonomia, aux->tipo, aux->custo, aux->localizacao);
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
	float bat, aut, cust;
	char tipo[50], loc[50];
	Meio* aux = NULL; // criaçao da lista meios(aux) 
	fp = fopen("meios.txt", "r"); // le o ficheiro
	if (fp != NULL) // verifica se o ficheiro esta vazio 
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d|Bateria:%f|Autunomia:%f|Tipo:%[^|]|Custo:%f|Localizacao:%[^\n]\n", &cod, &bat, &aut, tipo, &cust, &loc);
			aux = inserirMeio(aux, cod, tipo, bat, aut, cust, loc); //faz scanf do que esta no ficheiro e poe no porgrama
		}
		fclose(fp);// fecha o ficheiro 
	}
	return(aux);
}

// Inserção de um novo registo
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, float cust, char loc[])
{
	Grafo g = NULL;
	if (!existeMeio(inicio, cod))
	{
		Meio* novo = malloc(sizeof(struct registo));// cria caixa(node) nova para o novo meios(atribui a memoria necessaria para criar um novo meio)
		if (novo != NULL)
		{
			//insere as variaveis de parametros numa nova caixa
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			novo->custo = cust;
			strcpy(novo->localizacao, loc);
			novo->seguinte = inicio; // aponta endereço da caixa para o inicio da lista
			return(novo);
		}
	}
	else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio* inicio)
{
	while (inicio != NULL) // verifica se alista meios é vazia
	{
		printf("%d| Tipo:%s| Bateria:%.2f| Autunomia:%.2f| Custo:%.2f| Localizacao:%s\n", inicio->codigo, inicio->tipo,
			inicio->bateria, inicio->autonomia, inicio->custo, inicio->localizacao);
		inicio = inicio->seguinte; //atribui a caixa as variaveis da caixa seguinte ate ser null
	}
}


// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio* inicio, int cod)
{
	while (inicio != NULL) // verifica se struct meio tem alguma caixa
	{
		if (inicio->codigo == cod) return(1); // se existir algum codigo do parametro igual ao codigo de alguma caixa retorna 1 se nao existir retorna 0
		inicio = inicio->seguinte;
	}
	return(0);
}

// Remover um meio a partir do seu código{
Meio* removerMeio(Meio* inicio, int cod)
{
	Meio* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) // remoção se estiver na 1 posiçao. 
	{
		aux = atual->seguinte; // aponta para a posiçao n2 da lista
		free(atual); // remove a posiçao n1 da memoria
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;        //percorremos a lista e paramos quando apontar para null ou para o encontrarmos o node selecionado
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte; // quando encontrarmos o node removemos lo da lista e o  node segunite passa a ser o anterior e o  
			//atual passa a ser o seguiinte.
			free(atual); // libertamos a memoria ocupada pelo atual
			return(inicio);
		}
	}
}

Meio* alterarMeio(Meio* inicio, int pos, int cod, char tipo[], float bat, float aut, float cust, char loc[]) {
	Meio* atual = inicio;
	int i = 1;

	while (atual != NULL && i < pos) { // algoritmo para percorrer a lista
		atual = atual->seguinte;
		i++;
	}

	if (atual == NULL) {
		printf("Posicao invalida!\n");
		return inicio;
	}

	atual->codigo = cod; // troca o codigo do atual para o novo codigo que queres dar
	strcpy(atual->tipo, tipo);
	atual->bateria = bat;
	atual->autonomia = aut;
	atual->custo = cust;
	strcpy(atual->localizacao, loc);

	return inicio;
}

Meio* ordenarMeios(Meio* head) {
	int swapped;
	Meio* ptr1;            // variaveis que vao ser usadas para a procura
	Meio* lptr = NULL;

	if (head == NULL) {
		return;
	}

	do {
		swapped = 0;
		ptr1 = head;

		while (ptr1->seguinte != lptr) { // algoritmo pra ler ciclo
			if (ptr1->autonomia < ptr1->seguinte->autonomia) {
				int temp = ptr1->autonomia;                           //Se o parametro autunomia for menor que o parametro autonomia do seu vizinho 
				ptr1->autonomia = ptr1->seguinte->autonomia;          // trocamos los, continuamos o loop ate nao haver mais trocas. ou seja ate a
				ptr1->seguinte->autonomia = temp;                     // lista estar ordenada.
				swapped = 1;
			}
			ptr1 = ptr1->seguinte;
		}
		lptr = ptr1;
	} while (swapped);
	return head;
}

int guardarUtilizador(User* inicio)
{
	FILE* fp;
	fp = fopen("users.txt", "w"); // cria o txt caso ele ainda nao exista
	if (fp != NULL)
	{
		User* aux = inicio;
		while (aux != NULL) // se a lista estiver vazia ele adiciona os respetivos meios
		{
			fprintf(fp, "ID:%d|NIF:%d|Saldo:%f|Nome:%s|Morada:%s\n", aux->id, aux->nif,
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
	User* aux = NULL; // criaçao da lista meios(aux) 
	fp = fopen("users.txt", "r"); // le o ficheiro
	if (fp != NULL) // verifica se o ficheiro esta vazio 
	{
		while (!feof(fp))
		{
			fscanf(fp, "ID:%d|NIF:%d|Saldo:%f|Nome:%[^\n]s|Morada:%[^\n]s\n", &id, &nif, &saldo, nome, morada);
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
		printf("ID:%d|NIF:%d|Saldo:%.2f|Nome:%s|Morada:%s\n", inicio->id, inicio->nif,
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

User* alterarUtilizador(User* inicio, int id, int nif, float saldo, char nome[], char morada[]) {
	User* p = inicio;
	while (p != NULL) {
		if (p->id == id) {
			p->nif = nif;
			p->saldo = saldo;
			strcpy(p->nome, nome);
			strcpy(p->morada, morada);
			return inicio;
		}
		p = p->seguinte;
	}
	printf("Utilizador nao encontrado!\n");
	return inicio;
}

Gestor* inserirGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[])
{
	if (!existeGestor(inicio, idG))
	{
		Gestor* novo = malloc(sizeof(struct gestor));
		if (novo != NULL)
		{
			novo->idG = idG;
			strcpy(novo->nomeG, nomeG);
			strcpy(novo->moradaG, moradaG);
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}

void listarGestores(Gestor* inicio)
{
	while (inicio != NULL)
	{
		printf("ID:%d|Nome:%s|Morada:%s\n", inicio->idG, inicio->nomeG, inicio->moradaG);
		inicio = inicio->seguinte;
	}
}

int existeGestor(Gestor* inicio, int idG)
{
	while (inicio != NULL)
	{
		if (inicio->idG == idG) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}

Gestor* removerGestor(Gestor* inicio, int idG)
{
	Gestor* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->idG == idG) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->idG != idG)) // verifica que nao é o ultimo nem o primeiro
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

Gestor* alterarGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[]) {
	Gestor* p;
	for (p = inicio; p != NULL; p = p->seguinte) {
		if (p->idG == idG) {
			// Found the gestor with matching id, update data
			strcpy(p->nomeG, nomeG);
			strcpy(p->moradaG, moradaG);
			return inicio;  // Return the updated list
		}
	}
	// If gestor with matching id not found, do nothing
	return inicio;
}

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo* g, char localizacao[])
{
	Grafo novo = malloc(sizeof(struct registo1));
	if (novo != NULL)
	{
		strcpy(novo->vertice, localizacao);
		novo->meios = NULL;
		novo->seguinte = *g;
		*g = novo;
		return(1);
	}
	else return(0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo g, char localizacao[])
{
	while (g != NULL)
	{
		if (strcmp(g->vertice, localizacao) == 0) return(1);
		else g = g->seguinte;
	}
	return(0);
}

// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso)
{
	Adjacente novo;
	if (existeVertice(g, vOrigem) && existeVertice(g, vDestino))
	{
		while (strcmp(g->vertice, vOrigem) != 0) g = g->seguinte;
		novo = malloc(sizeof(struct registo1));
		if (novo != NULL)
		{
			strcpy(novo->vertice, vDestino);
			novo->peso = peso;
			novo->seguinte = g->adjacentes;
			g->adjacentes = novo;
			return(1);
		}
		else return(0);
	}
	else return(0);
}

// Listar os vértices adjacentes 
void listarAdjacentes(Grafo g, char localizacao[])
{
	Adjacente aux;
	if (existeVertice(g, localizacao))
	{
		while (strcmp(g->vertice, localizacao) != 0) g = g->seguinte;
		aux = g->adjacentes;
		while (aux != NULL)
		{
			printf("Adjacente:%s Peso:%.2f\n", aux->vertice, aux->peso);
			aux = aux->seguinte;
		}
	}
	else
	{
		printf("O vértice não existe no grafo.\n");
	}
}

void procurarVerticePorMeio(Grafo g, char localiizacao[]) {
	while (g != NULL) {
		Meio* meioAtual = g->meios;

		while (meioAtual != NULL) {
			if (strcmp(meioAtual->tipo, localiizacao) == 0) {
				return g;
			}
			meioAtual = meioAtual->seguinte;
		}

		g = g->seguinte;
	}

	return NULL;
}

// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeioG(Grafo g, char geocodigo[], int codigoMeio)
{
	while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
		g = g->seguinte;
	if (g == NULL) return(0);
	else {
		Meio* novo = malloc(sizeof(struct registo));
		novo->codigo = codigoMeio;
		novo->seguinte = g->meios;
		g->meios = novo;
		return(1);
	}
}