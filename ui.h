#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include <string.h>

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

int getString20(char* str)
{
    char buf[20] = "";
    scanf("%20s", buf);
    clearExtraInput();

    if (strlen(buf) > 19)
    {
        return 1;
    }

    else
    {
        strcpy(str, buf);
        printf("-- %s", str);
        return 0;
    }
}

void showMenu()
{
    printf("1. Create new good configuration\n"
    "2. Save current configuration to file\n"
    "3. Import configuration from file\n"
    "4. View current configuration\n"
    "99. Exit\n");
}

void setupBodyColor(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Body color:\n"
    "1. White\n"
    "2. Black\n>");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->BodyColor = COLOR_WHITE;
        break;
    
    case 2:
        lamp->BodyColor = COLOR_BLACK;
        break;

    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupBody(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Body type:\n"
    "1. Aluminum\n"
    "2. Steel\n "
    "3. Carbon\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->Body = ALUMINUM;
        break;
    
    case 2:
        lamp->Body = STEEL;
        break;

    case 3:
        lamp->Body = CARBON;
        setupBodyColor(lamp);
        break;

    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupForcedStand(struct Lamp* lamp)
{
    printf(
    "Forced Stand?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->StandTier = PLAIN_STAND;
        break;
    
    case 2:
        lamp->StandTier = FORCED_STAND;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupStand(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Stand type:\n"
    "1. Floor\n"
    "2. Ceiling\n"
    "3. Wall\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->Stand = FLOOR;
        break;
    
    case 2:
        lamp->Stand = CEILING;
        break;

    case 3:
        lamp->Stand = WALL;
        setupForcedStand(lamp);
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupEmitterAction(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Emitter action:\n"
    "1. Basic\n"
    "2. Anti-microbes\n"
    "3. Anti-viruses\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->EmitterAction = PLAIN_ACTION;
        break;
    
    case 2:
        lamp->EmitterAction = ANTI_MICROBES;
        break;

    case 3:
        lamp->EmitterAction = ANTI_VIRUSES;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupEmitterExtra(struct Lamp* lamp)
{
    printf(
    "Extra Emitter?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->EmitterExtra = NO_EXTRA_EMMITTER;
        break;
    
    case 2:
        lamp->EmitterExtra = EXTRA_EMMITTER;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupEmitter(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Emitter type:\n"
    "1. Basic\n"
    "2. ECO\n"
    "3. High Class\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->EmitterType = BASIC_EMITTER;
        break;
    
    case 2:
        lamp->EmitterType = ECO_EMMITTER;
        break;

    case 3:
        lamp->EmitterType = HI_CLASS_EMITTER;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupControllerType(struct Controller* Controller)
{
    printf("Type '99' to return to menu\n"
    "Select Controller type:\n"
    "1. Basic\n"
    "2. With Clock\n>");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        Controller->type = PLAIN;
        break;
    
    case 2:
        Controller->type = W_CLOCK;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupControllerWifi(struct Controller* Controller)
{
    printf(
    "Wifi Module?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        Controller->wifiChip = NO_WIFI;
        break;
    
    case 2:
        Controller->wifiChip = WIFI;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupControllerRc(struct Controller* Controller)
{
    printf(
    "Remote Control by IR?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        Controller->rc = NO_RC;
        break;
    
    case 2:
        Controller->rc = RC;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupControllerRcMount(struct Controller* Controller)
{
    printf(
    "Mount for Remote Control?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        Controller->rcMount = NO_MOUNT;
        break;
    
    case 2:
        Controller->rc = WALL_MOUNT;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupControllerDumbProtection(struct Controller* Controller)
{
    printf(
    "Dumb protection?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        Controller->rcDP = NO_MOUNT;
        break;
    
    case 2:
        Controller->rcDP = WALL_MOUNT;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupController(struct Lamp* lamp)
{
    printf("Controller Setup:\n");
    setupControllerType(&lamp->_Controller);
    if (lamp->_Controller.type != PLAIN)
    {
        setupControllerWifi(&lamp->_Controller);
        setupControllerRc(&lamp->_Controller);
        setupControllerRcMount(&lamp->_Controller);
        setupControllerDumbProtection(&lamp->_Controller);
    }
}

void setupWarranty(struct Lamp* lamp)
{
    printf(
    "Extra Warranty?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->Warranty = NO_EXTRA_WARRANTY;
        break;
    
    case 2:
        lamp->Warranty = EXTRA_WARRANTY;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupAdvancedWarranty(struct Lamp* lamp)
{
    printf(
    "Advanced Care Warranty?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->AdvancedWarranty = NO_ADVANCED_CARE;
        break;
    
    case 2:
        lamp->AdvancedWarranty = ADVANCED_CARE;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupAdvancedService(struct Lamp* lamp)
{
    printf(
    "Advanced 24/7 Service?:\n"
    "1. Yes\n"
    "2. No\n");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 99};
        choice = getIntChoice(3, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->Service = NO_ADVANCED_SERVICE;
        break;
    
    case 2:
        lamp->Service = H24SERVICE;
        break;
    
   case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

// Optional Parameters

void setupOptionalType(struct Lamp* lamp)
{
    printf("Type '99' to return to menu\n"
    "Select Extra Option Type:\n"
    "1. No extras\n"
    "2. Home comfort extras\n"
    "3. Facility extras\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        lamp->ExtraType = NO_EXTRA_OPTIONS;
        break;
    
    case 2:
        lamp->ExtraType = HOME_OPTIONS;
        break;

    case 3:
        lamp->ExtraType = FACILITY_OPTIONS;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

// HOME Options
void setupDecorativePanels(struct HomeOptions* homeOpt)
{
    printf("Type '99' to return to menu\n"
    "Select DecorativePanels Type:\n"
    "1. No panels\n"
    "2. Wooden panels\n"
    "3. Plastic panels\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        homeOpt->DecorativePanels = NO_PANELS;
        break;
    
    case 2:
        homeOpt->DecorativePanels = WOOD_PANELS;
        break;

    case 3:
        homeOpt->DecorativePanels = PLASTIC_PANELS;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupHomeComfort(struct HomeOptions* homeOpt)
{
    setupDecorativePanels(homeOpt);
}

// FACILITY Options

void setupWaterProtection(struct FacilityOptions* facOpt)
{
    printf("Type '99' to return to menu\n"
    "Select DecorativePanels Type:\n"
    "1. No protection\n"
    "2. IP67\n"
    "3. IP68\n> ");

    int choice = -1;

    while (choice == -1)
    {
        int choices[] = {1, 2, 3, 99};
        choice = getIntChoice(4, choices);
    }
    
    switch (choice)
    {
    case 1:
        facOpt->WaterProtection = NO_WATER_PROTECTION;
        break;
    
    case 2:
        facOpt->WaterProtection = IP67_WATER_PROTECTION;
        break;

    case 3:
        facOpt->WaterProtection = IP68_WATER_PROTECTION;
        break;
    
    case 99:
        return;
        break;
    
    default:
        printf("Incorrect Input!\n> ");
        break;
    }
}

void setupFacilityExtras(struct FacilityOptions* facOpt)
{
    setupWaterProtection(facOpt);
}

void setupConfiguration(struct Lamp* lp)
{
    setupBody(lp);
    if (lp->Body == CARBON)
    {
        setupBodyColor(lp);
    }

    setupStand(lp);
    if (lp->Stand == WALL)
    {
        setupForcedStand(lp);
    }

    setupEmitter(lp);
    if (lp->EmitterType)
    {
        setupEmitterAction(lp);
        setupEmitterExtra(lp);
    }

    setupController(lp);

    setupWarranty(lp);
    if(lp->Warranty)
    {
        setupAdvancedService(lp);
        setupAdvancedWarranty(lp);
    }

    setupOptionalType(lp);
    if (lp->ExtraType)
    {
        if (lp->ExtraType == HOME_OPTIONS)
        {
            setupHomeComfort(&lp->_ExtraOptions.homeOpt);
        }

        else
        {
            setupFacilityExtras(&lp->_ExtraOptions.facOpt);
        }
    }
}

void printInfo(union Configuration* conf, struct Lamp* lp, struct Prices* pc)
{
    printf("Body: %d\nBody color: %d\nStand: %d\nStand Tier: %d\n"
    "Emitter: %d\nEmitter Action: %d\n EmitterExtra: %d\n\n", lp->Body, lp->BodyColor ,lp->Stand, lp->StandTier,lp->EmitterType, lp->EmitterAction, lp->EmitterExtra);

    struct Controller* cnt = &lp->_Controller;
    struct HomeOptions* homeOpt = &lp->_ExtraOptions.homeOpt;
    struct FacilityOptions* facOpt = &lp->_ExtraOptions.facOpt;

    printf("Controller:\nController type: %d\nWifi chip: %d\nRemote Control: %d\nRemote Control Mount: %d\nDumb Protection: %d\n\n", cnt->type, cnt->wifiChip, cnt->rc, cnt->rcMount, cnt->rcDP);
    printf("Warranty: %d\nAdvancedWarranty: %d\nCare Service :%d\n\n", lp->Warranty, lp->AdvancedWarranty, lp->Service);

    if (lp->ExtraType)
    {
        if (lp->ExtraType == HOME_OPTIONS)
        {
            printf("Decorative panels: %d\n\n", homeOpt->DecorativePanels);
        }

        else
        {
            printf("WaterProtection: %d\n\n", facOpt->WaterProtection);
        }
    }

    printf("Price: %d\n", calculatePrice(lp, pc));

    printf("raw: %d\n\n", conf->_bytes);
}