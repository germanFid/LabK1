#ifndef DE3D87D9_E439_492B_8790_3EC1E51B0DE4
#define DE3D87D9_E439_492B_8790_3EC1E51B0DE4

#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <string.h>
#include <ctype.h>
#include <limits.h>

// int isNumber(char s[])
// {
//     for (int i = 0; s[i]!= '\0'; i++)
//     {
//         if (isdigit(s[i]) == 0)
//               return 0;
//     }
//     return 1;
// }

int setPriceField (char* num, struct Prices* prices, int price, int n)
{
    if (!strcmp(num, "1.1"))
    {
        prices->body[n] = price;
        return 3;
    }

    if (!strcmp(num, "1.2"))
    {
        prices->color[n] = price;
        return 2;
    }

    if (!strcmp(num, "2.1"))
    {
        prices->sType[n] = price;
        return 3;
    }

    if (!strcmp(num, "2.2"))
    {
        prices->sTier[n] = price;
        return 2;
    }

    if (!strcmp(num, "3.1"))
    {
        prices->eType[n] = price;
        return 3;
    }

    if (!strcmp(num, "3.2"))
    {
        prices->eTypeAction[n] = price;
        return 3;
    }

    if (!strcmp(num, "3.3"))
    {
        prices->eExtraEmitter[n] = price;
        return 2;
    }

    if (!strcmp(num, "4.1"))
    {
        prices->cType[n] = price;
        return 2;
    }

    if (!strcmp(num, "4.2"))
    {
        prices->wfType[n] = price;
        return 2;
    }

    if (!strcmp(num, "4.3"))
    {
        prices->rcType[n] = price;
        return 2;
    }

    if (!strcmp(num, "4.4"))
    {
        prices->rcMount[n] = price;
        return 2;
    }

    if (!strcmp(num, "4.5"))
    {
        prices->rcDP[n] = price;
        return 2;
    }

    if (!strcmp(num, "5.1"))
    {
        prices->optType[n] = price;
        return 3;
    }

    if (!strcmp(num, "5.2"))
    {
        prices->panelsType[n] = price;
        return 3;
    }

    if (!strcmp(num, "5.3"))
    {
        prices->waterProtect[n] = price;
        return 3;
    }

    if (!strcmp(num, "6.1"))
    {
        prices->wType[n] = price;
        return 2;
    }

    if (!strcmp(num, "6.2"))
    {
        prices->awType[n] = price;
        return 2;
    }

    if (!strcmp(num, "6.3"))
    {
        prices->swType[n] = price;
        return 2;
    }

    return -1;
}

int readPrices (const char* filename, struct Prices* prices)
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int lineCount = 0; // счетчик строк (не более 18и)

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s", line);

        char buf[200];
        strcpy(buf, line);

        lineCount++;
        char* num = (char*) malloc(3); // Номер компонента цены
        
        char* pch;
        pch = strtok(buf, " ");
        strcpy(num, pch);

        int res = 100;
        int resCounter = 1;

        // printf("=== %d %d ===\n", lineCount, res);

        long i;
        pch = strtok (NULL, " ");
        while (pch != NULL) // пока есть лексемы
        {
            if (resCounter > res)
            {
                printf("Too many prices in string %d\n", lineCount);
                fclose(fp);
                return -2;
            }

            char* end;

            // Обработка pch
            // printf("%s|", pch);
            i = strtol(pch, &end, 10);
            // printf("%d\n", (int)i);

            if (i != LONG_MAX && i != LONG_MIN)
            {
                // field[resCounter] = (int) i;
                int r = setPriceField(num, prices, i, resCounter-1);
                if (res == 100)
                {
                    res = r;
                }
            }

            pch = strtok (NULL, " ");
            resCounter++;
        }

        free(num);
        if (resCounter - 1 != res)
        {
            printf("Too few prices in string %d : %d %d\n", lineCount, resCounter, res);
            fclose(fp);
            return -2;
        }
    }
    fclose(fp);
    return 0;
}

#endif /* DE3D87D9_E439_492B_8790_3EC1E51B0DE4 */
