#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//declare functions
void addLetters();
void addPoints();

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
	printf("First word: ");
	char* firstWord = scanf("s");

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