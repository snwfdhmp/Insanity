#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define LEVEL1 100
#define LEVEL2 500
#define LEVEL3 1000
#define MIN 1

int level(){
	unsigned short level;

	printf("1- 1 to 100\n");
	printf("2- 1 to 500\n");
	printf("3- 1 to 1000\n");
	printf("\n");

	do{
		printf("Enter the desired level (1 to 3 only) :\n");
		scanf("%d", &level);
		getchar();
	}while(level < 1 || level > 3);

	return level;
}

int main(int argc, char const *argv[])
{
	char begin;
	unsigned int finded = 0, player, random, max;

	srand(time(NULL));
	
	printf("====== WELCOME TO THE PRICE IS RIGHT GAME ======\n");
	printf("You have to guess what number I'm thinking about!\nAre you ready ?\n");
	printf("Press 'O' to begin\n\n");

	while(toupper(begin = getchar()) != 'O');
	
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("Choose the level : \n");
		int diff = level();
		
		if(diff == 1){
			random = (rand() % (LEVEL1 - MIN + 1)) + MIN;
			max = LEVEL1;
		}
		if(diff == 2){
			random = (rand() % (LEVEL2- MIN + 1)) + MIN;
			max = LEVEL2;
		}

		if(diff == 3){
			random = (rand() % (LEVEL3 - MIN + 1)) + MIN;
			max = LEVEL3;
		}
		
		printf("Well let me think...\n");
		sleep(2);
		printf("I have a number!\n\n");
		//printf("%d\n", random);
		
		do{
			printf("Enter a number : ");
			int check = scanf("%d", &player); //retourne 0 si c'est pas un chiffre
			getchar();

			while(!check){
				printf("Numbers only!!! Watch out!!\n");
				printf("Enter a number \n");
				getchar();
				check = scanf("%d", &player);
				
			}
			
			if(player > random)
				printf("No..Stop thinking so big!\n\n");

			if(player < random)
				printf("Nop see above!\n\n");

			if(player == random)
				finded = 1;
		}while(finded == 0);

		printf("\n\n\n");
		printf("Congrats you found what number I was thinking about!! You are more intelligent than I though\n");
		printf("Do you want to play again
			?\n");
		printf("Press 'Enter' to replay et 'q' to quit\n");
	}while(getchar() != 'q' && getchar() == '\n');

	return 0;
}