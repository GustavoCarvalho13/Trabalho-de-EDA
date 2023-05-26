#include <stdio.h>

#define TAM 50

typedef struct registo
{
	int codigo; // c�digo do meio de mobilidade el�trica
	char tipo[50], localizacao[TAM];
	float bateria;
	float autonomia, custo;
	struct registo* seguinte; // aponta para o proximo node da lista ligada
} Meio;

int guardarMeios(Meio* inicio);
Meio* lerMeios();
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, float cust, char loc[]); // Inser��o de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conte�do da lista ligada
int existeMeio(Meio* inicio, int codigo); // Determinar exist�ncia do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu c�digo
Meio* alterarMeio(Meio* inicio, int pos, int cod, char tipo[], float bat, float aut, float cust, char loc[]); // Alterar dados
Meio* ordenarMeios(Meio* inicio);

// estrutura de users
typedef struct utilizador {
	int id;
	int nif;
	float saldo;
	char nome[50];
	char morada[50];
	struct utilizador* seguinte; // endere�o de mem�ria para uma struct registo
}User;

// Inser��o de um novo user
int guardarUtilizador(User* inicio);
User* lerUsers();
User* inserirUtilizadores(User* inicio, int id, int nif, float saldo, char nome[], char morada[]);
void listarUtilizadores(User* inicio); // listar na consola o conte�do da lista ligada
int existeUtilizador(User* inicio, int id); // Determinar exist�ncia do 'id' na lista ligada 'inicio'
User* removerUtilizador(User* inicio, int id); // Remover um utilizador a partir do seu c�digo
User* alterarUtilizador(User* inicio, int id, int nif, float saldo, char nome[], char morada[]); // Alterar dados

typedef struct gestor {
	int idG;
	char nomeG[50];
	char moradaG[50];
	struct gestor* seguinte; // endere�o de mem�ria para uma struct gestor
}Gestor;

Gestor* inserirGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[]);
void listarGestores(Gestor* inicio); // listar na consola o conte�do da lista ligada
int existeGestor(Gestor* inicio, int idG); // Determinar exist�ncia do 'id' na lista ligada 'inicio'
Gestor* removerGestor(Gestor* inicio, int idG); // Remover um gestor a partir do seu c�digo
Gestor* alterarGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[]); // Alterar dados

#define TAM 50

typedef struct registo2
{
	char vertice[TAM]; // geoc�digo 
	float peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	char vertice[TAM]; // geoc�digo 
	Adjacente adjacentes;
	Meio* meios; // Lista ligada com os c�digos dos meios de transporte existente
	// neste geoc�digo
	struct registo1* seguinte;
} *Grafo;

// Criar um novo v�rtice
// Devolve 1 em caso de sucesso ou 0 caso contr�rio
int criarVertice(Grafo* g, char localizacao[]);
// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contr�rio
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso);
int existeVertice(Grafo g, char vertice[]);
void listarAdjacentes(Grafo g, char vertice[]);
void procurarVerticePorMeio(Grafo g, char localizacao[]);
// Inserir meio de transporte na localiza��o com geoc�digo passado por par�metro
int inserirMeioG(Grafo g, char geocodigo[], int codigoMeio);
