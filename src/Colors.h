#ifndef COLORS
#define COLORS

#include <vector>
#include <raylib.h>

// Only declarations here (no = {...})
extern Color darkGrey;
extern Color green;
extern Color red;
extern Color orange;
extern Color yellow;
extern Color purple;
extern Color cyan;
extern Color blue;
extern Color lightBlue;
extern Color darkblue;

std::vector<Color> GetCellColors();
Color RandomColor();
std::vector<Color> GetRandomCellColors();
std::vector<Color> SetOriginalColors();


#endif
