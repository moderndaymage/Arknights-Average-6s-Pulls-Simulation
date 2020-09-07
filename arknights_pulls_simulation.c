#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int TrialRunPulls[100001];
int menu(void), pullSimulator(int baseRateUp);

int main(void)
{
	int baseRateUp = 0;
	baseRateUp = menu();	//	Enter main menu
	srand(time(0));
	pullSimulator(baseRateUp);	// Simulate pulls
	//	Sort TrialRunPulls array and find the median
	return 0;
}

int menu(void)
{
	int choice = 0;
	printf("\nArknights average 6* pulls simulation\n\nEnter a number of your choice:\n");
	printf("[1] - For a specific 6* rate-up in solo rate-up Standard Banner.\n");
	printf("[2] - For a specific 6* rate-up in duo rate-up Standard Banner.\n");
	printf("[3] - For a specific 6* rate-up in Limited Banner\n");
	printf("[4] - For any 6* rate-up in duo rate-up Standard Banner\n");
	printf("[5] - For any 6* rate-up in Limited Banner\n");
	printf("[6] - For any 6* in Standard or Limited Banner\n\n");
	while (scanf("%d", &choice) != 1)	//	Reads user input until the user enters a valid input
	{
		printf("Invalid input, please enter a number: \n");
		scanf("%*s");
	}
	switch (choice)	//	Sets odds for the 6* pull
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
	return 0;
}

int pullSimulator(int baseRateUp)
{
	int pullCounter = 0, pityCounter = 0, singlePullRNG = 0, isPullSuccess = 0;
	for (int count = 0; count < 100001; count++;)	//	100001 trials starts here
	{
		do
		{	//	Pulls until you pulled the 6* operator you want per trial
			pullCounter++;	//	Do a single pull
			if (pullCounter > 50)	//	Checks for pity first before rolling on RNG
				pityCounter++;
			singlePullRNG = (rand() % 100 + 1);	//	Simulate a single pull, RNG range is from 1 to 100
			if (singlePullRNG <= (2 + (pityCounter * 2)))	//	Checks if you pulled a 6* operator
			{
				singlePullRNG = (rand() % 100 + 1);	//	Rolls to see which 6* you pulled
				if (singlePullRNG <= baseRateUp)	//	Checks if you pulled the 6* operator you want
					isPullSuccess = 1;	//	returns 1 if pull is a success
				pityCounter = 0;	//	Resets the pity counter once you pulled any 6* operator
			}
		} while (isPullSuccess == 0);
		TrialRunPulls[count] = pullCounter;
		printf("Trial #%d, Number of pulls: %d\n", count + 1, pullCounter);
		isPullSuccess = 0;	//	Reset this variable for the next do while loop run
	}
	return 0;
}