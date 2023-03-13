#include <stdio.h>
// Remover um meio a partir do seu código

typedef struct registo
{
	int codigo; // código do meio de mobilidade elétrica
	char tipo[50];
	float bateria;
	float autonomia;
	struct registo* seguinte; // endereço de memória para uma struct registo
} Meio;


// Inserção de um novo registo
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut);

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio* inicio);

// Determinar existência do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio* inicio, int codigo);

// Remover um meio a partir do seu código
Meio* removerMeio(Meio* inicio, int cod);

// estrutura de users
typedef struct utiliador {
	int id; 
	int NIF;
	float saldo;
	char nome[50];
	char morada[50];
	struct utilizador* seguinte; // endereço de memória para uma struct registo
}User;

// Inserção de um novo user
User* inserirUtilizadores(User* inicio, int id, int NIF, float saldo, char nome[], char morada[]);



