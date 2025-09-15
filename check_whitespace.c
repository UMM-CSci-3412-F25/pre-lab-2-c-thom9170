#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Strips spaces from both the front and back of a string,
 * leaving any internal spaces alone.
 */


char const *strip(char const *str) {
	int size = strlen(str);

    int num_spaces = 0;
    int first_non_space = 0;
    while (first_non_space < size && str[first_non_space] == ' ') {
        ++num_spaces;
        ++first_non_space;
    }

   
   
    int last_non_space = size - 1;
    while (last_non_space >= 0 && str[last_non_space] == ' ') {
        ++num_spaces;
        --last_non_space;
    }

   
   
    // If the string is all spaces, return literal empty string
    if (num_spaces >= size) {
       
	    return "";
   
    }

   
   
    // Allocate memory for the stripped string + null terminator
    char *result = (char *) calloc(size - num_spaces + 1, sizeof(char));
    int i;
    for (i = first_non_space; i <= last_non_space; ++i) {
        result[i - first_non_space] = str[i];
    }
    result[i - first_non_space] = '\0';

    return result;
}

/*
 * Return true (1) if the given string is "clean", i.e., has
 * no spaces at the front or the back of the string.
 */
int is_clean(char const *str) {
    
	const char *cleaned = strip(str);
    
	int result = strcmp(str, cleaned);

    // Free allocated memory unless it is the literal ""
    
	if (cleaned[0] != '\0') {
        
		free((void *) cleaned);
    
	}

    return result == 0;
}
