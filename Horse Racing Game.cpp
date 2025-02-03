#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void readysetgo(int* myarray, int n) {
	static int init = 0;
	time_t t;
	if (!init) {
		srand((unsigned)time(&t));
		init = 1;
	}

	for (int i = 0; i < n; i++) {
		int randomValue = i + (rand() % (n - i));
		int randomElement = myarray[randomValue];
		myarray[randomValue] = myarray[i];
		myarray[i] = randomElement;
	}
}

int is_number(char s[]) {
	int length = strlen(s);
	for (int i = 0; i < length; i++)
		if (!isdigit(s[i])) {
			printf("Faulty input %c\n", s[i]);
			return 0;
		}
	return 1;
}

int chopit(char* s, char* array[10]) {
	int i = 0;
	char* p = strtok(s, " ");

	while (p != NULL)
	{
		array[i++] = p;
		p = strtok(NULL, " ");
	}

	return i;
}

////////////////////////////////////////////////////////////////////////////////////

int main() {

	int myarray[4] = { 1, 2, 3, 4 };
	int n = sizeof(myarray) / sizeof(myarray[0]);
	int x, y, z;
	int balance = 200;
	char* wordsarray[10];
	char sentence[256];

	printf("Horse Racing Rodeo\n\nExacta bet ($15): Exacta # #\nExacta box bet ($10): Exactabox # #\nTrifecta bet ($20): Trifecta # # #\n");
	printf("Trifecta box bet ($18): Trifectabox # # #\nCheck balance: Balance\nExit: End\n");

	while (1) {

		{
			readysetgo(myarray, n);
			printf("\n[Cheat: %d %d %d %d]\n\n",
				myarray[0], myarray[1], myarray[2], myarray[3]);

			////////////////////////////////////////////////////////////////////////////////////

			printf("Enter a command: ");

			fgets(sentence, sizeof(sentence), stdin);
			sentence[strcspn(sentence, "\n")] = 0;

			int numwords = chopit(sentence, wordsarray);
			if (numwords < 1) continue;

			if (strcmp(wordsarray[0], "End") == 0) {
				printf("See you next time!\n");
				break;
			}

			////////////////////////////////////////////////////////////////////////////////////

			if (strcmp(wordsarray[0], "Exacta") == 0)
			{
				if ((numwords >= 3) &&
					is_number(wordsarray[1]) &&
					is_number(wordsarray[2])
					) {
					int x = atoi(wordsarray[1]);
					int y = atoi(wordsarray[2]);
					if ((x == myarray[0]) &&
						(y == myarray[1])) {
						printf("Congratulations, you win $150!\n");
						printf("Your current balance is $%i.\n", balance + 135);
					}

					else {
						printf("Sorry, you lost.\n");
						printf("Your current balance is $%i.\n", balance - 15);
					}
				}
			}

			////////////////////////////////////////////////////////////////////////////////////

			if (strcmp(wordsarray[0], "Trifecta") == 0)
			{
				if ((numwords >= 4) &&
					is_number(wordsarray[1]) &&
					is_number(wordsarray[2]) &&
					is_number(wordsarray[3])
					) {
					int x = atoi(wordsarray[1]);
					int y = atoi(wordsarray[2]);
					int z = atoi(wordsarray[3]);
					if ((x == myarray[0]) &&
						(y == myarray[1]) &&
						(z == myarray[2])) {
						printf("Congratulations, you win $250!\n");
						printf("Your current balance is $%i.\n", balance + 230);
					}

					else {
						printf("Sorry, you lost.\n");
						printf("Your current balance is $%i.\n", balance - 20);
					}

				}
			}

			////////////////////////////////////////////////////////////////////////////////////

			if (strcmp(wordsarray[0], "Exactabox") == 0)
			{
				if ((numwords >= 3) &&
					is_number(wordsarray[1]) &&
					is_number(wordsarray[2])
					) {
					int x = atoi(wordsarray[1]);
					int y = atoi(wordsarray[2]);
					if (((x == myarray[0]) &&
						(y == myarray[1])) ||
						((x == myarray[1]) &&
							(y == myarray[0]))) {
						printf("Congratulations, you win $100!\n");
						printf("Your current balance is $%i.\n", balance + 90);
					}

					else {
						printf("Sorry, you lost.\n");
						printf("Your current balance is $%i.\n", balance - 10);
					}
				}
			}

			////////////////////////////////////////////////////////////////////////////////////

			if (strcmp(wordsarray[0], "Trifectabox") == 0)
			{
				if ((numwords >= 4) &&
					is_number(wordsarray[1]) &&
					is_number(wordsarray[2]) &&
					is_number(wordsarray[3])
					) {
					int x = atoi(wordsarray[1]);
					int y = atoi(wordsarray[2]);
					int z = atoi(wordsarray[3]);
					if (((x == myarray[0]) &&
						(y == myarray[1]) &&
						(z == myarray[2])) ||
						((x == myarray[0]) &&
							(y == myarray[2]) &&
							(z == myarray[1])) ||
						((x == myarray[1]) &&
							(y == myarray[0]) &&
							(z == myarray[2])) ||
						((x == myarray[1]) &&
							(y == myarray[2]) &&
							(z == myarray[0])) ||
						((x == myarray[2]) &&
							(y == myarray[0]) &&
							(z == myarray[1])) ||
						((x == myarray[2]) &&
							(y == myarray[1]) &&
							(z == myarray[0]))) {
						printf("Congratulations, you win $180!\n");
						printf("Your current balance is $%i.\n", balance + 162);
					}

					else {
						printf("Sorry, you lost.\n");
						printf("Your current balance is $%i.\n", balance - 18);
					}
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////

		if (strcmp(wordsarray[0], "Balance") == 0) {
			printf("You have $%i in your piggy bank.\n", balance);
		}

	}

	return 0;

}
