#ifndef UTILS_H
# define UTILS_H

char    *getValues(char *key, char **numbers, char **values);
char    *getLength(char *str);
char    *getLengthNumber(char *str);
int     zero(char *str);
char    *getInput(char *str, const char *dict_pathname);
int     myStrlen(char *str);
void    myStrcatSpaces(char *dest, char *src);
char    *myStringDuplicate(char *src);
int     myStringcmp(char *s1, char *s2);
int     myAtoi(char *str);
char    *getNumber(int *cur, char *str, char **number);
int     getSize(int cur, char *str);
int     onlySpaces(int cur, char *str);
int     parseString(char **strs, char ***nums, char ***vals);
void    *getLineLength(int file, int *file_sizes);
int     getLineLoop(int file, int *file_sizes, char ***lines);
int     getLines(const char *pathname, char ***lines);

#endif 