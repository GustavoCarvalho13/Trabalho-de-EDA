#include <stdio.h>

#define TAM 50

typedef struct registo
{
	int codigo; // código do meio de mobilidade elétrica
	char tipo[50], localizacao[TAM];
	float bateria;
	float autonomia, custo;
	struct registo* seguinte; // aponta para o proximo node da lista ligada
} Meio;

int guardarMeios(Meio* inicio);
Meio* lerMeios();
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, float cust, char loc[]); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
int existeMeio(Meio* inicio, int codigo); // Determinar existência do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu código
Meio* alterarMeio(Meio* inicio, int pos, int cod, char tipo[], float bat, float aut, float cust, char loc[]); // Alterar dados
Meio* ordenarMeios(Meio* inicio);

// estrutura de users
typedef struct utilizador {
	int id;
	int nif;
	float saldo;
	char nome[50];
	char morada[50];
	struct utilizador* seguinte; // endereço de memória para uma struct registo
}User;

// Inserção de um novo user
int guardarUtilizador(User* inicio);
User* lerUsers();
User* inserirUtilizadores(User* inicio, int id, int nif, float saldo, char nome[], char morada[]);
void listarUtilizadores(User* inicio); // listar na consola o conteúdo da lista ligada
int existeUtilizador(User* inicio, int id); // Determinar existência do 'id' na lista ligada 'inicio'
User* removerUtilizador(User* inicio, int id); // Remover um utilizador a partir do seu código
User* alterarUtilizador(User* inicio, int id, int nif, float saldo, char nome[], char morada[]); // Alterar dados

typedef struct gestor {
	int idG;
	char nomeG[50];
	char moradaG[50];
	struct gestor* seguinte; // endereço de memória para uma struct gestor
}Gestor;

Gestor* inserirGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[]);
void listarGestores(Gestor* inicio); // listar na consola o conteúdo da lista ligada
int existeGestor(Gestor* inicio, int idG); // Determinar existência do 'id' na lista ligada 'inicio'
Gestor* removerGestor(Gestor* inicio, int idG); // Remover um gestor a partir do seu código
Gestor* alterarGestor(Gestor* inicio, int idG, char nomeG[], char moradaG[]); // Alterar dados

#define TAM 50

typedef struct registo2
{
	char vertice[TAM]; // geocódigo 
	float peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	char vertice[TAM]; // geocódigo 
	Adjacente adjacentes;
	Meio* meios; // Lista ligada com os códigos dos meios de transporte existente
	// neste geocódigo
	struct registo1* seguinte;
} *Grafo;

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo* g, char localizacao[]);
// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso);
int existeVertice(Grafo g, char vertice[]);
void listarAdjacentes(Grafo g, char vertice[]);
void procurarVerticePorMeio(Grafo g, char localizacao[]);
// Inserir meio de transporte na localização com geocódigo passado por parâmetro
int inserirMeioG(Grafo g, char geocodigo[], int codigoMeio);
