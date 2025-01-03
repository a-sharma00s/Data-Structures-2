/*
 * your program signature
 */ 
#include<stdio.h>
#ifndef MYWORD_H
#define MYWORD_H

typedef enum boolean {
// your code
    FALSE = 0, TRUE = 1
} BOOLEAN;

typedef struct word {
//your code
    char* word[20];
    int count;
} WORD; 

typedef struct wordstats {
// your code
    int line_count;
    int word_count;
    int keyword_count;
} WORDSTATS;

/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictrionay);

/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word);

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif