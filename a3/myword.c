/*
 * your program signature
 */ 

#include <stdio.h>
#include <string.h>
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

// You can copy here the functions in mysttring.c if you want to use them in the
// following functions. You can also add other auxiliary functions here. 

/**
 *  add your comment
 */
int create_dictionary(FILE *fp, char *dictionary) {
    // your code
    char line[MAX_LINE_LEN];
    int count = 0;

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        char delimiters[] = " .,\n\t\r";
        char *word_token = strtok(line, delimiters);
        while (word_token != NULL) {
            if (contain_word(dictionary, word_token) == FALSE) {
                strcat(dictionary, ",");
                strcat(dictionary, word_token);
                strcat(dictionary, ",");
                count++;
            }

            word_token = strtok(NULL, delimiters);
        }
    }

    return count;

}

/**
 *  add your comment
 */
BOOLEAN contain_word(char *dictionary, char *word) {
    // your code
    if (word == NULL || *word == '\0') {
            return 0;
        } else {
            for (int i = 0; word[i]; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    word[i] = word[i] + ('a' - 'A');
                }
            }

    char x[50] = {0};
    strcat(x, ",");
    strcat(x, word);
    strcat(x, ",");

    if (strstr(dictionary, x) != NULL) {
        return 1;
    } else {
        return 0;
    }
}
}

/**
 *  add your comment
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    // your code
    WORDSTATS stats = {0, 0, 0};
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        stats.line_count++;

        char delimiters[] = " .,\n\t\r";
        char *word_token = strtok(line, delimiters);

        while (word_token != NULL) {
            stats.word_count++;
            if (contain_word(dictionary, word_token) != TRUE) {
                int i;
                for (i = 0; i < stats.keyword_count; i++) {
                    if (strcmp(words[i].word, word_token) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (i == stats.keyword_count) {
                    if (stats.keyword_count < MAX_WORDS) {
                        strcpy(words[stats.keyword_count].word, word_token);
                        words[stats.keyword_count].count = 1;
                        stats.keyword_count++;
                    }
                }
            }

            word_token = strtok(NULL, delimiters);
        }
    }
    return stats;
}