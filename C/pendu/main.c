#include <stdio.h>
#include <unistd.h>
#include "pendu.h"

int main(int argc, char const *argv[])
{
	char* wordtoguess = chooseWord();
	//printf("%s\n", wordtoguess);
	
	int size = getlen(wordtoguess);
	//printf("%d\n", size);
	char *userword = malloc(size*sizeof(char));
	int count = 0, life = 10, win;

	//printf("%d\n", size);
	
	do{
		char guess;

		for(int i = 0; i < size; i++)
			userword[i] = '*';
		
		printf("====== Jeu du pendu =======\n");
		printf("Regles : Vous devez devnier le mot auquelle je pense..Voila C'est simple non ?\nSi apres 10 coups vous n'y etes arrive pas vous avez perdu\n");
		printf("Challenge accepte ?\nD'accord laisse moi reflechir a un mot...\n");
		sleep(2);
		printf("C'est bon j'ai une bonne idee!\n\n");

		do{
			count = 0;
			
			printf("Tapez un lettre : ");
			scanf("%c", &guess);
			getchar();
			
			for(int i = 0; i < size; i++){
				if(guess == wordtoguess[i]){
					userword[i] = guess;
					count++;
				}
			}
			
			if(count > 0)
				printf("La lettre %c est presente %d fois dans le mot\n", guess, count);
			else 
				printf("La lettre n'est pas dans le mot\n");
			
			life--;
			
			win = check(userword, wordtoguess);
		
			printf("%s\n", userword);
			printf("Il vous reste %d vies\n\n", life);

		}while(life > 0 && win == 0);

		if(win == 0)
			printf("Desole vous avez perdu...\nLe mot auquelle je pensais ete %s", wordtoguess);
		else printf("Bravo!! Tu es trop fort :) \n");
		
		printf("\n\n\n");
		printf("Tu veux recommancer ?\n");
		printf("Press 'Enter' to replay et 'q' to quit\n");
	
	}while(getchar() != 'q' && getchar() == '\n');	

	return 0;
}