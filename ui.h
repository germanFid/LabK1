#include <stdio.h>
#include <stdlib.h>

void clearExtraInput()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

int getIntChoice(int n, int* choices)
{
    char buf[3];

    scanf("%3s", buf);
    clearExtraInput();

    char* end;
    int choice = (int) strtol(buf, &end, 10);

    if (choice == 0)
        return -1;

    for (size_t i = 0; i < n; i++)
    {
        if(choices[i] == choice)
            return choice;
    }
    
    return -1;
}

void showMenu()
{
    printf("1. Create new good configuration\n"
    "2. Save current configuration to file\n"
    "3. Import configuration from file\n"
    "4. View/edit current configuration\n"
    "5. Calculate price per item\n\n"
    "99. Exit\n");
}