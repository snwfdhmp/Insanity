#include "tpir.h"

int level(){
	unsigned short level;

	printf("1- 1 to 100\n");
	printf("2- 1 to 200\n");
	printf("3- 1 to 300\n");
	printf("4- 1 to 400\n");
	printf("5- 1 to 500\n");
	printf("6- 1 to 600\n");
	printf("7- 1 to 700\n");
	printf("8- 1 to 800\n");
	printf("9- 1 to 900\n");
	printf("10- 1 to 1000\n");
	printf("\n");

	do{
		printf("Enter the desired level (1 to 10 only) :\n");
		scanf("%d", &level);
		getchar();
	}while(level < 1 || level > 10);

	return level;
}

void registerScore(char *name, int score){
	FILE* scorefile = fopen("score.txt", "a+");

	fprintf(scorefile, "%s : %d\n", name, score);

	fclose(scorefile);
}

int getAletNumber(int MAX){
	return (rand() % (MAX - MIN + 1)) + MIN;
}

void putscore(int random){
	FILE* cancel = fopen("cancel.txt", "a+");

	fprintf(cancel, "%d\n", random);

	fclose(cancel);
}

int available(int random){
	FILE* cancel = fopen("cancel.txt", "r");
	int nbr;

	if (random == 0)
		return 0;

	while(!feof(cancel)){
		fscanf(cancel, "%d", &nbr);
		//printf("NBR : %d\n", nbr);
		if(nbr == random){
			fclose(cancel);
			return 0;
		}
	}
	fclose(cancel);
	return 1;
}

int bestScore(int max){
	FILE* score = fopen("score.txt", "a+");
	int nbr;
	char name[20];

	while(!feof(score)){
		fscanf(score, "%s %d", name, &nbr);
		if(nbr > max){
			fclose(score);
			return 0;
		}
	}
	fclose(score);
	return 1; 
}