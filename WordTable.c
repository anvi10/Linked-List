
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WordTable.h"

// Initializes a word table
void wtable_init(WordTable * wtable)
{
	// Allocate and initialize space for the table
	wtable->nWords = 0;
	wtable->maxWords = 10;
	wtable->wordArray = (WordInfo *) malloc(wtable->maxWords * sizeof(WordInfo));
	for (int i = 0; i < wtable->maxWords; i++) {
		llist_init(&wtable->wordArray[i].positions);
	}
}

// Add word to the tableand position. Position is added to the corresponding linked list.
void wtable_add(WordTable * wtable, char * word, int position)
{
	// Find first word if it exists
	for (int i = 0; i < wtable->nWords; i++) {
		if ( strcmp(wtable->wordArray[i].word, word)== 0 ) {
			// Found word. Add position in the list of positions
			llist_insert_last(&wtable->wordArray[i].positions, position);
			return;
		}
	}

	// Word not found.

	// Make sure that the array has space.
	// Expand the wordArray here.

	// Add new word and position
	wtable->wordArray[wtable->nWords].word = strdup(word);
	llist_insert_last(&wtable->wordArray[wtable->nWords].positions, position);
	wtable->nWords++;
}

// Print contents of the table.
void wtable_print(WordTable * wtable, FILE * fd)
{
	fprintf(fd, "------- WORD TABLE -------\n");

	// Print words
	for (int i = 0; i < wtable->nWords; i++) {
		fprintf(fd, "%d: %s: ", i, wtable->wordArray[i].word);
		llist_print( &wtable->wordArray[i].positions);
	}
}

// Get positions where the word occurs
LinkedList * wtable_getPositions(WordTable * wtable, char * word)
{
	// Write your code here
	return NULL;
}

//
// Separates the string into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;
int wordCount;
int charCount;
int wordPos;

// It returns the next word from stdin.
// If there are no more more words it returns NULL.
// A word is a sequence of alphabetical characters.
static char * nextword(FILE * fd) { 

 	int c;
	int i = 0;
	while(( c=fgetc(fd) ) != -1) {
                          
		if ( c  != -1 && c != ' ' && c != '\t' && c != '\n' && c != '\r'   ) {		 
		 word[i] = c;
		 	i++;
		 } 
		else  { 
		if ( i == 0) 
			continue;

			word[i] = '\0'; 
			return word;
			
		}
	 }
	 
	 if  ( i > 0 ) {
		return word;
	 }
        return NULL;
}

// Conver string to lower case
void toLower(char *s) {
	// Write your code here
	
}


// Read a file and obtain words and positions of the words and save them in table.
int wtable_createFromFile(WordTable * wtable, char * fileName, int verbose)
{
FILE *fd = fopen(fileName, "w");	// Write your code here
return 0;
}

// Sort table in alphabetical order.
void wtable_sort(WordTable * wtable)
{
int i;
  int j;
  for(i = 0; i < wtable->nWords - 1; i ++) {
    for(j = 0; j < wtable->nWords - i - 1; j ++) {
      
	if(strcmp(wtable->wordArray[j].word,wtable->wordArray[j+1].word)>0) {
	  char * n = strdup(wtable->wordArray[j].word);
	  void * v = (void *) (wtable->wordArray[j].word);
	  wtable->wordArray[j].word = strdup(wtable->wordArray[j+1].word);
	  
	  wtable->wordArray[j].word = (void *) (wtable->wordArray[j+1].word);
	  wtable->wordArray[j+1].word = strdup(n);
	  wtable->wordArray[j + 1].word = (void *) (v);
	}	
	// Write your code here

}
}
}
// Print all segments of text in fileName that contain word.
// at most 200 character. Use fseek to position file pointer.
// Type "man fseek" for more info. 
int wtable_textSegments(WordTable * wtable, char * word, char * fileName)
{
	// Write your code here
	return  0;
}

