#include <stdio.h>
#include <stdlib.h>
#include "md5.h"
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        printf("cant open %s for reading\n", argv[1]);
        exit(1);
    }
    
    
    FILE *out = fopen(argv[2], "w");
    if(!out)
    {
        printf("cant open %s for writing\n", argv[2]);
        exit(1);
    }

    char password[100];
    while(fgets(password, 100, in))
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(password[i] == '\n')
            {
                password[i] = '\0';
            }
        }
        fprintf(out, "%s\n", md5(password, strlen(password)));
    }

}