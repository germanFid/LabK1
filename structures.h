#ifndef STRUCTURES
#define STRUCTURES

#define uint unsigned int

enum bType {ALUMINUM, STEEL, CARBON};
enum bColor {COLOR_WHITE, COLOR_BLACK};

enum sType {FLOOR, CEILING, WALL};
enum sTier {PLAIN_STAND, FORCED_STAND};

enum eType {BASIC_EMITTER, ECO_EMMITTER, HI_CLASS_EMITTER};
enum eTypeAction {PLAIN_ACTION, ANTI_MICROBES, ANTI_VIRUSES};
enum eExtraEmmitter {NO_EXTRA_EMMITTER, EXTRA_EMMITTER};

enum cType {PLAIN, W_CLOCK};
enum wfType {NO_WIFI, WIFI};
enum rcType {NO_RC, RC};
enum rcMount {NO_MOUNT, WALL_MOUNT};
enum cDumbProtection {NO_DUMB_PROTECTION, DUMB_PROTECTION};

enum OptType {NO_EXTRA_OPTIONS, HOME_OPTIONS, FACILITY_OPTIONS}; // Выбор типа опций
enum PanelsType {NO_PANELS, WOOD_PANELS, PLASTIC_PANELS};
enum WaterProtect {NO_WATER_PROTECTION, IP67_WATER_PROTECTION, IP68_WATER_PROTECTION};

enum wType {NO_EXTRA_WARRANTY, EXTRA_WARRANTY};
enum awType {NO_ADVANCED_CARE, ADVANCED_CARE};
enum swType {NO_ADVANCED_SERVICE, H24SERVICE};

struct __attribute__((__packed__)) Controller
{
    uint type: 1;
    uint wifiChip: 1;
    uint rc: 1;
    uint rcMount: 1;
    uint rcDP: 1;
};

struct __attribute__((__packed__)) HomeOptions
{
    uint DecorativePanels: 2;
};

struct __attribute__((__packed__)) FacilityOptions
{
    uint WaterProtection: 2;
};

union ExtraOptions
{
    struct HomeOptions homeOpt;
    struct FacilityOptions facOpt;
};

struct __attribute__((__packed__)) Lamp
{
    uint Body: 2;
    uint BodyColor: 1;

    uint Stand: 2;
    uint StandTier: 1;

    uint EmitterType: 2;
    uint EmitterAction: 2;
    uint EmitterExtra: 1;
    
    struct Controller _Controller; // 5

    uint Warranty: 1;
    uint AdvancedWarranty: 1;
    uint Service: 1;

    uint ExtraType: 2;
    union ExtraOptions _ExtraOptions; // 4
};

union Configuration
{
    uint _bytes;
    struct Lamp _Lamp;
};

void cInit(union Configuration* config)
{
    config->_bytes = 0;
}

struct Prices
{
    int body[3]; // 1.1
    int color[2]; // 1.2

    int sType[3]; // 2.1
    int sTier[2]; // 2.2

    int eType[3]; // 3.1
    int eTypeAction[3]; // 3.2
    int eExtraEmitter[2]; // 3.3

    int cType[2]; // 4.1
    int wfType[2]; // 4.2
    int rcType[2]; // 4.3
    int rcMount[2]; // 4.4
    int rcDP[2]; // 4.5

    int optType[3]; // 5.1
    int panelsType[3]; // 5.2
    int waterProtect[3]; // 5.3

    int wType[2]; // 6.1
    int awType[2]; // 6.2
    int swType[2]; // 6.3
};

int calculatePrice(struct Lamp* l, struct Prices* p)
{
    int result = 0;
    result += p->body[l->Body] + p->color[l->BodyColor];
    printf("=== %d %d %d\n", result, p->body[l->Body], l->Body);
    result += p->sType[l->Stand] + p->sTier[l->StandTier];
    result += p->eType[l->EmitterType] + p->eTypeAction[l->EmitterAction] + p->eExtraEmitter[l->EmitterExtra];

    struct Controller* cnt = &l->_Controller;
    result += p->cType[cnt->type] + p->wfType[cnt->wifiChip] + p->rcType[cnt->rc] + p->rcMount[cnt->rcMount] + p->rcDP[cnt->rcDP];

    result += p->optType[l->ExtraType] + p->panelsType[l->_ExtraOptions.homeOpt.DecorativePanels] + p->waterProtect[l->_ExtraOptions.facOpt.WaterProtection];
    result += p->wType[l->Warranty] + p->awType[l->AdvancedWarranty] + p->swType[l->Service];

    return result;
};

#endif
