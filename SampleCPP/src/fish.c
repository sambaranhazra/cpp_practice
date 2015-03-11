#include<stdio.h>

typedef struct exercise
{

	char description[256];
	float duration;
}exercise;

typedef struct meal
{
	char ingredients[256];
	float weight;
}meal;
typedef struct preference
{
	meal food;
	exercise exercise;
}preference;
struct fish
{
	char name[20];
	char species[20];
	int teeth;
	int age;
	preference care;
};

void display_fish(struct fish);
int main()
{

	struct fish f;
	printf("Enter name:");
	fgets(f.name,20,stdin);
	printf("Enter species:");
	fgets(f.species,20,stdin);
	printf("Enter age:");
	scanf("%d",&(f.age));
	printf("Enter no of teeth:");
	scanf("%d",&(f.teeth));
	getchar();
	printf("Enter preffered food:");
	fgets(f.care.food.ingredients,256,stdin);
	printf("Enter exercise description:");
	fgets(f.care.exercise.description,256,stdin);
	display_fish(f);
}

void display_fish(struct fish f)
{
	printf("Name: %sSpecies: %sAge: %d\nNo of Teeth: %d",f.name,f.species,f.age,f.teeth);
	printf("\nPreferred Food: %sExercises: %s",f.care.food.ingredients,f.care.exercise.description);
 
}
