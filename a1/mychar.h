#ifndef MYCHAR_H
#define MYCHAR_H
/**
 * Determine the type of a char character. 
 *
 * @param c - char type value
 * @return - 0 if c is a digit, 1 if c is an arithmetic operator, 2 if c is an English letter; otherwise -1. 
 */
int mytype(char c);

/**
 * Flip the case of an English character. 
 *
 * @param c - char type value of ASCII code of English letter.
 * @return  -  c's upper/lower case letter if c is a lower/upper case English letter. 
 */
char case_flip(char c);

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value of ASCII code of digit charactor.
 * @return - its corresponding integer value if c is a digit character. 
 */
int char_to_int(char c);

#endif