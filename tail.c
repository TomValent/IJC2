// tail.c
// Riesenie IJC-DU2, priklad a), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vypis poslednych n riadkov suboru

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 500
#define DEFAULTLINECOUNT 10

int checkArguments(char *first, char *second)
{
    if (strcmp(first, "-n") != 0)
    {
        fprintf(stderr, "Error: Wrong arguments. Expected: '-n number'.\n");
        return 1;
    }

    char *string = NULL;
    int lines = strtol(second, &string, 10);
    if(string[0] != '\0')
    {
        fprintf(stderr, "Error: Number in argument was not converted correctly.\n");
        return 1;
    }

    if(lines < 0) {
        fprintf(stderr, "Count of lines cant be lower than zero.\n");
        return 1;
    }
    return lines;
}

int main(int argc, char **argv)
{
    int lastLines = DEFAULTLINECOUNT, lineCounterFirst = 0, lineCounterSecond = 0;
    char line[LINESIZE];
    FILE *file = stdin;
    FILE *filename;
    int error = 0;

    filename = fopen ("subor.txt", "w");     //zaloha pre stdin
    if(filename == NULL)
    {
        fprintf(stderr, "File was not opened correctly.\n");
        return 1;
    }

    if(argc == 2)
    {
        file = fopen (argv[1], "r");     //len subor
        if(file == NULL)
        {
            fprintf(stderr, "File was not opened correctly.\n");
            return 1;
        }
    }
    else if(argc == 3)
    {
        lastLines = checkArguments(argv[1], argv[2]);            //cislo riadka
    }
    else if(argc == 4)
    {
        lastLines = checkArguments(argv[1], argv[2]);            //cislo riadka a subor
        file = fopen(argv[3], "r");
        if(file == NULL)
        {
            fprintf(stderr, "File was not opened correctly.\n");
            return 1;
        }
    }
    else if(argc != 1)
    {
        fprintf(stderr, "Error: Expected 2-4 arguments.\n");
        return 1;
    }

    while(fgets(line, LINESIZE, file) != NULL)
    {
        lineCounterFirst++;
        fprintf(filename, "%s", line);
    }

    fclose(file);
    fclose(filename);

    FILE *subor = fopen ("subor.txt", "r");
    if(subor == NULL)
    {
        fprintf(stderr, "File was not opened correctly.\n");
        return 1;
    }

    while(fgets(line, LINESIZE+1, subor) != NULL)
    {
        if(++lineCounterSecond >= lineCounterFirst - lastLines)
        {
            if(strlen(line) > LINESIZE)
            {
                if(++error == 1)
                {
                    fprintf(stderr, "Minimally 1 line is too long.\n");
                }
            }
            printf("%s", line);
        }
    }

    fclose(filename);
    return 0;
}