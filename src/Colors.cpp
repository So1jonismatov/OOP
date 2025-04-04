#include "Colors.h"
#include <cstdlib>   
#include <ctime> 

Color darkGrey   = {26, 31, 40, 255};
Color green      = {47, 230, 23, 255};
Color red        = {232, 18, 18, 255};
Color orange     = {226, 116, 17, 255};
Color yellow     = {237, 234, 4, 255};
Color purple     = {166, 0, 247, 255};
Color cyan       = {21, 204, 209, 255};
Color blue       = {13, 64, 216, 255};
Color lightBlue  = {59, 85, 162, 255};
Color darkblue   = {44, 44, 127, 255};

std::vector<Color> GetCellColors() {
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

Color RandomColor() {
    

    Color c;
    c.r = 100 + rand() % 156;
    c.g = 100 + rand() % 156;
    c.b = 100 + rand() % 156;
    c.a = 255;
    return c;
}

std::vector<Color> GetRandomCellColors() {
    green    = RandomColor();
    red      = RandomColor();
    orange   = RandomColor();
    yellow   = RandomColor();
    purple   = RandomColor();
    cyan     = RandomColor();
    blue     = RandomColor();

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

std::vector<Color> SetOriginalColors() {
    darkGrey   = {26, 31, 40, 255};
    green      = {47, 230, 23, 255};
    red        = {232, 18, 18, 255};
    orange     = {226, 116, 17, 255};
    yellow     = {237, 234, 4, 255};
    purple     = {166, 0, 247, 255};
    cyan       = {21, 204, 209, 255};
    blue       = {13, 64, 216, 255};
    lightBlue  = {59, 85, 162, 255};
    darkblue   = {44, 44, 127, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
