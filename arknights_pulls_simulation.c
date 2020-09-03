#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int TrialRunPulls[100001];
int menu(void);
int pullSimulator(int baseRateup);

int main(void)
{
	int baseRateUp = 0;
	baseRateUp = menu();	//	Enter main menu
	srand(time(0));
	pullSimulator(baseRateUp);	// Simulate pulls
	printf("%d", baseRateUp);
	return 0;
}

int menu(void)
{
	int choice = 0;
	printf("\nArknights average 6* pulls simulation\n");
	printf("\nEnter a number of your choice:\n");
	printf("[1] - For a specific 6* rate-up in solo rate-up Standard Banner.\n");
	printf("[2] - For a specific 6* rate-up in duo rate-up Standard Banner.\n");
	printf("[3] - For a specific 6* rate-up in Limited Banner\n");
	printf("[4] - For any 6* rate-up in duo rate-up Standard Banner\n");
	printf("[5] - For any 6* rate-up in Limited Banner\n");
	printf("[6] - For any 6* in Standard or Limited Banner\n\n");
	while (scanf("%d", &choice) != 1)
	{
		printf("Invalid input, please enter a number: \n");
		scanf("%*s");
	}
	switch (choice)
	{
		case 1:
		case 4:
			return 50;
		case 2:
			return 25;
		case 3:
			return 35;
		case 5:
			return 70;
		case 6:
			return 100;
		default:
			printf("Invalid input, try again.\n");
	}
}

int pullSimulator(int baseRateup)
{
	return 0;
}