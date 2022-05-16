#define NUM_CHOICES 6

#include "ui.h"
#include "parser.h"
#include <stdlib.h>

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* записываем знак */
        n = -n;          /* делаем n положительным числом */
    i = 0;
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(int argc, char* argv[])
{   
    // if (argc != 2)
    // {
    //     printf("Invalid arguments!\n");
    //     exit(EXIT_FAILURE);
    // }

    union Configuration conf;
    struct Prices prs = {0};

    // int res = readPrices(argv[1], &prs);
    int res = readPrices("prices.txt", &prs);

    if (res != 0)
    {
        if (res == -1)
        {
            printf("Error opening prices file!");
        }

        exit(EXIT_FAILURE);
    }

    cInit(&conf);
    
    int choices[NUM_CHOICES] = {99, 1, 2, 3, 4, 5};

    showMenu();
    while (1)
    {
        printf("> ");
        int choice = getIntChoice(NUM_CHOICES, choices);

        switch (choice)
        {
        case 1:
            setupConfiguration(&conf._Lamp);
            break;
        
        case 2:
            res = 1;
            char fname[20] = "";
            while (res)
            {
                printf("Enter 99 to return to menu\nEnter Filename (less than 20 symbols)\n>");
                res = getString20(fname);    
                printf("%d", res);    
            }

            if(!strcmp("99", fname))
            {
                break;
            }

            printf("%s\n", fname);
            FILE* fp = fopen(fname, "rwb");

            if (fp == NULL)
            {
                printf("New config!\n");
                fclose(fp);
                fp = fopen(fname, "wb");
                if (fp == NULL)
                {
                    perror("Cannot open File");
                    break;
                }
            }
            fseek(fp, 0, SEEK_END);
            int len = ftell(fp);

            if (len)
            {
                printf("Rewrite %s?\n1-Yes\2-No", fname);
                int ch[2] = {1, 2};
                int res = getIntChoice(2, ch);

                if (res == 2)
                {
                    break;
                }
            }

            fclose(fp);
            fp = fopen(fname, "wb");

            char buf[20] = "";
            itoa(conf._bytes, buf);

            printf("======== %s", buf);

            fseek(fp, SEEK_SET, 0);
            fprintf(fp, "%s", buf);
            printf("Success!\n");
            fclose(fp);
            break;

        case 4:
            printInfo(&conf, &conf._Lamp, &prs);
            break;
            
        default:
            printf("Incorrect Input!\n");
            break;
        }
    }
}