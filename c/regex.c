
#include <stdio.h>
#include <regex.h>

/*
 * Match string against the extended regular expression in
 * pattern, treating errors as no match.
 *
 * return 1 for match, 0 for no match
 */

int main (int argc, char** argv) {
    if(sizeof(argv) == 1)  { printf("Pass a string in as an argument\n");  return 0; }
    match(argv[1], "^([a-zA-Z])+");
    return 0;
}

int match(const char *string, char *pattern)
{
    int    status;
    regex_t    re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        printf("Error compiling regular expression");
        return(0);      /* report error */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        printf("Expression did not match\n");
        return(0);      /* report error */
    }
    printf("Expression matched\n");
    return(1);
}
