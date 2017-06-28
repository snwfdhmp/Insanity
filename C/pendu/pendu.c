#include "pendu.h"

int getlen(char *game){
	return strlen(game);
}

int check(char *player, char* game){
	if(strcmp(player, game) == 0){
		return 1;
	}
	return 0;
}

char* chooseWord(){
	FILE* words;
	char *word = malloc(20*sizeof(char));
	words = fopen("liste_francais.txt","r");

	srand(time(NULL));
	int random = (rand() % (MAX - MIN + 1)) + MIN;
	
	printf("%d\n", random);

	for(int i =0; i < random; i++){
		fscanf(words, "%s", word);
		//printf("%s\n", word);
	}

	return word;
	
}