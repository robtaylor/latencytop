#include <stdlib.h>
#include <stdio.h>
#include "android.h"


ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
       char *line = *lineptr;
       ssize_t len = 0, alloced = *n;
       int ch;

       do {
               ch = fgetc(stream);
               if (ch == EOF) {
                       if (len)
                               break;
                       return -1;
               }
               if (len + 1 > alloced) {
                       alloced = alloced ? alloced * 2 : 120;
                       line = realloc(line, alloced);
                       if (line == NULL)
                               return -1;
               }
               line[len++] = ch;
       } while (ch != delim);

       line[len] = 0;
       *lineptr = line;
       *n = alloced;
       return len;
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
       /* FIXME: could optimize with fgets() */
       return getdelim(lineptr, n, '\n', stream);
}
