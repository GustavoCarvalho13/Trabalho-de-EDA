#include <stdio.h>

typedef struct registo
{
	int codigo; // c�digo do meio de mobilidade el�trica
	char tipo[50];
	float bateria;
	float autonomia;
	struct registo* seguinte;
} Meio;

int guardarMeios(Meio* inicio);
Meio* lerMeios();
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut); // Inser��o de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conte�do da lista ligada
int existeMeio(Meio* inicio, int codigo); // Determinar exist�ncia do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu c�digo

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

