#include <stdio.h>
// Remover um meio a partir do seu c�digo

typedef struct registo
{
	int codigo; // c�digo do meio de mobilidade el�trica
	char tipo[50];
	float bateria;
	float autonomia;
	struct registo* seguinte; // endere�o de mem�ria para uma struct registo
} Meio;


// Inser��o de um novo registo
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut);

// listar na consola o conte�do da lista ligada
void listarMeios(Meio* inicio);

// Determinar exist�ncia do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio* inicio, int codigo);

// Remover um meio a partir do seu c�digo
Meio* removerMeio(Meio* inicio, int cod);

// estrutura de users
typedef struct utiliador {
	int id; 
	int NIF;
	float saldo;
	char nome[50];
	char morada[50];
	struct utilizador* seguinte; // endere�o de mem�ria para uma struct registo
}User;

// Inser��o de um novo user
User* inserirUtilizadores(User* inicio, int id, int NIF, float saldo, char nome[], char morada[]);



