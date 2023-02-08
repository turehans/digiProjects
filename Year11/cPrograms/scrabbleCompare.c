#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//declare functions
void addLetters();

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
	for (int i = 0; i < 26; i++){
		printf("Letter %i: %c\n",i ,scrabbleLetters[i].Letters);
	}
} 

void addLetters(){
	for (int i = 0; i < 26; i++){
		scrabbleLetters[i].Letters = 'A' + i;
	}
}