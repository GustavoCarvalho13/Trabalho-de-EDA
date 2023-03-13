#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	Meio* meios = NULL; // Lista ligada vazia 

	meios = inserirMeio(meios, 1, "bicicleta", 55, 30);
	meios = inserirMeio(meios, 2, "bicicleta", 85, 50);
	meios = inserirMeio(meios, 3, "trotinete", 85, 50);

	listarMeios(meios);

	if (existeMeio(meios, 1)) printf("Meio 1 existe\n");
	else printf("Meio 1 nao existe\n");

	if (existeMeio(meios, 4)) printf("Meio 4 existe\n");
	else printf("Meio 4 nao existe\n");

	meios = removerMeio(meios, 1);
	meios = removerMeio(meios, 2);
	meios = removerMeio(meios, 3);
	listarMeios(meios);

	User* inicio = NULL;
	inicio = adicionarUtilizador(inicio, 1, 123456789, 50.0, "Maria", "Rua A");
	inicio = adicionarUtilizador(inicio, 2, 987654321, 20.0, "Joao", "Rua B");
	inicio = adicionarUtilizador(inicio, 3, 111111111, 10.0, "Ana", "Rua C");

	printf("Lista de utilizadores:\n");
    // list all users
    listarUtilizadores(inicio);

	return(0);
}
