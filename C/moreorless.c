#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define LEVEL1 100
#define LEVEL2 500
#define LEVEL3 1000
#define MIN 1

int niveau(){
	unsigned short niveau;

	printf("1--De 1 a 100\n");
	printf("2-De 1 a 500\n");
	printf("3-De 1 a 1000\n");

	do{
		printf("Tapez un niveau de 1 a 3 uniquement :\n");
		scanf("%d", &niveau);
		getchar();
	}while(niveau < 1 || niveau > 3);

	return niveau;
}

int main(int argc, char const *argv[])
{
	char begin;
	unsigned int finded = 0, player, random, max;

	srand(time(NULL));
	
	printf("====== BIENVENU DANS LE PLUS OU MOINS ======\n");
	printf("Le but du jeu est de deviner le nombre auquel je pense\nVous etes pret ?\n");
	printf("Tapez 'O' pour commencer\n");

	while(toupper(begin = getchar()) != 'O');
	
	do{
		printf("Choisissez un niveau : \n");
		int level = niveau();
		
		if(level == 1){
			random = (rand() % (LEVEL1 - MIN + 1)) + MIN;
			max = LEVEL1;
		}
		if(level == 2){
			random = (rand() % (LEVEL2- MIN + 1)) + MIN;
			max = LEVEL2;
		}

		if(level == 3){
			random = (rand() % (LEVEL3 - MIN + 1)) + MIN;
			max = LEVEL3;
		}
		
		printf("Ok laisse moi reflechir....\n");
		sleep(2);
		printf("C'est bon !\n");
		//printf("%d\n", random);
		
		do{
			printf("Tapez un nombre : ");
			int check = scanf("%d", &player); //retourne 0 si c'est pas un chiffre
			getchar();

			while(!check){
				printf("Que des chiffres! Je t'ai a l'oeil!!\n");
				printf("Tapez un nombre : \n");
				getchar();
				check = scanf("%d", &player);
				
			}
			
			if(player > random)
				printf("Non je pense a un nombre plus petit!\n");

			if(player < random)
				printf("Voit les choses plus grand!\n");

			if(player == random)
				finded = 1;
		}while(finded == 0);

		printf("Felicitation tu as trouver le nombre auquel je pense!!\n");
		printf("Tu veux rejouer ?\n");
		printf("Appuie sur 'Entree' pour recommence et 'q' pour quitter\n");
	}while(getchar() != 'q' && getchar() == '\n');

	return 0;
}