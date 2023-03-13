#include <stdio.h>

typedef struct registo
{
	int codigo; // código do meio de mobilidade elétrica
	char tipo[50];
	float bateria;
	float autonomia;
	struct registo* seguinte;
} Meio;

int guardarMeios(Meio* inicio);
Meio* lerMeios();
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
int existeMeio(Meio* inicio, int codigo); // Determinar existência do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu código

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

