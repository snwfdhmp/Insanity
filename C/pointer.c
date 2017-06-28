#include <stdio.h>

int main(int argc, char const *argv[])
{
	int age = 18;
	int tab[4];
	tab[0] = 300;
	tab[1] = 0;
	tab[2] = -15;
	int *pt = &age;
	printf("Adresse p : %p\n", &age);
	printf("Adresse d : %d\n", &age);
	printf("pt : %p\n", pt);
	printf("content pt %d\n", *pt);
	printf("pt adresse : %p\n", &pt);
	printf("pt adresse %d\n", &pt);
	printf("tab : %d\n", *(tab+450));

	return 0;
}