/**
 * -------------------------------------
 * @file  mystring.h
 * 
 * -------------------------------------
 * @author Ashish Sharma, 169044454, shar4454@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */

#ifndef MYSTRING_H
#define MYSTRING_H

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a str
 * @return - return the number of words. 
 */
int str_words(char *s);

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.   
 */
int str_lower(char *s);

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s);

#endif