#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//declare functions
void getInput(char *question, char *inputBuffer, int bufferLength);
void addLetters();
void addPoints();
int findPoints(char* word);
void toUppercase(char* word);
void betterWord(int firstWordPoints, int secondWordPoints, char* firstWord, char* secondWord);

//create struct scrabbleLetters
struct scrabbleLetters {
  char  Letters;
  int Points;
};

//create an array of the number of points for each letter
struct scrabbleLetters scrabbleLetters[26];

int main(){
	//call function that adds letters to array
	addLetters();
	//call function that adds corresponding points
	addPoints();
	for (int i = 0; i < 26; i++){
		printf("%c,", scrabbleLetters[i].Letters);
		printf("%i\n" ,scrabbleLetters[i].Points);
	}


	//get first word
	char* firstWord = malloc(8); 
	getInput("Enter first word:", firstWord, 8);

	

	//get second word using function
	char* secondWord = malloc(8); 
	getInput("Enter second word:", secondWord, 8);


	//covert word to uppercase
	toUppercase(firstWord);
	toUppercase(secondWord);


	//find number of points in first word
	int firstWordPoints = findPoints(firstWord);
	printf("firstWordPoints: %i\n", firstWordPoints);
	int secondWordPoints = findPoints(secondWord);
	printf("secondWordPoints: %i\n", secondWordPoints);


	//find better word and print it
	betterWord(firstWordPoints, secondWordPoints, firstWord, secondWord);
	free(firstWord);
	free(secondWord);
} 

void addLetters(){
	for (int i = 0; i < 26; i++){
		scrabbleLetters[i].Letters = 'A' + i;
	}
}

void addPoints(){
	for (int i = 0; i < 26; i++){
		if (scrabbleLetters[i].Letters == 'A' || scrabbleLetters[i].Letters == 'E' || scrabbleLetters[i].Letters == 'I' || scrabbleLetters[i].Letters == 'O' || scrabbleLetters[i].Letters == 'U' || scrabbleLetters[i].Letters == 'L' || scrabbleLetters[i].Letters == 'N' || scrabbleLetters[i].Letters == 'S'|| scrabbleLetters[i].Letters == 'T' || scrabbleLetters[i].Letters == 'R')
		{
			scrabbleLetters[i].Points = 1;
		} 
		else if (scrabbleLetters[i].Letters == 'D' || scrabbleLetters[i].Letters == 'G')
		{
			scrabbleLetters[i].Points = 2;
		} 
		else if (scrabbleLetters[i].Letters == 'B' || scrabbleLetters[i].Letters == 'C' || scrabbleLetters[i].Letters == 'M' || scrabbleLetters[i].Letters == 'P')
		{
			scrabbleLetters[i].Points = 3;
		}
		else if (scrabbleLetters[i].Letters == 'F' || scrabbleLetters[i].Letters == 'H' || scrabbleLetters[i].Letters == 'V' || scrabbleLetters[i].Letters == 'W' || scrabbleLetters[i].Letters == 'Y')
		{
			scrabbleLetters[i].Points = 4;
		}
		else if (scrabbleLetters[i].Letters == 'K')
		{
			scrabbleLetters[i].Points = 5;
		}
		else if (scrabbleLetters[i].Letters == 'J' || scrabbleLetters[i].Letters == 'X')
		{
			scrabbleLetters[i].Points = 8;
		}
		else if (scrabbleLetters[i].Letters == 'Q' || scrabbleLetters[i].Letters == 'Z')
		{
			scrabbleLetters[i].Points = 10;
		}
		else{
			printf("Error: Not a valid Letter");
		}
	}
}

int findPoints(char* word){
	int numberPoints = 0;
	for (int i = 0; i < strlen(word); i++){
		for (int j = 0; j < 26; j++){
			if (word[i] == scrabbleLetters[j].Letters){
				numberPoints += scrabbleLetters[j].Points;
			}
			
		}
	}
	return numberPoints;
}

void betterWord(int firstWordPoints, int secondWordPoints, char* firstWord, char* secondWord){
	if (firstWordPoints > secondWordPoints){
		printf("%s is the better word\n", firstWord);
	} else if (secondWordPoints > firstWordPoints){
		printf("%s is the better word\n", secondWord);
	} else {
		printf("Both words are equivalent\n");
	}
}

void getInput(char *statement, char *inputBuffer, int bufferLength){
	printf("%s  (Max %d characters)\n", statement, bufferLength - 1);
    fgets(inputBuffer, bufferLength, stdin);

    if (inputBuffer[strlen(inputBuffer) -1] != '\n')
    {
        int dropped = 0;
        while (fgetc(stdin) != '\n')
            dropped++;

        if (dropped > 0) // if they input exactly (bufferLength - 1) 
                         // characters, there's only the \n to chop off
        {
            printf("Error word was to long!\n");
            getInput(statement, inputBuffer, bufferLength);
        }
    }
    else
    {
        inputBuffer[strlen(inputBuffer) -1] = '\0';      
    }
}

void toUppercase(char* word){
	for(int i = 0; i < strlen(word); i++){
		word[i] = toupper(word[i]);
	}
}