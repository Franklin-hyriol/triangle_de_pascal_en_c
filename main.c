#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lib/creaco.h"

void print_triangle(int taille);

int main(int argc, char **argv){
	 
	char taille[10];
	int i;
	int nombre = 0;
	do{ //seul les nombres entrier passe
		printf("Entrer un nombre entier decimal: ");
		gets(taille);

		for(i = 0; i < strlen(taille); i++){
			if(isdigit(taille[i])){
				continue;
			}else{
				printf("'%s'  n'est pas un entier decimal\n", taille);
				char taille[10];
				break;
			}
		}

		nombre = atoi(taille);

		if(nombre <= 2){
			printf("Taille minimum 3\n");
		}
	}while(nombre <= 2);

	print_triangle(nombre);

	set_color(15); //revenir au couleur blanc avant de quitter
	getchar();
	return 0;
}


void print_triangle(int taille){

	int i,j,k;
	//allocation d'un tableau 2D
	int *triangle[taille];
	for (i=0; i<taille; i++){
        triangle[i] = (int *)malloc(taille * sizeof(int));
	}
	//calcule des nombres de pascal
	for(i=0; i<taille; i++){
		for(j=0; j<taille; j++){
			if(i == 0 || i == j){
				triangle[i][j] = 1;
			}else{
				triangle[i][j] = triangle[i][j-1] + triangle[i-1][j-1];
			}
		}
	}

	//print dans la console windows avec coloration

	for(i=0; i<taille; i++){
		srand(time(NULL));
		for(j=i; j<taille; j++){
			printf(" ");
		}
		for(k=0; k<=i; k++){
			set_color(rand() % 16);
			printf("%d ", triangle[k][i]);
		}
		printf("\n");
	}
}


