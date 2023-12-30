#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

int main() {
	//Creating random 3 digit number
	srand(time(NULL));
	int correctNum = rand() % 999 + 1;
	while((correctNum - 100) < 0) {
		correctNum = rand() % 999 + 1;
	}
	char correctChar[4]; 
	sprintf(correctChar, "%d", correctNum);

	//intro
	printf("Hi! I'm Connor. I've picked a random three-digit number and now it's your job to guess it (Rules are in the README file). GOOD LUCK!\n");
	printf("Also...if you give up, it's control+C to quit! \n\n");
	
	int numGuess;
	char numGuessChar[4];	
	while(1) {
		printf("Guess a number: ");
		scanf("%d", &numGuess);
		if(numGuess != correctNum) {
			int digits = 0;
			int places = 0;
			sprintf(numGuessChar, "%d", numGuess);
			//Check the # of places
			for(int i = 0; i < 3; i++) {
				if(correctChar[i] == numGuessChar[i]) {
					places++;
				}	
			}
			//Check for the # of digits
			if(strchr(correctChar, numGuessChar[0]) != NULL)
				digits++;
			if(numGuessChar[0] != numGuessChar[1]) {
				if(strchr(correctChar, numGuessChar[1]) != NULL) 
					digits++;
			} 
			if((numGuessChar[2] != numGuessChar[1]) && (numGuessChar[2] != numGuessChar[0])) {
				if(strchr(correctChar, numGuessChar[2]) != NULL) 
					digits++;
			}

			printf("| # of correct places: %d | # of correct digits: %d |\n", places, digits);
			printf("\n");
		} else {
			printf("Nice job! You won!\n");
			break;
		}
	}
	
	return 0;
}
