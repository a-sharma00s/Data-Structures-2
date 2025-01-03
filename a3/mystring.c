/*
 * your program signature
 */ 
#include<stdio.h>
#include<string.h>
#include "mystring.h"

int str_words(char *s) {
    int len = strlen(s);
    int word_count = 0;
    char delimiters[] = " .,\t";

    int i = 0;
    while (i < len && strchr(delimiters, s[i]) != NULL) {
        i++;
    }

    while (i < len) {
        if (isalpha(s[i])) {
            word_count++;
        }

        while (i < len && strchr(delimiters, s[i]) == NULL) {
            i++;
        }

        while (i < len && strchr(delimiters, s[i]) != NULL) {
            i++;
        }
    }

    return word_count;

}


int str_lower(char *s) {
    // your code
    if (s == NULL) {
        return 0;
    }

    int strlower_flips = 0;

    while (*s != '\0') {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + ('a' - 'A');
            strlower_flips++;
        }

        s++;
    }

    return strlower_flips;
}

/**
 *  add your comment
 */
void str_trim(char *s) {
    // your code
    int nonspace_count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s[nonspace_count] = s[i];
            nonspace_count++;
        }
    }

    s[nonspace_count] = '\0';
    
    return s;
}