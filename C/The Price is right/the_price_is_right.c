#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "tpir.h"

int main(int argc, char const *argv[])
{
	char begin, name[40];
	unsigned int finded = 0, player, random = 0, MAX, mode;

	srand(time(NULL));
	
	printf("====== WELCOME TO THE PRICE IS RIGHT GAME ======\n");
	printf("You have to guess what number I'm thinking about!\nAre you ready ?\n");
	printf("Press 'O' to begin\n\n");

	while(toupper(begin = getchar()) != 'O');
	
	do{
		unsigned int score = 0;

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("Solo mode or Duo mode ? :\n");
		printf("Press 1 or 2 : \n");
		
		unsigned int rep = scanf("%u", &mode);
		
		while(!rep || mode < 1|| mode > 2){
			printf("NOT AVAILABLE VALUE!\n");
			printf("Solo mode or Duo mode ? :\n");
			printf("Press 1 or 2 : \n");
			rep = scanf("%d", &mode);
		}

		printf("\n\n");

		if(mode == 1){
			printf("Choose the level : \n");
			int diff = level();
			
			switch(diff){
				case 1 :
					MAX = LEVEL1;
				break;

				case 2 :
					MAX = LEVEL2;
				break;

				case 3: 
					MAX = LEVEL3;
				break;

				case 4: 
					MAX = LEVEL4;
				break;
				
				case 5: 
					MAX = LEVEL5;
				break;
				
				case 6: 
					MAX = LEVEL6;
				break;
				
				case 7: 
					MAX = LEVEL7;
				break;
				
				case 8: 
					MAX = LEVEL8;
				break;
				
				case 9: 
					MAX = LEVEL9;
				break;
				
				case 10: 
					MAX = LEVEL10;
				break;
			}

			while(!available(random))
				random = getAletNumber(MAX);

		printf("Well let me think...\n");
		sleep(2);
		printf("I have a number!\n\n");

		}
		else {
			printf("Player 1 choose a number :\n");
			scanf("%d", &random);
			getchar();
			
			while(!available(random)){
				printf("Number not available\n");
				printf("Player 1 choose an other number : ");
				scanf("%d", &random);
				getchar();
			}

			for (int i = 0; i < 100; ++i)
			printf("\n");
		}
			
		
		putscore(random);
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

			score++;
			
			if(player > random){
				if(player-random > 20)
					printf("Cold! (Advise: I think about a lower number)\n");
				if(player-random <= 20 && player-random > 5)
					printf("Almost but it still to high..\n");
				else printf("You are so close!! (Just a bit less)\n");
			}
			
			if(player < random){
				if(random-player > 20)
					printf("Cold! (Advise: I think about a higer number)\n");
				if(random-player <= 20 && random-player > 5)
					printf("Almost but it still to low..\n");
				else printf("You are so close!! (Just a bit more)\n");
			}

			if(player == random)
				finded = 1;
		}while(finded == 0);

		printf("\n\n\n");
		printf("Congrats you found what number I was thinking about!! You are more intelligent than I though\n");
		if(bestScore(score))
			printf("======= BEST SCORE =======\n\n");
		printf("Your name : ");
		scanf("%s", name);
		getchar();
		registerScore(name, score);
		printf("Do you want to play again ?\n");
		printf("Press 'Enter' to replay et 'q' to quit\n");
	}while(getchar() != 'q' && getchar() == '\n');

	return 0;
}